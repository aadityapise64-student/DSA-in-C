#include <stdio.h>
#include <stdlib.h> // Need this for malloc

// Define the structure of a node in the Linked List
// A node contains the "data" and a "pointer" to the next node
struct Node {
    int data;           // Holds the actual data
    struct Node* next;  // Points to the next node in the list
};

// Function to print the linked list
// We start from the "head" (first node) and traverse until we hit NULL
void printList(struct Node* node) {
    // Loop until node pointer points to NULL
    while (node != NULL) {
        printf("%d -> ", node->data); // Print the data
        node = node->next;            // Move to the next node
    }
    printf("NULL\n"); // End of the list
}

int main() {
    // 1. Declare pointers for the start (head) and other nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // 2. Allocate memory for nodes dynamically in the heap using malloc
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Assign data and link the nodes
    // First node (Head)
    head->data = 1;        // Assign data '1'
    head->next = second;   // Link first node to the second node

    // Second node
    second->data = 2;      // Assign data '2'
    second->next = third;  // Link second node to the third node

    // Third node
    third->data = 3;       // Assign data '3'
    third->next = NULL;    // Link third node to NULL, indicating the end of the list

    // 4. Print the entire list starting from head
    printf("Linked List contents: \n");
    printList(head);

    // Free the dynamically allocated memory
    free(head);
    free(second);
    free(third);
    
    return 0;
}
