/**
  * @file    HAL_STLM75.h
  * @author  ART Team IMS-Systems Lab
  * @version V2.2
  * @date    01/11/2011
  * @brief   Hardware Abstraction Layer for STLM75.
  * @details
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
  * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
  * IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */



/* Define to prevent recursive inclusion*/
#ifndef __HAL_STLM75_H
#define __HAL_STLM75_H

#ifdef __cplusplus
 extern "C" {
#endif 
  

/* Includes ------------------------------------------------------------------*/
#include "cube_hal.h"//"stm32l1xx_hal.h"

/**
* @defgroup STLM75
* @{
*/


/**
* @defgroup  STLM75_I2C_Define
* @{
*/

#define TEMP_I2C                  I2C1	
#define TEMP_I2C_Speed            10000     
#define TEMP_RCC_Periph_I2C()      __I2C1_CLK_ENABLE()

#define TEMP_I2C_Port             GPIOB
#define TEMP_I2C_Port_CLOCK()     __GPIOB_CLK_ENABLE()

#define TEMP_I2C_SCL_AF           GPIO_AF4_I2C1
#define TEMP_I2C_SCL_Pin          GPIO_PIN_6

#define TEMP_I2C_SDA_AF           GPIO_AF4_I2C1
#define TEMP_I2C_SDA_Pin          GPIO_PIN_7


/**
*@}
*/ /* end of group STLM75_I2C_Define */ 


/**
* @defgroup STLM75_Interrupt_PIN_Define
* @{
*/

#ifdef OS_INT_ENABLE
#define STLM75_INT_Pin                   GPIO_PIN_5
#define STLM75_INT_Port                  GPIOB
#define STLM75_INT_RCC()                __HAL_RCC_GPIOB_CLK_ENABLE()
#define STLM75_INT_EXTI_IRQCHANNEL       EXTI9_5_IRQn
#define STLM75_INT_Preemption_Priority   12
#define STLM75_INT_Sub_Priority          0
#endif //OS_INT_ENABLE

/**
*@}
*/ /* end of group STLM75_Interrupt_PIN_Define */

/**
*@}
*/ /* end of group STLM75 */


#endif /* __HAL_STLM75_H */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
