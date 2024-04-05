#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addEntry(FILE *fp)
{
    char entry[1000];
    printf("Enter your diary entry:\n");
	scanf("%s",entry);
	fprintf(fp,"\n%s",entry);
}

void viewEntries(FILE *fp) 
{
    char ch;
    rewind(fp); 
    printf("Your Diary Entries:\n");
    while ((ch= fgetc(fp))!= EOF) 
	{
    	putchar(ch);
    }
}

int main() {
    FILE *fp;
    int choice;
    fp = fopen("diary.txt","a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    while(1){
        printf("\n\nPersonal Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addEntry(fp);
                break;
            case 2:
                viewEntries(fp);
                break;
            case 3:
                printf("Exiting diary...\n");
                fclose(fp);
                return 0;
            default:
                printf("Invalid choice");
            }
        }
    }
