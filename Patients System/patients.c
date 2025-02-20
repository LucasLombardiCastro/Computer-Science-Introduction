#include <stdio.h>
#include <stdlib.h>
#include "patients.h"

//Aux Function to alloc memory ant get the data from input
structPatient *creatingPatient(){
    structPatient *patient = malloc(sizeof(structPatient));
    if(patient == NULL)
        printf("There is not enought memory\n");

    
    //Getting Data 
    printf("\nPlease, insert the ID:");
    scanf("%u", &patient->ID); 
    printf("\nPlease, insert the Name:");
    scanf("%s", patient->name); 
    printf("\nPlease, insert the Day of birth:");
    scanf("%d", &patient->birthDate.day); 
    printf("\nPlease, insert the Month of birth:");
    scanf("%d", &patient->birthDate.month); 
    printf("\nPlease, insert the Year of birth:");
    scanf("%d", &patient->birthDate.year);

    return patient;
}

//Main function to create an object an add it on Data File
int createPatientFile(){
    //Opening the File
    FILE *data = fopen(DATA_FILE, "ab");
    if(data == NULL){
        printf("There is a ERROR with the Data Base :( \n)");
        return 0; 
    }

    //Creating the Patient with the input and writing in the file
    structPatient *patient = creatingPatient(); 
    int n = fwrite(patient,sizeof(structPatient),1,data);
    if(n == 0)
        return 0;

    free(patient);
    fclose(data);
    return 1;
}

int countOfRecords(){ //Couting records from a Binary File
    int quant = 0, n;
    FILE *data = fopen(DATA_FILE,"rb");
    if(data == NULL){
        printf("There is a problem opening the Data Base\n");
        return 0;        
    }

    structPatient *tempPatient = (structPatient*) calloc(1,sizeof(structPatient)); //Temp object just to stock the currente data while reading it

    while(fread(tempPatient,sizeof(structPatient),1,data) == 1) //Reading the objects one by one (It will stop when EOF is gotten)
        quant++;
    
    
    free(tempPatient);
    fclose(data);

    return quant;
}

void readingData(){ //Reading all the data from a binary file
    int quant = countOfRecords();
    structPatient *currentPatient = malloc(sizeof(structPatient)); //Not a vector, because we will print each obj one by one

    FILE *data = fopen(DATA_FILE, "rb");
    if(data == NULL){
        printf("There is a problemn with the Data Base:(\n");
        return;
    }    

    printf("\n\nNumber of Records: %d\n",countOfRecords());
    while(fread(currentPatient,sizeof(structPatient),1,data)) //Reading and printing data one by one
        printf("ID: %d\nName: %s\nBirth Date: %d/%d/%d\n\n",currentPatient->ID,currentPatient->name,currentPatient->birthDate.day,currentPatient->birthDate.month,currentPatient->birthDate.year);
   
    fclose(data);
    return;
}



int positionRecord (int id){ //Returning the position of a record by ID
    FILE *data = fopen(DATA_FILE, "rb");
    if(data == NULL){
        printf("There is a problemn with the Data Base:(\n");
        return -1;
    }  

    structPatient *currentPatient = malloc(sizeof(structPatient));
    int position = 0;
    while(fread(currentPatient,sizeof(structPatient),1,data) == 1){ //Reading one by one each record while EOF is not gotten
        if(currentPatient->ID == id)
            break;
        else
            position++;
    }

    //printf("Position Record: %d", position);

    free(currentPatient);
    fclose(data);
    return position; 
}

void printingByPosition(int position){ //Gave a position, print all the information of this record
    structPatient *patient = malloc(sizeof(structPatient));
    FILE *data = fopen(DATA_FILE, "rb");
    if(data == NULL){
        printf("There is a problem with the Data Base:(\n");
        return;
    }  
    
    fseek(data,position*sizeof(structPatient),SEEK_SET);
    // Finding by ID and printing the object
    if(fread(patient,sizeof(structPatient),1,data) == 0){
        printf("ERRO while reading the document");
        return;
    }

    printf("\nID: %d\nName: %s\nBirth Date: %d/%d/%d\n",patient->ID,patient->name,patient->birthDate.day,patient->birthDate.month,patient->birthDate.year);
    
    free(patient);
    fclose(data);
    return;
}

void editingRecord(int ID, structPatient *patient){ //Rewriting a patient in a existing patient
    FILE *data = fopen(DATA_FILE, "r+b");
    if(data == NULL){
        printf("There is a problemn with the Data Base:(\n");
        return;
    } 

    fseek(data,positionRecord(ID) * sizeof(structPatient), SEEK_SET);
    fwrite(patient, sizeof(structPatient),1,data);

    free(patient);
    fclose(data);
    return;
}

