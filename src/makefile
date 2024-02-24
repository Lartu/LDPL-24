OBJS = ldpl.o
SOURCE = ldpl.cpp
HEADER = ldpl.h nvm.h cpptrim.h
OUT = ldpl
CC = c++
FLAGS = -g -c -Wall -std=c++03
#LFLAGS = -static-libgcc -static-libstdc++

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	rm ldpl.o

ldpl.o: ldpl.cpp
	$(CC) $(FLAGS) ldpl.cpp -fpermissive -DVERSION='"0.1 (AU 2024)"' -DCOMPILEDATE='"$(shell date)"' -DSTANDARD=11


clean:
	rm -f $(OBJS) $(OUT)
