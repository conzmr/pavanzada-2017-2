typedef struct dictElement{
  char *key;
  void *value;
} DictElement;


typedef struct dict {
  DictElement *elements;
  unsigned int size; //size cannot be negative, this way compiler help me
} Dict;


//what is not in heap, dies when function ends
//what is in heap, dies until program ends
Dict * initDictionary(unsigned int, int *);
//Here I create a container with size and dictionary
//newDict is just where I will save the direction


void upsertDictionary(Dict *, char *, void *, int *); //3rd int is the error code
