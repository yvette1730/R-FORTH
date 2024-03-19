#include <stdio.h> 


int main()
{
    int arr1[2][2] = {{1, 2}, {3, 4}};
    int arr1Rows = sizeof(arr1) / sizeof(arr1[0]); 
    int arr1Columns = sizeof(arr1[0]) / sizeof(arr1[0][0]);
    int arr2[2][2] = {{5, 6}, {7, 8}};
    int arr2Rows = sizeof(arr2) / sizeof(arr2[0]); 
    int arr2Columns = sizeof(arr2[0]) / sizeof(arr2[0][0]);

    int sum[arr1Rows][arr1Columns];
    int product[arr1Rows][arr1Columns]; 

    for(int i = 0; i < arr1Rows; i++)
    {
        for(int j = 0; j < arr1Columns; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }


    for(int b = 0; b < arr1Rows; b++)
    {
        for(int d = 0; d < arr1Columns; d++)
        {
            product[b][d] += arr1[b][d] * arr2[b][d];
        }
    }
    printf("Matrix Addition: \n");
    for(int i = 0; i < arr1Rows; i++)
    {
        for(int j = 0; j < arr1Columns; j++)
        {
            printf("%d ", sum[i][j]); 
        }
        printf("\n"); 
    }
    printf("Matrix Multiplication: \n");
    for(int i = 0; i < arr1Rows; i++)
    {
        for(int j = 0; j < arr1Columns; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n"); 
    }
    return 0; 
}


