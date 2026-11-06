#include <stdint.h>
#include <stdio.h>

enum {
    CONTROL_ENABLE = 1 << 0,
    CONTROL_INTERRUPT_ENABLE = 1 << 1
};

static volatile int simulated_control_register;

static void write_register(uintptr_t address, int value)
{
    *(volatile int *)address = value;
}

int main(void)
{
    uintptr_t address = (uintptr_t)&simulated_control_register;
    int value = CONTROL_ENABLE | CONTROL_INTERRUPT_ENABLE;

    printf("Register before write: 0x%08x\n",
           (unsigned int)simulated_control_register);

    write_register(address, value);

    printf("Register after write:  0x%08x\n",
           (unsigned int)simulated_control_register);
    printf("Device enabled:        %s\n",
           (simulated_control_register & CONTROL_ENABLE) ? "yes" : "no");
    printf("Interrupts enabled:    %s\n",
           (simulated_control_register & CONTROL_INTERRUPT_ENABLE) ? "yes" : "no");

    return 0;
}
