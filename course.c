/**
 * @file course.c
 * @author Insiyah Ujjainwala (ujjainwi@pascal.cas.mcmaster.ca)
 * @brief This is the code for the course library and all the functions it contains.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief This library takes a course and a student as input and then enrolls a student to that specific course.
 *        By means of if-else statements, it uses calloc to allocate memory for a single student and gets a pointer to represent the student,
 *        If there are more students, it uses realloc to allocate memory for the other students.
 * 
 * @param course 
 * @param student 
 */


void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Takes in a course and prints all the information about the course, ie. 
 *        the course name, code, total number of students in the course, and names of all the students enrolled in the course.
 * 
 * @param course 
 */


void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Takes the name of a course as input and compares the averages of all students enrolled in it to find the student with the highest average.
 * 
 * @param course 
 * @return Student* 
 */


Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * @brief Takes in as inputs the name of the course and the number of students that are passing (average>=50) and returns the students.
 * 
 * @param course 
 * @param total_passing 
 * @return Student* 
 */


Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}