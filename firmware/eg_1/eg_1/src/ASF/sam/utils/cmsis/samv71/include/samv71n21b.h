/**
 * \file
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _SAMV71N21B_
#define _SAMV71N21B_

/** \addtogroup SAMV71N21B_definitions SAMV71N21B definitions
  This file defines all structures and symbols for SAMV71N21B:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/
/*@{*/

#ifdef __cplusplus
 extern "C" {
#endif 

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#include <stdint.h>
#endif

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_cmsis CMSIS Definitions */
/*@{*/

/**< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M7 Processor Exceptions Numbers ******************************/
  NonMaskableInt_IRQn   = -14, /**<  2 Non Maskable Interrupt                */
  HardFault_IRQn        = -13, /**<  3 HardFault Interrupt                   */
  MemoryManagement_IRQn = -12, /**<  4 Cortex-M7 Memory Management Interrupt */
  BusFault_IRQn         = -11, /**<  5 Cortex-M7 Bus Fault Interrupt         */
  UsageFault_IRQn       = -10, /**<  6 Cortex-M7 Usage Fault Interrupt       */
  SVCall_IRQn           = -5,  /**< 11 Cortex-M7 SV Call Interrupt           */
  DebugMonitor_IRQn     = -4,  /**< 12 Cortex-M7 Debug Monitor Interrupt     */
  PendSV_IRQn           = -2,  /**< 14 Cortex-M7 Pend SV Interrupt           */
  SysTick_IRQn          = -1,  /**< 15 Cortex-M7 System Tick Interrupt       */
/******  SAMV71N21B specific Interrupt Numbers *********************************/
  
  SUPC_IRQn            =  0, /**<  0 SAMV71N21B Supply Controller (SUPC) */
  RSTC_IRQn            =  1, /**<  1 SAMV71N21B Reset Controller (RSTC) */
  RTC_IRQn             =  2, /**<  2 SAMV71N21B Real Time Clock (RTC) */
  RTT_IRQn             =  3, /**<  3 SAMV71N21B Real Time Timer (RTT) */
  WDT_IRQn             =  4, /**<  4 SAMV71N21B Watchdog Timer (WDT) */
  PMC_IRQn             =  5, /**<  5 SAMV71N21B Power Management Controller (PMC) */
  EFC_IRQn             =  6, /**<  6 SAMV71N21B Enhanced Embedded Flash Controller (EFC) */
  UART0_IRQn           =  7, /**<  7 SAMV71N21B UART 0 (UART0) */
  UART1_IRQn           =  8, /**<  8 SAMV71N21B UART 1 (UART1) */
  PIOA_IRQn            = 10, /**< 10 SAMV71N21B Parallel I/O Controller A (PIOA) */
  PIOB_IRQn            = 11, /**< 11 SAMV71N21B Parallel I/O Controller B (PIOB) */
  USART0_IRQn          = 13, /**< 13 SAMV71N21B USART 0 (USART0) */
  USART1_IRQn          = 14, /**< 14 SAMV71N21B USART 1 (USART1) */
  USART2_IRQn          = 15, /**< 15 SAMV71N21B USART 2 (USART2) */
  PIOD_IRQn            = 16, /**< 16 SAMV71N21B Parallel I/O Controller D (PIOD) */
  HSMCI_IRQn           = 18, /**< 18 SAMV71N21B Multimedia Card Interface (HSMCI) */
  TWIHS0_IRQn          = 19, /**< 19 SAMV71N21B Two Wire Interface 0 HS (TWIHS0) */
  TWIHS1_IRQn          = 20, /**< 20 SAMV71N21B Two Wire Interface 1 HS (TWIHS1) */
  SPI0_IRQn            = 21, /**< 21 SAMV71N21B Serial Peripheral Interface 0 (SPI0) */
  SSC_IRQn             = 22, /**< 22 SAMV71N21B Synchronous Serial Controller (SSC) */
  TC0_IRQn             = 23, /**< 23 SAMV71N21B Timer/Counter 0 (TC0) */
  TC1_IRQn             = 24, /**< 24 SAMV71N21B Timer/Counter 1 (TC1) */
  TC2_IRQn             = 25, /**< 25 SAMV71N21B Timer/Counter 2 (TC2) */
  AFEC0_IRQn           = 29, /**< 29 SAMV71N21B Analog Front End 0 (AFEC0) */
  DACC_IRQn            = 30, /**< 30 SAMV71N21B Digital To Analog Converter (DACC) */
  PWM0_IRQn            = 31, /**< 31 SAMV71N21B Pulse Width Modulation 0 (PWM0) */
  ICM_IRQn             = 32, /**< 32 SAMV71N21B Integrity Check Monitor (ICM) */
  ACC_IRQn             = 33, /**< 33 SAMV71N21B Analog Comparator (ACC) */
  USBHS_IRQn           = 34, /**< 34 SAMV71N21B USB Host / Device Controller (USBHS) */
  MCAN0_INT0_IRQn      = 35, /**< 35 SAMV71N21B Controller Area Network (MCAN0) */
  MCAN0_INT1_IRQn      = 36, /**< 36 SAMV71N21B Controller Area Network (MCAN0) */
  MCAN1_INT0_IRQn      = 37, /**< 37 SAMV71N21B Controller Area Network (MCAN1) */
  MCAN1_INT1_IRQn      = 38, /**< 38 SAMV71N21B Controller Area Network (MCAN1) */
  GMAC_IRQn            = 39, /**< 39 SAMV71N21B Ethernet MAC (GMAC) */
  AFEC1_IRQn           = 40, /**< 40 SAMV71N21B Analog Front End 1 (AFEC1) */
  TWIHS2_IRQn          = 41, /**< 41 SAMV71N21B Two Wire Interface 2 HS (TWIHS2) */
  QSPI_IRQn            = 43, /**< 43 SAMV71N21B Quad I/O Serial Peripheral Interface (QSPI) */
  UART2_IRQn           = 44, /**< 44 SAMV71N21B UART 2 (UART2) */
  UART3_IRQn           = 45, /**< 45 SAMV71N21B UART 3 (UART3) */
  UART4_IRQn           = 46, /**< 46 SAMV71N21B UART 4 (UART4) */
  TC9_IRQn             = 50, /**< 50 SAMV71N21B Timer/Counter 9 (TC9) */
  TC10_IRQn            = 51, /**< 51 SAMV71N21B Timer/Counter 10 (TC10) */
  TC11_IRQn            = 52, /**< 52 SAMV71N21B Timer/Counter 11 (TC11) */
  MLB_IRQn             = 53, /**< 53 SAMV71N21B MediaLB (MLB) */
  AES_IRQn             = 56, /**< 56 SAMV71N21B AES (AES) */
  TRNG_IRQn            = 57, /**< 57 SAMV71N21B True Random Generator (TRNG) */
  XDMAC_IRQn           = 58, /**< 58 SAMV71N21B DMA (XDMAC) */
  ISI_IRQn             = 59, /**< 59 SAMV71N21B Camera Interface (ISI) */
  PWM1_IRQn            = 60, /**< 60 SAMV71N21B Pulse Width Modulation 1 (PWM1) */
  FPU_IRQn             = 61, /**< 61 SAMV71N21B Floating Point Unit Registers (FPU) */
  RSWDT_IRQn           = 63, /**< 63 SAMV71N21B Reinforced Safety Watchdog Timer (RSWDT) */
  CCW_IRQn             = 64, /**< 64 SAMV71N21B System Control Registers (SystemControl) */
  CCF_IRQn             = 65, /**< 65 SAMV71N21B System Control Registers (SystemControl) */
  GMAC_Q1_IRQn         = 66, /**< 66 SAMV71N21B Gigabit Ethernet MAC (GMAC) */
  GMAC_Q2_IRQn         = 67, /**< 67 SAMV71N21B Gigabit Ethernet MAC (GMAC) */
  IXC_IRQn             = 68, /**< 68 SAMV71N21B Floating Point Unit Registers (FPU) */
  I2SC0_IRQn           = 69, /**< 69 SAMV71N21B Inter-IC Sound Controller (I2SC0) */
  GMAC_Q3_IRQn         = 71, /**< 71 SAMV71N21B Gigabit Ethernet MAC (GMAC) */
  GMAC_Q4_IRQn         = 72, /**< 72 SAMV71N21B Gigabit Ethernet MAC (GMAC) */
  GMAC_Q5_IRQn         = 73, /**< 73 SAMV71N21B Gigabit Ethernet MAC (GMAC) */

  PERIPH_COUNT_IRQn    = 74  /**< Number of peripheral IDs */
} IRQn_Type;

typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  
  /* Cortex-M handlers */
  void* pfnReset_Handler;
  void* pfnNMI_Handler;
  void* pfnHardFault_Handler;
  void* pfnMemManage_Handler;
  void* pfnBusFault_Handler;
  void* pfnUsageFault_Handler;
  void* pfnReserved1_Handler;
  void* pfnReserved2_Handler;
  void* pfnReserved3_Handler;
  void* pfnReserved4_Handler;
  void* pfnSVC_Handler;
  void* pfnDebugMon_Handler;
  void* pfnReserved5_Handler;
  void* pfnPendSV_Handler;
  void* pfnSysTick_Handler;

  /* Peripheral handlers */
  void* pfnSUPC_Handler;   /*  0 Supply Controller */
  void* pfnRSTC_Handler;   /*  1 Reset Controller */
  void* pfnRTC_Handler;    /*  2 Real Time Clock */
  void* pfnRTT_Handler;    /*  3 Real Time Timer */
  void* pfnWDT_Handler;    /*  4 Watchdog Timer */
  void* pfnPMC_Handler;    /*  5 Power Management Controller */
  void* pfnEFC_Handler;    /*  6 Enhanced Embedded Flash Controller */
  void* pfnUART0_Handler;  /*  7 UART 0 */
  void* pfnUART1_Handler;  /*  8 UART 1 */
  void* pvReserved9;
  void* pfnPIOA_Handler;   /* 10 Parallel I/O Controller A */
  void* pfnPIOB_Handler;   /* 11 Parallel I/O Controller B */
  void* pvReserved12;
  void* pfnUSART0_Handler; /* 13 USART 0 */
  void* pfnUSART1_Handler; /* 14 USART 1 */
  void* pfnUSART2_Handler; /* 15 USART 2 */
  void* pfnPIOD_Handler;   /* 16 Parallel I/O Controller D */
  void* pvReserved17;
  void* pfnHSMCI_Handler;  /* 18 Multimedia Card Interface */
  void* pfnTWIHS0_Handler; /* 19 Two Wire Interface 0 HS */
  void* pfnTWIHS1_Handler; /* 20 Two Wire Interface 1 HS */
  void* pfnSPI0_Handler;   /* 21 Serial Peripheral Interface 0 */
  void* pfnSSC_Handler;    /* 22 Synchronous Serial Controller */
  void* pfnTC0_Handler;    /* 23 Timer/Counter 0 */
  void* pfnTC1_Handler;    /* 24 Timer/Counter 1 */
  void* pfnTC2_Handler;    /* 25 Timer/Counter 2 */
  void* pvReserved26;
  void* pvReserved27;
  void* pvReserved28;
  void* pfnAFEC0_Handler;  /* 29 Analog Front End 0 */
  void* pfnDACC_Handler;   /* 30 Digital To Analog Converter */
  void* pfnPWM0_Handler;   /* 31 Pulse Width Modulation 0 */
  void* pfnICM_Handler;    /* 32 Integrity Check Monitor */
  void* pfnACC_Handler;    /* 33 Analog Comparator */
  void* pfnUSBHS_Handler;  /* 34 USB Host / Device Controller */
  void* pfnMCAN0_INT0_Handler;     /* 35  Controller Area Network (MCAN0) */
  void* pfnMCAN0_INT1_Handler;     /* 36  Controller Area Network (MCAN0) */
  void* pfnMCAN1_INT0_Handler;     /* 37  Controller Area Network (MCAN1) */
  void* pfnMCAN1_INT1_Handler;     /* 38  Controller Area Network (MCAN1) */
  void* pfnGMAC_Handler;   /* 39 Ethernet MAC */
  void* pfnAFEC1_Handler;  /* 40 Analog Front End 1 */
  void* pfnTWIHS2_Handler; /* 41 Two Wire Interface 2 HS */
  void* pvReserved42;  
  void* pfnQSPI_Handler;   /* 43 Quad I/O Serial Peripheral Interface */
  void* pfnUART2_Handler;  /* 44 UART 2 */
  void* pfnUART3_Handler;  /* 45 UART 3 */
  void* pfnUART4_Handler;  /* 46 UART 4 */
  void* pvReserved47;
  void* pvReserved48;
  void* pvReserved49;
  void* pfnTC9_Handler;    /* 50 Timer/Counter 9 */
  void* pfnTC10_Handler;   /* 51 Timer/Counter 10 */
  void* pfnTC11_Handler;   /* 52 Timer/Counter 11 */
  void* pfnMLB_Handler;    /* 53 MediaLB */
  void* pvReserved54;
  void* pvReserved55;
  void* pfnAES_Handler;    /* 56 AES */
  void* pfnTRNG_Handler;   /* 57 True Random Generator */
  void* pfnXDMAC_Handler;  /* 58 DMA */
  void* pfnISI_Handler;    /* 59 Camera Interface */
  void* pfnPWM1_Handler;   /* 60 Pulse Width Modulation 1 */
  void* pfnFPU_Handler;    /* 61 Floating Point Unit Registers (FPU) */
  void* pvReserved62;
  void* pfnRSWDT_Handler;  /* 63 Reinforced Safety Watchdog Timer (RSWDT) */
  void* pfnCCW_Handler;    /* 64 System Control Registers (SystemControl) */
  void* pfnCCF_Handler;    /* 65 System Control Registers (SystemControl) */
  void* pfnGMAC_Q1_Handler;/* 66 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q2_Handler;/* 67 Gigabit Ethernet MAC (GMAC) */
  void* pfnIXC_Handler;    /* 68 Floating Point Unit Registers (FPU) */
  void* pfnI2SC0_Handler;  /* 69 Inter-IC Sound Controller (I2SC0) */
  void* pvReserved70;
  void* pfnGMAC_Q3_Handler;/* 71 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q4_Handler;/* 72 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q5_Handler;/* 73 Gigabit Ethernet MAC (GMAC) */
} DeviceVectors;

