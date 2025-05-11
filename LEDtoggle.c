#include <stdint.h>
#include <stdio.h>
#include <L433RC.h>
#include <L433RC_GPIO_DRIVER.h>

void delay() {
    for(volatile uint32_t i = 0; i < 600000; i++);
}

int main(void) {

    GPIO_Handle_t LED;

    LED.pGPIOx = GPIOB;
    LED.GPIO_PINconfig.GPIO_PinMode = GPIO_MODE_OUT;
    LED.GPIO_PINconfig.GPIO_PinNum = GPIO_PIN_13;
    LED.GPIO_PINconfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    LED.GPIO_PINconfig.GPIO_OUTType = GPIO_OUT_PP;
    LED.GPIO_PINconfig.GPIO_PinPuPdCtrl = GPIO_NO_PUPD;

    GPIO_PeriCLockControl(GPIOB, ENABLE);
    GPIO_Init(&LED);

    while(1) {
        GPIO_Toggle_OutputPin(GPIOB, GPIO_PIN_13);
        delay();
    }

    return 0;
}
