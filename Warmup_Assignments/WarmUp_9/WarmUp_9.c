#include <stdio.h> 
 

//create the file 
//add writing into the file
//close the file 

//while the file still has times of code 
//print line 
int main()
{FILE* fileTest; 
char fileText[] = "Hello, World!"; 
char buffer[100];  

fileTest = fopen("WarmUp_9.txt", "w");
fprintf(fileTest, "%s", fileText);
fclose(fileTest); 


//reading the data 
fileTest = fopen("WarmUp_9.txt", "r");
fgets(buffer, sizeof(buffer), fileTest);
fclose(fileTest);

printf("%s\n", buffer); 





}
