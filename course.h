/**
 * @file course.h
 * @author Insiyah Ujjainwala (ujjainwi@pascal.cas.mcmaster.ca)
 * @brief This is the header code for the course library and all its functions.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>

/**
 * @brief Defines the typedef struct course, each course entry includes the course's name, the code, names of students and the total number of students.
 * 
 */

#include "student.h"
#include <stdbool.h>
 
typedef struct _course 
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


