
/**
 * @file main.c
 * @author Insiyah Ujjainwala (ujjainwi@pascal.cas.mcmaster.ca)
 * @brief This is the code that uses both the course and student libraries.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

int main()
{
  srand((unsigned) time(NULL));

  // uses the course structure to define a course called MATH101, named Basics of Mathematics and code MATH 101.
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // loop to add 20 students in the MATH101 course and assign 8 random grades to each of them.
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  // prints all the information pertaining to the student with the highest avgerage in the course.
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // prints how many students are passing the course and all their names.
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}