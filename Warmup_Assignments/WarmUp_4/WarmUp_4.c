#include <stdio.h> 

int main()
{
    char word[] = "car";
    int curIndex = 0;
    int newWordSize = sizeof(word)-1;
    char newWord[newWordSize]; 
    for(int i = sizeof(word) - 2 ; i >= 0; i--)
    {
        char curChar  = word[i];
        newWord[curIndex] = curChar;
        curIndex++; 
    }

    printf("The word reveresed is %s", newWord);
}