/**
  ******************************************************************************
  * @file    stm32l0xx_nucleo.h
  * @author  MCD Application Team
  * @author  LowPower RF BU - AMG
  * @version 3.2.0
  * @date    May 1, 2016
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/** @addtogroup SDK_EVAL_NUCLEO
  * @{
  */ 

/** @addtogroup STM32L0XX_NUCLEO
 *  @brief This module contains the peripherial defines to run the SDK_EVAL on the NUCLEO-L053RB
 * @{
 */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L0XX_NUCLEO_H
#define __STM32L0XX_NUCLEO_H

#ifdef __cplusplus
 extern "C" {
#endif
                                              
/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
   

/** @defgroup STM32L0XX_NUCLEO_Exported_Constants Exported Constants  
 * @{
 */ 

   
/** 
  * @brief  Define for STM32L0xx_NUCLEO board  
  */ 
#if !defined (USE_STM32L0xx_NUCLEO)
 #define USE_STM32L0xx_NUCLEO
#endif
  


   
   
#define SDK_EVAL_NUCLEO_VER         0x80
     

#define NUCLEO_SPI_PERIPH_NB                  SPI1
#define NUCLEO_SPI_CLK_ENABLE()                __SPI1_CLK_ENABLE()
#define NUCLEO_SPI_CLK_DISABLE()                __SPI1_CLK_ENABLE()

/* Defines for MOSI pin*/
#define NUCLEO_SPI_PERIPH_MOSI_PORT           GPIOA
#define NUCLEO_SPI_PERIPH_MOSI_PIN            GPIO_PIN_7
#define NUCLEO_SPI_PERIPH_MOSI_AF             GPIO_AF0_SPI1
#define NUCLEO_SPI_PERIPH_MOSI_CLK_ENABLE()      __GPIOA_CLK_ENABLE() 
#define NUCLEO_SPI_PERIPH_MOSI_CLK_DISABLE()      __GPIOA_CLK_DISABLE() 

/* Defines for MISO pin */
#define NUCLEO_SPI_PERIPH_MISO_PORT           GPIOA
#define NUCLEO_SPI_PERIPH_MISO_PIN            GPIO_PIN_6
#define NUCLEO_SPI_PERIPH_MISO_AF             GPIO_AF0_SPI1
#define NUCLEO_SPI_PERIPH_MISO_CLK_ENABLE()      __GPIOA_CLK_ENABLE() 
#define NUCLEO_SPI_PERIPH_MISO_CLK_DISABLE()      __GPIOA_CLK_DISABLE() 

/* Defines for SCLK pin */
#define NUCLEO_SPI_PERIPH_SCLK_PORT           GPIOB
#define NUCLEO_SPI_PERIPH_SCLK_PIN            GPIO_PIN_3
#define NUCLEO_SPI_PERIPH_SCLK_AF             GPIO_AF0_SPI1
#define NUCLEO_SPI_PERIPH_SCLK_CLK_ENABLE()       __GPIOB_CLK_ENABLE()
#define NUCLEO_SPI_PERIPH_SCLK_CLK_DISABLE()       __GPIOB_CLK_DISABLE()

#ifdef X_NUCLEO_IDS01Ax
 /* Defines for chip select pin */
 #define NUCLEO_SPI_PERIPH_CS_PORT             GPIOB
 #define NUCLEO_SPI_PERIPH_CS_PIN              GPIO_PIN_6
 #define NUCLEO_SPI_PERIPH_CS_CLK_ENABLE()     __GPIOB_CLK_ENABLE()
 #define NUCLEO_SPI_PERIPH_CS_CLK_DISABLE()    __GPIOB_CLK_DISABLE()
#else
 /* Defines for chip select pin */
 #define NUCLEO_SPI_PERIPH_CS_PORT             GPIOA
 #define NUCLEO_SPI_PERIPH_CS_PIN              GPIO_PIN_1
 #define NUCLEO_SPI_PERIPH_CS_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
 #define NUCLEO_SPI_PERIPH_CS_CLK_DISABLE()    __GPIOA_CLK_DISABLE()
#endif
   
#define NUCLEO_SPI_DMA_CLK_ENABLE()                   __DMA1_CLK_ENABLE()

#define NUCLEO_SPI_TX_DMA_CHANNEL              DMA1_Channel3
#define NUCLEO_SPI_RX_DMA_CHANNEL              DMA1_Channel2
#define NUCLEO_SPI_DMA_TX_IRQn                 DMA1_Channel2_3_IRQn
#define NUCLEO_SPI_DMA_RX_IRQn                 DMA1_Channel2_3_IRQn
#define NUCLEO_SPI_DMA_TX_IRQHandler           DMA1_Channel2_3_IRQHandler
#define NUCLEO_SPI_DMA_RX_IRQHandler           DMA1_Channel2_3_IRQHandler
#define NUCLEO_SPI_RX_DMA_REQUEST                     DMA_REQUEST_1
#define NUCLEO_SPI_TX_DMA_REQUEST                     DMA_REQUEST_1
   
#define M2S_GPIO_0_PORT_NUCLEO                        GPIOA
#define M2S_GPIO_0_CLOCK_NUCLEO()                     __GPIOA_CLK_ENABLE()
#define M2S_GPIO_0_PIN                         GPIO_PIN_0
#define M2S_GPIO_0_SPEED                       GPIO_SPEED_HIGH
#define M2S_GPIO_0_PUPD                        GPIO_NOPULL
#define M2S_GPIO_0_MODE                        GPIO_MODE_OUTPUT_PP
#define M2S_GPIO_0_EXTI_MODE                   GPIO_MODE_IT_FALLING
#define M2S_GPIO_0_EXTI_IRQN                   EXTI0_1_IRQn
#define M2S_GPIO_0_EXTI_PREEMPTION_PRIORITY    2
#define M2S_GPIO_0_EXTI_SUB_PRIORITY           2
#define M2S_GPIO_0_EXTI_IRQ_HANDLER            EXTI0_1_IRQHandler

   
#define M2S_GPIO_1_PORT_NUCLEO                        GPIOA
#define M2S_GPIO_1_CLOCK_NUCLEO()                     __GPIOA_CLK_ENABLE()
#define M2S_GPIO_1_PIN                         GPIO_PIN_4
#define M2S_GPIO_1_SPEED                       GPIO_SPEED_HIGH
#define M2S_GPIO_1_PUPD                        GPIO_NOPULL
#define M2S_GPIO_1_MODE                       GPIO_MODE_OUTPUT_PP
#define M2S_GPIO_1_EXTI_MODE                   GPIO_MODE_IT_FALLING
#define M2S_GPIO_1_EXTI_IRQN                   EXTI4_15_IRQn
#define M2S_GPIO_1_EXTI_PREEMPTION_PRIORITY    2
#define M2S_GPIO_1_EXTI_SUB_PRIORITY           2
#define M2S_GPIO_1_EXTI_IRQ_HANDLER            EXTI4_15_IRQHandler

   
#define M2S_GPIO_2_PORT_NUCLEO                        GPIOB
#define M2S_GPIO_2_CLOCK_NUCLEO()                     __GPIOB_CLK_ENABLE()
#define M2S_GPIO_2_PIN                         GPIO_PIN_0
#define M2S_GPIO_2_SPEED                       GPIO_SPEED_HIGH
#define M2S_GPIO_2_PUPD                        GPIO_NOPULL
#define M2S_GPIO_2_MODE                        GPIO_MODE_OUTPUT_PP
#define M2S_GPIO_2_EXTI_MODE                   GPIO_MODE_IT_FALLING
#define M2S_GPIO_2_EXTI_IRQN                   EXTI0_1_IRQn
#define M2S_GPIO_2_EXTI_PREEMPTION_PRIORITY    2
#define M2S_GPIO_2_EXTI_SUB_PRIORITY           2
#define M2S_GPIO_2_EXTI_IRQ_HANDLER            EXTI0_1_IRQHandler



#define M2S_GPIO_3_PORT_NUCLEO                        GPIOC
#define M2S_GPIO_3_CLOCK_NUCLEO()                     __GPIOC_CLK_ENABLE()

#ifdef X_NUCLEO_IDS01Ax
 #define M2S_GPIO_3_PIN                         GPIO_PIN_7
 #define M2S_GPIO_3_EXTI_IRQN                   EXTI9_5_IRQn
 #define M2S_GPIO_3_EXTI_IRQ_HANDLER            EXTI9_5_IRQHandler
#else
 #define M2S_GPIO_3_PIN                         GPIO_PIN_0
 #define M2S_GPIO_3_EXTI_IRQN                   EXTI0_1_IRQn
 #define M2S_GPIO_3_EXTI_IRQ_HANDLER            EXTI0_1_IRQHandler
#endif
   
#define M2S_GPIO_3_SPEED                       GPIO_SPEED_HIGH
#define M2S_GPIO_3_PUPD                        GPIO_NOPULL
#define M2S_GPIO_3_MODE                        GPIO_MODE_OUTPUT_PP
#define M2S_GPIO_3_EXTI_MODE                   GPIO_MODE_IT_FALLING

#define M2S_GPIO_EXTI_PREEMPTION_PRIORITY    1



#define M2S_GPIO_SDN_PORT                      GPIOA
   
#ifdef X_NUCLEO_IDS01Ax
 #define M2S_GPIO_SDN_PIN                       GPIO_PIN_10
#else
 #define M2S_GPIO_SDN_PIN                       GPIO_PIN_8
#endif
   
#define M2S_GPIO_SDN_CLOCK_NUCLEO()                __GPIOA_CLK_ENABLE()
#define M2S_GPIO_SDN_SPEED                     GPIO_SPEED_HIGH
#define M2S_GPIO_SDN_PUPD                      GPIO_NOPULL
#define M2S_GPIO_SDN_MODE                      GPIO_MODE_OUTPUT_PP

#define LEDn                                    1

#define NUCLEO_LED1_PIN                         GPIO_PIN_5
#define NUCLEO_LED1_GPIO_PORT                   GPIOA
#define NUCLEO_LED1_GPIO_CLK                    __GPIOA_CLK_ENABLE

#define TCXO_EN_PIN                             GPIO_PIN_7
#define TCXO_EN_PORT                            GPIOC
#define TCXO_EN_GPIO_CLK                        __GPIOC_CLK_ENABLE


/**
* @brief  Number of buttons of the SDK EVAL board
*/

  
/**
* @brief Key push-button
*/
#define BUTTON1_PIN                   GPIO_PIN_13
#define BUTTON1_GPIO_PORT             GPIOC
#define BUTTON1_GPIO_CLK()            __GPIOC_CLK_ENABLE()
#define BUTTON1_EXTI_IRQn             EXTI4_15_IRQn
#define BUTTON1_EXTI_IRQ_HANDLER      EXTI4_15_IRQHandler
#define BUTTON1_KEY			 BUTTON_1
#define BUTTON1_IRQ_PREEMPTION_PRIORITY	 0
#define BUTTON1_IRQ_SUB_PRIORITY	          0

   
   
#define EEPROM_SPI_PERIPH_NB                  SPI1
#define EEPROM_SPI_PERIPH_RCC                 __SPI1_CLK_ENABLE
  

/* Defines for MOSI pin*/
#define EEPROM_SPI_PERIPH_MOSI_PORT           GPIOA
#define EEPROM_SPI_PERIPH_MOSI_PIN            GPIO_PIN_7
#define EEPROM_SPI_PERIPH_MOSI_AF             GPIO_AF0_SPI1
#define EEPROM_SPI_PERIPH_MOSI_RCC            __GPIOA_CLK_ENABLE
#define EEPROM_SPI_PERIPH_MOSI_RCC_SOURCE     GPIO_PinSource7

/* Defines for MISO pin */
#define EEPROM_SPI_PERIPH_MISO_PORT           GPIOA
#define EEPROM_SPI_PERIPH_MISO_PIN            GPIO_PIN_6
#define EEPROM_SPI_PERIPH_MISO_AF             GPIO_AF0_SPI1
#define EEPROM_SPI_PERIPH_MISO_RCC            __GPIOA_CLK_ENABLE
#define EEPROM_SPI_PERIPH_MISO_RCC_SOURCE     GPIO_PinSource6

/* Defines for SCLK pin */
#define EEPROM_SPI_PERIPH_SCLK_PORT           GPIOB
#define EEPROM_SPI_PERIPH_SCLK_PIN            GPIO_PIN_3
#define EEPROM_SPI_PERIPH_SCLK_AF             GPIO_AF0_SPI1
#define EEPROM_SPI_PERIPH_SCLK_RCC            __GPIOB_CLK_ENABLE
#define EEPROM_SPI_PERIPH_SCLK_RCC_SOURCE     GPIO_PinSource3

/* Defines for chip select pin */
#define EEPROM_SPI_PERIPH_CS_PORT             GPIOA
#define EEPROM_SPI_PERIPH_CS_PIN              GPIO_PIN_9
#define EEPROM_SPI_PERIPH_CS_RCC              __GPIOA_CLK_ENABLE
#define EEPROM_SPI_PERIPH_CS_RCC_SOURCE       GPIO_PinSource9
   
   
/*Defines for chip select pin on XNUCLEO-S2868A1*/
#define EEPROM_SPI_PERIPH_XNUCLEO_CS_PORT       GPIOB 
#define EEPROM_SPI_PERIPH_XNUCLEO_CS_PIN        GPIO_PIN_4 
#define EEPROM_SPI_PERIPH_XNUCLEO_CS_RCC        __GPIOB_CLK_ENABLE 
#define EEPROM_SPI_PERIPH_XNUCLEO_CS_RCC_SOURCE GPIO_PinSource4 

  

#define NUCLEO_UARTx                            USART2
#define NUCLEO_UARTx_AF                          GPIO_AF4_USART2
#define NUCLEO_UARTx_PORT                               GPIOA
#define NUCLEO_UARTx_RX_PIN                         GPIO_PIN_2
#define NUCLEO_UARTx_TX_PIN                         GPIO_PIN_3

#define NUCLEO_UARTx_GPIO_CLK_ENABLE()           __GPIOA_CLK_ENABLE()
#define NUCLEO_UARTx_GPIO_CLK_DISABLE()          __GPIOA_CLK_DISABLE()
#define NUCLEO_UARTx_CLK_ENABLE()              __USART2_CLK_ENABLE()
#define NUCLEO_UARTx_IRQn                       USART2_IRQn
#define NUCLEO_UARTx_PRIORITY                       2
   
#define NUCLEO_UARTx_TX_DMA_CHANNEL_IRQHandler           DMA1_Channel4_5_6_7_IRQHandler
#define NUCLEO_UARTx_TX_DMA_CHANNEL_IRQn                DMA1_Channel4_5_6_7_IRQn
#define NUCLEO_UARTx_TX_DMA_CHANNEL                     DMA1_Channel7
#define NUCLEO_UARTx_TX_DMA_REQUEST                     DMA_REQUEST_4
    
#define NUCLEO_UARTx_RX_DMA_CHANNEL_IRQHandler           DMA1_Channel4_5_6_7_IRQHandler
#define NUCLEO_UARTx_RX_DMA_CHANNEL_IRQn                DMA1_Channel4_5_6_7_IRQn
#define NUCLEO_UARTx_RX_DMA_CHANNEL                     DMA1_Channel6
#define NUCLEO_UARTx_RX_DMA_REQUEST                     DMA_REQUEST_4
    
#define NUCLEO_UARTx_DMA_CLK_ENABLE()                   __DMA1_CLK_ENABLE()
   
#define EEPROM_SPI_PERIPH_NB                  SPI1
#define EEPROM_SPI_PERIPH_RCC                 __SPI1_CLK_ENABLE


#define NUCLEO_UARTx_RX_QUEUE_SIZE                         (400)
#define NUCLEO_UARTx_TX_QUEUE_SIZE                           (400)

 
#define NUCLEO_TIMx_PRIORITY                    1//3
#define TIM1                                    TIM21
#define TIM1_IRQn                               TIM21_IRQn
#define __HAL_RCC_TIM1_CLK_ENABLE()     __TIM21_CLK_ENABLE()
   
#define TIM3                                     TIM2
#define TIM3_IRQn                               TIM2_IRQn
#define __HAL_RCC_TIM3_CLK_ENABLE()     __TIM2_CLK_ENABLE()
   
   
#define TIM4                                    TIM21
#define TIM4_IRQn                               TIM1_IRQn
#define __HAL_RCC_TIM4_CLK_ENABLE()     __TIM21_CLK_ENABLE()
   
#define TIM5                                    TIM22
#define TIM5_IRQn                                TIM22_IRQn
#define __HAL_RCC_TIM5_CLK_ENABLE()             __TIM22_CLK_ENABLE()
   
   
#define TIM7                                    TIM6
#define TIM7_IRQn                               TIM6_IRQn
#define __HAL_RCC_TIM7_CLK_ENABLE()             __TIM6_CLK_ENABLE()
  
   
#define TIM6_IRQHandler                         TIM6_DAC_IRQHandler
   

#define STM32_EEPROM_BASE       DATA_EEPROM_BASE
#define STM32_TYPEPROGRAM_WORD   TYPEPROGRAM_WORD  

#define STM32_RTC_IRQHandler    RTC_IRQHandler
#define STM32_RTC_IRQn    RTC_IRQn

#define  STM32_GPIO_CLK_DISABLE()   {__GPIOB_CLK_DISABLE();__GPIOC_CLK_DISABLE();__GPIOD_CLK_DISABLE();__GPIOA_CLK_DISABLE();}
#define  STM32_GPIO_CLK_ENABLE()   {__GPIOA_CLK_ENABLE();__GPIOB_CLK_ENABLE();__GPIOC_CLK_ENABLE();__GPIOD_CLK_ENABLE();}

/**
  * @}
  */


    

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0XX_NUCLEO_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