/* Cortex-M7 core handlers */
void Reset_Handler      ( void );
void NMI_Handler        ( void );
void HardFault_Handler  ( void );
void MemManage_Handler  ( void );
void BusFault_Handler   ( void );
void UsageFault_Handler ( void );
void SVC_Handler        ( void );
void DebugMon_Handler   ( void );
void PendSV_Handler     ( void );
void SysTick_Handler    ( void );

/* Peripherals handlers */
void ACC_Handler        ( void );
void AES_Handler        ( void );
void AFEC0_Handler      ( void );
void AFEC1_Handler      ( void );
void CCF_Handler        ( void );
void CCW_Handler        ( void );
void DACC_Handler       ( void );
void EFC_Handler        ( void );
void FPU_Handler        ( void );
void GMAC_Handler       ( void );
void HSMCI_Handler      ( void );
void ICM_Handler        ( void );
void ISI_Handler        ( void );
void I2SC0_Handler      ( void );
void IXC_Handler        ( void );
void MCAN0_INT0_Handler ( void );
void MCAN0_INT1_Handler ( void );
void MCAN1_INT0_Handler ( void );
void MCAN1_INT1_Handler ( void );
void MLB_Handler        ( void );
void PIOA_Handler       ( void );
void PIOB_Handler       ( void );
void PIOD_Handler       ( void );
void PMC_Handler        ( void );
void PWM0_Handler       ( void );
void PWM1_Handler       ( void );
void GMAC_Q1_Handler    ( void );
void GMAC_Q2_Handler    ( void );
void GMAC_Q3_Handler    ( void );
void GMAC_Q4_Handler    ( void );
void GMAC_Q5_Handler    ( void );
void QSPI_Handler       ( void );
void RSTC_Handler       ( void );
void RSWDT_Handler      ( void );
void RTC_Handler        ( void );
void RTT_Handler        ( void );
void SPI0_Handler       ( void );
void SSC_Handler        ( void );
void SUPC_Handler       ( void );
void TC0_Handler        ( void );
void TC1_Handler        ( void );
void TC2_Handler        ( void );
void TC9_Handler        ( void );
void TC10_Handler       ( void );
void TC11_Handler       ( void );
void TRNG_Handler       ( void );
void TWIHS0_Handler     ( void );
void TWIHS1_Handler     ( void );
void TWIHS2_Handler     ( void );
void UART0_Handler      ( void );
void UART1_Handler      ( void );
void UART2_Handler      ( void );
void UART3_Handler      ( void );
void UART4_Handler      ( void );
void USART0_Handler     ( void );
void USART1_Handler     ( void );
void USART2_Handler     ( void );
void USBHS_Handler      ( void );
void WDT_Handler        ( void );
void XDMAC_Handler      ( void );

