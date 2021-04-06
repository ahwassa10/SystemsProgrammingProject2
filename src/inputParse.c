#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringList.h"

struct userInput {
        char** firstFile;
        size_t numberOfFileArguments;
        
        size_t dOption;
        size_t fOption;
        size_t aOption;
        char* sOption;
};

bool isOption(char* argument) {
        if (strncmp(argument, "-", 1) == 0) {
                return true;
        } else {
                return false;
        }
}

void inputStructInit(struct userInput* input) {
        input->firstFile = NULL;
        input->numberOfFileArguments = 0;
        input->dOption = 1;
        input->fOption = 1;
        input->aOption = 1;
        input->sOption = ".txt";
}

// Parses a string into a positive number (and zero).
// -1: Failed to parse
// >0 : The parsed number.
int parsePositive(char* argument) {
        size_t argLength = strlen(argument);
        
        for (int i = 0; i < argLength; i++ ) {
                char charAt = argument[i];
                if (!isdigit(charAt)) {
                        return -1;
                }
        }
        size_t number = atoi(argument);
        return number;
}
                

// Parses the optional arguments
// 0 : Success
// 1: Invalid option or numeric.
int parseOption(struct userInput* input, char* argument) {
        int parseRet = 0;
        
        if (!strncmp(argument, "-d", 2)) {
                parseRet = parsePositive(&argument[2]);
                if (parseRet <= 0) {
                        fprintf(stderr, "Invalid numeric for -d\n");
                        return 1;
                } else {
                        input->dOption = parseRet;
                }
                
        } else if (!strncmp(argument, "-f", 2)) {
                parseRet = parsePositive(&argument[2]);
                if (parseRet <= 0) {
                        fprintf(stderr, "Invalid numeric for -f\n");
                        return 1;
                } else {
                        input->fOption = parseRet;
                }
                
        } else if (!strncmp(argument, "-a", 2)) {
                parseRet = parsePositive(&argument[2]);
                if (parseRet <=0) {
                        fprintf(stderr, "Invalid numeric for -a\n");
                        return 1;
                } else {
                        input->aOption = parseRet;
                }
                
        } else if (!strncmp(argument, "-s", 2)) {
                input->sOption = &argument[2];
                
        } else {
                fprintf(stderr, "%s is an invalid optional argument\n", argument);
                return 1; 
        }
        
        return 0;
}

void printUserInput (struct userInput* input) {
        for (int i = 0; i < input->numberOfFileArguments; i++) {
                printf("%s\n", input->firstFile[i]);
        }
        
        printf("-d is %ld\n", input->dOption);
        printf("-f is %ld\n", input->fOption);
        printf("-a is %ld\n", input->aOption);
        printf("-s is %s\n", input->sOption);
        
}

// -1: System Error
// 0: Success
// 1: Not enough arguments
// 2: Invalid optional argument
// 3: No file arguments given.
int parse(int argc, char** argv, struct userInput* inputStruct) {
        if (argc < 2) {
                return 1;
        }
        
        struct stringList fileArguments;
        if (sl_init(&fileArguments)) {
                return -1;
        }
        
        int ret;
        for (int i = 1; i < argc; i++) { 
                char* argument = argv[i];
                
                if (isOption(argument)) {
                        ret = parseOption(inputStruct, argument);
                        if (ret == 1) {
                                sl_destroy(&fileArguments);
                                return 2;
                        }
                } else {
                        ret = sl_append(&fileArguments, argument);
                        if (ret) {
                                sl_destroy(&fileArguments);
                                return -1;
                        }
                }
        }
        
        if (fileArguments.size == 0) {
                sl_destroy(&fileArguments);
                return 3;
        } else {
                inputStruct->numberOfFileArguments = fileArguments.size;
                inputStruct->firstFile = fileArguments.data;
        }
        return 0;
}
                
        