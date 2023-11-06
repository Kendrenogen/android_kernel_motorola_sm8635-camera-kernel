/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2019, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 */
#ifndef _CAM_OIS_CORE_H_
#define _CAM_OIS_CORE_H_

#include <linux/cma.h>
#include "cam_ois_dev.h"

#define OIS_NAME_LEN 32
#define OIS_ENDIANNESS_MASK_FW              0x0F
#define OIS_ENDIANNESS_MASK_INPUTPARAM      0xF0

#ifdef CONFIG_MOT_OIS_EARLY_UPGRADE_FW
#define QCOM_OIS_FW_DL_FLAG                    1
#define MOT_OIS_FW_DL_FLAG                     2
#define MOT_OIS_FW_DL_EARLY_FLAG               3
#endif

#ifdef CONFIG_MOT_OIS_EARLY_UPGRADE_FW
#define MOT_CAM_OIS_PACKET_OPCODE_OIS_FW_UPGRADE    20     /* keep same with HAL opcode MotCSLPacketOpcodesOisFwUpgrade */
#endif
#ifdef CONFIG_MOT_OIS_AF_DRIFT
#define MOT_CAM_OIS_PACKET_OPCODE_AF_DRIFT          21     /* keep same with HAL opcode MotCSLPacketOpcodesOisAfDrift */
#endif

/**
 * @power_info: power setting info to control the power
 *
 * This API construct the default ois power setting.
 *
 * @return Status of operation. Negative in case of error. Zero otherwise.
 */
int32_t cam_ois_construct_default_power_setting(
	struct cam_sensor_power_ctrl_t *power_info);


int cam_ois_driver_cmd(struct cam_ois_ctrl_t *e_ctrl, void *arg);

/**
 * @o_ctrl: OIS ctrl structure
 *
 * This API handles the shutdown ioctl/close
 */
void cam_ois_shutdown(struct cam_ois_ctrl_t *o_ctrl);

struct completion *cam_ois_get_i3c_completion(uint32_t index);

#endif
/* _CAM_OIS_CORE_H_ */
