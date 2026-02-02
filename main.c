#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rollNo[20];
    char name[50];
    int age;
} Student;

void addStudent() {
    Student student;
    FILE *file = fopen("students.dat", "ab");
    if (!file) {
        printf("Error opening file!\n");
    } else {
        printf("Enter Roll Number: ");
        scanf("%19s", student.rollNo);
        printf("Enter Name: ");
        scanf(" %49[^\n]", student.name);
        printf("Enter Age: ");
        scanf("%d", &student.age);
        fwrite(&student, sizeof(Student), 1, file);
        fclose(file);
        printf("Student added successfully.\n");
    }
}

void displayStudents() {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("No records available.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Roll Number: %s, Name: %s, Age: %d\n", student.rollNo, student.name, student.age);
        found = 1;
    }

    if (!found) {
        printf("No records available.\n");
    }

    fclose(file);
}

void searchStudent() {
    char rollNo[20];
    printf("Enter Roll Number to search: ");
    scanf("%19s", rollNo);

    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("Error opening file!\n");
    } else {
        Student student;
        int found = 0;
        while (fread(&student, sizeof(Student), 1, file)) {
            if (strcmp(student.rollNo, rollNo) == 0) {
                printf("Student Found - Roll Number: %s, Name: %s, Age: %d\n", student.rollNo, student.name, student.age);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Student not found.\n");
        }
        fclose(file);
    }
}

void updateStudent() {
    char rollNo[20];
    printf("Enter Roll Number to update: ");
    scanf("%19s", rollNo);

    FILE *file = fopen("students.dat", "rb+");
    if (!file) {
        printf("Error opening file!\n");
    } else {
        Student student;
        int found = 0;
        while (fread(&student, sizeof(Student), 1, file)) {
            if (strcmp(student.rollNo, rollNo) == 0) {
                printf("Enter new Name: ");
                scanf(" %49[^\n]", student.name);
                printf("Enter new Age: ");
                scanf("%d", &student.age);
                fseek(file, (long)-sizeof(Student), SEEK_CUR);
                fwrite(&student, sizeof(Student), 1, file);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Student not found.\n");
        }
        fclose(file);
    }
}

void deleteStudent() {
    char rollNo[20];
    printf("Enter Roll Number to delete: ");
    scanf("%19s", rollNo);

    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("Error opening file!\n");
    } else {
        FILE *tempFile = fopen("temp.dat", "wb");
        if (!tempFile) {
            printf("Error opening temporary file!\n");
        } else {
            Student student;
            int found = 0;
            while (fread(&student, sizeof(Student), 1, file)) {
                if (strcmp(student.rollNo, rollNo) != 0) {
                    fwrite(&student, sizeof(Student), 1, tempFile);
                } else {
                    found = 1;
                }
            }
            if (found) {
                printf("Student deleted successfully.\n");
            } else {
                printf("Student not found.\n");
            }
            fclose(tempFile);
            fclose(file);
            remove("students.dat");
            rename("temp.dat", "students.dat");
        }
    }
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- Student Management System ---\n");
        printf("\n1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }
    }
}
