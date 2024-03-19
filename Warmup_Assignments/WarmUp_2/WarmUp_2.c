#include <stdio.h> 
#include <stdlib.h> 


int main(int argc, char * * argv)
{
    int firstNum; 
    int secondNum; 

    printf("Enter your first number: ");
    scanf("%d", &firstNum);

    printf("Enter your second number: ");
    scanf("%d", &secondNum);

    int sum = firstNum + secondNum;
    printf("Sum:  %d + %d = %d", firstNum, secondNum, sum);
    int subtraction = firstNum - secondNum;
    printf("\nDifference:  %d - %d = %d", firstNum, secondNum, subtraction);
    int multiple = firstNum * secondNum;
    printf("\nMultiplication:  %d * %d = %d", firstNum, secondNum, multiple);
    int division = firstNum / secondNum;
    printf("\nDivision: %d / %d = %d", firstNum, secondNum, division);
    
}