/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) uTango Project and Contributors. All rights reserved.
 */
#ifndef __PLATFORM_REGS_H__
#define __PLATFORM_REGS_H__

#include <utango.h>

/* ==== System Control Region (SCReg) ======================================= */
#define SCReg_BASE_S                            (0x50020000UL)
#define SCReg_BASE_NS                           (0x40020000UL)

/* ==== System Control Register block (SCR_S) =============================== */
#define SCR_BASE_S                              (SCReg_BASE_S  + 0x1000UL)
#define SCR_S                                   ((SCR_type*)SCR_BASE_S)

/* struct type to access SCR */
typedef struct
{
    volatile uint32_t SECDBGSTAT;
    volatile uint32_t SECDBGSET;
    volatile uint32_t SECDBGCLR;
    volatile uint32_t SCSECCTRL;
    volatile uint32_t FCLK_DIV;
    volatile uint32_t SYSCLK_DIV;
    volatile uint32_t CLOCKFORCE;
    volatile uint32_t RESERVED0[57];
    volatile uint32_t RESETSYNDROME;
    volatile uint32_t RESETMASK;
    volatile uint32_t SWRESET;
    volatile uint32_t GRETREG;
    volatile uint32_t INITSVTOR0;
    volatile uint32_t INITSVTOR1;
    volatile uint32_t CPUWAIT;
    volatile uint32_t RESERVED1;
    volatile uint32_t WICCTRL;
    volatile uint32_t EWCTRL;
    volatile uint32_t RESERVED2[54];
    volatile uint32_t PDCM_PD_SYS_SENSE;
    volatile uint32_t PDCM_PD_CPU0CORE_SENSE;
    volatile uint32_t PDCM_PD_CPU1CORE_SENSE;
    volatile uint32_t PDCM_PD_SRAM0_SENSE;
    volatile uint32_t PDCM_PD_SRAM1_SENSE;
    volatile uint32_t PDCM_PD_SRAM2_SENSE;
    volatile uint32_t PDCM_PD_SRAM3_SENSE;
    volatile uint32_t RESERVED3[5];
    volatile uint32_t PDCM_PD_CC_SENSE;
    volatile uint32_t PDCM_PD0_OUT_SENSE;
    volatile uint32_t PDCM_PD1_OUT_SENSE;
    volatile uint32_t PDCM_PD2_OUT_SENSE;
    volatile uint32_t PDCM_PD3_OUT_SENSE;
    volatile uint32_t RESERVED4[864];
    volatile uint32_t PIDR4;
    volatile uint32_t RESERVED5[3];
    volatile uint32_t PIDR0;
    volatile uint32_t PIDR1;
    volatile uint32_t PIDR2;
    volatile uint32_t PIDR3;
    volatile uint32_t CIDR0;
    volatile uint32_t CIDR1;
    volatile uint32_t CIDR2;
    volatile uint32_t CIDR3;
} SCR_type;

/* RESET_MASK register flags */
#define SCR_RESETMASK_SYSRSTREQ0_EN             (1U << 4U)

/* SECDBGSET register flags */
#define SCR_SECDBGSET_SPNIDEN_SEL_SET           (1U << 7U)
#define SCR_SECDBGSET_SPNIDEN_I_SET             (1U << 6U)
#define SCR_SECDBGSET_SPIDEN_SEL_SET            (1U << 5U)
#define SCR_SECDBGSET_SPIDEN_I_SET              (1U << 4U)
#define SCR_SECDBGSET_NIDEN_SEL_SET             (1U << 3U)
#define SCR_SECDBGSET_NIDEN_I_SET               (1U << 2U)
#define SCR_SECDBGSET_DBGEN_SEL_SET             (1U << 1U)
#define SCR_SECDBGSET_DBGEN_I_SET               (1U << 0U)

/* ==== Memory Protection Controlers (MPC) ================================== */
#define MPC_ISRAMS_BASE                         (0x50083000UL)

