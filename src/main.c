#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "inputParse.h"

int main(int argc, char** argv) {
        struct userInput input;
        inputStructInit(&input);
        
        int ret;
        ret = parse(argc, argv, &input);
        if (ret == 1) {
                fprintf(stderr, "Not enough arguments\n");
                return EXIT_FAILURE;
        } else if (ret == 2) {
                fprintf(stderr, "Invalid optional argument\n");
                return EXIT_FAILURE;
        } else if (ret == 3) {
                fprintf(stderr, "No file arguments given\n");
                return EXIT_FAILURE;
        } else if (ret == -1) {
                fprintf(stderr, "System Error\n");
                return EXIT_FAILURE;
        }
        
        printUserInput(&input);
        
        return EXIT_SUCCESS;
}