// Define hardware register addresses for RP2040
#define SIO_BASE        0xD0000000
#define GPIO_OUT_REG    (SIO_BASE + 0x10)   // GPIO output register
#define GPIO_OUT_SET    (SIO_BASE + 0x14)   // GPIO output set register
#define GPIO_OUT_CLR    (SIO_BASE + 0x18)   // GPIO output clear register

#define GPIO_CTRL_BASE  0x40014000
#define GPIO_OE_REG     (SIO_BASE + 0x20)    // GPIO output enable register
#define GPIO0_CTRL      (GPIO_CTRL_BASE + 0xC0)  // Control register for GPIO 0

// Function to create a simple delay
void delay(volatile unsigned int count) {
    while (count--) { __asm__("nop"); } // Do nothing for 'count' iterations
}

int main() {
    // Set GPIO 0 as SIO (function = 5)
    *((volatile unsigned int *) GPIO0_CTRL) = 5;  
    // Enable GPIO 0 as an output
    *((volatile unsigned int *) GPIO_OE_REG) |= (1 << 0);  

    while (1) {
        // Turn GPIO 0 ON (LED on)
        *((volatile unsigned int *) GPIO_OUT_SET) = (1 << 0);  
        delay(1000000);  // Delay to keep LED on
        
        // Turn GPIO 0 OFF (LED off)
        *((volatile unsigned int *) GPIO_OUT_CLR) = (1 << 0);  
        delay(1000000);  // Delay to keep LED off
    }

    return 0;
}
