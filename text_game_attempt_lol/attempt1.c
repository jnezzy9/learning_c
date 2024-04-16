#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char start[5];
  printf("Would you like to start playing the game? Type \"Yes\" if so.\n");
  fgets(start, sizeof(start), stdin);
  if (strcmp(start, "Yes\n") != 0) {
    printf("Ok, not sure why you opened the .exe then. Have a nice day. This "
           "message will self destruct in 3...2...1... (Make sure to buy "
           "Nezcorp Humanely Cultivated Fried Chicken. Or NHCFC. ((Still "
           "working on the acronym.)))\n");
    exit(EXIT_SUCCESS);
  }

  char name[32];

  printf("This is the journey's beginning. Name your character:\n");
  fgets(name, sizeof(name), stdin);
  size_t len = strlen(name) - 1;
  if (name[len] == '\n') {
    name[len] = 0;
  }
  printf(" %s, a lovely name.\n", name);
  return 0;
}
