#include <stdio.h>

/*
 * ============================================================================
 * QUESTION: Add two Complex Numbers using Structures
 * ============================================================================
 * 
 * Problem Statement:
 * A complex number consists of a real part and an imaginary part (e.g., 5 + 3i).
 * Define a structure to represent a complex number. 
 * Then, write a function to add two complex numbers and return the result.
 * ============================================================================
 */

// Structure definition for a Complex Number using typedef
typedef struct {
    float real;
    float imag;
} Complex;

/*
 * Function: addComplex
 * --------------------
 * Adds two complex numbers. Since we grouped 'real' and 'imag' inside a 
 * structure, we can pass and return the entire complex number easily.
 * 
 *  c1: First complex number
 *  c2: Second complex number
 *  returns: A new Complex structure containing the sum
 */
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    
    // Add the real parts together
    result.real = c1.real + c2.real;
    
    // Add the imaginary parts together
    result.imag = c1.imag + c2.imag;
    
    return result;
}

int main() {
    // Initializing two complex numbers
    // c1 = 4.5 + 2.0 i
    Complex c1 = {4.5, 2.0};
    
    // c2 = 1.2 + 3.8 i
    Complex c2 = {1.2, 3.8};
    
    printf("First Complex Number:  %.1f + %.1fi\n", c1.real, c1.imag);
    printf("Second Complex Number: %.1f + %.1fi\n", c2.real, c2.imag);
    
    // Call the function to add them
    Complex sum = addComplex(c1, c2);
    
    // Display the output
    printf("-----------------------------------\n");
    printf("Sum of Complex Numbers: %.1f + %.1fi\n", sum.real, sum.imag);
    
    return 0;
}
