#include "railcipher.h"
#include <stdio.h>
#include <ctype.h>
char* decrypting(int argc, char* argv[], char string[]){

    char *str = strdup(string);
    int length = strlen(str);
    int rows = (length / atoi(argv[1]));
    char array[rows][atoi(argv[1])];

    int m = 1;
    int i = 0;
    int j = 0;
    int l = 0;

    while(m <= (argc - 2)){ //m < permutation length
        if(atoi(argv[i+2]) == m){ //if m == permutation order at i+2
            for(j = 0; j < rows; j++){ //start getting the rows
                array[j][i] = str[l++]; //add to array
            }
            m++; //increment the next permutation order
            i = 0; //reset the list to look through
        }else{
            i++; //increment y if m not found
        }
    }

    l = 0;

    for(i = 0; i < rows; i++){
        for(j = 0; j < atoi(argv[1]); j++){
            str[l++] = array[i][j];
        }
    }

    return str;

}