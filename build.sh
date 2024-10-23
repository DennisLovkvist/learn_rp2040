arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -o main.o -c main.c
arm-none-eabi-as -mcpu=cortex-m0plus -mthumb -o startup.o startup.S
arm-none-eabi-ld -T rp2040.ld -o firmware.elf main.o startup.o
arm-none-eabi-objcopy -O binary firmware.elf firmware.uf2
cp firmware.uf2 /mnt/rp2040