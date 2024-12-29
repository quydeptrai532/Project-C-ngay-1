//Khai bao nguyen mau ham
#ifndef FUNCTION_H
#define FUNCTION_H
#include "datatype.h"

void displayMenu();
void addStudent(Student **students, int *count);
void displayStudents(Student *students, int count);
void saveToFile(Student *students, int count, const char *filename);
void loadFromFile(Student **students, int *count, const char *filename);
void editStudent(Student *students, int count);
void deleteStudent(Student **students, int *count);