/**
 * \brief Configuration of the Cortex-M7 Processor and Core Peripherals 
 */

#define __CM7_REV              0x0000 /**< SAMV71N21B core revision number ([15:8] revision number, [7:0] patch number) */
#define __MPU_PRESENT          1      /**< SAMV71N21B does provide a MPU */
#define __NVIC_PRIO_BITS       3      /**< SAMV71N21B uses 3 Bits for the Priority Levels */
#define __FPU_PRESENT          1      /**< SAMV71N21B does provide a FPU                */
#define __FPU_DP               1      /**< SAMV71N21B Double precision FPU              */
#define __ICACHE_PRESENT       1      /**< SAMV71N21B does provide an Instruction Cache */
#define __DCACHE_PRESENT       1      /**< SAMV71N21B does provide a Data Cache         */
#define __DTCM_PRESENT         1      /**< SAMV71N21B does provide a Data TCM           */
#define __ITCM_PRESENT         1      /**< SAMV71N21B does provide an Instruction TCM   */
#define __Vendor_SysTickConfig 0      /**< Set to 1 if different SysTick Config is used */
#define __SAM_M7_REVB		   1	  /**< SAMV71N21 Revision B */

/*
 * \brief CMSIS includes
 */

#include <core_cm7.h>
#if !defined DONT_USE_CMSIS_INIT
#include "system_samv71.h"
#endif /* DONT_USE_CMSIS_INIT */

/*@}*/

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_api Peripheral Software API */
/*@{*/

#include "component/acc.h"
#include "component/aes.h"
#include "component/afec.h"
#include "component/chipid.h"
#include "component/dacc.h"
#include "component/efc.h"
#include "component/gmac.h"
#include "component/gpbr.h"
#include "component/hsmci.h"
#include "component/i2sc.h"
#include "component/icm.h"
#include "component/isi.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/mlb.h"
#include "component/pio.h"
#include "component/pmc.h"
#include "component/pwm.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rswdt.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/spi.h"
#include "component/ssc.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/trng.h"
#include "component/twihs.h"
#include "component/uart.h"
#include "component/usart.h"
#include "component/usbhs.h"
#include "component/utmi.h"
#include "component/wdt.h"
#include "component/xdmac.h"
/*@}*/