#define MPC_ISRAM0_BASE                         (MPC_ISRAMS_BASE + 0x0000UL)
#define MPC_ISRAM0                              ((MPC_type*)MPC_ISRAM0_BASE)
#define MPC_ISRAM1_BASE                         (MPC_ISRAMS_BASE + 0x1000UL)
#define MPC_ISRAM1                              ((MPC_type*)MPC_ISRAM1_BASE)
#define MPC_ISRAM2_BASE                         (MPC_ISRAMS_BASE + 0x2000UL)
#define MPC_ISRAM2                              ((MPC_type*)MPC_ISRAM2_BASE)
#define MPC_ISRAM3_BASE                         (MPC_ISRAMS_BASE + 0x3000UL)
#define MPC_ISRAM3                              ((MPC_type*)MPC_ISRAM3_BASE)

#define MPC_QSPI_BASE                           (0x50120000UL)
#define MPC_QSPI                                ((MPC_type*)MPC_QSPI_BASE)
#define MPC_CODE_SRAMS_BASE                     (0x50130000UL)
#define MPC_CODE_SRAMS                          ((MPC_type*)MPC_CODE_SRAMS_BASE)

/* MPCs range list */
#define MPC_ISRAM0_BASE_NS                      (0x20000000UL)
#define MPC_ISRAM0_TOP_NS                       (0x20007FFFUL)
#define MPC_ISRAM0_BASE_S                       (0x30000000UL)
#define MPC_ISRAM0_TOP_S                        (0x30007FFFUL)

#define MPC_ISRAM1_BASE_NS                      (0x20008000UL)
#define MPC_ISRAM1_TOP_NS                       (0x2000FFFFUL)
#define MPC_ISRAM1_BASE_S                       (0x30008000UL)
#define MPC_ISRAM1_TOP_S                        (0x3000FFFFUL)

#define MPC_ISRAM2_BASE_NS                      (0x20010000UL)
#define MPC_ISRAM2_TOP_NS                       (0x20017FFFUL)
#define MPC_ISRAM2_BASE_S                       (0x30010000UL)
#define MPC_ISRAM2_TOP_S                        (0x30017FFFUL)

#define MPC_ISRAM3_BASE_NS                      (0x20018000UL)
#define MPC_ISRAM3_TOP_NS                       (0x2001FFFFUL)
#define MPC_ISRAM3_BASE_S                       (0x30018000UL)
#define MPC_ISRAM3_TOP_S                        (0x3001FFFFUL)

#define MPC_CODE_SRAM_BASE_NS                   (0x00000000UL)
#define MPC_CODE_SRAM_TOP_NS                    (0x00200000UL)
#define MPC_CODE_SRAM_BASE_S                    (0x10000000UL)
#define MPC_CODE_SRAM_TOP_S                     (0x10200000UL)

#define MPC_QSPI_BASE_NS                        (0x00200000UL)
#define MPC_QSPI_TOP_NS                         (0x00240000UL)
#define MPC_QSPI_BASE_S                         (0x10200000UL)
#define MPC_QSPI_TOP_S                          (0x10240000UL)

/* struct type to access MPCs */
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t RESERVED[3];
    volatile uint32_t BLK_MAX;
    volatile uint32_t BLK_CFG;
    volatile uint32_t BLK_IDX;
    volatile uint32_t BLK_LUTN;
    volatile uint32_t INT_STAT;
    volatile uint32_t INT_CLEAR;
    volatile uint32_t INT_EN;
    volatile uint32_t INT_INFO1;
    volatile uint32_t INT_INFO2;
    volatile uint32_t INT_SET;
    volatile uint32_t RESERVED2[997];
    volatile uint32_t PIDR4;
    volatile uint32_t PIDR5;
    volatile uint32_t PIDR6;
    volatile uint32_t PIDR7;
    volatile uint32_t PIDR0;
    volatile uint32_t PIDR1;
    volatile uint32_t PIDR2;
    volatile uint32_t PIDR3;
    volatile uint32_t CIDR0;
    volatile uint32_t CIDR1;
    volatile uint32_t CIDR2;
    volatile uint32_t CIDR3;
} MPC_type;

