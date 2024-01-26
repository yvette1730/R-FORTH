#include <stdio.h> 


int linearSearch(int arr[], int size, int num)
{
    int index = -1; 
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            index = i; 
            break;
        }
    }
    return index; 
}

int main() 
{
    int findNum = 8; 
    int arrNums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = (sizeof(arrNums) / sizeof(arrNums[0]));
    int index = -1; 
    index = linearSearch(arrNums, size, findNum);
    if(index != -1)
    {
        printf("The number %d was found at index %d\n", findNum, index);
    }
    else 
    {
        printf("The number %d was not found\n", findNum); 
    }
}
