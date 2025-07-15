/**
 *  Calculator
 * 
 *  A simple calculator that allows a user to use
 *  addition, subtraction, multiplication, and division.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    char problem[100];      // User input
    char operand1[50];      // The left side number of the problem 
    char operand2[50];      // The right side number of the problem 
    bool operator_found = false;  // Is the operator found in the problem
    char operator;          // The operator of the problem
    int number_found = 0;   // Keeps track of the number of characters found in the problem
    float op1 = 0;          // The left side number as a float
    float op2 = 0;          // The right side number as a float
    float answer;           // The solution to the math problem

    printf("Enter a simple math problem. For example: 1 + 1\n");
    printf("Enter here: ");
    fgets(problem, sizeof(problem), stdin);

    // The size of the user's entry
    int problem_length = sizeof(problem) / sizeof(problem[0]);

    // Parse the user's entry, a string such as '5 + 5' into it's individual operands and operator.
    // It takes into account if the user did or did not use spaces.
    // TO-DO: Do a check that the user entered a valid math problem
    for (int i = 0; i < problem_length && problem[i] != '\0'; ++i) {
        // Check if the first number is actually a number or a decimal. Once operator has been found, move on.
        if ((problem[i] >= '0' && problem[i] <= '9' || problem[i] == '.') && operator_found == false) {
            operand1[i] = problem[i];
            ++number_found;
        // Increase number found for every character in to problem up until the second operand
        } else if (problem[i] == ' ') {
            ++number_found;
            continue;
        // Check if the character is an operator
        } else if (problem[i] == '+' || problem[i] == '-' || problem[i] == '*' || problem[i] == '/') {
            operator = problem[i];
            operator_found = true;
            ++number_found;
        // Assemble the second operand as a string using number found to index the character array.
        } else {
            operand2[i - number_found] = problem[i];
        }
        
    }

    // Convert both operand strings into floats
    op1 = atof(operand1);
    op2 = atof(operand2);

    // Check the operator and solve the problem.
    switch(operator) {
        case '+':
            answer = op1 + op2;
            break;
        case '-':
            answer = op1 - op2;
            break;
        case '*':
            answer = op1 * op2;
            break;
        case '/':
            answer = op1 / op2;
            break;
        default:
            printf("Not a valid operator.");
            break;
    }

    // Show the answer.
    printf("%.2f %c %.2f = %.2f\n", op1, operator, op2, answer);
    
    return 0;
}