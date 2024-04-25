def clean_zephyr_cache() {
    sh """#!/bin/bash -xe
        rm -f /media/share/jenkins_share/zephyrproject_zephyr_alif.tar.gz"""
}

def zephyr_init() {
    sh """#!/bin/bash -xe
        printenv NODE_NAME
        eval `ssh-agent -s`
        rm -rf venv
        mkdir venv
        python3 -m venv venv
        . venv/bin/activate
        pip install wheel
        pip install west
        deactivate"""

    if (fileExists('/media/share/jenkins_share/zephyrproject_zephyr_alif.tar.gz')) {
        sh """#!/bin/bash -xe
            eval `ssh-agent -s`
            . venv/bin/activate
            cp /media/share/jenkins_share/zephyrproject_zephyr_alif.tar.gz .
            tar xf zephyrproject_zephyr_alif.tar.gz
            cd zephyrproject/zephyr
            #west update
            west zephyr-export
            pip install -r scripts/requirements.txt
            cd ../..
            deactivate"""
    } else {
        sh """#!/bin/bash -xe
            . venv/bin/activate
            eval `ssh-agent -s`
            west init zephyrproject -m org-115832732@github.com:AlifSemiDev/zephyr_alif.git
            cd zephyrproject/
            west update
            cd zephyr
            ssh-add /home/alif-fi/.ssh/id_ed25519_alif-ci
            west update
            west zephyr-export
            pip install -r scripts/requirements.txt
            cd ../..
            tar -czvf zephyrproject_zephyr_alif.tar.gz zephyrproject
            cp zephyrproject_zephyr_alif.tar.gz /media/share/jenkins_share/
            deactivate"""
    }
}

def build_zephyr(String sample, String build_dir, String board, String conf_file=null) {
    String overlay = ""
    if (conf_file) {
    	overlay = "-- -DOVERLAY_CONFIG=$conf_file"
    }
    sh """#!/bin/bash -x
        set +e
        env
        . venv/bin/activate
        cd zephyrproject/zephyr
        ssh-add /home/alif-fi/.ssh/id_ed25519_alif-ci
        //Go and checkout the PR branch in ../modules/hal/alif before building!
        cd ../modules/hal/alif
        git fetch --all
        git branch -avv
        git remote -v
        if [ -n ${CHANGE_BRANCH} ];
          then git checkout $CHANGE_BRANCH;
        else
          echo "building 'main' branch";
        fi
        cd ../../..
        cd zephyr
        west build -p always -b $board --build-dir $build_dir $sample $overlay
        deactivate"""
}


return [
    build_zephyr: this.&build_zephyr,
    clean_zephyr_cache: this.&clean_zephyr_cache,
    zephyr_init: this.&zephyr_init
]
