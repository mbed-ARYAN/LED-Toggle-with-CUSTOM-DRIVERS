/*
 * L433RC MCU Peripheral Definitions and Macros
 * This header file provides the base addresses, register structures,
 * clock enable/disable macros, and reset macros for GPIO, RCC, and peripheral modules.
 *
 * Target: STM32L433RC
 * Author: [Your Name]
 * Date: [Date]
 */

#ifndef INC_L433RC_H_
#define INC_L433RC_H_

#include <stdio.h>
#include <stdint.h>

// Define shorthand for volatile keyword
#define __vol volatile

/*************************************************************
 *                      GPIO Reset Macros                    *
 *************************************************************/
#define GPIOA_REG_RESET()  do{(RCC->AHB2RSTR |= (1<<0));  (RCC->AHB2RSTR &= ~(1<<0));}while(0) // Reset GPIOA
#define GPIOB_REG_RESET()  do{(RCC->AHB2RSTR |= (1<<1));  (RCC->AHB2RSTR &= ~(1<<1));}while(0) // Reset GPIOB
#define GPIOC_REG_RESET()  do{(RCC->AHB2RSTR |= (1<<2));  (RCC->AHB2RSTR &= ~(1<<2));}while(0) // Reset GPIOC
#define GPIOD_REG_RESET()  do{(RCC->AHB2RSTR |= (1<<3));  (RCC->AHB2RSTR &= ~(1<<3));}while(0) // Reset GPIOD

/*************************************************************
 *                      Generic Macros                       *
 *************************************************************/
#define ENABLE 1           // Enable state
#define DISABLE 0          // Disable state
#define SET ENABLE         // Set macro alias
#define RESET DISABLE      // Reset macro alias
#define GPIO_PIN_SET SET   // GPIO pin set alias
#define GPIO_PIN_RESET RESET // GPIO pin reset alias

/*************************************************************
 *                     GPIO Mode Macros                      *
 *************************************************************/
#define GPIO_MODE_IN 0       // Input mode
#define GPIO_MODE_OUT 1      // Output mode
#define GPIO_MODE_ALT 2      // Alternate function mode
#define GPIO_MODE_ANALOG 3   // Analog mode
#define GPIO_MODE_IT_FT 4    // Interrupt falling trigger
#define GPIO_MODE_IT_RT 5    // Interrupt rising trigger
#define GPIO_MODE_IT_RFT 6   // Interrupt rising/falling trigger

/*************************************************************
 *               GPIO Output Type and Speed Macros           *
 *************************************************************/
#define GPIO_OUT_PP 0       // Push-pull output
#define GPIO_OUT_OD 1       // Open-drain output
#define GPIO_SPEED_LOW 0    // Low speed
#define GPIO_SPEED_MEDIUM 1 // Medium speed
#define GPIO_SPEED_FAST 2   // Fast speed
#define GPIO_SPEED_HIGH 3   // High speed

/*************************************************************
 *                GPIO Pull-up/Pull-down Macros              *
 *************************************************************/
#define GPIO_NO_PUPD 0     // No pull-up/pull-down
#define GPIO_PIN_PU 1      // Pull-up
#define GPIO_PIN_PD 2      // Pull-down

/*************************************************************
 *                    GPIO Pin Number Macros                 *
 *************************************************************/
#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

/*************************************************************
 *                Memory Base Addresses                      *
 *************************************************************/
#define FLASH_BASEADD   0x08000000U // Flash memory base
#define SRAM1_BASEADD   0x20000000U // SRAM1 base
#define SRAM2_BASEADD   0x10000000U // SRAM2 base
#define ROM_BASEADD     0x1FFF0000U // ROM base
#define SRAM            SRAM1_BASEADD // General SRAM alias

/*************************************************************
 *           Peripheral Bus Base Addresses                   *
 *************************************************************/
