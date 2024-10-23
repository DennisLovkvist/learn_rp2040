.global _start
_start:
    ldr r0, =_estack     // Load the stack address into r0
    mov sp, r0           // Set stack pointer (sp) to the value in r0
    bl main              // Call main
    b .                  // Infinite loop if main returns

_estack = 0x20040000     // Top of 256KB RAM for RP2040
