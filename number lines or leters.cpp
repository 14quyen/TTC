/**
 * C program to append data to a file
 * Source: codeforwin.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
void readFile(FILE * fPtr);
int countLettersInFile(FILE * fPtr);
int numberlines(FILE * fPtr);

int main()
{
    /* File pointer to hold reference of input file */
    FILE *fPtr;
    char filePath[100];

    char dataToAppend[BUFFER_SIZE];


    /* Input file path to remove empty lines from user */
    printf("Enter file path: ");
    scanf("%s", filePath);

    /*  Open all file in append mode. */
    fPtr = fopen(filePath, "a");


    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }


    
	/* Input data to append from user */
    printf("\nEnter data to append: ");
    
	while(1) // Repeat inputing until press "Exit"
	{	
		fflush(stdin);          // To clear extra white space characters in stdin
	    gets(dataToAppend);
	    
		if(strcmp(dataToAppend, "Exit")==0){  // Break if "Exit" entered.
			printf("\nBye bye!");
			break;			
		}
	    
		/* Append data to file */
	    fputs(dataToAppend, fPtr);
	    fputc('\n', fPtr); // Adding newline charater
	}	 

    /* Reopen file in read mode to print file contents */
    fPtr = freopen(filePath, "r", fPtr);

    /* Print file contents after appending string */
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n\n");
    readFile(fPtr);
    
    /* Print number of letters in file */
    fPtr = freopen(filePath, "r", fPtr);
    printf("\n Number of letters in the file is: %d", countLettersInFile(fPtr));
    /*Print number of lines in file*/
    fPtr = freopen(filePath, "r", fPtr);
    printf("\n Number of lines in the file is: %d",numberlines(fPtr));
   


    /* Done with file, hence close file. */
    fclose(fPtr);

    return 0;
}



/**
 * Reads a file character by character 
 * and prints on console.
 * 
 * @fPtr    Pointer to FILE to read.
 */
void readFile(FILE * fPtr)
{
    char ch;

    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
};

/**
 * Reads a file character by character 
 * and count number of letters (A-Z) or (a-z).
 * 
 * @fPtr    Pointer to FILE to read.
 */
int countLettersInFile(FILE * fPtr)
{
    char ch;
	int count = 0;
    do 
    {
        ch = fgetc(fPtr);

        //putchar(ch);
        if (((ch >= 65) && (ch<=90)) || ((ch>=97) && (ch<=122)))
		{
        	count++;
        }

    } while (ch != EOF);    
    
    return count;
}
int numberlines(FILE * fPtr){
	int count = 0; // Line counter (result)
	char c;



	// Extract characters from file and store in character c
	do{
		c = getc(fPtr);
		 
		if (c =='\n') // Increment count if this character is newline
			count++;
	}
	while (c != EOF);
	return count;
	
}