/* ==== Security Privilege Control Block (SPCB) ============================= */
#define SPCB_BASE                               (0x50080000UL)
#define SPCB                                    ((SPCB_type*)SPCB_BASE)

/* struct type to access SPCB */
typedef struct
{
    volatile uint32_t SPCSECCTRL;
    volatile uint32_t BUSWAIT;
    volatile uint32_t RESERVED[2];
    volatile uint32_t SECRESPCFG;
    volatile uint32_t NSCCFG;
    volatile uint32_t RESERVED2;
    volatile uint32_t SECMPCINTSTAT;
    volatile uint32_t SECPPCINTSTAT;
    volatile uint32_t SECPPCINTCLR;
    volatile uint32_t SECPPCINTEN;
    volatile uint32_t RESERVED3;
    volatile uint32_t SECMSCINTSTAT;
    volatile uint32_t SECMSCINTCLR;
    volatile uint32_t SECMSCINTEN;
    volatile uint32_t RESERVED4;
    volatile uint32_t BRGINTSTAT;
    volatile uint32_t BRGINTCLR;
    volatile uint32_t BRGINTEN;
    volatile uint32_t RESERVED5;
    volatile uint32_t AHBNSPPC0;
    volatile uint32_t RESERVED6[3];
    volatile uint32_t AHBNSPPCEXP0;
    volatile uint32_t AHBNSPPCEXP1;
    volatile uint32_t AHBNSPPCEXP2;
    volatile uint32_t AHBNSPPCEXP3;
    volatile uint32_t APBNSPPC0;
    volatile uint32_t APBNSPPC1;
    volatile uint32_t RESERVED7[2];
    volatile uint32_t APBNSPPCEXP0;
    volatile uint32_t APBNSPPCEXP1;
    volatile uint32_t APBNSPPCEXP2;
    volatile uint32_t APBNSPPCEXP3;
    volatile uint32_t AHBSPPPC0;
    volatile uint32_t RESERVED8[3];
    volatile uint32_t AHBSPPPCEXP0;
    volatile uint32_t AHBSPPPCEXP1;
    volatile uint32_t AHBSPPPCEXP2;
    volatile uint32_t AHBSPPPCEXP3;
    volatile uint32_t APBSPPPC0;
    volatile uint32_t APBSPPPC1;
    volatile uint32_t RESERVED9[2];
    volatile uint32_t APBSPPPCEXP0;
    volatile uint32_t APBSPPPCEXP1;
    volatile uint32_t APBSPPPCEXP2;
    volatile uint32_t APBSPPPCEXP3;
    volatile uint32_t NSMSCEXP;
    volatile uint32_t RESERVED10[959];
    volatile uint32_t PID4;
    volatile uint32_t PID5;
    volatile uint32_t PID6;
    volatile uint32_t PID7;
    volatile uint32_t PID0;
    volatile uint32_t PID1;
    volatile uint32_t PID2;
    volatile uint32_t PID3;
    volatile uint32_t CID0;
    volatile uint32_t CID1;
    volatile uint32_t CID2;
    volatile uint32_t CID3;
} SPCB_type;

/* SPCB SECPPCINTx masks of each PPC */
#define SPCB_SECPPCINTx_APB_PPC0                (1UL << 0)
#define SPCB_SECPPCINTx_APB_PPC1                (1UL << 1)

#define SPCB_SECPPCINTx_APB_PPCEXP0             (1UL << 4)
#define SPCB_SECPPCINTx_APB_PPCEXP1             (1UL << 5)
#define SPCB_SECPPCINTx_APB_PPCEXP2             (1UL << 6)
#define SPCB_SECPPCINTx_APB_PPCEXP3             (1UL << 7)

