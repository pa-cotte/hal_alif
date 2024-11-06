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

    if (fileExists('/media/share/jenkins_share/zephyrproject_hal_alif.tar.gz')) {
        sh """#!/bin/bash -xe
            eval `ssh-agent -s`
            . venv/bin/activate
	    echo "Unpackage from tar"
            cp /media/share/jenkins_share/zephyrproject_hal_alif.tar.gz .
            tar xf zephyrproject_hal_alif.tar.gz
            cd zephyrproject
	    cd alif
	    GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' git checkout main
	    cd ..
            GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' west update
	    cd zephyr
            GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' west zephyr-export
            pip install -r scripts/requirements.txt
            cd ../..
            deactivate"""
    } else {
        sh """#!/bin/bash -xe
            . venv/bin/activate
            eval `ssh-agent -s`
	    echo "Initialize SDK"
	    ls -la

	    # rm -rf zephyrproject
	    GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' west init zephyrproject -m org-115832732@github.com:AlifSemiDev/sdk-alif.git

            cd zephyrproject/

	    GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' west update

            cd zephyr
            GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' west zephyr-export
            pip install -r scripts/requirements.txt
            cd ../..
            tar -czvf zephyrproject_hal_alif.tar.gz zephyrproject
            cp zephyrproject_hal_alif.tar.gz /media/share/jenkins_share/
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
        # Go and checkout the PR branch in ../modules/hal/alif before building!
        cd ../modules/hal/alif

        GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' git fetch --all
        GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' git branch -avv
        git remote -v
        if [ -n ${CHANGE_BRANCH} ];
          then GIT_SSH_COMMAND='ssh -i ~/.ssh/id_ed25519_alif-ci-Dev-cert -o IdentitiesOnly=yes' git checkout $CHANGE_BRANCH;
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
