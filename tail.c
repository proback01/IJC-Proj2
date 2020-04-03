#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1023 + 2 // 1023 characters + EOF + \0

//Modes
#define DEFAULT_MODE 0
#define TO_END_MODE 1 // Mode when program is ran with argument -n +x, prints lines from x to the end


int processArguments(int argc, char** argv, int* linesNum, char** filename, bool* usingStdin, int* mode);

int main(int argc, char** argv) {
    int mode = DEFAULT_MODE;
    bool usingStdin = true;
    int linesNum = 10; //Number of lines that will be printed
    char* filename;

    //Processing arguments and checking if arguments were proccessed correctly
    if(processArguments(argc, argv, &linesNum, &filename, &usingStdin, &mode) == EXIT_FAILURE)
	return EXIT_FAILURE;

    printf("Mode: %i\n", mode);
    printf("Using stdin: %i\n", usingStdin);

    return EXIT_SUCCESS;
}

/* 
 * Function processes arguments
 * If there is argument -n, function sets linesNum
 * Function sets filename
 * Function sets usingStdin if arguments dont contain file to read from
 * Function sets mode "to the end", if there is argument -n +x
 */

int processArguments(int argc, char** argv, int* linesNum, char** filename, bool* usingStdin, int* mode) {
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
	    *usingStdin = false;
	}
    } 
    return EXIT_SUCCESS;
}