#define SPCB_SECPPCINTx_AHB_PPCEXP0             (1UL << 20)
#define SPCB_SECPPCINTx_AHB_PPCEXP1             (1UL << 21)
#define SPCB_SECPPCINTx_AHB_PPCEXP2             (1UL << 22)
#define SPCB_SECPPCINTx_AHB_PPCEXP3             (1UL << 23)

/* ==== Non-Secure Privilege Control Block (NSPCB) ========================== */
#define NSPCB_BASE                              (0x40080000UL)
#define NSPCB                                   ((NSPCB_type*)NSPCB_BASE)

/* struct type to access NSPCB */
typedef struct
{
    volatile uint32_t RESERVED[36];
    volatile uint32_t AHBNSPPPC0;
    volatile uint32_t RESERVED3[3];
    volatile uint32_t AHBNSPPPCEXP0;
    volatile uint32_t AHBNSPPPCEXP1;
    volatile uint32_t AHBNSPPPCEXP2;
    volatile uint32_t AHBNSPPPCEXP3;
    volatile uint32_t APBNSPPPC0;
    volatile uint32_t APBNSPPPC1;
    volatile uint32_t RESERVED4[2];
    volatile uint32_t APBNSPPPCEXP0;
    volatile uint32_t APBNSPPPCEXP1;
    volatile uint32_t APBNSPPPCEXP2;
    volatile uint32_t APBNSPPPCEXP3;
    volatile uint32_t RESERVED5[960];
    volatile uint32_t PIDR4;
    volatile uint32_t RESERVED7;
    volatile uint32_t RESERVED8;
    volatile uint32_t RESERVED9;
    volatile uint32_t PIDR0;
    volatile uint32_t PIDR1;
    volatile uint32_t PIDR2;
    volatile uint32_t PIDR3;
    volatile uint32_t CIDR0;
    volatile uint32_t CIDR1;
    volatile uint32_t CIDR2;
    volatile uint32_t CIDR3;
} NSPCB_type;

/* ==== SPCB + NSPCB Bits Definition ======================================== */

/* AHB PPC0 peripherals definition */

/* APB PPC0 peripherals definition */
#define APB_PPC0_TIMER0                         0U
#define APB_PPC0_TIMER1                         1U
#define APB_PPC0_DTIMER                         2U
#define APB_PPC0_MHU0                           3U
#define APB_PPC0_MHU1                           4U

/* APB PPC1 peripherals definition */
#define APB_PPC1_S32K_TIMER                     0U

/* AHB PPCEXP0 peripherals definition */
#define AHB_PPCEXP0_PERIPHS                     0U

/* AHB PPCEXP1 peripherals definition */

/* AHB PPCEXP2 peripherals definition */

/* AHB PPCEXP3 peripherals definition */

/* APB PPCEXP0 peripherals definition */

/* APB PPCEXP1 peripherals definition */

/* ==== Serial Configuration Control (SCC) ================================== */
#define SCC_BASE                                (0x4010C000UL)
#define SCC                                     ((SCC_Type*)SCC_BASE)

