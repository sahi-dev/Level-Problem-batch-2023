/*Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy*/





#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void changeCase(FILE *source, FILE *destination, int option) {
    char ch;
    int previousChar = '\n';

    while ((ch = fgetc(source)) != EOF) {
        switch (option) {
            case 'u':
                fputc(toupper(ch), destination);
                break;
            case 'l':
                fputc(tolower(ch), destination);
                break;
            case 's':
                if (previousChar == '.' || previousChar == '?' || previousChar == '!') {
                    fputc(toupper(ch), destination);
                } else {
                    fputc(tolower(ch), destination);
                }
                break;
            default:
                fputc(ch, destination);
                break;
        }
        previousChar = ch;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s source_file destination_file [option]\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Error opening destination file.\n");
        fclose(source);
        return 1;
    }

    int option = 'n';  // Default option: normal copy
    if (argc >= 4) {
        option = argv[3][0];
    }

    changeCase(source, destination, option);

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}