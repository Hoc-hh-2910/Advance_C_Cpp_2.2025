#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

jmp_buf buf;
int check;
char *error_message;

#define TRY if((check = setjmp(buf)) == 0)
#define CATCH else if(check != NO_ERROR)
#define THROW(x, error_message) printf("%s", error_message); longjmp(buf, x)

enum ErrorCodes
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCUlATION_ERROR
};

void readFile(){
    printf("Reading file...\n");
    THROW(FILE_ERROR, "File not found\n");
}

void networkOperation(){
    printf("Network operation...\n");
    THROW(NETWORK_ERROR, "Network error\n");
}

void calculateData(){
    printf("Calculating data...\n");
    THROW(CALCUlATION_ERROR, "Calculation error\n");
}

int main(int argc, char const *argv[])
{
    check = NO_ERROR;

    TRY
    {
        //readFile();
        //networkOperation();
        calculateData();
    }
    CATCH
    {
        printf("An error occurred: %d\n", check);
    }
    return 0;
}