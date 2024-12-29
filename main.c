#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"

int main() {
    Student *students = NULL;
    int count = 0;
    int choice;
    const char *filename = "studentdata.bin";
    
	Student sampleStudents[10] = {
        {"ID001", "Nguyen Thi Mai", 20, "Toan", 85.5},
        {"ID002", "Tran Minh Quang", 21, "Ly", 90.0},
        {"ID003", "Le Thi Lan", 22, "Hoa", 92.5},
        {"ID004", "Pham Minh Tuan", 19, "Toan", 88.0},
        {"ID005", "Nguyen Thi Lan", 23, "Sinh", 78.5},
        {"ID006", "Dang Thi Hoa", 20, "Ly", 91.0},
        {"ID007", "Hoang Minh Tu", 22, "Hoa", 85.0},
        {"ID008", "Vu Thi Mai", 21, "Toan", 87.5},
        {"ID009", "Nguyen Thi Lan", 20, "Sinh", 79.0},
        {"ID010", "Le Thi Thanh", 19, "Ly", 93.0}
    };

    students = malloc(10 * sizeof(Student));
    int i;
    for ( i = 0; i < 10; i++) {
        students[i] = sampleStudents[i];
    }
    count = 10;

    saveToFile(students, count, filename);

    loadFromFile(&students, &count, filename);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count, filename);
                break;
            case 4:
                loadFromFile(&students, &count, filename);
                break;
            case 5:
                editStudent(students, count);
                break;
            case 6:
                deleteStudent(&students, &count);
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                free(students);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