/* ************************************************************************** */
/*   REGISTER ACCESS DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_reg Registers Access Definitions */
/*@{*/

#include "instance/hsmci.h"
#include "instance/ssc.h"
#include "instance/spi0.h"
#include "instance/tc0.h"
#include "instance/twihs0.h"
#include "instance/twihs1.h"
#include "instance/pwm0.h"
#include "instance/usart0.h"
#include "instance/usart1.h"
#include "instance/usart2.h"
#include "instance/mcan0.h"
#include "instance/mcan1.h"
#include "instance/usbhs.h"
#include "instance/afec0.h"
#include "instance/dacc.h"
#include "instance/acc.h"
#include "instance/icm.h"
#include "instance/isi.h"
#include "instance/gmac.h"
#include "instance/tc3.h"
#include "instance/pwm1.h"
#include "instance/twihs2.h"
#include "instance/afec1.h"
#include "instance/mlb.h"
#include "instance/aes.h"
#include "instance/trng.h"
#include "instance/xdmac.h"
#include "instance/qspi.h"
#include "instance/matrix.h"
#include "instance/i2sc0.h"
#include "instance/utmi.h"
#include "instance/pmc.h"
#include "instance/uart0.h"
#include "instance/chipid.h"
#include "instance/uart1.h"
#include "instance/efc.h"
#include "instance/pioa.h"
#include "instance/piob.h"
#include "instance/piod.h"
#include "instance/rstc.h"
#include "instance/supc.h"
#include "instance/rtt.h"
#include "instance/wdt.h"
#include "instance/rtc.h"
#include "instance/gpbr.h"
#include "instance/rswdt.h"
#include "instance/uart2.h"
#include "instance/uart3.h"
#include "instance/uart4.h"
/*@}*/

/* ************************************************************************** */
/*   PERIPHERAL ID DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_id Peripheral Ids Definitions */
/*@{*/

#define ID_SUPC   ( 0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC   ( 1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC    ( 2) /**< \brief Real Time Clock (RTC) */
#define ID_RTT    ( 3) /**< \brief Real Time Timer (RTT) */
#define ID_WDT    ( 4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC    ( 5) /**< \brief Power Management Controller (PMC) */
#define ID_EFC    ( 6) /**< \brief Enhanced Embedded Flash Controller (EFC) */
#define ID_UART0  ( 7) /**< \brief UART 0 (UART0) */
#define ID_UART1  ( 8) /**< \brief UART 1 (UART1) */
#define ID_PIOA   (10) /**< \brief Parallel I/O Controller A (PIOA) */
#define ID_PIOB   (11) /**< \brief Parallel I/O Controller B (PIOB) */
#define ID_USART0 (13) /**< \brief USART 0 (USART0) */
#define ID_USART1 (14) /**< \brief USART 1 (USART1) */
#define ID_USART2 (15) /**< \brief USART 2 (USART2) */
#define ID_PIOD   (16) /**< \brief Parallel I/O Controller D (PIOD) */
#define ID_HSMCI  (18) /**< \brief Multimedia Card Interface (HSMCI) */
#define ID_TWIHS0 (19) /**< \brief Two Wire Interface 0 HS (TWIHS0) */
#define ID_TWIHS1 (20) /**< \brief Two Wire Interface 1 HS (TWIHS1) */
#define ID_SPI0   (21) /**< \brief Serial Peripheral Interface 0 (SPI0) */
#define ID_SSC    (22) /**< \brief Synchronous Serial Controller (SSC) */
#define ID_TC0    (23) /**< \brief Timer/Counter 0 (TC0) */
#define ID_TC1    (24) /**< \brief Timer/Counter 1 (TC1) */
#define ID_TC2    (25) /**< \brief Timer/Counter 2 (TC2) */
#define ID_AFEC0  (29) /**< \brief Analog Front End 0 (AFEC0) */
#define ID_DACC   (30) /**< \brief Digital To Analog Converter (DACC) */
#define ID_PWM0   (31) /**< \brief Pulse Width Modulation 0 (PWM0) */
#define ID_ICM    (32) /**< \brief Integrity Check Monitor (ICM) */
#define ID_ACC    (33) /**< \brief Analog Comparator (ACC) */
#define ID_USBHS  (34) /**< \brief USB Host / Device Controller (USBHS) */
#define ID_MCAN0  (35) /**< \brief MCAN Controller 0 (MCAN0) */
#define ID_MCAN1  (37) /**< \brief MCAN Controller 1 (MCAN1) */
#define ID_GMAC   (39) /**< \brief Ethernet MAC (GMAC) */
#define ID_AFEC1  (40) /**< \brief Analog Front End 1 (AFEC1) */
#define ID_TWIHS2 (41) /**< \brief Two Wire Interface 2 HS (TWIHS2) */
#define ID_QSPI   (43) /**< \brief Quad I/O Serial Peripheral Interface (QSPI) */
#define ID_UART2  (44) /**< \brief UART 2 (UART2) */
#define ID_UART3  (45) /**< \brief UART 3 (UART3) */
#define ID_UART4  (46) /**< \brief UART 4 (UART4) */
#define ID_TC9    (50) /**< \brief Timer/Counter 9 (TC9) */
#define ID_TC10   (51) /**< \brief Timer/Counter 10 (TC10) */
#define ID_TC11   (52) /**< \brief Timer/Counter 11 (TC11) */
#define ID_MLB    (53) /**< \brief MediaLB (MLB) */
#define ID_AES    (56) /**< \brief AES (AES) */
#define ID_TRNG   (57) /**< \brief True Random Generator (TRNG) */
#define ID_XDMAC  (58) /**< \brief DMA (XDMAC) */
#define ID_ISI    (59) /**< \brief Camera Interface (ISI) */
#define ID_PWM1   (60) /**< \brief Pulse Width Modulation 1 (PWM1) */
#define ID_RSWDT  (63) /**< \brief Reinforced Secure Watchdog Timer (RSWDT) */
#define ID_I2SC0  (69) /**< \brief Inter-IC Sound controller (I2SC0) */

