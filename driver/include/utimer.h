/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#ifndef UTIMER_H_
#define UTIMER_H_

#define UTIMER_GLB_CNTR_START(global_addr)	(global_addr + 0x00U)
#define UTIMER_GLB_CNTR_STOP(global_addr)	(global_addr + 0x04U)
#define UTIMER_GLB_CNTR_CLEAR(global_addr)	(global_addr + 0x08U)
#define UTIMER_GLB_CNTR_RUNNING(global_addr)	(global_addr + 0x0CU)
#define UTIMER_GLB_DRIVER_OEN(global_addr)	(global_addr + 0x10U)
#define UTIMER_GLB_CLOCK_ENABLE(global_addr)	(global_addr + 0x20U)

#define UTIMER_START_0_SRC(timer_addr)		(timer_addr + 0x0000U)
#define UTIMER_START_1_SRC(timer_addr)		(timer_addr + 0x0004U)
#define UTIMER_STOP_0_SRC(timer_addr)		(timer_addr + 0x0008U)
#define UTIMER_STOP_1_SRC(timer_addr)		(timer_addr + 0x000CU)
#define UTIMER_CLEAR_0_SRC(timer_addr)		(timer_addr + 0x0010U)
#define UTIMER_CLEAR_1_SRC(timer_addr)		(timer_addr + 0x0014U)
#define UTIMER_UP_0_SRC(timer_addr)		(timer_addr + 0x0018U)
#define UTIMER_UP_1_SRC(timer_addr)		(timer_addr + 0x001CU)
#define UTIMER_DOWN_0_SRC(timer_addr)		(timer_addr + 0x0020U)
#define UTIMER_DOWN_1_SRC(timer_addr)		(timer_addr + 0x0024U)
#define UTIMER_TRIG_CAPTURE_SRC_A_0(timer_addr)	(timer_addr + 0x0028U)
#define UTIMER_TRIG_CAPTURE_SRC_A_1(timer_addr)	(timer_addr + 0x002CU)
#define UTIMER_TRIG_CAPTURE_SRC_B_0(timer_addr)	(timer_addr + 0x0030U)
#define UTIMER_TRIG_CAPTURE_SRC_B_1(timer_addr)	(timer_addr + 0x0034U)
#define UTIMER_DMA_CLEAR_SRC_A_0(timer_addr)	(timer_addr + 0x0038U)
#define UTIMER_DMA_CLEAR_SRC_A_1(timer_addr)	(timer_addr + 0x003CU)
#define UTIMER_DMA_CLEAR_SRC_B_0(timer_addr)	(timer_addr + 0x0040U)
#define UTIMER_DMA_CLEAR_SRC_B_1(timer_addr)	(timer_addr + 0x0044U)
#define UTIMER_CNTR_PAUSE_SRC(timer_addr)	(timer_addr + 0x0048U)
#define UTIMER_CNTR_CTRL(timer_addr)		(timer_addr + 0x0080U)
#define UTIMER_FILTER_CTRL_A(timer_addr)	(timer_addr + 0x0084U)
#define UTIMER_FILTER_CTRL_B(timer_addr)	(timer_addr + 0x0088U)
#define UTIMER_COMPARE_CTRL_A(timer_addr)	(timer_addr + 0x008CU)
#define UTIMER_COMPARE_CTRL_B(timer_addr)	(timer_addr + 0x0090U)
#define UTIMER_BUF_OP_CTRL(timer_addr)		(timer_addr + 0x0094U)
#define UTIMER_CNTR(timer_addr)			(timer_addr + 0x00A0U)
#define UTIMER_CNTR_PTR(timer_addr)		(timer_addr + 0x00A4U)
#define UTIMER_CNTR_PTR_BUF1(timer_addr)	(timer_addr + 0x00A8U)
#define UTIMER_CNTR_PTR_BUF2(timer_addr)	(timer_addr + 0x00ACU)
#define UTIMER_CAPTURE_A(timer_addr)		(timer_addr + 0x00B0U)
#define UTIMER_CAPTURE_A_BUF1(timer_addr)	(timer_addr + 0x00B4U)
#define UTIMER_CAPTURE_A_BUF2(timer_addr)	(timer_addr + 0x00B8U)
#define UTIMER_CAPTURE_B(timer_addr)		(timer_addr + 0x00C0U)
#define UTIMER_CAPTURE_B_BUF1(timer_addr)	(timer_addr + 0x00C4U)
#define UTIMER_CAPTURE_B_BUF2(timer_addr)	(timer_addr + 0x00C8U)
#define UTIMER_COMPARE_A(timer_addr)		(timer_addr + 0x00D0U)
#define UTIMER_COMPARE_A_BUF1(timer_addr)	(timer_addr + 0x00D4U)
#define UTIMER_COMPARE_A_BUF2(timer_addr)	(timer_addr + 0x00D8U)
#define UTIMER_COMPARE_B(timer_addr)		(timer_addr + 0x00E0U)
#define UTIMER_COMPARE_B_BUF1(timer_addr)	(timer_addr + 0x00E4U)
#define UTIMER_COMPARE_B_BUF2(timer_addr)	(timer_addr + 0x00E8U)
#define UTIMER_DT_UP(timer_addr)		(timer_addr + 0x00F0U)
#define UTIMER_DT_UP_BUF1(timer_addr)		(timer_addr + 0x00F4U)
#define UTIMER_DT_DOWN(timer_addr)		(timer_addr + 0x00F8U)
#define UTIMER_DT_DOWN_BUF1(timer_addr)		(timer_addr + 0x00FCU)
#define UTIMER_CHAN_STATUS(timer_addr)		(timer_addr + 0x0114U)
#define UTIMER_CHAN_INTERRUPT(timer_addr)	(timer_addr + 0x0118U)
#define UTIMER_CHAN_INTERRUPT_MASK(timer_addr)	(timer_addr + 0x011CU)
#define UTIMER_DUTY_CYCLE_CTRL(timer_addr)	(timer_addr + 0x0120U)
#define UTIMER_DEAD_TIME_CTRL(timer_addr)	(timer_addr + 0x0124U)
#define UTIMER_INT_CNTR_CTRL(timer_addr)	(timer_addr + 0x0130U)
#define UTIMER_FAULT_CTRL(timer_addr)		(timer_addr + 0x0134U)


