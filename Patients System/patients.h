#define DATA_FILE "patientsData.dat"

typedef struct{
    int day;
    int month;
    int year;
} date;

typedef struct{
    unsigned int ID;
    char name[50];
    date birthDate;
} structPatient;


structPatient *creatingPatient();
int createPatientFile();
int countOfRecords();
void readingData();
int positionRecord (int id);
void printingByPosition(int position);
void editingRecord(int ID, structPatient *patient);