#define ID_PERIPH_COUNT (74) /**< \brief Number of peripheral IDs */
/*@}*/

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_base Peripheral Base Address Definitions */
/*@{*/

#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define HSMCI  (0x40000000U) /**< \brief (HSMCI ) Base Address */
#define SSC    (0x40004000U) /**< \brief (SSC   ) Base Address */
#define SPI0   (0x40008000U) /**< \brief (SPI0  ) Base Address */
#define TC0    (0x4000C000U) /**< \brief (TC0   ) Base Address */
#define TWIHS0 (0x40018000U) /**< \brief (TWIHS0) Base Address */
#define TWIHS1 (0x4001C000U) /**< \brief (TWIHS1) Base Address */
#define PWM0   (0x40020000U) /**< \brief (PWM0  ) Base Address */
#define USART0 (0x40024000U) /**< \brief (USART0) Base Address */
#define USART1 (0x40028000U) /**< \brief (USART1) Base Address */
#define USART2 (0x4002C000U) /**< \brief (USART2) Base Address */
#define MCAN0  (0x40030000U) /**< \brief (MCAN0 ) Base Address */
#define MCAN1  (0x40034000U) /**< \brief (MCAN1 ) Base Address */
#define USBHS  (0x40038000U) /**< \brief (USBHS ) Base Address */
#define AFEC0  (0x4003C000U) /**< \brief (AFEC0 ) Base Address */
#define DACC   (0x40040000U) /**< \brief (DACC  ) Base Address */
#define ACC    (0x40044000U) /**< \brief (ACC   ) Base Address */
#define ICM    (0x40048000U) /**< \brief (ICM   ) Base Address */
#define ISI    (0x4004C000U) /**< \brief (ISI   ) Base Address */
#define GMAC   (0x40050000U) /**< \brief (GMAC  ) Base Address */
#define TC3    (0x40054000U) /**< \brief (TC3   ) Base Address */
#define PWM1   (0x4005C000U) /**< \brief (PWM1  ) Base Address */
#define TWIHS2 (0x40060000U) /**< \brief (TWIHS2) Base Address */
#define AFEC1  (0x40064000U) /**< \brief (AFEC1 ) Base Address */
#define MLB    (0x40068000U) /**< \brief (MLB   ) Base Address */
#define AES    (0x4006C000U) /**< \brief (AES   ) Base Address */
#define TRNG   (0x40070000U) /**< \brief (TRNG  ) Base Address */
#define XDMAC  (0x40078000U) /**< \brief (XDMAC ) Base Address */
#define QSPI   (0x4007C000U) /**< \brief (QSPI  ) Base Address */
#define MATRIX (0x40088000U) /**< \brief (MATRIX) Base Address */
#define I2SC0  (0x4008C000U) /**< \brief (I2SC0 ) Base Address */
#define UTMI   (0x400E0400U) /**< \brief (UTMI  ) Base Address */
#define PMC    (0x400E0600U) /**< \brief (PMC   ) Base Address */
#define UART0  (0x400E0800U) /**< \brief (UART0 ) Base Address */
#define CHIPID (0x400E0940U) /**< \brief (CHIPID) Base Address */
#define UART1  (0x400E0A00U) /**< \brief (UART1 ) Base Address */
#define EFC    (0x400E0C00U) /**< \brief (EFC   ) Base Address */
#define PIOA   (0x400E0E00U) /**< \brief (PIOA  ) Base Address */
#define PIOB   (0x400E1000U) /**< \brief (PIOB  ) Base Address */
#define PIOD   (0x400E1400U) /**< \brief (PIOD  ) Base Address */
#define RSTC   (0x400E1800U) /**< \brief (RSTC  ) Base Address */
#define SUPC   (0x400E1810U) /**< \brief (SUPC  ) Base Address */
#define RTT    (0x400E1830U) /**< \brief (RTT   ) Base Address */
#define WDT    (0x400E1850U) /**< \brief (WDT   ) Base Address */
#define RTC    (0x400E1860U) /**< \brief (RTC   ) Base Address */
#define GPBR   (0x400E1890U) /**< \brief (GPBR  ) Base Address */
#define RSWDT  (0x400E1900U) /**< \brief (RSWDT ) Base Address */
#define UART2  (0x400E1A00U) /**< \brief (UART2 ) Base Address */
#define UART3  (0x400E1C00U) /**< \brief (UART3 ) Base Address */
#define UART4  (0x400E1E00U) /**< \brief (UART4 ) Base Address */
#else
#define HSMCI  ((Hsmci  *)0x40000000U) /**< \brief (HSMCI ) Base Address */
#define SSC    ((Ssc    *)0x40004000U) /**< \brief (SSC   ) Base Address */
#define SPI0   ((Spi    *)0x40008000U) /**< \brief (SPI0  ) Base Address */
#define TC0    ((Tc     *)0x4000C000U) /**< \brief (TC0   ) Base Address */
#define TWIHS0 ((Twihs  *)0x40018000U) /**< \brief (TWIHS0) Base Address */
#define TWIHS1 ((Twihs  *)0x4001C000U) /**< \brief (TWIHS1) Base Address */
#define PWM0   ((Pwm    *)0x40020000U) /**< \brief (PWM0  ) Base Address */
#define USART0 ((Usart  *)0x40024000U) /**< \brief (USART0) Base Address */
#define USART1 ((Usart  *)0x40028000U) /**< \brief (USART1) Base Address */
#define USART2 ((Usart  *)0x4002C000U) /**< \brief (USART2) Base Address */
#define MCAN0  ((Mcan   *)0x40030000U) /**< \brief (MCAN0 ) Base Address */
#define MCAN1  ((Mcan   *)0x40034000U) /**< \brief (MCAN1 ) Base Address */
#define USBHS  ((Usbhs  *)0x40038000U) /**< \brief (USBHS ) Base Address */
#define AFEC0  ((Afec   *)0x4003C000U) /**< \brief (AFEC0 ) Base Address */
#define DACC   ((Dacc   *)0x40040000U) /**< \brief (DACC  ) Base Address */
#define ACC    ((Acc    *)0x40044000U) /**< \brief (ACC   ) Base Address */
#define ICM    ((Icm    *)0x40048000U) /**< \brief (ICM   ) Base Address */
#define ISI    ((Isi    *)0x4004C000U) /**< \brief (ISI   ) Base Address */
#define GMAC   ((Gmac   *)0x40050000U) /**< \brief (GMAC  ) Base Address */
#define TC3    ((Tc     *)0x40054000U) /**< \brief (TC3   ) Base Address */
#define PWM1   ((Pwm    *)0x4005C000U) /**< \brief (PWM1  ) Base Address */
#define TWIHS2 ((Twihs  *)0x40060000U) /**< \brief (TWIHS2) Base Address */
#define AFEC1  ((Afec   *)0x40064000U) /**< \brief (AFEC1 ) Base Address */
#define MLB    ((Mlb    *)0x40068000U) /**< \brief (MLB   ) Base Address */
#define AES    ((Aes    *)0x4006C000U) /**< \brief (AES   ) Base Address */
#define TRNG   ((Trng   *)0x40070000U) /**< \brief (TRNG  ) Base Address */
#define XDMAC  ((Xdmac  *)0x40078000U) /**< \brief (XDMAC ) Base Address */
#define QSPI   ((Qspi   *)0x4007C000U) /**< \brief (QSPI  ) Base Address */
#define MATRIX ((Matrix *)0x40088000U) /**< \brief (MATRIX) Base Address */
#define I2SC0  ((I2sc   *)0x4008C000U) /**< \brief (I2SC0 ) Base Address */
#define UTMI   ((Utmi   *)0x400E0400U) /**< \brief (UTMI  ) Base Address */
#define PMC    ((Pmc    *)0x400E0600U) /**< \brief (PMC   ) Base Address */
#define UART0  ((Uart   *)0x400E0800U) /**< \brief (UART0 ) Base Address */
#define CHIPID ((Chipid *)0x400E0940U) /**< \brief (CHIPID) Base Address */
#define UART1  ((Uart   *)0x400E0A00U) /**< \brief (UART1 ) Base Address */
#define EFC    ((Efc    *)0x400E0C00U) /**< \brief (EFC   ) Base Address */
#define PIOA   ((Pio    *)0x400E0E00U) /**< \brief (PIOA  ) Base Address */
#define PIOB   ((Pio    *)0x400E1000U) /**< \brief (PIOB  ) Base Address */
#define PIOD   ((Pio    *)0x400E1400U) /**< \brief (PIOD  ) Base Address */
#define RSTC   ((Rstc   *)0x400E1800U) /**< \brief (RSTC  ) Base Address */
#define SUPC   ((Supc   *)0x400E1810U) /**< \brief (SUPC  ) Base Address */
#define RTT    ((Rtt    *)0x400E1830U) /**< \brief (RTT   ) Base Address */
#define WDT    ((Wdt    *)0x400E1850U) /**< \brief (WDT   ) Base Address */
#define RTC    ((Rtc    *)0x400E1860U) /**< \brief (RTC   ) Base Address */
#define GPBR   ((Gpbr   *)0x400E1890U) /**< \brief (GPBR  ) Base Address */
#define RSWDT  ((Rswdt  *)0x400E1900U) /**< \brief (RSWDT ) Base Address */
#define UART2  ((Uart   *)0x400E1A00U) /**< \brief (UART2 ) Base Address */
#define UART3  ((Uart   *)0x400E1C00U) /**< \brief (UART3 ) Base Address */
#define UART4  ((Uart   *)0x400E1E00U) /**< \brief (UART4 ) Base Address */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/*@}*/

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */
/** \addtogroup SAMV71N21B_pio Peripheral Pio Definitions */
/*@{*/

