#include <stdio.h> 
#include <stdlib.h> 
#include "patients.h"



// ---------------------------- MAIN FUNCTION ----------------------------
int main(){
    int option, id, stop = 0;

    while(stop == 0){
        printf("\n---Welcome to the Patitent Record System.\n1. Add a Patient.\n2.Print all the records\n3.Count how many records there are.\n4.Find a record by ID.\n5.Edit a record\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if(createPatientFile() == 1)
                printf("Patient added with sucess!\n");
            else 
                printf("Failed\n");
            break;
        
        case 2:
            readingData();
            break;

        case 3:
            printf("\nIn the data base, there are %d patients.\n", countOfRecords());
            break;
        
        case 4:
            printf("Please, insert the ID: ");
            scanf("%d", &id);
            printingByPosition(positionRecord(id));
            break;

        case 5:
            printf("Please, insert the ID: ");
            scanf("%d", &id);
            editingRecord(id, creatingPatient());
            break;
    
        default:
            break;
        }

    printf("\nDo you want to exit?\n1 - Yes\n0 - No\n");
    scanf("%d", &stop);
    }
    return 0;
}