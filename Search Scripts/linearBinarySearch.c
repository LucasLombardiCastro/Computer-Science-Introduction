#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t startTime, endTime; //Variables to measure the time
    int countNumber, number, position = -1, option;

    printf("Please, insert the count number:",countNumber);
    scanf("%d", &countNumber);
    if(countNumber <= 0){
        printf("Please, insert a positive value\nClosing program...\n");
        return 0;
    }

    int *vector = malloc(countNumber * sizeof(int)); //Allocating the memory
    if(vector == NULL){ //Checking if there is avaible memory
        printf("Fail trying to allocate memory :(\nClosing program...\n");
        return 0;
    }

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
        int runningMiddleVector = 0, start = 0, end = countNumber - 1; //Variables to acess our vector

        while (start < end)
        {
            runningMiddleVector = start + (end - start) / 2; 
            if(number < vector[runningMiddleVector]) //My running number is bigger (getting the first part of the running vector) 
                end = runningMiddleVector;
            else if(number > vector[runningMiddleVector]) //My running number is smaller (getting the last part of the running vector)
                start = runningMiddleVector;
            else if(number == vector[runningMiddleVector]){ //I found the number
                position = runningMiddleVector;
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

    free(vector);

    return 0;
}