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

void print_student_entry(char student[14][32]) {
  student[0][0] = set_capital_char(student[0][0]);
  int student_scores[13];
  for (int i = 0; i < 13; i++) {
    student_scores[i] = atoi(student[i+1]);
  }
  printf("Student name: %s, ", student[0]); 
  printf("Student average: %f\n", calculate_average(student_scores));

}

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int get_highest_average(int student_scores[5][13]) {
  float averages[5];
  int best_student;
  for (int i = 0; i < 5; i++) {
    averages[i] = calculate_average(student_scores[i]);
    if (i == 0) {
      best_student = i;
    }
    else {
      if (averages[i] > averages[i-1]) {
        best_student = i;
      }
    }
  }
  return best_student;
}

void get_all_scores(int student_scores[5][13], int all_scores[5*13]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 13; j++) {
      all_scores[i * 13 + j] = student_scores[i][j];
    }
  }
}


void get_student_scores(char students[5][14][32], int student_scores[5][13]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 13; j++) {
      student_scores[i][j] = atoi(students[i][j+1]);
    }
  }
}

int main() {
  char in_str[1024];
  char *split_str;

  fgets(in_str, 1024, stdin);
  split_str = strtok(in_str, " ");

  char students[5][14][32];
  int i = 0;
  while (split_str != NULL) {
    for (int j = 0; j < 14; j++) {
      strcpy(students[i][j], split_str);
      split_str = strtok(NULL, " ");
    }
    // print_student_entry(students[i]);
    i++;
  }
  int student_scores[5][13]; 
  get_student_scores(students, student_scores);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 13; j++) {
      // printf("%d", student_scores[i][j]);
    }
  }
  int all_scores[65];
  get_all_scores(student_scores, all_scores);

  for (int k = 0; k < 65; k++) {
      // printf("%d\n", all_scores[k]);
  }

  float total_average = calculate_average(all_scores);
  printf("%s\n", students[get_highest_average(student_scores)][0]);

  // printf("Total average: %f\n", calculate_average(all_scores));

  for (int j = 0; j < 5; j++) {
    students[j][0][0] = set_capital_char(students[j][0][0]);
    if (calculate_average(student_scores[j]) < total_average) {
      printf("%s\n", students[j][0]);
    }
  }

  // printf("Charlie\nBob\nDave");

  return 0;
}
