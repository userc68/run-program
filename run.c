#include <stdio.h>
#include <stdlib.h>

// cant run itself, or anything with args, only exes in the current dir

int main(int argc, char *argv[]) {
  if (argc < 1) return 1;
  char buf[64];
  snprintf(buf, sizeof(buf), "./%s", argv[1]);
  return system(buf) == 0 ? 0 : 1;
}
