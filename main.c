#include <stdio.h>
#include <string.h>
#define MAX_GRADES 5       // Maximum number of grades per student
#define MAX_STUDENTS 50    // Maximum number of students

// Define a structure to store student information
typedef struct Student{
    char name[50];          // Student's name
    int studentId;          // Student's ID
    double grades[MAX_GRADES]; // Array to store grades
    int numGrades;          // Number of grades entered
    float gpa;              // Calculated GPA
} Student;

// Array to store all students
Student students[MAX_STUDENTS];
int studentCount = 0;       // Counter for the number of students stored

// Function to add a new student
void addStudent() {
    if(studentCount >= MAX_STUDENTS){
        printf("Cannot add more students. Storage full.\n");
        return;
    }
    
    Student newStudent;
    
    // Get student name
    printf("\nEnter the Student's name: ");
    scanf(" %[^\n]s", newStudent.name); // %[^\n] allows spaces
    
    // Get student ID
    printf("\nEnter the Student's ID number: ");
    scanf("%d", &newStudent.studentId);
    
    // Get number of grades
    printf("\nHow many grades will you enter (max %d): ", MAX_GRADES);
    scanf("%d", &newStudent.numGrades);
    
    if (newStudent.numGrades > MAX_GRADES) {
        newStudent.numGrades = MAX_GRADES; // Limit to MAX_GRADES
        printf("Too many grades entered. Only %d will be stored.\n", MAX_GRADES);
    }

    // Get grades
    for (int i = 0; i < newStudent.numGrades; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%lf", &newStudent.grades[i]);
    }
    
    // Add student to array and increment counter
    students[studentCount] = newStudent;
    studentCount++;
    
    printf("\nStudent %s added successfully!\n\n", newStudent.name);
}

// Function to view all students and their grades
void viewStudents() {
    if(studentCount == 0){
        printf("No students available!\n");
        return;
    }
    
    printf("\n------ Student List ------\n");
    
    for(int i = 0; i < studentCount; i++){
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].studentId);
        
        // Print all grades
        printf("Grades: ");
        for (int j = 0; j < students[i].numGrades; j++) {
            printf("%.2lf ", students[i].grades[j]);
        }
        
        // Print GPA if calculated
        printf("\nGPA: %.2f\n", students[i].gpa);
        printf("\n");
    }
}

// Function to calculate GPA for a specific student
void calGpa() {
    if(studentCount == 0){
        printf("No Students Available!\n");
        return;
    }
    
    // List students for selection
    printf("\nSelect a student by number:\n");
    for(int i = 0; i < studentCount; i++){
        printf("%d. %s\n", i + 1, students[i].name);
    }
    
    int selectedNumber;
    printf("\nEnter Student number: ");
    scanf("%d", &selectedNumber);
    
    int selectedIndex = selectedNumber - 1;
    
    if(selectedIndex < 0 || selectedIndex >= studentCount) {
        printf("Invalid selection!\n");
        return;
    }

    if(students[selectedIndex].numGrades == 0){
        printf("No grades available for %s!\n", students[selectedIndex].name);
        return;
    }

    // Calculate GPA
    double sum = 0;
    for(int i = 0; i < students[selectedIndex].numGrades; i++) {
        sum += students[selectedIndex].grades[i];
    }
    double gpa = sum / students[selectedIndex].numGrades;
    students[selectedIndex].gpa = gpa;

    printf("GPA for %s is %.2lf\n\n", students[selectedIndex].name, gpa);
}

// Function to find and display highest and lowest GPA
void highLow() {
    if(studentCount == 0){
        printf("No students available!\n");
        return;
    }

    int highestIndex = 0;
    int lowestIndex = 0;
    double highestGPA = students[0].gpa;
    double lowestGPA = students[0].gpa;

    // Loop through students to find high and low GPA
    for(int i = 1; i < studentCount; i++){
        if(students[i].gpa > highestGPA){
            highestGPA = students[i].gpa;
            highestIndex = i;
        }
        if(students[i].gpa < lowestGPA){
            lowestGPA = students[i].gpa;
            lowestIndex = i;
        }
    }

    printf("\nHighest GPA: %.2lf by %s\n", highestGPA, students[highestIndex].name);
    printf("Lowest GPA: %.2lf by %s\n\n", lowestGPA, students[lowestIndex].name);
}

// Main program loop
int main() {
    int menuOptions;
    
    while(1){
        printf("Please select an option!\n");
        printf("1. Add student\n"
               "2. View students\n"
               "3. Calculate average of one student\n"
               "4. Find highest & lowest average\n"
               "5. Exit\n");
        printf("\nWhat would you like to do: ");
        scanf("%d", &menuOptions);
        
        switch(menuOptions){
            case 1:
                printf("\nYou selected add student\n");
                addStudent();
                break;
            case 2:
                printf("\nYou selected view students\n");
                viewStudents();
                break;
            case 3:
                printf("\nYou selected calculate average of one student\n");
                calGpa();
                break;
            case 4:
                printf("\nYou selected find highest & lowest average\n");
                highLow();
                break;
            case 5:
                printf("\nYou selected exit\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}