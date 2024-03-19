#include <stdio.h> 

int factorialSum(int num)
{
    if(num <= 0 )
    {
        return 1;
    }
    else
    {
        int curNum = num;
        curNum--;
        return num * factorialSum(curNum);
    }
}

int main()
{
    int num = 5;
    printf("Factorial of the number %d \n", factorialSum(num));
}
