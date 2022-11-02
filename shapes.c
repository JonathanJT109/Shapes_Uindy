/*
Assignment: Homework 7
Name: Jonathan Gonzalez Martinez
Email: gonzalezmartinezj@uindy.edu
Date: 10/30/2022
Description: The program will show the user multiple tasks that the user can
perform such as printing a rectangle frame, or a right triangle, or a DEATH
STAR, etc. The program will the listen to the user's option and call different
functions.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define calcX(n, j, a) (n * n * j * j - 2 * n * j * a + a * a)
#define calcY(i, p) (i * i * p * p)
#define calcXY(n, j, i, p) (p * p * i * i + n * n * j * j)
#define calcR(n, p) (n * n * p * p)

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
    printf("%s?\n", prompt);
    scanf("%d", &value);
    if (value < 0) {
      printf("%s should be non-negative\n", prompt);
    }
  } while (value < 0);
  return value;
}
// Option 1
void printFilledRectangle(int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      printf("*");
    }
    printf("\n");
  }
}

// Option 2
void printRectangleFrame(int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (row == 0 || row == height - 1)
        printf("*");
      else if (col == 0 || col == width - 1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// Option 3
void printRectangleFrameWithAlternatingInterior(int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (row == 0 || row == height - 1)
        printf("*");
      else if (col == 0 || col == width - 1)
        printf("*");
      else if (col % 2 == 0)
        printf(".");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// Option 4
void printSquareWithAlternatingInterior(int size) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row == 0 || row == size - 1)
        printf("*");
      else if (col == 0 || col == size - 1)
        printf("*");
      else if (col % 2 == 0)
        printf(".");
      else if (col % 2 == 1)
        printf(",");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// Option 5
void printRectangleFrameWithRandomInside(int height, int width) {
  int r;
  srand(time(NULL));
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      r = random() % width;
      if (row == 0 || row == height - 1)
        printf("*");
      else if (col == 0 || col == width - 1)
        printf("*");
      else if (r % 7 == 0)
        printf(".");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// Option 6
void printRightTriangle(int width) {
  for (int row = 0; row < width; row++) {
    for (int col = 0; col <= row; col++)
      printf("*");
    printf("\n");
  }
}

// Option 7
void printPyramid(int width) {
  width /= 2;
  for (int row = 0; row < width; row++) {
    for (int i = 0; i < width - 1 - row; i++)
      printf(" ");
    for (int i = 0; i < row * 2 + 1; i++)
      printf("*");
    printf("\n");
  }
}

// Option 8
void printCircle(int radius) {
  float p = floor((4 * radius - 2.5) / 5.8);
  radius = (float)radius + 3;
  for (float row = p; row >= -p; row--) {
    for (float col = -radius; col <= radius; col++) {
      if (calcXY(radius, row, col, p) <= calcR(radius, p))
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// Option 9
/* Description: I want to write a little about the issues I had during the
 process of creating this function.
 1. It is hard to make a circle using C. Due to the lack of precision with
 really small or large numbers, the calculations of the X and Y coordinates
 vary. I squared the entire function x^2 + y^2 = r^2 to get a more precise
 solution and the draw a star in that location.
 2. It is hard to make a circle look good in C. I've tried to play with the rows
 and columns. Making the rows a bit less than the columns solves the problem if
 the radius is less than 15 (it depends really), after 15 the cirlce starts to
 look really bad. Another Idea that came to mind was to add a space between
 columns but it was the same problem, however, if the radius was less than 15
 the circle looked weird. I decided to proceed with the first solution.
 3. Making the smaller circle had the same issues as for the big one.
 In summary, It is hard to generalize the formula of a circle, in programming,
 where the form is consistent from 1 to infinity.
*/
void printDeathStar(int radius) {
  int n = (float)radius + 5;
  float q, p = floor((4 * radius - 2.5) / 5.8);
  if (radius <= 12)
    q = floor((4 * radius - 2.5) / 6);
  else
    q = floor(p / 1.5);
  for (float i = p; i >= -p; i--) {
    for (float j = -n; j <= n; j++) {
      if ((pow(p * j - p * q, 2.0) + pow(n * i - q * p, 2.0)) <=
          (q * q * p * p))
        printf(".");
      else if (calcXY(n, i, j, p) <= calcR(n, p))
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}

int main(void) {
  int height;
  int width;
  int radius;

  int choice = getMenuChoice();
  switch (choice) {
  case 1:
    height = getPositiveInput("height");
    width = getPositiveInput("width");
    printFilledRectangle(height, width);
    break;
  case 2:
    height = getPositiveInput("height");
    width = getPositiveInput("width");
    printRectangleFrame(height, width);
    break;
  case 3:
    height = getPositiveInput("height");
    width = getPositiveInput("width");
    printRectangleFrameWithAlternatingInterior(height, width);
    break;
  case 4:
    width = getPositiveInput("size");
    printSquareWithAlternatingInterior(width);
    break;
  case 5:
    height = getPositiveInput("height");
    width = getPositiveInput("width");
    printRectangleFrameWithRandomInside(height, width);
    break;
  case 6:
    width = getPositiveInput("width");
    printRightTriangle(width);
    break;
  case 7:
    width = getPositiveInput("width");
    printPyramid(width);
    break;
  case 8:
    radius = getPositiveInput("radius");
    printCircle(radius);
    break;
  case 9:
    radius = getPositiveInput("radius");
    printDeathStar(radius);
    break;
  default:
    printf("Not implemented (yet)!\n");
    break;
  }
}