#define PERI_BASE       0x40000000U // Base for all peripherals
#define APB1PERI_BASE   PERI_BASE   // APB1 peripheral base
#define APB2PERI_BASE   0x40010000U // APB2 peripheral base
#define AHB1PERI_BASE   0x40020000U // AHB1 peripheral base
#define AHB2PERI_BASE   0x48000000U // AHB2 peripheral base
#define RCC_BASEADD     (AHB1PERI_BASE + 0x1000) // RCC base address

/*************************************************************
 *       Base Addresses of GPIO Peripherals (AHB2 Bus)       *
 *************************************************************/
#define GPIOA_BASEADD   (AHB2PERI_BASE + 0x0000) // GPIOA base
#define GPIOB_BASEADD   (AHB2PERI_BASE + 0x0400) // GPIOB base
#define GPIOC_BASEADD   (AHB2PERI_BASE + 0x0800) // GPIOC base
#define GPIOD_BASEADD   (AHB2PERI_BASE + 0x0C00) // GPIOD base
#define GPIOE_BASEADD   (AHB2PERI_BASE + 0x10000) // GPIOE base

/*************************************************************
 *      Base Addresses of Other Peripherals (APBx)           *
 *************************************************************/
#define SPI2_BASEADD    (APB1PERI_BASE + 0x3800) // SPI2 base
#define SPI3_BASEADD    (APB1PERI_BASE + 0x3C00) // SPI3 base
#define I2C1_BASEADD    (APB1PERI_BASE + 0x5400) // I2C1 base
#define I2C2_BASEADD    (APB1PERI_BASE + 0x5800) // I2C2 base
#define I2C3_BASEADD    (APB1PERI_BASE + 0x5C00) // I2C3 base
#define USART2_BASEADD  (APB1PERI_BASE + 0x4400) // USART2 base
#define USART3_BASEADD  (APB1PERI_BASE + 0x4800) // USART3 base
#define SPI1_BASEADD    (APB2PERI_BASE + 0x3000) // SPI1 base
#define USART1_BASEADD  (APB2PERI_BASE + 0x3800) // USART1 base
#define EXT1_BASEADD    (APB2PERI_BASE + 0x0400) // EXTI base

/*************************************************************
 *               GPIO Register Definition Structure          *
 *************************************************************/
typedef struct {
    __vol uint32_t MODER;     // Mode register
    __vol uint32_t OTYPER;    // Output type register
    __vol uint32_t OSPEEDR;   // Output speed register
    __vol uint32_t PUPDR;     // Pull-up/pull-down register
    __vol uint32_t IDR;       // Input data register
    __vol uint32_t ODR;       // Output data register
    __vol uint32_t BSRR;      // Bit set/reset register
    __vol uint32_t LCKR;      // Lock register
    __vol uint32_t AFR[2];    // Alternate function registers
    __vol uint32_t BRR;       // Bit reset register
} GPIOx_RegDef_t;

/*************************************************************
 *               RCC Register Definition Structure           *
 *************************************************************/
typedef struct {
    __vol uint32_t CR, ICSCR, CFGR, PLLCFGR, PLLSAI1CFGR, null1;          // Clock control
    __vol uint32_t CIER, CIFR, CICR, null2;                               // Clock interrupt
    __vol uint32_t AHB1RSTR, AHB2RSTR, AHB3RSTR, null3;                   // Reset registers
    __vol uint32_t APB1RSTR1, APB1RSTR2, APB2RSTR, null4;                 // Peripheral resets
    __vol uint32_t RCC_AHB1ENR, AHB2ENR, AHB3ENR, null5;                  // Clock enable
    __vol uint32_t APB1ENR1, APB1ENR2, APB2ENR, null6;                    // More enables
    __vol uint32_t AHB1SMENR, AHB2SMENR, AHB3SMENR, null7;                // Sleep mode enables
    __vol uint32_t APB1SMENR1, APB1SMENR2, APB2SMENR, null8;              // Sleep mode cont.
    __vol uint32_t CCIPR, null9, BDCR, CSR, CRRCR, CCIPR2;                // Clock config
} RCC_RegDef_t;

/*************************************************************
 *                  GPIO Peripheral Definitions              *
 *************************************************************/
