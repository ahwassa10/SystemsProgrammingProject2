
struct userInput {
        char** firstFile;
        size_t numberOfFileArguments;
        
        size_t dOption;
        size_t fOption;
        size_t aOption;
        char* sOption;
};

bool isOption(char*);
void inputStructInit(struct userInput*);
int parsePositive(char*);
int parseOption(struct userInput*, char*);
void printUserInput (struct userInput*);
int parse(int, char**, struct userInput*);