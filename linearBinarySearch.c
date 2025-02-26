#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t startTime, endTime; //Variables to measure the time
    int countNumber = 100000, number, position = -1, option;
    int vector[countNumber];

    printf("Count number is:%d\n",countNumber);
    for(int i = 0; i < countNumber; i++) //Filling up the vector
        vector[i] = i;
    
   

    printf("Please, insert the number: ");
    scanf("%d", &number);

    printf("Please, select the type of search\n1 - Linear Search\n2 - Binary Search\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1: //Linear Serach
        startTime = clock();
        for(int i = 0; i < countNumber; i++){ //Comparing one by one
            if(vector[i] == number){ 
                position = i;
                break;
            } 
        }
        endTime = clock();
        break;
    
    case 2:
        startTime = clock();
        int middleVector = 0, start = 0, end = countNumber - 1, check = 1; //Variables to acess our vector

        while (check == 1 && start != end)
        {
            middleVector += (end - start) / 2; 
            if(number < vector[middleVector]) //My running number is bigger (getting the first part of the running vector) 
                end = middleVector;
            else if(number > vector[middleVector]) //My running number is smaller (getting the last part of the running vector)
                start = middleVector;
            else{ //I found the number
                position = middleVector;
                check = 0;
                break;
            }
        }

        endTime = clock();     
        break;

    default:
        break;
    }
    
    
    printf("The position is: %d\n", position);
    printf("The time used was: %f\n", (endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}