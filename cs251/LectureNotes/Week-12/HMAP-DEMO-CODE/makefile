
hmap.o: hmap.c hmap.h
	gcc -c -g hmap.c

test: test.c hmap.h hmap.o
	gcc -g test.c hmap.o -o test

clean:
	rm -f *.o test

