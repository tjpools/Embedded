# Volatile Register Write Demo

This project demonstrates the embedded C statement:

```c
*(volatile int *)address = value;
```

The program uses a normal variable as a safe stand-in for a memory-mapped
hardware control register. Its address is converted to `uintptr_t`, passed to
`write_register`, converted back to `volatile int *`, and written through the
pointer.

## Build and run

```sh
make
make run
```

Expected output:

```text
Register before write: 0x00000000
Register after write:  0x00000003
Device enabled:        yes
Interrupts enabled:    yes
```

## Mapping this to embedded hardware

In actual firmware, `address` would commonly be a memory-mapped peripheral
register address supplied by the microcontroller documentation:

```c
#include <stdint.h>

uintptr_t address = 0x40001000u;
uint32_t value = 0x00000003u;

*(volatile uint32_t *)address = value;
```

Do not run that version on a desktop computer. An arbitrary address is usually
unmapped and accessing it can terminate the program. On embedded hardware, use
the exact register address and width documented by the device vendor. A
fixed-width type such as `uint32_t` is normally preferable to `int` for a real
register.

`volatile` ensures that the compiler emits the access, but it does not by
itself provide atomicity, synchronization, or a hardware memory barrier.
