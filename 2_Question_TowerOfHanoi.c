#include <stdio.h>

/*
 * ============================================================================
 * QUESTION: Tower of Hanoi using Recursion
 * ============================================================================
 * 
 * Problem Statement:
 * You have 3 rods (Source, Auxiliary, Destination) and 'N' disks of different sizes.
 * Initially, all disks are stacked in ascending order of size on the Source rod.
 * 
 * Objective: Move the entire stack to the Destination rod obeying these rules:
 * 1. Only one disk can be moved at a time.
 * 2. Each move consists of taking the top disk from one rod and placing it on another.
 * 3. No disk may be placed on top of a smaller disk.
 * ============================================================================
 */

/*
 * Function: towerOfHanoi
 * ----------------------
 * Solves the Tower of Hanoi algorithm to move 'n' disks from a source rod to a 
 * destination rod using an auxiliary buffer rod.
 * 
 * Logic:
 * Let 'N' = number of disks to move.
 * Step 1: Move top (N-1) disks from Source to Auxiliary (using Destination as buffer).
 * Step 2: Move the Nth disk from Source to Destination.
 * Step 3: Move (N-1) disks from Auxiliary to Destination (using Source as buffer).
 * 
 *  n: number of disks to move
 *  from_rod: name of the source rod (e.g., 'A')
 *  to_rod: name of the destination rod (e.g., 'C')
 *  aux_rod: name of the auxiliary rod (e.g., 'B')
 */
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base Case: If only 1 disk is left, just move it directly to destination
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Step 1: Move (n-1) disks from 'from_rod' to 'aux_rod'
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Step 2: Move the nth (largest) disk from 'from_rod' to 'to_rod'
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Step 3: Move (n-1) disks from 'aux_rod' to 'to_rod'
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    // Number of disks
    int n = 3; 
    
    printf("Steps for Tower of Hanoi with %d disks:\n\n", n);
    
    // Calling the recursive function
    // 'A' represents the Source rod
    // 'C' represents the Destination rod
    // 'B' represents the Auxiliary (buffer) rod
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}
