# SystemsProgrammingProject2



Interface for parse(int, char**):

Used to fill in a struct containing all the input information information:
struct input = {
        char** firstFile;
        size_t numberOfFileArguments;
        
        size_t dOption;
        size_t fOption;
        size_t aOption;
        char* sOption;
};

Specification of the parse function
1) Can handle optional arguments in any order.
2) Can handle repeats of optional arguments
3) Optional and file arguments can be intermixed.
4) Errors on no file arguments.
5) Can handle any number of file arguments.


Return Values:
        0 - successfully parsed input. Program can proceed to the next step.
        1 - Not enough arguments
        2 - Invalid optional arguments.
        3 - No file arguments.
       -1 - System error.
        