#define GPIOA  ((GPIOx_RegDef_t*)GPIOA_BASEADD) // GPIOA pointer
#define GPIOB  ((GPIOx_RegDef_t*)GPIOB_BASEADD) // GPIOB pointer
#define GPIOC  ((GPIOx_RegDef_t*)GPIOC_BASEADD) // GPIOC pointer
#define GPIOD  ((GPIOx_RegDef_t*)GPIOD_BASEADD) // GPIOD pointer
#define GPIOE  ((GPIOx_RegDef_t*)GPIOE_BASEADD) // GPIOE pointer

/*************************************************************
 *                      RCC Peripheral Definition            *
 *************************************************************/
#define RCC    ((RCC_RegDef_t*)RCC_BASEADD) // RCC pointer

/*************************************************************
 *        Clock Enable Macros for GPIO peripherals           *
 *************************************************************/
#define GPIOA_PCLK_EN()  (RCC->AHB2ENR |= (1 << 0)) // Enable GPIOA clock
#define GPIOB_PCLK_EN()  (RCC->AHB2ENR |= (1 << 1)) // Enable GPIOB clock
#define GPIOC_PCLK_EN()  (RCC->AHB2ENR |= (1 << 2)) // Enable GPIOC clock
#define GPIOD_PCLK_EN()  (RCC->AHB2ENR |= (1 << 3)) // Enable GPIOD clock
#define GPIOE_PCLK_EN()  (RCC->AHB2ENR |= (1 << 4)) // Enable GPIOE clock

#define I2C1_PCLK_EN()   (RCC->APB1ENR1 |= (1 << 21)) // Enable I2C1 clock
#define I2C2_PCLK_EN()   (RCC->APB1ENR1 |= (1 << 22)) // Enable I2C2 clock
#define I2C3_PCLK_EN()   (RCC->APB1ENR1 |= (1 << 23)) // Enable I2C3 clock

#define SPI1_PCLK_EN()   (RCC->APB2ENR |= (1 << 12)) // Enable SPI1 clock
#define SPI2_PCLK_EN()   (RCC->APB1ENR1 |= (1 << 14)) // Enable SPI2 clock
#define SPI3_PCLK_EN()   (RCC->APB1ENR1 |= (1 << 15)) // Enable SPI3 clock

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 14)) // Enable USART1 clock
#define USART2_PCLK_EN() (RCC->APB1ENR1 |= (1 << 17)) // Enable USART2 clock
#define USART3_PCLK_EN() (RCC->APB1ENR1 |= (1 << 18)) // Enable USART3 clock

/*************************************************************
 *        Clock Disable Macros for GPIO peripherals           *
 *************************************************************/


#define GPIOA_PCLK_DI()  (RCC->AHB2ENR &= ~(1 << 0)) // Disable GPIOA clock
#define GPIOB_PCLK_DI()  (RCC->AHB2ENR &= ~(1 << 1)) // Disable GPIOB clock
#define GPIOC_PCLK_DI()  (RCC->AHB2ENR &= ~(1 << 2)) // Disable GPIOC clock
#define GPIOD_PCLK_DI()  (RCC->AHB2ENR &= ~(1 << 3)) // Disable GPIOD clock
#define GPIOE_PCLK_DI()  (RCC->AHB2ENR &= ~(1 << 4)) // Disable GPIOE clock

#define I2C1_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 21)) // Disable I2C1 clock
#define I2C2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 22)) // Disable I2C2 clock
#define I2C3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 23)) // Disable I2C3 clock

#define SPI1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 12)) // Disable SPI1 clock
#define SPI2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 14)) // Disable SPI2 clock
#define SPI3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 15)) // Disable SPI3 clock

#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 14)) // Disable USART1 clock
#define USART2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 17)) // Disable USART2 clock
#define USART3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 18)) // Disable USART3 clock


// Include the GPIO driver header for further abstraction
#include <L433RC_GPIO_DRIVER.h>

#endif /* INC_L433RC_H_ */
