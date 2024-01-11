/**
 * @file student.h
 * @author Insiyah Ujjainwala (ujjainwi@pascal.cas.mcmaster.ca)
 * @brief This is the header code for the student library and all its functions.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Defines the typedef struct student, each student entry includes student name (first & last), student ID, and their grades.
 */ 
typedef struct _student 
{ 
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades; 
  int num_grades; 
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
