/**
  ******************************************************************************
  * @file    HALL_F30X_SpeednPosFdbkClass.h
  * @author  STMicroelectronics - System Lab - MC Team
  * @version 4.2.0
  * @date    20-Aug-2015 18:06
  * @brief   This file contains interface of HALL class specifically designed 
  *          for STM32F30x microcontrollers.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HALL_F30X_SPEEDNPOSFDBKCLASS_H
#define __HALL_F30X_SPEEDNPOSFDBKCLASS_H

#define GPIO_NoRemap_TIMx ((uint32_t)(0))

/* HALL SENSORS PLACEMENT ----------------------------------------------------*/
#define	DEGREES_120 0u
#define	DEGREES_60 1u

/** @addtogroup STM32_PMSM_MC_Library
  * @{
  */
  
/** @addtogroup SpeednPosFdbk_HALL_F30X
  * @{
  */

/** @defgroup HALL_F30X_class_exported_types HALL_F30X class exported types
* @{
*/

/** 
  * @brief  Public HALL_F30X class definition
  */
typedef struct CHALL_F30X_SPD_t *CHALL_F30X_SPD;

/** 
  * @brief  HALL_F30X class parameters definition
  */
typedef const struct
{
  /* SW Settings */
  uint8_t IRQnb;        /*!< MC IRQ number used for TIMx capture update event.*/

  uint8_t bSensorPlacement; /*!< Define here the mechanical position of the sensors 
                             with reference to an electrical cycle.
                             Allowed values are: DEGREES_120 or DEGREES_60.*/
  
  int16_t hPhaseShift;  /*!< Define here in s16degree the electrical phase shift 
                             between the low to high transition of signal H1 and
                             the maximum of the Bemf induced on phase A.*/
  
  uint16_t hSpeedSamplingFreqHz; /*!< Frequency (Hz) at which motor speed is to 
                             be computed. It must be equal to the frequency
                             at which function SPD_CalcAvrgMecSpeed01Hz
                             is called.*/
  
  uint8_t bSpeedBufferSize; /*!< Size of the buffer used to calculate the average 
                             speed. It must be less than 18.*/
  
  uint16_t hInpCaptFilter;  /*!< Time filter applied to validate HALL sensor capture.
                             This value defines the frequency used to sample 
                             HALL sensors input and the length of the digital
                             filter applied. The digital filter is made of an 
                             event counter in which N events are needed to 
                             validate a transition on the input.
                                0000: No filter, sampling is done at fCK_INT.
                                0001: fSAMPLING=fCK_INT , N=2. 
                                0010: fSAMPLING=fCK_INT , N=4.
                                0011: fSAMPLING=fCK_INT , N=8. 
                                0100: fSAMPLING=fCK_INT/2, N=6.
                                0101: fSAMPLING=fCK_INT/2, N=8.
                                0110: fSAMPLING=fCK_INT/4, N=6.
                                0111: fSAMPLING=fCK_INT/4, N=8.
                                1000: fSAMPLING=fCK_INT/8, N=6.
                                1001: fSAMPLING=fCK_INT/8, N=8.
                                1010: fSAMPLING=fCK_INT/16, N=5.
                                1011: fSAMPLING=fCK_INT/16, N=6.
                                1100: fSAMPLING=fCK_INT/16, N=8.
                                1101: fSAMPLING=fCK_INT/32, N=5.
                                1110: fSAMPLING=fCK_INT/32, N=6.
                                1111: fSAMPLING=fCK_INT/32, N=8 */
								
  /* HW Settings */
  uint32_t wTIMClockFreq; /*!< Timer clock frequency express in Hz.*/

  TIM_TypeDef* TIMx;    /*!< Timer used for HALL sensor management.*/
  
  uint32_t RCC_APB1Periph_TIMx; 
                        /*!< RCC Clock related to timer TIMx. 
                             (Ex. RCC_APB1Periph_TIM2).*/
  
  uint8_t TIMx_IRQChannel; 
                        /*!< IRQ Channle related to TIMx. 
                             (Ex. TIM2_IRQChannel).*/
  
  uint32_t wTIMxRemapping; 
                        /*!< It remaps TIMx outputs. It must equal to 
                             GPIO_PartialRemap_TIMx, GPIO_FullRemap_TIMx or 
                             GPIO_NoRemap_TIMx according the HW availability.*/
  
  GPIO_TypeDef* hH1Port; 
                        /*!< HALL sensor H1 channel GPIO input port (if used, 
                             after re-mapping). It must be GPIOx x= A, B, ...*/
  
  uint16_t hH1Pin;      /*!< HALL sensor H1 channel GPIO output pin (if used, 
                             after re-mapping). It must be GPIO_Pin_x x= 0, 1, 
                             ...*/
  
  GPIO_TypeDef* hH2Port; 
                        /*!< HALL sensor H2 channel GPIO input port (if used, 
                             after re-mapping). It must be GPIOx x= A, B, ...*/
  
  uint16_t hH2Pin;      /*!< HALL sensor H2 channel GPIO output pin (if used, 
                             after re-mapping). It must be GPIO_Pin_x x= 0, 1, 
                             ...*/
  
  GPIO_TypeDef* hH3Port; 
                        /*!< HALL sensor H3 channel GPIO input port (if used, 
                             after re-mapping). It must be GPIOx x= A, B, ...*/
  
  uint16_t hH3Pin;      /*!< HALL sensor H3 channel GPIO output pin (if used, 
                             after re-mapping). It must be GPIO_Pin_x x= 0, 1, 
                             ...*/
/* Alternate functions definition --------------------------------------------*/
  uint8_t bH1AF;        /*!< HALL sensor H1 alternate 
                             functions setting. It must be one
                             of the GPIO_AF_x (x=0,1, ...) 
                             according to the defined GPIO port 
                             and pin.*/
  uint8_t bH2AF;        /*!< HALL sensor H2 alternate 
                             functions setting. It must be one
                             of the GPIO_AF_x (x=0,1, ...) 
                             according to the defined GPIO port 
                             and pin.*/
  uint8_t bH3AF;        /*!< HALL sensor H3 alternate 
                             functions setting. It must be one
                             of the GPIO_AF_x (x=0,1, ...) 
                             according to the defined GPIO port 
                             and pin.*/
} HALL_F30XParams_t, *pHALL_F30XParams_t;
/**
  * @}
  */

/** @defgroup HALL_F30X_class_exported_methods HALL_F30X class exported methods
  * @{
  */
  
/**
  * @brief  Creates an object of the class HALL_F30X
  * @param  pSpeednPosFdbkParams pointer to an SpeednPosFdbk parameters structure
  * @param  pHALL_F30XParams pointer to an HALL_F30X parameters structure
  * @retval CHALL_F30X_SPD new instance of HALL_F30X object
  */
CHALL_F30X_SPD HALL_F30X_NewObject(pSpeednPosFdbkParams_t pSpeednPosFdbkParams,
                                   pHALL_F30XParams_t pHALLParams);

/**
  * @}
  */
  
/**
  * @}
  */

/**
  * @}
  */

#endif /*__HALL_F30X_SPEEDNPOSFDBKCLASS_H*/

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
