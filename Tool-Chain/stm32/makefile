CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MACH) -mthumb

MACH = cortex-m4

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@  
	