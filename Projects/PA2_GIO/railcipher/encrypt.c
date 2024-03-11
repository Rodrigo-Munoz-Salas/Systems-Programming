#include "railcipher.h"
#include <stdio.h>
#include <ctype.h>
char* encrypting(int argc, char* argv[], char string[]){

    //Remove non alpha characters (anything non alphabetical)
    char *str = strdup(string);
    int i, j, k, l, m;

    for(i = 0, j = 0; str[i] != '\0'; i++){
        if(isalpha(str[i])){
            str[j++] = tolower(str[i]); //Make everything lowercase
        }
    }
    str[j] = '\0';
    char *strCopy = strdup(str);

    //Create the array and add the letters
    int rows = (strlen(str) + (atoi(argv[1]) - 1)) / atoi(argv[1]); // rows = (a + (b - 1)) / b
    char array[rows][atoi(argv[1])];

    for(i = 0; i < rows; i++){
        for(j = 0; j < atoi(argv[1]); j++){
            array[i][j] = *str++;
        }
    }

    //Fill the empty slots in the array
    int empty = (rows * atoi(argv[1])) - strlen(strCopy); // empty = (rows * columns) - string length
    int ascii_val = 122 - empty; // ascii code of z - the number of empty slots
    k = atoi(argv[1]) - empty; // index to start at = number of permutations - number of empty slots

    while(ascii_val != 122){ //while we havent reached z
        ascii_val++; //increment to start at the right letter
        array[rows - 1][k++] = (char)ascii_val; //add the value to the last row and increment the columns until the end
    }

    //Create the ciphertext
    l = 0;
    m = 1;
    i = 0;

    while(m <= (argc - 2)){ //m < permutation length
        if(atoi(argv[i+2]) == m){ //if m == permutation order at i+2
            for(j = 0; j < rows; j++){ //start getting the rows
                str[l++] = toupper(array[j][i]); //add to str
            }
            m++; //increment the next permutation order
            i = 0; //reset the list to look through
        }else{
            i++; //increment y if m not found
        }
    }
    str[l] = '\0'; //add and endline to str
    
    return str;

}