#include "pio/samv71n21b.h"
/*@}*/

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */

#define IFLASH_SIZE             (0x200000u)
#define IFLASH_PAGE_SIZE        (512u)
#define IFLASH_LOCK_REGION_SIZE (8192u)
#define IFLASH_NB_OF_PAGES      (4096u)
#define IFLASH_NB_OF_LOCK_BITS  (128u)
#define IRAM_SIZE               (0x60000u)

#define QSPIMEM_ADDR  (0x80000000u) /**< QSPI Memory base address */
#define AXIMX_ADDR    (0xA0000000u) /**< AXI Bus Matrix base address */
#define ITCM_ADDR     (0x00000000u) /**< Instruction Tightly Coupled Memory base address */
#define IFLASH_ADDR   (0x00400000u) /**< Internal Flash base address */
#define IROM_ADDR     (0x00800000u) /**< Internal ROM base address */
#define DTCM_ADDR     (0x20000000u) /**< Data Tightly Coupled Memory base address */
#define IRAM_ADDR     (0x20400000u) /**< Internal RAM base address */

/* ************************************************************************** */
/*   MISCELLANEOUS DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */

#define CHIP_JTAGID (0x05B3D03FUL)
#define CHIP_CIDR   (0xA1220E00UL)
#define CHIP_EXID   (0x00000001UL)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAMV71N21B */
/* ************************************************************************** */

