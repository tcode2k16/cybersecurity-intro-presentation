#include <stdio.h>
#include <string.h>

int main() {
  int x = 0;
  printf("welcome to the impossible program!\n");
  x += 1;
  if (x == 2) {
    printf("Congratulation for achieving the impossible!\n");
    char a[] = "i~lqlcxy~UhcdkxsUzk~ibw";
    for (int i = 0; i < strlen(a); i++) {
      a[i] = a[i]^(char)(10);
    }
    printf("flag: %s\n", a);
  } else {
    printf("See it's impossible!\n");
  }
  return 0;
}
