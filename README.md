
# 🔌 STM32L433RC LED Toggle Using Custom Driver (STM32CubeIDE)

This project shows how to **blink an LED** using a **custom GPIO driver** (written from scratch) on the **STM32L433RC** microcontroller.  
It's built using **STM32CubeIDE**, without HAL or LL libraries — only **register-level programming** with CMSIS.

---

## 📦 What This Project Includes

✅ LED blinking on GPIO pin **PC13**  
✅ Fully custom GPIO driver (no HAL, no LL)  
✅ STM32CubeIDE-ready project  
✅ Clean and minimal code structure  
✅ Beginner-friendly for learning low-level STM32 programming

---

## 🧰 Tools Needed

- **STM32CubeIDE** (latest version)
- **STM32L433RC board**
- **ST-Link V2** (for programming)
- USB cable and basic breadboard (if using external LED)

---

## 🔧 How to Run (Step-by-Step)

### 1. Clone or Download the Project


git clone https://github.com/mbed-ARYAN/LED-Toggle-with-CUSTOM-DRIVERS.git
Or download as ZIP and extract it.

2. Open in STM32CubeIDE
Open STM32CubeIDE

Go to File > Open Projects from File System

Select the folder you cloned/extracted

Click Finish to import

3. Connect Your Board
Plug in your STM32L433RC with ST-Link

Make sure it’s detected in CubeIDE (top right: ST-LINK should show up)

4. Build the Project
Click on the hammer icon 🔨 or press Ctrl + B

5. Flash the MCU
Click the green bug icon 🐞 or press F11

This will compile, flash, and start running the code

💡 What Happens
gpio_driver.c/h contains your custom GPIO functions

main.c uses that driver to blink an LED on PC13

LED turns ON and OFF with delay — repeated forever

🔩 Example Code (main.c)
c
Copy
Edit
GPIO_Init(GPIOC, 13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_OTYPE_PP);

while (1) {
    GPIO_TogglePin(GPIOC, 13);        // Toggle LED on PC13
    for (volatile int i = 0; i < 100000; i++);  // Simple delay
}
🧠 Learnings from This Project
Setup GPIO manually using registers (MODER, OTYPER, etc.)

Understand how peripheral registers work (CMSIS)

Build reusable, clean driver code

Get started with bare-metal STM32 programming

📚 References
STM32L433 Reference Manual: RM0394

STM32L433 Datasheet: DS11015

CMSIS Docs: CMSIS GitHub

✍️ Author
Aryan (@mbed-ARYAN)
👉 Learning Embedded Systems with Real Drivers
📍 GitHub: https://github.com/mbed-ARYAN

📄 License
MIT License — free to use, learn, and share. ⭐
