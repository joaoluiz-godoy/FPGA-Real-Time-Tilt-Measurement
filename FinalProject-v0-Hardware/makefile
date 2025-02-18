C = g++
CFLAGS = -g -Wall
OBJS = DE1SoChps.o GSensor.o GSensorMain.o

lab_project: $(OBJS)
	$(GCC) $(OBJS) -o lab_project

DE1SoChps.o: DE1SoChps.cpp
	$(GCC) $(CFLAGS) -c DE1SoChps.cpp

GSensor.o: GSensor.cpp
	$(GCC) $(CFLAGS) -c GSensor.cpp

GSensorMain.o: GSensorMain.cpp
	$(GCC) $(CFLAGS) -c GSensorMain.cpp

clean:
	rm $(OBJS) lab_project
