/**
* @file    SDK_EVAL_Timers.c
* @author  VMA division - AMS
* @version 3.2.0
* @date    May 1, 2016
* @brief   SDK EVAL timers configuration.
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
* <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
*/


/* Includes ------------------------------------------------------------------*/
#include "SDK_EVAL_Timers.h"


/**
* @addtogroup SDK_EVAL_NUCLEO
* @{
*/

/**
* @addtogroup SDK_EVAL_Timers
* @{
*/


/**
* @defgroup SDK_EVAL_Timers_Private_TypesDefinitions           SDK EVAL Timers Private Types Definitions
* @{
*/

/**
*@}
*/


/**
* @defgroup SDK_EVAL_Timers_Private_Defines                    SDK EVAL Timers Private Defines
* @{
*/

/**
*@}
*/


/**
* @defgroup SDK_EVAL_Timers_Private_Macros                     SDK EVAL Timers Private Macros
* @{
*/

/**
* @brief  Absolute value macro.
* @param  x: Value on which apply the abs function.
* @retval None
*/
#define ABS(x)  (x>0?x:-x)


/**
*@}
*/

/**
* @defgroup SDK_EVAL_Timers_Private_Variables                  SDK EVAL Timers Private Variables
* @{
*/

volatile uint32_t lSystickCounter=0;

/**
*@}
*/

/**
* @defgroup SDK_EVAL_Timers_Private_FunctionPrototypes         SDK EVAL Timers Private Function Prototypes
* @{
*/

/**
*@}
*/


/**
* @defgroup SDK_EVAL_Timers_Private_Functions                  SDK EVAL Timers Private Functions
* @{
*/



/**
* @brief  Computes two integer value prescaler and period such that Cycles = prescaler * period.
* @param  lCycles the specified cycles for the desired timer value.
* @param  pnPrescaler prescaler factor.
* @param  pnCounter period factor.
* @retval None.
*/
void SdkEvalTimersFindFactors(uint32_t lCycles, uint16_t *pnPrescaler, uint16_t *pnCounter)
{
  uint16_t b0;
  uint16_t a0;
  long err, err_min=lCycles;
  
  *pnPrescaler = a0 = ((lCycles-1)/0xffff) + 1;
  *pnCounter = b0 = lCycles / *pnPrescaler;
  
  for (; *pnPrescaler < 0xffff-1; (*pnPrescaler)++) {
    *pnCounter = lCycles / *pnPrescaler;
    err = (long)*pnPrescaler * (long)*pnCounter - (long)lCycles;
    if (ABS(err) > (*pnPrescaler / 2)) {
      (*pnCounter)++;
      err = (long)*pnPrescaler * (long)*pnCounter - (long)lCycles;
    }
    if (ABS(err) < ABS(err_min)) {
      err_min = err;
      a0 = *pnPrescaler;
      b0 = *pnCounter;
      if (err == 0) break;
    }
  }
  
  *pnPrescaler = a0;
  *pnCounter = b0;
}


/**
* @brief  Configures the specified timer to raise an interrupt every time the counter
*         reaches the nPeriod value counting with a prescaler of nPrescaler.
* @note   The specified timer is configured but not enabled.
* @param  TIM_TimeBaseStructure Timer Handler of the timer to be set.
*          This parameter can be a pointer to @ref TIM_HandleTypeDef .
* @param  nPrescaler prescaler factor.
* @param  nPeriod period factor.
* @retval None.
*/
void SdkEvalTimersTimConfig(TIM_HandleTypeDef* TIM_TimeBaseStructure, uint16_t nPrescaler, uint16_t nPeriod)
{
  TIM_TypeDef *xTim=TIM_TimeBaseStructure->Instance;
  
  /* disable the timer */
  __HAL_TIM_DISABLE(TIM_TimeBaseStructure);
  
  /* Configure the timer in update mode */
  __HAL_TIM_DISABLE_IT(TIM_TimeBaseStructure, TIM_IT_UPDATE);
  
  /* put the timer clock on */
  if(xTim == TIM2) {
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
  else if(xTim==TIM3) {
    __HAL_RCC_TIM3_CLK_ENABLE();
  }
  else if(xTim==TIM4) {
    __HAL_RCC_TIM4_CLK_ENABLE();
  }
  else if(xTim==TIM6) {
    __HAL_RCC_TIM6_CLK_ENABLE();
  }
  else if(xTim==TIM7) {
    __HAL_RCC_TIM7_CLK_ENABLE();
  }
  
  /* Time base configuration */
  TIM_TimeBaseStructure->Init.Prescaler         = nPrescaler;
  TIM_TimeBaseStructure->Init.Period            = nPeriod;
  TIM_TimeBaseStructure->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  TIM_TimeBaseStructure->Init.CounterMode       = TIM_COUNTERMODE_UP;
  
  /* Init the time base structure */
  HAL_TIM_Base_Init(TIM_TimeBaseStructure);
  
  
  /* NVIC configuration */
  if(xTim == TIM2) {
    HAL_NVIC_SetPriority(TIM2_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  }
  else if(xTim == TIM3) {
    HAL_NVIC_SetPriority(TIM3_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  }
  else if(xTim == TIM4) {
    HAL_NVIC_SetPriority(TIM4_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  }
  else if(xTim == TIM6) {
    HAL_NVIC_SetPriority(TIM6_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM6_IRQn);
  }
  else if(xTim == TIM7) {
    HAL_NVIC_SetPriority(TIM7_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM7_IRQn);
  }
  
  /* Clear the timer pending bit */
  __HAL_TIM_CLEAR_FLAG(TIM_TimeBaseStructure, TIM_FLAG_UPDATE);
  
}

#ifdef USE_SYSTICK_DELAY
/**
* @brief  This function handles SysTick Handler.
* @param  None
* @retval None
*/
void SysTick_Handler(void)
{
  lSystickCounter++;
}


/**
* @brief  This function implements return the current
*         systick with a step of 1 ms.
* @param  lTimeMs desired delay expressed in ms.
* @retval None
*/
uint32_t SdkGetCurrentSysTick(void)
{
  return lSystickCounter;
  
}

void SdkStartSysTick(void)
{
  SysTick_Config(32000);
  lSystickCounter = 0;
  
}

/**
* @brief  This function implements a delay using the microcontroller
*         Systick with a step of 1 ms.
* @param  lTimeMs desired delay expressed in ms.
* @retval None
*/
void SdkDelayMs(volatile uint32_t lTimeMs)
{
  uint32_t nWaitPeriod = ~lSystickCounter;
  
  if(nWaitPeriod<lTimeMs) {
    while( lSystickCounter != 0xFFFFFFFF);
    nWaitPeriod = lTimeMs-nWaitPeriod;
  }
  else
    nWaitPeriod = lTimeMs+ ~nWaitPeriod;
  
  while( lSystickCounter != nWaitPeriod ) ;
  
}
#endif
/**
*@}
*/


/**
*@}
*/


/**
*@}
*/


/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
