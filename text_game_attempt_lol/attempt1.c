#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stats {
  int str;
  int dex;
  int con;
  int intel;
  int wis;
  int cha;
};

struct player {
  char name[32];
  int health;
  struct stats s;
};

void sleep_ms(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  sleep(milliseconds / 1000);
#endif
}

int main() {

  char name[32];

  struct player p = {
      .health = 32,
      .s.str = 10,
      .s.dex = 10,
      .s.con = 10,
      .s.intel = 10,
      .s.wis = 10,
      .s.cha = 10,
  };

  char start[5];
  printf("Would you like to start playing the game? Type \"Yes\" if so.\n");
  if (fgets(start, sizeof(start), stdin) == NULL) {
    perror("fgets");
  }
  if (strcmp(start, "Yes\n") != 0) {
    printf("Ok, not sure why you opened the .exe then. Have a nice day. This "
           "message will self destruct in 3...2...1... (Make sure to buy "
           "Nezcorp Humanely Cultivated Fried Chicken. Or NHCFC. ((Still "
           "working on the acronym.)))\n");
    exit(EXIT_SUCCESS);
  }

  printf("This is the journey's beginning. Name your character:\n");
  if (fgets(name, sizeof(name), stdin) == NULL) {
    perror("fgets");
  }

  size_t len = strlen(name) - 1;
  if (name[len] == '\n') {
    name[len] = 0;
  }
  printf("%s, a lovely name.\n", name);
  sleep_ms(2000);
  printf("\nSome time has passed.\n");
  printf("%d Strength \n%d Dexterity \n%d Constituition \n%d Intelligence\n % d "
          "Wisdom \n%d Charisma\n",
         p.s.str, p.s.dex, p.s.con, p.s.intel, p.s.wis, p.s.cha);
  printf("You may upgrade one stat by 2 points. Type a number 1-6 based on the "
         "stat you want to upgrade from above.\n");

  char selected_stat;
  if (scanf(" %c", &selected_stat) == EOF) {
    perror("Scanf");
  }

  switch (selected_stat) {
  case '1':
    p.s.str += 2;
    printf("%d is your new Strength Score.\n", p.s.str);
    break;
  case '2':
    p.s.dex += 2;
    printf("%d is your new Dexterity Score.\n", p.s.dex);
    break;
  case '3':
    p.s.con += 2;
    printf("%d is your new Constituition Score.\n", p.s.con);
    break;
  case '4':
    p.s.intel += 2;
    printf("%d is your new Intelligence Score.\n", p.s.intel);
    break;
  case '5':
    p.s.wis += 2;
    printf("%d is your new Wisdom Score.\n", p.s.wis);
    break;
  case '6':
    p.s.cha += 2;
    printf("%d is your new Charisma Score.\n", p.s.cha);
    break;
  default:
    abort();
  }

  for (;;) {
  }
  return 0;
}
