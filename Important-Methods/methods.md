**THIS FILE INCLUDES A LIST OF IMPORTANT METHODS FOR SOFTWARE DEVELOPMENT**

# From stdio.h
* printf("mesage"); // output: message
* sprintf(buffer, message) --> sprintf(string, "I am %d years old.", 20); //string = "I am 20 years old"
* fgets(buffer, sizeBuffer, sdtin) --> fgets(string, sizeof(buffer), stdin); //string = input_user
* scanf("%type", &variable) --> scanf("%s", string) // string = input_user
* sscanf(buffer, "%type", &var) --> sscanf("12345", "%d", &num) // if returns 1, then num = 12345

# From math.h
* ceil(double) --> ceil(2.3) // returns 3.0
* floor(double) --> floor(2.3) // returns 2.0
* fabs(double) --> fabs(-234) // returns 234 (absolute value)
* fmod(double, double) --> fmod(8.2, 3) // returns 2.2 (remainder of 8.2 / 3)
* sqrt(double) --> sqrt(9) // returns 3.0
* pow(double, double) --> pow(2, 3) // returns 8.0

# From string.h and ctype.h
* strncpy(to, from, int) --> strncpy(dest, src, 5) // copies the first 5 chars from src to dest
* strcpy(to, from) --> strcpy(dest, src) // dest = src
* strncat(to, from, int) --> strncat(dest, src, 5) // concatenates the first 5 chars of src to dest
* strcat(to, from) --> strcat(dest, src) // dest += src
* strncmp(str1, str2, int) --> strncmp(str1, str2, 2) // returns 0 if the first 2 chars of str1 and str2 are the same
* strcmp(str1, str2) // returns 0 if str1 is equal to str2
* char* ptr = strchr(string, 'char') --> ptr = strchr("Hello", 'e') // returns pointer at 1
* char* ptr = strstr(string, pattern) --> ptr = strstr("Hello world", "world") // returns pointer at 6
* char* tkn = strtok(string, delimeter) -> tkn = strtok("This is a sample sentence", " ") //returns "This"
For next call, do tkn = strtok(NULL, " ") // returns "a"
* For string to lower case make and call:
    void toLowerCase(char* str){
        for(int i=0; str[i]; i++){
            str[i] = tolower((unsigned char)str[i]);
        }
    }
* For string to upper case make and call:
    void toUpperCase(char* str){
        for(int i=0; str[i]; i++){
            str[i] = toupper((unsigned char)str[i]);
        }
    }
* strdup(string) --> char* duplicate = strdup(string) // a duplicate of string is generated into duplicate

# From stdlib.h
* atof(string) --> atof("2.3") // returns a double 2.3
* atoi(string) --> atoi("5") // returns an int 5
* qsort(void* base, size_t n, size_t size, int (*compar)(const void*, const void*))
  make a compare function:

  int cmp(const void* a, const void* b){
    return ( *({type}*)a - *({type}*) b);
  }
  then call:

  qsort(array, 5, sizeof({type}), cmp);
  // note, assuming there is an array with 5 elements. type is the type of the array
* malloc() --> examples usage:
    char* strings = (char*)malloc(1000) //allocate a string dynamically
    triangle* triangle = (triangle*)malloc(sizeof(triangle)) // assume there is a struct called triangle
    node* temp = (node*)malloc(sizeof(node)) // allocates dynamically a node struct called temp.