/* Bit definition for TIMER_RegInfo:cntr_start_src_1 register */
#define CNTR_SRC1_PGM_EN_BIT			31U
#define CNTR_SRC1_PGM_EN			(BIT(CNTR_SRC1_PGM_EN_BIT))

/* Bit definition for TIMER_RegInfo:cntr_ctrl register */
#define CNTR_CTRL_EN_BIT			0U
#define CNTR_CTRL_EN				(BIT(CNTR_CTRL_EN_BIT))
#define CNTR_CTRL_START_BIT			1U
#define CNTR_CTRL_START				(BIT(CNTR_CTRL_START_BIT))
#define CNTR_CTRL_SAWTOOTH_ONE_SHOT_BIT		2U
#define CNTR_CTRL_SAWTOOTH_ONE_SHOT		\
				(BIT(CNTR_CTRL_SAWTOOTH_ONE_SHOT_BIT))
#define CNTR_CTRL_TRIANGLE_BUF_TROUGH_BIT	4U
#define CNTR_CTRL_TRIANGLE_BUF_TROUGH		\
				(BIT(CNTR_CTRL_TRIANGLE_BUF_TROUGH_BIT))
#define CNTR_CTRL_TRIANGLE_BUF_TROUGH_CREST	(BIT(2) | BIT(4))
#define CNTR_CTRL_TRIANGLE_ONE_SHOT		(BIT(3) | BIT(4))
#define CNTR_CTRL_DIR_DOWN_BIT			8U
#define CNTR_CTRL_DIR_DOWN			(BIT(CNTR_CTRL_DIR_DOWN_BIT))

