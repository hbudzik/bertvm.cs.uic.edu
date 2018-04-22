
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned h0(char *s) {
  unsigned h = 0;

  while(*s != '\0'){
    h += *s;
    s++;
  }
  return h;
}

int main(){

  unsigned x = h0("noteworthinesses");

  printf(" h0('noteworthinesses'): %u\n", x);

  return 0;
}
