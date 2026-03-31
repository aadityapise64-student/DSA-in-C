#include <stdio.h>
#include <string.h>

/*
 * ============================================================================
 * TOPIC: Structures in C (struct)
 * ============================================================================
 * 
 * What is a Structure?
 * A structure is a user-defined data type in C that allows you to combine 
 * data items of different kinds. While an array holds data of the same type,
 * a structure can hold multiple variables of different types under one name.
 * 
 * Why are they important in DSA?
 * Structures form the foundation for complex data structures like Linked Lists, 
 * Trees, and Graphs, where we need to store a value AND a pointer to the 
 * next node within a single entity.
 * ============================================================================
 */

// Defining a structure using the 'struct' keyword
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Typedef allows us to give a simpler alias to our structure, 
// so we don't have to keep typing 'struct Employee' everywhere.
typedef struct Employee {
    int id;
    int salary;
} Emp;

int main() {
    printf("--- Structure Basics ---\n\n");

    // 1. Initializing Structure Variables
    struct Student s1; // Declaring a variable of type 'struct Student'
    
    // Assigning values to structure members using the dot (.) operator
    s1.rollNumber = 101;
    strcpy(s1.name, "Aaditya");
    s1.marks = 95.5;

    printf("Student 1 Details:\n");
    printf("Name: %s\n", s1.name);
    printf("Roll No: %d\n", s1.rollNumber);
    printf("Marks: %.2f\n\n", s1.marks);

    // 2. Initialization during declaration
    struct Student s2 = {102, "Rahul", 88.0};
    printf("Student 2 Details:\n");
    printf("Name: %s\n", s2.name);
    printf("Roll No: %d\n", s2.rollNumber);
    printf("Marks: %.2f\n\n", s2.marks);

    // 3. Using typedef Structures
    Emp e1; // No need to write 'struct Employee'
    e1.id = 5001;
    e1.salary = 75000;
    
    printf("Employee 1 Details:\n");
    printf("ID: %d\n", e1.id);
    printf("Salary: $%d\n\n", e1.salary);

    // 4. Pointers to Structures
    // This concept is CRITICAL for creating Linked Lists and Trees!
    struct Student *ptr = &s1;
    
    printf("Accessing Structure using Pointers:\n");
    // We use the arrow operator (->) to access members using a pointer
    printf("Name via pointer: %s\n", ptr->name);
    printf("Roll No via pointer: %d\n", ptr->rollNumber);

    return 0;
}
