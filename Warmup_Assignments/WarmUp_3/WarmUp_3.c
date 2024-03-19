#include <stdio.h> 
int main()
{
    int array1[5] = { 1,2,3,4,5 };
    int sum = 0; 
    for(int i; i < 5; i++)
    {
        sum = array1[i] + sum; 
    }
    printf("The sum is %d", sum); 
}