/* Bit definition for TIMER_RegInfo:compare_ctrl register */
#define COMPARE_CTRL_DRV_RETAIN_VAL_AT_COMP_MATCH	(~BIT(0))
#define COMPARE_CTRL_DRV_LOW_AT_COMP_MATCH		(BIT(0))
#define COMPARE_CTRL_DRV_HIGH_AT_COMP_MATCH		(BIT(1))
#define COMPARE_CTRL_DRV_TOGGLE_AT_COMP_MATCH		(BIT(0) | BIT(1))
#define COMPARE_CTRL_DRV_COMP_MATCH_Msk			(BIT(0) | BIT(1))
#define COMPARE_CTRL_DRV_RETAIN_VAL_AT_CYCLE_END	(~BIT(2))
#define COMPARE_CTRL_DRV_LOW_AT_CYCLE_END		(BIT(2))
#define COMPARE_CTRL_DRV_HIGH_AT_CYCLE_END		(BIT(3))
#define COMPARE_CTRL_DRV_TOGGLE_AT_CYCLE_END		(BIT(2) | BIT(3))
#define COMPARE_CTRL_DRV_CYCLE_END_Msk			(BIT(2) | BIT(3))
#define COMPARE_CTRL_DRV_START_VAL_HIGH_BIT		4U
#define COMPARE_CTRL_DRV_START_VAL_HIGH			 \
				(BIT(COMPARE_CTRL_DRV_START_VAL_HIGH_BIT))
#define COMPARE_CTRL_DRV_STOP_VAL_HIGH_BIT		6U
#define COMPARE_CTRL_DRV_STOP_VAL_HIGH			\
				(BIT(COMPARE_CTRL_DRV_STOP_VAL_HIGH_BIT))
#define COMPARE_CTRL_DRV_START_STOP_LEVEL_BIT		7U
#define COMPARE_CTRL_DRV_START_STOP_LEVEL		\
				(BIT(COMPARE_CTRL_DRV_START_STOP_LEVEL_BIT))
#define COMPARE_CTRL_DRV_DRIVER_EN_BIT			8U
#define COMPARE_CTRL_DRV_DRIVER_EN			\
				(BIT(COMPARE_CTRL_DRV_DRIVER_EN_BIT))
#define COMPARE_CTRL_DRV_DISABLE_VAL_HIGH_BIT		9U
#define COMPARE_CTRL_DRV_DISABLE_VAL_HIGH		\
				(BIT(COMPARE_CTRL_DRV_DISABLE_VAL_HIGH_BIT))
#define COMPARE_CTRL_DRV_COMPARE_EN_BIT			11U
#define COMPARE_CTRL_DRV_COMPARE_EN			\
				(BIT(COMPARE_CTRL_DRV_COMPARE_EN_BIT))
#define COMPARE_CTRL_DRV_COMPARE_TRIG_EN_BIT		12U
#define COMPARE_CTRL_DRV_COMPARE_TRIG_EN		\
				(BIT(COMPARE_CTRL_DRV_COMPARE_TRIG_EN_BIT))
#define COMPARE_CTRL_DRV_DMA_CLEAR_EN_BIT		13U
#define COMPARE_CTRL_DRV_DMA_CLEAR_EN			\
				(BIT(COMPARE_CTRL_DRV_DMA_CLEAR_EN_BIT))

/* Bit definition for TIMER_RegInfo:glb_cntr_start register */
#define GLB_CNTR_START				((uint32_t)0x0000FFFF)

/* Bit definition for TIMER_RegInfo:glb_cntr_stop register */
#define GLB_CNTR_STOP				((uint32_t)0x0000FFFF)

/* Bit definition for TIMER_RegInfo:glb_cntr_clear register */
#define GLB_CNTR_CLEAR				((uint32_t)0x000007FF)

/* Bit definition for TIMER_RegInfo:glb_cntr_running register */
#define GLB_CNTR_RUNNING			((uint32_t)0x0000FFFF)

/* Bit definition for TIMER_RegInfo:glb_driver_oen register */
#define GLB_DRIVER_CHAN_A_OEN_BIT		0U
#define GLB_DRIVER_CHAN_A_OEN			(BIT(GLB_DRIVER_CHAN_A_OEN_BIT))
#define GLB_DRIVER_CHAN_B_OEN_BIT		1U
#define GLB_DRIVER_CHAN_B_OEN			(BIT(GLB_DRIVER_CHAN_B_OEN_BIT))
#define GLB_DRIVER_CHAN_OEN			(BIT(0) | BIT(1))

/* Bit definition for TIMER_RegInfo:glb_clk_en register */
#define GLB_CLK_EN				((uint32_t)0x0000FFFF)

#endif /* UTIMER_H_ */
