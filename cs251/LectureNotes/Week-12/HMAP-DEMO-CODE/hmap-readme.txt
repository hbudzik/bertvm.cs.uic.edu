

Hash table implementation of a map ADT.

Data structure maps from strings to generic pointers (void *), the interpretation of
which is client dependent.

Main files:

  hmap.h  :  specifies the interface to hmap ADT

  hmap.c  :  the implementation of the ADT

  test.c  :  toy driver program

  makefile

Simple test program test.c reads a dictionary from standard input and populates
two hmaps (where each hmap uses a different hash function).  Then prints a crude
ASCII visualization of the table list lengths.  The following will read the dictionary
dictionary-small.txt and print a summary of table statistics to the file 'profile'

    ./test < dictionary-small.txt > profile

Options to test program:

    -d : output displays the 'collision profile' of each table -- i.e., a 
          sideways histogram showing the number of elements in each 
          array entry.

    -c <coeff> : lets the user set the scaling coefficient for the default
                hash function to positive integer of their choice.
                Default value is 27 (see hmap.h)

Dictionary files:

    dictionary-small.txt
    dictionary-big.txt
