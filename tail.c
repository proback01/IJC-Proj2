#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1025 // 1023 characters + EOF + \0

//Modes
#define DEFAULT_MODE 0
#define TO_END_MODE 1 // Mode when program is ran with argument -n +x, prints lines from x to the end

int processArguments(int argc, char** argv, int* linesNum, char** filename, int* mode);
int runTail(int linesNum, char* filename);
int runToEndTail(int startFrom, char *filename);

int main(int argc, char** argv) {
    int mode = DEFAULT_MODE;
    int linesNum = 10; //Number of lines that will be printed
    char* filename = NULL;

    //Processing arguments and checking if arguments were proccessed correctly
    if(processArguments(argc, argv, &linesNum, &filename, &mode) == EXIT_FAILURE)
        return EXIT_FAILURE;


    if(mode == DEFAULT_MODE)
        runTail(linesNum, filename);
    else if(mode == TO_END_MODE)
        runToEndTail(linesNum, filename);

    return EXIT_SUCCESS;
}

/*
 * Function processes arguments
 * If there is argument -n, function sets linesNum
 * Function sets filename
 * Function sets usingStdin if arguments dont contain file to read from
 * Function sets mode "to the end", if there is argument -n +x
 */

int processArguments(int argc, char** argv, int* linesNum, char** filename, int* mode) {
    if(argc > 4) {
        fprintf(stderr, "Spatny pocet zadanych argumentu\n");
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++) {
        if(strcmp("-n", argv[i]) == 0) { //Checking for argument -n
            //After -n there is no number
            if(i + 1 == argc) {
                fprintf(stderr, "Po argumentu -n musi nasledovat cislo\n");
                return EXIT_FAILURE;
            }

            // Checking if there is + in front of number -n
            if(*argv[i+1] == '+')
                *mode = TO_END_MODE;

            char* endPtr;
            *linesNum = strtol(argv[i+1], &endPtr, 10); // Parsing number of lines
            i++;
        }
        else { //Name of file
            *filename = argv[i];
        }
    }
    return EXIT_SUCCESS;
}

int runTail(int linesNum, char* filename) {
    bool overflowMsg = false; // Variable indicates if overflow msg was alread written
    char* lines = malloc(sizeof(char*) * linesNum * MAX_LINE_LEN); // Allocation of dynamic array of static arrays
    FILE* file = fopen(filename, "r");

    //Checking if file was opened
    if(file == NULL) {
        fprintf(stderr, "Nepodarilo se otevrit soubor\n");
        free(lines);
        return EXIT_FAILURE;
    }

    int lineIndex = 0;
    int charIndex= 0;
    int c;
    while((c = getc(file)) != EOF) {
        lines[(lineIndex * MAX_LINE_LEN) + charIndex] = (char)c; // Storing current character

        if(c == '\n' || charIndex == MAX_LINE_LEN - 2) { // Newline character or overflow
            if(charIndex == MAX_LINE_LEN - 2 && c != '\n') { // Overflow
                if(!overflowMsg) {
                    fprintf(stderr, "Nepodarilo se nacist cely soubor\n");
                    overflowMsg = true;
                }
                lines[(lineIndex * MAX_LINE_LEN) + (MAX_LINE_LEN - 2)] = '\n';
            }

            lines[(lineIndex * MAX_LINE_LEN) + (charIndex + 1)] = '\0'; // Ending of line
            lineIndex++;
            charIndex = 0;

            // If array with lines is full, overwriting first line
            if(lineIndex >= linesNum)
                lineIndex = 0;
        }
        else { // Normal character
            charIndex++;
        }
    }

    if(charIndex != 0) // Last line is valid line
        lines[lineIndex * MAX_LINE_LEN + charIndex] = '\0';
    else { // Last line is only EOF
        lineIndex--; // Getting back one line
        if(lineIndex == -1)
            lineIndex = linesNum - 1;
    }


    //Printing result
    for(int i  = lineIndex + 1; i < linesNum; i++)
        printf("%s", &lines[i * MAX_LINE_LEN]);

    for(int i = 0; i <= lineIndex; i++)
        printf("%s", &lines[i * MAX_LINE_LEN]);


    fclose(file);
    free(lines);
    return EXIT_SUCCESS;
}

int runToEndTail(int startFrom, char *filename) {
    bool overflowMsg = false; // Variable indicates if overflow msg was alread written
    FILE* file = fopen(filename, "r");

    //Checking if file was opened
    if(file == NULL) {
        fprintf(stderr, "Nepodarilo se otevrit soubor\n");
        return EXIT_FAILURE;
    }

    int lineIndex = 0;
    int charIndex= 0;
    int c;
    while((c = getc(file)) != EOF) {
        if(lineIndex >= startFrom - 1)
            putc((char)c, stdout); // Storing current character

        if(c == '\n' || charIndex == MAX_LINE_LEN - 2) { // Newline character or overflow
            if(charIndex == MAX_LINE_LEN - 2 && c != '\n') { // Overflow
                if(!overflowMsg) {
                    fprintf(stderr, "Nepodarilo se nacist cely soubor\n");
                    overflowMsg = true;
                }
                putc('\n', stdout);
            }
            lineIndex++;
            charIndex = 0;
        }
        else { // Normal character
            charIndex++;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}