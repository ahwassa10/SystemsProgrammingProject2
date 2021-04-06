struct stringList {
        char** data;
        size_t size;
        size_t maxSize;
};

int sl_init(struct stringList*);

int sl_append(struct stringList*, char*);

void sl_destroy(struct stringList*);