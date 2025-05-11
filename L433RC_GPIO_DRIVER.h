/*
 * L433RC_GPIO_DRIVER.h
 *
 *  Created on: Jan 28, 2025
 *      Author: xarya
 *
 *  Description:
 *  This header file contains the necessary data structures, function prototypes,
 *  and macros required for interfacing with GPIO peripherals on the STM32L433RC.
 */

#ifndef INC_L433RC_GPIO_DRIVER_H_
#define INC_L433RC_GPIO_DRIVER_H_

#include <L433RC.h>  // MCU-specific definitions for GPIO register mappings

/**
 * @brief GPIO Pin Configuration Structure
 *        Used to configure a specific pin on a GPIO port.
 */
typedef struct {
    uint8_t GPIO_PinNum;        /*!< GPIO pin number (0 to 15). */
    uint8_t GPIO_PinMode;       /*!< Mode: Input, Output, Alternate Function, or Analog. */
    uint8_t GPIO_PinSpeed;      /*!< Speed: Low, Medium, High, Very High. */
    uint8_t GPIO_PinPuPdCtrl;   /*!< Pull-up/Pull-down control: No Pull, Pull-up, Pull-down. */
    uint8_t GPIO_OUTType;       /*!< Output type: Push-Pull or Open-Drain. */
    uint8_t GPIO_PinAltFunMode; /*!< Alternate function number (if used). */
} GPIO_PinConfig_t;

/**
 * @brief GPIO Handle Structure
 *        Encapsulates a GPIO port and associated pin configuration.
 */
typedef struct {
    GPIOx_RegDef_t *pGPIOx;         /*!< Pointer to the base address of GPIO port (e.g., GPIOA, GPIOB). */
    GPIO_PinConfig_t GPIO_PINconfig; /*!< Configuration structure for the GPIO pin. */
} GPIO_Handle_t;

/* ========================================================================== */
/*                         FUNCTION PROTOTYPES                                */
/* ========================================================================== */

/**
 * @brief Enable or disable peripheral clock for the GPIO port.
 * @param pGPIOx: Base address of GPIO port.
 * @param ENorDI: ENABLE (1) or DISABLE (0).
 */
void GPIO_PeriCLockControl(GPIOx_RegDef_t *pGPIOx, uint8_t ENorDI);

/**
 * @brief Initialize GPIO pin using the provided handle structure.
 * @param pGPIOHandle: Pointer to GPIO handle containing configuration.
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

/**
 * @brief Reset all registers of the GPIO port to their default state.
 * @param pGPIOx: Pointer to GPIO port.
 */
void GPIO_DeInit(GPIOx_RegDef_t *pGPIOx);

/* ========================================================================== */
/*                         DATA READ & WRITE FUNCTIONS                        */
/* ========================================================================== */

/**
 * @brief Read the logic level (0 or 1) of a specific GPIO input pin.
 * @param pGPIOx: Pointer to GPIO port.
 * @param PinNum: Pin number (0–15).
 * @return Logic level: 0 = LOW, 1 = HIGH.
 */
uint8_t GPIO_Read_InputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNum);

/**
 * @brief Read the input value of all 16 pins on a port at once.
 * @param pGPIOx: Pointer to GPIO port.
 * @return 16-bit value representing input pin states.
 */
uint16_t GPIO_Read_InputPort(GPIOx_RegDef_t *pGPIOx);

/**
 * @brief Write a HIGH (1) or LOW (0) value to a GPIO output pin.
 * @param pGPIOx: Pointer to GPIO port.
 * @param PinNum: Pin number to write.
 * @param value: Desired logic level.
 */
void GPIO_Write_OutputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNum, uint8_t value);

/**
 * @brief Write a full 16-bit value to all pins of a GPIO output port.
 * @param pGPIOx: Pointer to GPIO port.
 * @param value: 16-bit output value.
 */
void GPIO_Write_OutputPort(GPIOx_RegDef_t *pGPIOx, uint8_t value);

/**
 * @brief Toggle (invert) the current state of a specific GPIO output pin.
 * @param pGPIOx: Pointer to GPIO port.
 * @param PinNum: Pin number to toggle.
 */
void GPIO_Toggle_OutputPIn(GPIOx_RegDef_t *pGPIOx, uint8_t PinNum);

/* ========================================================================== */
/*                         INTERRUPT HANDLING FUNCTIONS                       */
/* ========================================================================== */

/**
 * @brief Configure interrupt settings for a GPIO pin.
 * @param IRQnumber: IRQ number associated with the pin.
 * @param IRQPriority: Priority level (lower = higher priority).
 * @param ENorDI: ENABLE (1) or DISABLE (0) the IRQ.
 */
void GPIO_IRQ_Config(uint8_t IRQnumber, uint8_t IRQPriority, uint8_t ENorDI);

/**
 * @brief Handle the interrupt for a GPIO pin (clear pending, execute ISR).
 * @param PinNum: Pin number that triggered the interrupt.
 */
void GPIO_IRQ_Handeling(uint8_t PinNum);

#endif /* INC_L433RC_GPIO_DRIVER_H_ */
