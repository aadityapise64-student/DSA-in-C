#include <stdio.h>

/*
 * ============================================================================
 * TOPIC: Recursion
 * ============================================================================
 * 
 * What is Recursion?
 * Recursion is a programming technique where a function calls ITSELF in order 
 * to solve smaller instances of the same problem.
 * 
 * Anatomy of a Recursive Function:
 * 1. Base Case: The condition where the recursion stops. Without this, the 
 *               function would call itself infinitely, leading to a Stack Overflow.
 * 2. Recursive Step: The part where the function breaks the problem down and 
 *                    calls itself.
 * 
 * Advantages: Makes code much cleaner and easier to write (e.g., Tree Traversals).
 * Disadvantages: High memory overhead due to the call stack; slower due to function calls.
 * ============================================================================
 */

/*
 * Example 1: Calculating Factorial
 * --------------------------------
 * factorial(n) = n * (n-1) * (n-2) * ... * 1
 * Mathematically: n! = n * (n-1)!
 * Base Case: 0! = 1 and 1! = 1
 */
int factorial(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive Step
    return n * factorial(n - 1);
}

/*
 * Example 2: Fibonacci Sequence
 * -----------------------------
 * Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13...
 * Logic: fib(n) = fib(n-1) + fib(n-2)
 * Base Cases: fib(0) = 0, fib(1) = 1
 */
int fibonacci(int n) {
    // Base Cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive Step
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    printf("--- Recursion Basics ---\n\n");
    
    // 1. Factorial Demonstration
    int num = 5;
    printf("Factorial of %d is: %d\n", num, factorial(num));
    
    printf("\n");
    
    // 2. Fibonacci Demonstration
    int limit = 7;
    printf("First %d terms of the Fibonacci series:\n", limit);
    for (int i = 0; i < limit; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}
