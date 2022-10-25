#include <stdio.h>

void printMenu() {
  printf("1. Filled-in rectangle\n");
  printf("2. Rectangle frame\n");
  printf("3. Rectangle frame with alternating interior\n");
  printf("4. Square with alternating interior\n");
  printf("5. Rectangle frame with random inside\n");
  printf("6. Right triangle\n");
  printf("7. Pyramid\n");
  printf("8. Circle\n");
  printf("9. Death Star (XC)\n");
  printf("Enter your choice.\n");
}

int isValid(int choice) { return choice >= 1 && choice <= 9; }

int getMenuChoice() {
  int choice;
  int validChoice = 0;
  do {
    printMenu();
    scanf("%d", &choice);
    validChoice = isValid(choice);
    if (!validChoice) {
      printf("Yikes! Please enter a valid choice.\n");
    }
  } while (!validChoice);
  return choice;
}

int getPositiveInput(char *prompt) {
  int value;
  do {
    printf("%s?", prompt);
    scanf("%d", &value);
    if (value < 0) {
      printf("%s should be non-negative\n", prompt);
    }
  } while (value < 0);
  return value;
}

void printFilledRectangle(int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      printf("*");
    }
    printf("\n");
  }
}

int main(void) {

  int height;
  int width;

  int choice = getMenuChoice();
  switch (choice) {
  case 1:
    height = getPositiveInput("height");
    width = getPositiveInput("width");
    printFilledRectangle(height, width);
    break;

  default:
    printf("Not implemented (yet)!\n");
    break;
  }
}