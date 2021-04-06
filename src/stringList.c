#define INIT_SIZE 2
#include <stdlib.h>


struct stringList {
        char** data;
        size_t size;
        size_t maxSize;
};

// Initializes the stringList data structure.
// Return 0 on Success. Return 1 on Failure.
int sl_init(struct stringList* sl) {
        sl->data = malloc(sizeof(char*) * INIT_SIZE);
        
        if (sl->data == NULL) {
                return 1;
        }
        
        sl->size = 0;
        sl->maxSize = INIT_SIZE;
        
        return 0;
}

// Appends the object string to the end of the list. 
// Automatically increases the size of the list and 
// update the size and maxSize members of the struct.
// Return 0 on Success. Return 1 on Failure.
int sl_append(struct stringList* sl, char* object) {
        size_t currentMax = sl->maxSize;
        
        if (sl->size == currentMax) {
                size_t newMax = currentMax * 2;
                sl->data = realloc(sl->data, sizeof(char*) * newMax);
                
                if (sl->data == NULL) {
                        return 1;
                }
                
                sl->maxSize = newMax;
        }
        
        sl->data[sl->size] = object;
        sl->size += 1;
        
        return 0;
}

// Frees the data member of the struct.
void sl_destroy(struct stringList* sl) {
        free(sl->data);
}