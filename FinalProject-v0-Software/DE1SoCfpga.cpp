#include "DE1SoCfpga.h"

DE1SoCfpga::DE1SoCfpga() {
    // Constructor implementation
    fd = open("/dev/mem", (O_RDWR | O_SYNC));
    if (fd == -1) {
        std::cerr << "ERROR: could not open /dev/mem..." << std::endl;
        exit(1);
    }
    pBase = (char *)mmap(NULL, LW_BRIDGE_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, LW_BRIDGE_BASE);
    if (pBase == MAP_FAILED) {
        std::cerr << "ERROR: mmap() failed..." << std::endl;
        close(fd);
        exit(1);
    }
}

DE1SoCfpga::~DE1SoCfpga() {
    // Destructor implementation
    if (munmap(pBase, LW_BRIDGE_SPAN) != 0) {
        std::cerr << "ERROR: munmap() failed..." << std::endl;
        exit(1);
    }
    close(fd);
}

void DE1SoCfpga::RegisterWrite(unsigned int offset, int value) {
    // RegisterWrite implementation
    *reinterpret_cast<volatile unsigned int *>(pBase + offset) = value;
}

int DE1SoCfpga::RegisterRead(unsigned int offset) {
    // RegisterRead implementation
    return *reinterpret_cast<volatile unsigned int *>(pBase + offset);
}