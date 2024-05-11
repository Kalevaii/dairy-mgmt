#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
#define MAX_ENTRY_SIZE 500
 
// Function to add new daairyyy 
void addEntry()
{
    char entry[500];
    printf(
        "Enter your diary entry (max 500 characters):\n");
    getchar(); // Consume the newline character left in the
               // buffer
    fgets(entry, sizeof(entry), stdin);
 
    //to  Get present date and time
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S", tm_info);
 
    // Append the entry to the diary file
    FILE* file = fopen("diary.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]\n%s\n\n", timestamp, entry);
        fclose(file);
        printf("Entry added successfully!\n");
    }
    else {
        printf("Error: Could not open the diary file.\n");
    }
}
 
// Function to display all previoud diary entities
void viewEntries()
{
    char line[MAX_ENTRY_SIZE];
    FILE* file = fopen("diary.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    }
    else {
        printf("Error: Could not open the diary file.\n");
    }
}
 
// main fuction
int main()
{
    int choice;
 
    // using do while loop until it gets exit
    do {
        // main dashboard
        printf("\nPersonal Diary Application\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        // select a choice
        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            printf("Exiting the diary application. "
                   "BYEEEEEEEEEEEEEEEE!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid "
                   "option.\n");
        }
    } while (choice != 3);
 
    return 0;
}