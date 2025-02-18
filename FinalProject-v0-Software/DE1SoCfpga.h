#ifndef DE1SOCFPGA_H
#define DE1SOCFPGA_H

#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdlib>

// Define the base address, span, and offsets as constants here
const unsigned int LW_BRIDGE_BASE = 0xFF200000;
const unsigned int LW_BRIDGE_SPAN = 0x00005000;

// Define your PIO offsets here
const unsigned int OUT_BASE = 0x00000020; // PIO output
const unsigned int IN_BASE = 0x00000040;  // PIO input

class DE1SoCfpga {
public:
    DE1SoCfpga(); // Constructor
    ~DE1SoCfpga(); // Destructor

    void RegisterWrite(unsigned int offset, int value);
    int RegisterRead(unsigned int offset);

protected:
    char *pBase;
    int fd;
};

#endif // DE1SOCFPGA_H

