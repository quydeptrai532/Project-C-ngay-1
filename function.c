//Code Ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

// Hàm hien thi menu
void displayMenu() {
    printf("\n==== Student Management System ====\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Save Data to File\n");
    printf("4. Load Data from File\n");
    printf("5. Edit Student\n");
    printf("6. Delete Student\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Ham them sinh vien
void addStudent(Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    if (*students == NULL) {
        printf("\nError: Memory allocation failed.\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%s", (*students)[*count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", (*students)[*count].name);
    printf("Enter Age: ");
    scanf("%d", &(*students)[*count].age);
    printf("Enter Class: ");
    scanf("%s", (*students)[*count].class);
    printf("Enter Score: ");
    scanf("%f", &(*students)[*count].score);

    (*count)++;
    printf("\nStudent added successfully!\n");
}

// Hàm hien thi danh sach sinh vien
void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("\nNo students to display.\n");
        return;
    }
    int i;
    printf("\n==== List of Students ====\n");
    for ( i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: %s\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Class: %s\n", students[i].class);
        printf("Score: %.2f\n", students[i].score);
    }
}

// Hàm luu du lieu vao tep
void saveToFile(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("\nError: Could not open file for saving.\n");
        return;
    }
    int i;
    for ( i = 0; i < count; i++) {
        fwrite(&students[i], sizeof(Student), 1, file);
    }
    fclose(file);
    printf("\nData saved successfully to '%s'.\n", filename);
}

// Hàm tai du lieu tu tep
void loadFromFile(Student **students, int *count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("\nError: Could not open file for loading. Starting with an empty list.\n");
        return;
    }

    *count = 0;
    *students = NULL;
    Student temp;

    while (fread(&temp, sizeof(Student), 1, file)) {
        *students = realloc(*students, (*count + 1) * sizeof(Student));
        if (*students == NULL) {
            printf("\nError: Memory allocation failed.\n");
            fclose(file);
            return;
        }
        (*students)[*count] = temp;
        (*count)++;
    }

    fclose(file);
    printf("\nData loaded successfully from '%s'.\n", filename);
}

// Ham chinh sua sinh vien
void editStudent(Student *students, int count) {
    char id[10];
    printf("\nEnter the ID of the student to edit: ");
    scanf("%s", id);
    int i;
    for ( i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("\nEditing student with ID %s:\n", id);
            printf("Enter new Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            printf("Enter new Class: ");
            scanf("%s", students[i].class);
            printf("Enter new Score: ");
            scanf("%f", &students[i].score);
            printf("\nStudent information updated successfully!\n");
            return;
        }
    }
    printf("\nError: Student with ID %s not found.\n", id);
}

// Ham xoa sinh vien
void deleteStudent(Student **students, int *count) {
    char id[10];
    printf("\nEnter the ID of the student to delete: ");
    scanf("%s", id);
    int i,j;
    for ( i = 0; i < *count; i++) {
        if (strcmp((*students)[i].id, id) == 0) {
            for ( j = i; j < *count - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*count)--;
            *students = realloc(*students, *count * sizeof(Student));
            printf("\nStudent with ID %s deleted successfully!\n", id);
            return;
        }
    }
    printf("\nError: Student with ID %s not found.\n", id);
}

