GCC = g++
CFLAGS = -g -Wall
OBJS = DE1SoChps.o DE1SoCfpga.o PIOControl.o GSensor.o GSensorMain.o

SW_project: $(OBJS)
	$(GCC) $(OBJS) -o SW_project

DE1SoChps.o: DE1SoChps.cpp DE1SoChps.h
	$(GCC) $(CFLAGS) -c DE1SoChps.cpp

DE1SoCfpga.o: DE1SoCfpga.cpp DE1SoCfpga.h
	$(GCC) $(CFLAGS) -c DE1SoCfpga.cpp

PIOControl.o: PIOControl.cpp PIOControl.h
	$(GCC) $(CFLAGS) -c PIOControl.cpp

GSensor.o: GSensor.cpp GSensor.h
	$(GCC) $(CFLAGS) -c GSensor.cpp

GSensorMain.o: GSensorMain.cpp GSensor.h PIOControl.h
	$(GCC) $(CFLAGS) -c GSensorMain.cpp

clean:
	rm -f $(OBJS) SW_project
