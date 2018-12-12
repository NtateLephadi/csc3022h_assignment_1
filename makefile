CFLAGS = -O
CC = g++

driver: database.h database.o driver.o 
	$(CC) $(CFLAGS) -o driver driver.o database.o --std=c++11

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

database.o: database.cpp
	$(CC) $(CFLAGS) -c database.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o