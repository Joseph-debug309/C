#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Struct definition
struct Student
{
    int id;
    char name[50];
    int age;
    char gender;
    int mathematics;
    int physics;
    int chemistry;
};

// Function declarations
void addStudent(struct Student students[], int *count);
void displayAllStudents(const struct Student students[], int count);
void searchStudentByID(const struct Student students[], int count);
void calculateAverageMarks(const struct Student students[], int count);
void clearInputBuffer();

int main()
{
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM         \n");
        printf("=========================================\n");
        printf("1. Add Student Details\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Calculate Average Marks for a Student\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            addStudent(students, &studentCount);
            break;
        case 2:
            displayAllStudents(students, studentCount);
            break;
        case 3:
            searchStudentByID(students, studentCount);
            break;
        case 4:
            calculateAverageMarks(students, studentCount);
            break;
        case 5:
            printf("Exiting system. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please select an option between 1 and 5.\n");
        }

        } while (choice != 5);

    return 0;
}

// Function to add a new student
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Error: Maximum student capacity (%d) reached!\n", MAX_STUDENTS);
        return;
    }

    struct Student newStudent;

    printf("\n--- Add New Student ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);

    // Check for duplicate ID
    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == newStudent.id)
        {
            printf("Error: Student ID %d already exists!\n", newStudent.id);
            return;
        }
    }

    clearInputBuffer(); // Clear leftover newline before taking string input

    printf("Enter Full Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    printf("Enter Gender (M/F): ");
    scanf(" %c", &newStudent.gender);

    printf("Enter Mathematics Score: ");
    scanf("%d", &newStudent.mathematics);

    printf("Enter Physics Score: ");
    scanf("%d", &newStudent.physics);

    printf("Enter Chemistry Score: ");
    scanf("%d", &newStudent.chemistry);

    // Save to array
    students[*count] = newStudent;
    (*count)++;

printf("Student successfully added!\n");
}

// Function to display all student records
void displayAllStudents(const struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("%-6s | %-20s | %-5s | %-6s | %-11s | %-8s | %-9s\n", 
           "ID", "Name", "Age", "Gender", "Mathematics", "Physics", "Chemistry");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-6d | %-20s | %-5d | %-6c | %-11d | %-8d | %-9d\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gender,
               students[i].mathematics,
               students[i].physics,
               students[i].chemistry);
    }
    printf("------------------------------------------------------------------------------------------------------\n");
}

// Function to search for a student by ID
void searchStudentByID(const struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records available to search.\n");
        return;
    }

    int searchID;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++)
    {if (students[i].id == searchID)
        {
            printf("\n--- Student Found ---\n");
            printf("ID:          %d\n", students[i].id);
            printf("Name:        %s\n", students[i].name);
            printf("Age:         %d\n", students[i].age);
            printf("Gender:      %c\n", students[i].gender);
            printf("Mathematics: %d\n", students[i].mathematics);
            printf("Physics:     %d\n", students[i].physics);
            printf("Chemistry:   %d\n", students[i].chemistry);
            return;
        }
    }

    printf("Student with ID %d not found.\n", searchID);
}

// Function to calculate and print the average mark of a student
void calculateAverageMarks(const struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    int targetID;
    printf("\nEnter Student ID to calculate average: ");
    scanf("%d", &targetID);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == targetID)
        {
            int total = students[i].mathematics + students[i].physics + students[i].chemistry;
            float average = total / 3.0f;

            printf("\n--- Grade Summary for %s (ID: %d) ---\n", students[i].name, students[i].id);
            printf("Total Marks:   %d / 300\n", total);
            printf("Average Marks: %.2f\n", average);
            return;
        }
    }

    printf("Student with ID %d not found.\n", targetID);
}

// Helper function to clear leftover input buffer characters
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}