/* struct type to access NSPCB */
typedef struct
{
    __RW uint32_t RESET_CTRL;
    __RW uint32_t CLK_CTRL;
    __RW uint32_t PWR_CTRL;
    __RW uint32_t PLL_CTRL;
    __RW uint32_t DBG_CTRL;
    __RW uint32_t SRAM_CTRL;
    __RW uint32_t INTR_CTRL;
    __RW uint32_t RESERVED1;
    __RW uint32_t CPU0_VTOR_SRAM;
    __RW uint32_t CPU0_VTOR_FLASH;
    __RW uint32_t CPU1_VTOR_SRAM;
    __RW uint32_t CPU1_VTOR_FLASH;
    __RW uint32_t IOMUX_MAIN_INSEL;
    __RW uint32_t IOMUX_MAIN_OUTSEL;
    __RW uint32_t IOMUX_MAIN_OENSEL;
    __RW uint32_t IOMUX_MAIN_DEFAULT_IN;
    __RW uint32_t IOMUX_ALTF1_INSEL;
    __RW uint32_t IOMUX_ALTF1_OUTSEL;
    __RW uint32_t IOMUX_ALTF1_OENSEL;
    __RW uint32_t IOMUX_ALTF1_DEFAULT_IN;
    __RW uint32_t IOMUX_ALTF2_INSEL;
    __RW uint32_t IOMUX_ALTF2_OUTSEL;
    __RW uint32_t IOMUX_ALTF2_OENSEL;
    __RW uint32_t IOMUX_ALTF2_DEFAULT_IN;
    __RW uint32_t PVT_CTRL;
    __RW uint32_t SPARE0;
    __RW uint32_t IOPAD_DS0;
    __RW uint32_t IOPAD_DS1;
    __RW uint32_t IOPAD_PE;
    __RW uint32_t IOPAD_PS;
    __RW uint32_t IOPAD_SR;
    __RW uint32_t IOPAD_IS;
    __RW uint32_t SRAM_RW_MARGINE;
    __RW uint32_t STATIC_CONF_SIG0;
    __RW uint32_t STATIC_CONF_SIG1;
    __RW uint32_t REQ_SET;
    __RW uint32_t REQ_CLEAR;
    __RW uint32_t IOMUX_ALTF3_INSEL;
    __RW uint32_t IOMUX_ALTF3_OUTSEL;
    __RW uint32_t IOMUX_ALTF3_OENSEL;
    __RW uint32_t IOMUX_ALTF3_DEFAULT_IN;
    __RW uint32_t PCSM_CTRL_OVERRIDE;
    __RW uint32_t PD_CPU0_ISO_OVERRIDE;
    __RW uint32_t PD_CPU1_ISO_OVERRIDE;
    __RW uint32_t SYS_SRAM_RW_ASSIST0;
    __RW uint32_t SYS_SRAM_RW_ASSIST1;
    __RW uint32_t SYS_SRAM_RW_ASSIST2;
    __RW uint32_t SYS_SRAM_RW_ASSIST3;
    __RW uint32_t SYS_SRAM_RW_ASSIST4;
    __RW uint32_t SYS_SRAM_RW_ASSIST5;
    __RW uint32_t RESERVED2[3];
    __RW uint32_t CRYPTO_SRAM_RW_ASSIST0;
    __RW uint32_t CRYPTO_SRAM_RW_ASSIST1;
    __RW uint32_t CRYPTO_SRAM_RW_ASSIST2;
    __RW uint32_t REQ_EDGE_SEL;
    __RW uint32_t REQ_ENABLE;
    __RW uint32_t RESERVED3[28];
    __RW uint32_t CHIP_ID;
    __RW uint32_t CLOCK_STATUS;
    __RW uint32_t IO_IN_STATUS;
} SCC_Type;

/* ==== Peripherals Addresses =============================================== */
#define CMSDK_TIMER0_BASE_NS                                (0x40000000UL)
#define CMSDK_TIMER1_BASE_NS                                (0x40001000UL)
#define CMSDK_DUALTIMER_BASE_NS                             (0x40002000UL)
#define MHU0_BASE_NS                                        (0x40003000UL)
#define MHU1_BASE_NS                                        (0x40004000UL)
#define CMSDK_32KTIMER_BASE_NS                              (0x4002F000UL)
#define PWM0_BASE_NS                                        (0x40107000UL)
#define PWM1_BASE_NS                                        (0x4010E000UL)
#define PWM2_BASE_NS                                        (0x4010F000UL)
#define I2S_BASE_NS                                         (0x40106000UL)
#define UART0_BASE_NS                                       (0x40101000UL)
#define UART1_BASE_NS                                       (0x40102000UL)
#define I2C0_BASE_NS                                        (0x40104000UL)
#define I2C1_BASE_NS                                        (0x40105000UL)
#define SPI_BASE_NS                                         (0x40103000UL)
#define GPTIMER_BASE_NS                                     (0x4010B000UL)
#define RTCLOCK_BASE_NS                                     (0x40108000UL)

#endif /* __PLATFORM_REGS_H__ */
