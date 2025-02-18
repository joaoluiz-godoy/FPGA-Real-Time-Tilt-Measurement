#include "PIOControl.h"
#include <iostream>

PIOControl::PIOControl() : out_regValue(0), in_regValue(0) {}

PIOControl::~PIOControl() {
    std::cout << "Closing PIOs..." << std::endl;
}

void PIOControl::WritePIOout(int value) {
    out_regValue = value;
    
    // Optimized with inline assembly for fast memory-mapped 
    // register writing
    asm volatile (
        "str %1, [%0]"
        :
        : "r" (OUT_BASE), "r" (out_regValue)
        : "memory"
    );
}

int PIOControl::ReadPIOin() {
    return RegisterRead(IN_BASE);
}
