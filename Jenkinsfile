

def common_funcs

def samples1 = ['beacon', 'broadcast_audio_sink', 'broadcast_audio_source', 'broadcaster', 'broadcaster_multiple', 'central',
               'central_gatt_write', 'central_hr', 'central_ht', 'central_iso', 'central_multilink', 'central_otc']

def samples2 = ['central_past', 'direct_adv', 'direction_finding_central', 'direction_finding_connectionless_rx', 'direction_finding_connectionless_tx', 'direction_finding_peripheral',
               'eddystone', 'handsfree', 'hap_ha', 'hci_pwr_ctrl', 'hci_rpmsg', 'hci_spi']

def samples3 = ['hci_uart', 'hci_usb', 'hci_usb_h4', 'ibeacon', 'ipsp', 'iso_broadcast',
               'iso_broadcast_benchmark', 'iso_connected_benchmark', 'iso_receive', 'mesh', 'mesh_demo', 'mesh_provisioner']

def samples4 = ['mtu_update', 'observer', 'periodic_adv', 'periodic_sync', 'peripheral', 'peripheral_accept_list',
               'peripheral_csc', 'peripheral_dis', 'peripheral_esp', 'peripheral_gatt_write', 'peripheral_hids', 'peripheral_hr']

def samples5 = ['peripheral_ht', 'peripheral_identity', 'peripheral_iso', 'peripheral_ots', 'peripheral_past',
               'peripheral_sc_only', 'scan_adv', 'st_ble_sensor', 'unicast_audio_client', 'unicast_audio_server']

def bleStagesMap1 = samples1.collectEntries {
    ["${it}" : generate_ble_stage(it)]
}

def bleStagesMap2 = samples2.collectEntries {
    ["${it}" : generate_ble_stage(it)]
}

def bleStagesMap3 = samples3.collectEntries {
    ["${it}" : generate_ble_stage(it)]
}

def bleStagesMap4 = samples4.collectEntries {
    ["${it}" : generate_ble_stage(it)]
}

def bleStagesMap5 = samples5.collectEntries {
    ["${it}" : generate_ble_stage(it)]
}

def generate_ble_stage(sample) {
    return {
        String str =
        stage("Build ${sample} sample") {
            script {
                common_funcs = load 'test_samples.groovy'
                common_funcs.build_zephyr("samples/bluetooth/${sample}", "build-b1-${sample}", "alif_b1_fpga_rtss_he_ble");
            }
        }
    }
}

pipeline {
    agent none
    parameters {
        booleanParam(name: "FORCE_CLEAN_CACHE", defaultValue: false, description: "Clean cached Zephyr base package")
    }
    options {
    	// Timeout for the whole build
        timeout(time: 2, unit: 'HOURS')
	skipDefaultCheckout() // Done manually
        timestamps()
    }
    stages {
        stage('Clean cache') {
            when {
                anyOf {
                    expression { return params.FORCE_CLEAN_CACHE }
                }
            }
            agent { label 'git-ssh2' }
            steps {
                script {
                    sh """#!/bin/bash -xe
        	       rm -f /media/share/jenkins_share/zephyrproject_zephyr_alif.tar.gz"""
                }
            }
        }
        stage('Init') {
            agent { label 'git-ssh2' }
            steps {
		script {
		    sh '''#!/bin/bash
		       if [ -z ${CHANGE_BRANCH} ];
                       then
                           export CHANGE_BRANCH=$BRANCH_NAME;
                           echo "checkout branch: ${CHANGE_BRANCH}";
		       else
			   git pull
                       fi
		       if [ ! -d "zephyr" ]; then
		           git clone git@github.com-AlifSemiDev:AlifSemiDev/hal_alif.git --branch ${CHANGE_BRANCH} --single-branch --depth 1 .
		       fi
		       '''
		}
                script {
                    common_funcs = load 'test_samples.groovy'
                }
                script {
		    sh '''#!/bin/bash
		       echo "CALL zephyr_init()"
		    '''
                    common_funcs.zephyr_init();
                }
            }
        }
        stage('Build') {
            stages {
                stage('Build helloworld sample') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            common_funcs.build_zephyr("samples/hello_world", "build-e7-hello-world", "alif_e7_dk_rtss_he");
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-e7-hello-world/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('BLE samples stage 1') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            parallel bleStagesMap1
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-b1-*/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('BLE samples stage 2') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            parallel bleStagesMap2
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-b1-*/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('BLE samples stage 3') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            parallel bleStagesMap3
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-b1-*/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('BLE samples stage 4') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            parallel bleStagesMap4
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-b1-*/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('BLE samples stage 5') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        script {
                            parallel bleStagesMap5
                        }
                    }
                    post {
                        success {
                            archiveArtifacts allowEmptyArchive: true, artifacts: 'zephyrproject/zephyr/build-b1-*/zephyr/**', followSymlinks: false, onlyIfSuccessful: true
                        }
                    }
                }
                stage('Cleanup stage') {
                    agent { label 'git-ssh2' }
                    options { skipDefaultCheckout() }
                    steps {
                        cleanWs()
                    }
                }
            }
        }
    }
}
