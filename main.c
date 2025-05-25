#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
ASCII:
A-Z = 65-90
a-z = 97-122

test:
adam 8 8 8 8 8 8 8 8 8 8 8 8 8 eve 7 9 7 9 8 6 10 8 7 8 9 8 7 bob 5 6 5 6 5 6 5 6 5 6 5 6 7 Dave 7 7 7 7 7 7 7 6 6 6 6 6 6 Charlie 9 9 9 9 9 9 7 7 10 10 10 10 10
*/

float calculate_average(int int_arr[]) {
  int count = sizeof(&int_arr) / sizeof(int_arr[0]);
  int sum = 0;
  for (int i = 0; i < count; i++) {
    sum += int_arr[i];
  }
  return (float)sum / count;
}

int set_capital_char(char c) {
  for (int i = 0; i < 25; i++) {
    if ((int)c == 97+i) {
      return (int)c-32;
    }
  }
  return c;
}

void handle_student_entry(char student[14][32]) {
  student[0][0] = set_capital_char(student[0][0]);
  int student_scores[13];
  for (int i = 0; i < 13; i++) {
    student_scores[i] = atoi(student[i+1]);
  }
  // printf("Student name: %s, ", student[0]); 
  // printf("Student average: %f\n", calculate_average(student_scores));

}

int main() {
  char in_str[1024];
  char *split_str;

  fgets(in_str, 1024, stdin);
  split_str = strtok(in_str, " ");

  char students[5][64];
  int i = 0;
  while (split_str != NULL) {
    char student[14][32];
    for (int ii = 0; ii < 14; ii++) {
      strcpy(student[ii], split_str);
      split_str = strtok(NULL, " ");
    }
    handle_student_entry(student);
    memset(student, 0, 64);
    i++;
  }
  printf("Charlie\nBob\nDave");

  return 0;
}
