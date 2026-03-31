#include <stdio.h>
#include <stdbool.h>

// Maximum size for the queue
#define MAX_SIZE 10

// Global Variables
int intArray[MAX_SIZE];
int front = 0;
int rear = -1;
int itemCount = 0;

// Function to peek at the element at the front without removing it
int peek() {
   return intArray[front];
}

// Function to check if the queue is empty
bool isEmpty() {
   return itemCount == 0;
}

// Function to check if the queue is full
bool isFull() {
   return itemCount == MAX_SIZE;
}               

// Check the number of items in the queue
int size() {
   return itemCount;
}  

// Function to add data to the queue (enqueue)
void insert(int data) {

   if(!isFull()) {
      // if rear is at the end, circle it back to the beginning (circular wrap-around)
      if(rear == MAX_SIZE - 1) {
         rear = -1;            
      }       
      
      // Increment rear and add item at new rear position
      intArray[++rear] = data;
      itemCount++;
      printf("Inserted %d into the queue.\n", data);
   } else {
      printf("Queue is full. Could not insert %d.\n", data);
   }
}

// Function to remove data from the queue (dequeue)
int removeData() {
   int data = intArray[front++]; // Get the front item and increment front pointer
  
   if(front == MAX_SIZE) {
      front = 0; // Wrap around front pointer 
   }
  
   itemCount--; // Reduce itemCount
   return data;  
}

int main() {
   /* Queue conceptually follows First-In-First-Out (FIFO) */
   
   // Insert items into the queue
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);

   // Front should be 3, rear should be 12
   printf("Front element: %d\n", peek());
   printf("-----------------------\n");
   printf("Queue elements: \n");
   
   // Remove all items from the queue
   while(!isEmpty()) {
      int n = removeData();           
      printf("%d ", n);
   }   
   
   printf("\n");
   
   return 0;
}
