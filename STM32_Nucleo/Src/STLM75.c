/**
  * @file    STLM75.c
  * @author  ART Team IMS-Systems Lab
  * @version V2.2
  * @date    01/11/2011
  * @brief   This file provides a set of functions needed to manage the
  *          communication between STM32 I2C master and STLM75 I2C slave.
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




/* Includes ------------------------------------------------------------------*/
#include "STLM75.h"
#include "HAL_STLM75.h"


/**
* @addtogroup STLM75
* @{
*/

/**
* @defgroup STLM75_API
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static I2C_HandleTypeDef I2cHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



/**
* @brief  Initializes the I2C peripheral used to drive the STLM75
* @param  None
* @retval None
*/

void STLM75_I2C_Init(void)
{
  
  
}

/**
* @brief  Initializes the OS/INT pin interrupt
* @param  None
* @retval None
*/

#ifdef OS_INT_ENABLE

void STLM75_INT_Config(void)
{
    
}
#endif


/**
* @brief  Set interrupt configuration of STLM75
* @param  STLM75_Interrupt_Struct: pointer to a STLM75_InterruptTypeDef structure that
*         contains the interrupt configuration setting for the STLM75.
* @retval None
*/

#ifdef OS_INT_ENABLE

void STLM75_Interrupt_Config(STLM75_InterruptTypeDef *STLM75_Interrupt_Struct)
{
    
}
#endif

/**
* @brief  Read temperature data registers
* @param  pBuffer : pointer to the buffer that receives the temperature
*                   data read from the STLM75. It will give in pBuffer the TMSB byte
*                   and in pBuffer++ the TLSB byte. Temperature data are expressed as
*                   2's complement numbers.
* @retval None
*/


void STLM75_Read_Temperature_Regs(uint8_t* pBuffer)
{
  
}


/**
* @brief  Read temperature registers and put in a signed 16-bit variable
* @param  out : variable where put the raw data
* @retval None
*/

void STLM75_Read_Raw_Data(signed short* out)
{


}


/**
* @brief  Read temperature data
* @param  refvalue : Temperature data expressed as
*                    2's complement numbers and in tenth of °C
* @retval None
*/

void STLM75_Read_Temperature_Signed(signed short* refvalue)
{
 
}

/**
* @brief  Enables or disables the lowpower mode for STLM75
* @param  refvalue : NewState: new state for the lowpower mode.
*         This parameter can be one of following parameters:
*         @arg ENABLE
*         @arg DISABLE
* @retval None
*/

void STLM75_Lowpower_Cmd(FunctionalState NewState)
{

}

/**
* @brief  Set temperature over-limit reference
* @param  refvalue : temperature threshold value expressed in tenth of °C
*                    with step of 5 tenth of °C
* @retval None
*/

void STLM75_Set_Over_Limit(signed short refvalue)
{
    
}

/**
* @brief  Set Hysteresis threshold
* @param  refvalue : Hysteresis threshold value expressed in tenth of °C
*                    with step of 5 tenth of °C
* @retval None
*/

void STLM75_Set_Hysteresis(signed short refvalue)
{
  
}

/**
* @brief  Set the command/Pointer register
* @param  eRegPointer : pointer value to write in the Command/Pointer
*                       register the buffer that receives the data read
*                       from the STLM75.
* @retval None
*/

void STLM75_SetPointer(uint8_t eRegPointer)
{  

}

/**
* @brief  Writes one or more byte to the STLM75 registers.
* @param  pBuffer : pointer to the buffer  containing the data to be 
*                    written into STLM75.
* @param  WriteAddr : STLM75's internal address to write to.
* @param  NumByteToWrite: Number of bytes to write
* @retval None
*/

void STLM75_Write(uint8_t* pBuffer, uint8_t WriteAddr, uint8_t NumByteToWrite)
{

    
}

/**
* @brief  Writes one or more byte to the STLM75 registers.
* @param  pBuffer : pointer to the buffer that receives the data read 
*                    from the STLM75.
* @param  ReadAddr : STLM75's internal address to read from.
* @param  NumByteToRead:number of bytes to read from the STLM75.
* @retval None
*/

int STLM75_Read(uint8_t* pBuffer, uint8_t ReadAddr, uint8_t NumByteToRead)
{
  
  return NumByteToRead;
}

/**
 * @}
 */ /* end of group STLM75_API */

/**
*@}
*/ /* end of group STLM75 */



/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
