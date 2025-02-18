#include "PIOControl.h"
#include <iostream>

PIOControl::PIOControl() : out_regValue(0), in_regValue(0) {}

PIOControl::~PIOControl() {
    std::cout << "Closing PIOs..." << std::endl;
}

void PIOControl::WritePIOout(int value) {
    out_regValue = value;
    RegisterWrite(OUT_BASE, out_regValue);
}

int PIOControl::ReadPIOin() {
    return RegisterRead(IN_BASE);
}
