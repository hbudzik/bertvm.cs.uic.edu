#include <stdio.h>

// This program is to show how to access the Command Line
// ARGuments in a C/C++ program.
// 
//   argc is the ARGument Count: 
//            an integer value containing
//            how many Command Line Argument were given
//
//   argv is the ARGument Values: k
//            an array of C style strings containing
//            one Comand Line Argument per array positions
//
// The name of the program is found at argv[0]

int main (int argc, char** argv)
{
 int i;

 printf ("This program contains %d Command Line Arguments.\n\n", argc);

 for (i = 0; i < argc; i++)
   {
    /* access the ith ARGument Value */
    printf ("argv[%d]: *%s*", i, argv[i]);

    /* Command line flags start with a dash by convention */
    if ('-' == argv[i][0])
      printf (" is a flag.");

    printf ("\n");
   }

 return 0;
}
