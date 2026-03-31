#include <stdio.h>
#include <stdbool.h>

// Define the maximum size for the stack
#define MAX_SIZE 10

// Global variables to store the stack and its top element index
int stack[MAX_SIZE];
int top = -1; // -1 means the stack is initially empty

// Function to check if the stack is full
// Returns true if top has reached MAX_SIZE - 1
bool isFull() {
    return top == (MAX_SIZE - 1);
}

// Function to check if the stack is empty
// Returns true if top is still -1
bool isEmpty() {
    return top == -1;
}

// Push operation: Adds an element to the top of the stack
void push(int data) {
    if (!isFull()) {
        top = top + 1;       // Increment top pointer
        stack[top] = data;   // Add data to the new top position
        printf("Pushed %d onto the stack.\n", data);
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

// Pop operation: Removes the top element from the stack
int pop() {
    int data;
    if (!isEmpty()) {
        data = stack[top]; // Get the data at top
        top = top - 1;     // Decrement the top pointer
        return data;       // Return the popped element
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
        return -1; // Specific return value signifying an error or empty
    }
}

// Peek operation: Returns the top element without removing it
int peek() {
    if (!isEmpty()) {
        return stack[top]; 
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

int main() {
    // Basic operations to demonstrate a Stack (LIFO - Last In First Out)
    
    // Pushing elements 
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    
    // Peeking at the top element
    printf("Element at top of the stack: %d\n", peek());
    
    // Popping elements
    printf("Elements: \n");
    
    // We keep popping all elements until the stack is empty
    while(!isEmpty()) {
        int popped_data = pop();
        printf("%d \n", popped_data);
    }
    
    // Try to pop from an empty stack
    pop(); 
    
    return 0;
}