/* %ATMEL_ELECTRICAL% */

/* Device characteristics */
#define CHIP_FREQ_SLCK_RC_MIN           (20000UL)
#define CHIP_FREQ_SLCK_RC               (32000UL)
#define CHIP_FREQ_SLCK_RC_MAX           (44000UL)
#define CHIP_FREQ_MAINCK_RC_4MHZ        (4000000UL)
#define CHIP_FREQ_MAINCK_RC_8MHZ        (8000000UL)
#define CHIP_FREQ_MAINCK_RC_12MHZ       (12000000UL)
#define CHIP_FREQ_CPU_MAX               (300000000UL)
#define CHIP_FREQ_XTAL_32K              (32768UL)
#define CHIP_FREQ_XTAL_12M              (12000000UL)

/* Embedded Flash Read Wait State (for Worst-Case Conditions) */
#define CHIP_FREQ_FWS_0                 (23000000UL)  /**< \brief Maximum operating frequency when FWS is 0 */
#define CHIP_FREQ_FWS_1                 (46000000UL)  /**< \brief Maximum operating frequency when FWS is 1 */
#define CHIP_FREQ_FWS_2                 (69000000UL)  /**< \brief Maximum operating frequency when FWS is 2 */
#define CHIP_FREQ_FWS_3                 (92000000UL)  /**< \brief Maximum operating frequency when FWS is 3 */
#define CHIP_FREQ_FWS_4                 (115000000UL) /**< \brief Maximum operating frequency when FWS is 4 */
#define CHIP_FREQ_FWS_5                 (138000000UL) /**< \brief Maximum operating frequency when FWS is 5 */
#define CHIP_FREQ_FWS_6                 (150000000UL) /**< \brief Maximum operating frequency when FWS is 6 */

#ifdef __cplusplus
}
#endif

/*@}*/

#endif /* _SAMV71N21B_ */
