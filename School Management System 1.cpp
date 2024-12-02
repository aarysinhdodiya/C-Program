#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.csv"


struct Student {
    int rollNumber;
    char name[50];
    int age;
    char className[20];
    char feesStatus[20]; 
    char parentsName[50];
    char mobileNumber[15];
    char address[100];
};


void addStudent(struct Student students[], int *studentCount);
void viewStudents(struct Student students[], int studentCount);
void searchStudent(struct Student students[], int studentCount, int rollNumber);
void deleteStudent(struct Student students[], int *studentCount, int rollNumber);
void loadStudents(struct Student students[], int *studentCount);
void saveStudents(struct Student students[], int studentCount);

int main() {
    struct Student students[MAX_STUDENTS]; 
    int studentCount = 0; 
    int choice, rollNumber;

    
    loadStudents(students, &studentCount);

    
    while(1) {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNumber);
                searchStudent(students, studentCount, rollNumber);
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(students, &studentCount, rollNumber);
                break;
            case 5:
                printf("Exiting system...\n");
                saveStudents(students, studentCount);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


void loadStudents(struct Student students[], int *studentCount) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No previous data found, starting fresh.\n");
        return;
    }

    
    while (fscanf(file, "%d,%49[^,],%d,%19[^,],%19[^,],%49[^,],%14[^,],%99[^\n]\n",
                  &students[*studentCount].rollNumber, 
                  students[*studentCount].name, 
                  &students[*studentCount].age,
                  students[*studentCount].className, 
                  students[*studentCount].feesStatus, 
                  students[*studentCount].parentsName, 
                  students[*studentCount].mobileNumber, 
                  students[*studentCount].address) == 8) {
        (*studentCount)++;
    }

    fclose(file);
}


void saveStudents(struct Student students[], int studentCount) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d,%s,%d,%s,%s,%s,%s,%s\n",
                students[i].rollNumber, 
                students[i].name, 
                students[i].age, 
                students[i].className,
                students[i].feesStatus,
                students[i].parentsName,
                students[i].mobileNumber,
                students[i].address);
    }

    fclose(file);
}


void addStudent(struct Student students[], int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("\nEnter student details:\n");
    printf("Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Name: ");
    getchar(); // to consume the newline character left by scanf
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove the newline character
    printf("Age: ");
    scanf("%d", &newStudent.age);
    printf("Class: ");
    getchar(); // to consume the newline character
    fgets(newStudent.className, sizeof(newStudent.className), stdin);
    newStudent.className[strcspn(newStudent.className, "\n")] = '\0'; // Remove the newline character

    printf("Fees Status (Submitted/Pending): ");
    fgets(newStudent.feesStatus, sizeof(newStudent.feesStatus), stdin);
    newStudent.feesStatus[strcspn(newStudent.feesStatus, "\n")] = '\0'; // Remove newline

    printf("Parent's Name: ");
    fgets(newStudent.parentsName, sizeof(newStudent.parentsName), stdin);
    newStudent.parentsName[strcspn(newStudent.parentsName, "\n")] = '\0'; // Remove newline

    printf("Mobile Number: ");
    fgets(newStudent.mobileNumber, sizeof(newStudent.mobileNumber), stdin);
    newStudent.mobileNumber[strcspn(newStudent.mobileNumber, "\n")] = '\0'; // Remove newline

    printf("Address: ");
    fgets(newStudent.address, sizeof(newStudent.address), stdin);
    newStudent.address[strcspn(newStudent.address, "\n")] = '\0'; // Remove newline

    students[*studentCount] = newStudent;
    (*studentCount)++;
    saveStudents(students, *studentCount); // Save to file after adding
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents(struct Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nStudent List:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\nRoll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Class: %s\n", students[i].className);
        printf("Fees Status: %s\n", students[i].feesStatus);
        printf("Parent's Name: %s\n", students[i].parentsName);
        printf("Mobile Number: %s\n", students[i].mobileNumber);
        printf("Address: %s\n", students[i].address);
    }
}


void searchStudent(struct Student students[], int studentCount, int rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Class: %s\n", students[i].className);
            printf("Fees Status: %s\n", students[i].feesStatus);
            printf("Parent's Name: %s\n", students[i].parentsName);
            printf("Mobile Number: %s\n", students[i].mobileNumber);
            printf("Address: %s\n", students[i].address);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
}

// Function to delete a student by roll number
void deleteStudent(struct Student students[], int *studentCount, int rollNumber) {
    for (int i = 0; i < *studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Shift all elements after the deleted student to the left
            for (int j = i; j < *studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            (*studentCount)--; // Decrease the student count
            saveStudents(students, *studentCount); // Save after deletion
            printf("Student with roll number %d has been deleted.\n", rollNumber);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
}
