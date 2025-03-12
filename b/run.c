#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 64

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "run: not enough args\n");
    return 1;
  }

  char buf[BUF_SIZE];
  int pos = snprintf(buf, sizeof(buf), "./%s", argv[1]);

  for (int i = 2; i < argc && pos < BUF_SIZE; i++) {
    pos += snprintf(buf + pos, sizeof(buf) - pos, " %s", argv[i]);
  }

  if (pos >= BUF_SIZE) {
    fprintf(stderr, "run: command exceeds buffer size of %d\n", BUF_SIZE);
    return 1;
  }

  return system(buf) == 0 ? 0 : 1;
}
