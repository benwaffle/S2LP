/**
  * @file    HAL_LIS331DLH.h
  * @author  ART Team IMS-Systems Lab
  * @version V2.2
  * @date    01/11/2011
  * @brief   Hardware Abstraction Layer for LIS331DLH.
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
#ifndef __HAL_LIS331DLH_H
#define __HAL_LIS331DLH_H

#ifdef __cplusplus
 extern "C" {
#endif 
  

/**
* @addtogroup LIS331DLH
* @{
*/
   
/**
* @addtogroup  LIS331DLH_SPI_Define
* @{
*/
#define LIS_SPI                  SPI1
#define LIS_RCC_Periph_SPI()       __SPI1_CLK_ENABLE()
#define LIS_SPI_Port             GPIOA
#define LIS_SPI_AF               GPIO_AF5_SPI1
#define LIS_SPI_MISO_Pin         GPIO_PIN_6
#define LIS_SPI_M0SI_Pin         GPIO_PIN_7
#define LIS_SPI_SCK_Pin          GPIO_PIN_5
#define LIS_SPI_CS_Pin           GPIO_PIN_4
#define LIS_SPI_CS_Port          GPIOA
#define LIS_RCC_Port_SPI()       __GPIOA_CLK_ENABLE()

 /**
*@}
*/ /* end of group LIS331DLH_SPI_Define */ 



/**
* @addtogroup Accelerometer_Interrupt_PIN_Define
* @{
*/
#ifdef  LIS_A_INT1_ENABLE
#define LIS_A_INT1_PIN           	GPIO_PIN_10
#define LIS_A_INT1_GPIO_PORT     	GPIOB
#define LIS_A_INT1_GPIO_CLK()       __GPIOB_CLK_ENABLE()
#define LIS_A_INT1_EXTI_IRQn		EXTI15_10_IRQn
#define LIS3DH_IRQHandler           EXTI15_10_IRQHandler
#endif

#ifdef LIS_A_INT2_ENABLE
#define LIS_A_INT2_Pin           GPIO_PIN_11
#define LIS_A_INT2_Port          GPIOB
#define LIS_A_INT2_RCC_Port()       __GPIOB_CLK_ENABLE()
#endif

/**
*@}
*/ /* end of group Accelerometer_Interrupt_PIN_Define */


/**
*@}
*/ /* end of group LIS331DLH */



#endif /* __HAL_LIS331DLH_H */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
