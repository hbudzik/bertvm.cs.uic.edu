
CC=gcc

FLAGS=-Wall

llist.o:  list.h llist.c
	$(CC) $(FLAGS) -c llist.c

sq_slow.o: llist.o sq.h sq_slow.c
	$(CC) $(FLAGS) -c sq_slow.c

driver: driver.c sq_slow.o 
	$(CC) $(FLAGS) driver.c sq_slow.o llist.o -lc -o driver

clean:
	rm -f *.o driver


