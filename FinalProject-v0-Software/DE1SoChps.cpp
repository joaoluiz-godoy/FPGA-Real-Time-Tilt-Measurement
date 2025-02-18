#include "DE1SoChps.h"
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdlib>

const unsigned int DE1SoChps::HPS_BRIDGE_BASE = 0xFF700000; // Adjust as necessary
const unsigned int DE1SoChps::HPS_BRIDGE_SPAN = 0x006FFFFF; // Adjust as necessary
const unsigned int DE1SoChps::I2C0_BASE = 0x00504000;

const unsigned int DE1SoChps::I2C0_CON = 0x00504000;
const unsigned int DE1SoChps::I2C0_TAR = 0x00504004;
const unsigned int DE1SoChps::I2C0_DATA_CMD = 0x00504010;
const unsigned int DE1SoChps::I2C0_FS_SCL_HCNT = 0x0050401C;
const unsigned int DE1SoChps::I2C0_FS_SCL_LCNT = 0x00504020;
   
const unsigned int DE1SoChps::I2C0_CLKR_INTR = 0x00504040;
const unsigned int DE1SoChps::I2C0_ENABLE = 0x0050406C;
const unsigned int DE1SoChps::I2C0_TXFLR = 0x00504074;
const unsigned int DE1SoChps::I2C0_RXFLR = 0x00504078;
const unsigned int DE1SoChps::I2C0_ENABLE_STATUS = 0x0050409C;
   
const unsigned int DE1SoChps::PIN_MUX_GEN_IO7 = 0x0060849C;
const unsigned int DE1SoChps::PIN_MUX_GEN_IO8 = 0x006084A0;
const unsigned int DE1SoChps::PIN_MUX_GPLMUX55 = 0x006086B0;
const unsigned int DE1SoChps::PIN_MUX_GPLMUX56 = 0x006086B4;
const unsigned int DE1SoChps::PIN_MUX_I2C0USEFPGA = 0x00608704;

DE1SoChps::DE1SoChps() {
    fd = open("/dev/mem", (O_RDWR | O_SYNC));
    if (fd == -1) {
        std::cerr << "ERROR: could not open /dev/mem..." << std::endl;
        exit(1);
    }

    pBase = (char *)mmap(NULL, HPS_BRIDGE_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, HPS_BRIDGE_BASE);
    if (pBase == MAP_FAILED) {
        std::cerr << "ERROR: mmap() failed..." << std::endl;
        close(fd);
        exit(1);
    }
}

DE1SoChps::~DE1SoChps() {
    if (munmap(pBase, HPS_BRIDGE_SPAN) != 0) {
        std::cerr << "ERROR: munmap() failed..." << std::endl;
        exit(1);
    }
    close(fd);
}

void DE1SoChps::RegisterWrite(unsigned int offset, int value) {
    *reinterpret_cast<volatile unsigned int *>(pBase + offset) = value;
}

int DE1SoChps::RegisterRead(unsigned int offset) {
    return *reinterpret_cast<volatile unsigned int *>(pBase + offset);
}
