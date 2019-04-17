/**
  * @file    STLM75.h
  * @author  ART Team IMS-Systems Lab
  * @version V2.2
  * @date    01/11/2011
  * @brief   Header for STLM75.c file
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



/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STLM75_H
#define __STLM75_H

#ifdef __cplusplus
 extern "C" {
#endif 
  
/* Includes ------------------------------------------------------------------*/
//#include "stm32l1xx_type.h"
#include "HAL_STLM75.h"

/**
* @addtogroup STLM75
* @{
*/

/* Exported types ------------------------------------------------------------*/

/** @defgroup STLM75_Register_Mapping
  * @{
  */

/** 
* \brief brief STLM75 I2C Slave Address 
*/

/* Exported constants --------------------------------------------------------*/
#define STLM75_ADDRESS         0x90


/**
*  \brief Command register / Address Pointer register
*  \code
*     Write
*     Default value: 0x00
*  `  7:2  0 (bits to be kept to "0" for correct device functionality)
*  `  1:0 P1-P0: Pointer/register Select Bits
*  
*        P1 |P0 | Name | Description      | Width (bits) | Type (R/W) | Default
*        --------------------------------------------------------------------
*         0 | 0 | TEMP | Temperature      |     16       |    R       |    NA
*           |   |      | Register         |
*        ---------------------------------------------------------------------
*         0 | 1 | CONF | Configuration    |     8        |    R/W     |    00
*           |   |      | Register         |
*        ---------------------------------------------------------------------
*         1 | 0 | Thys | Hysteresis       |     16       |    R/W     | 0x4B00
*           |   |      | Register         |
*        --------------------------------------------------------------------- 
*         1 | 1 | Tos  | Over-Temperature |     16       |    R/W     | 0x5000  
*           |   |      | Register         |              |            |
*        ----------------------------------------------------------------------
*
*     The command register retains pointer information between operations. Therefore
*     this register only needs to be update once for consecutive READ oeprations from
*     the same register.
*     We can use the the P1-P0 value of the Command/Pointer register as register address
*   \endcode
*/

/**
*  \brief Temperature register
*  \code
*   Read
*   Default value: NA
*   15 SB: Two's complement Sign Bit
*   14:7 Temperature Data Bits: T14 MSB  -- T7 LSB
*   6:0 RSV: 0
*  \endcode
*/

#define TEMP_REG_ADDR     0x00


/**
*  \brief Configuration register
*  \code
*   Read / Write
*   Default value: 0x00
*   7 RSV: 0
*   6:5 RSV: 0
*   4:3 FT1-FT0: Fault tolerance setting:
*  
*      FT1 | FT0 | STLM75 (Consecutive Faults)
*      ----------------------------------------
*       0  |  0  |        1
*       0  |  1  |        2 
*       1  |  0  |        4
*       1  |  1  |        6
*
*   2: POL: Output Polarity (0 Active Low - 1 Active High)
*   1: M : Thermostat Mode (0 Comparator Mode - 1 Interrupt Mode)
*   0: SD: Shutdown (0 Active Mode -  1 Low Power Mode)
*  \endcode
*/

#define CONF_REG_ADDR     0x01


/**
*  \brief Hysteresis Temperature Register
*  \code
*   Read / Write
*   Default value: 0x4B00 (75 C)
*   15 SB: Two's complement Sign Bit
*   14:7 Temperature Data Bits: T14 MSB  -- T7 LSB
*   6:0 RSV: 0
*  \endcode
*/

#define THYS_REG_ADDR     0x02


/**
*  \brief Over-Limit Temperature Register
*  \code
*   Read / Write
*   Default value: 0x5000 (80 C)
*   15 SB: Two's complement Sign Bit
*   14:7 Temperature Data Bits: T14 MSB  -- T7 LSB
*   6:0 RSV: 0
*  \endcode
*/

#define TOS_REG_ADDR     0x03

/**
 * @}
 */ /* End of STLM75_Register_Mapping */


/**
  * @defgroup STLM75_Configuration_Defines
  *@{
  */

/** 
* \brief Temperature sensitivity 5 d°C/LSB
*/
#define T_Resolution     5



/**
* @brief STLM75 Fault Tolerance 
*/

typedef enum {Fault_Value_1 = 0, Fault_Value_2 = 1, Fault_Value_3 = 2, Fault_Value_4 = 3} Fault_Tolerance_Setting; 

/**
* @brief STLM75 Init structure definition
*/

typedef struct
{
  uint8_t  Mode;  //Comparator Mode or Interrupt Mode
  uint8_t  Polarity; //Active Low or Active High
  Fault_Tolerance_Setting  Fault_Number; //See table 2 STLM75 datasheet
  signed short Over_Limit_Value; //Value expressed in tenth of °C
  signed short Hysteresis_Value; //Value expressed in tenth of °C
}STLM75_InterruptTypeDef;


#define STLM75_Comparator_Mode       ((uint8_t)0x00)
#define STLM75_Interrupt_Mode        ((uint8_t)0x02)
#define STLM75_Polarity_Low          ((uint8_t)0x00)
#define STLM75_Polarity_High         ((uint8_t)0x04)



/**
 * @}
 */ /* End of STLM75_Configuration_Defines */




void STLM75_I2C_Init(void);
void STLM75_INT_Config(void);
void STLM75_Interrupt_Config(STLM75_InterruptTypeDef *STLM75_Interrupt_Struct);
void STLM75_Read_Temperature_Regs(uint8_t* pBuffer);
void STLM75_Read_Raw_Data(signed short* out);
void STLM75_Read_Temperature_Signed(signed short* refvalue);
void STLM75_Lowpower_Cmd(FunctionalState NewState);
void STLM75_Set_Over_Limit(signed short refvalue);
void STLM75_Set_Hysteresis(signed short refvalue);
void STLM75_SetPointer(uint8_t eRegPointer);
void STLM75_Write(uint8_t* pBuffer, uint8_t WriteAddr, uint8_t NumByteToWrite);
int STLM75_Read(uint8_t* pBuffer, uint8_t ReadAddr, uint8_t NumByteToRead);

/**
 * @}
 */ /* End of STLM75 */

#endif /* __STLM75_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
