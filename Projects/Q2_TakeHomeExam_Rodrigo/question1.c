#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* findAndReplace(char* str, char* pattern, char* altPattern){

    // Find the number of instances of 'pattern' in a copy of 'str'
    char* copy = str;
    int numberOfFoundPatterns = 0;
    while((copy = strstr(copy, pattern)) != NULL){
        numberOfFoundPatterns++;
        copy += strlen(pattern);
    }

    // If no pattern was found in str, then return the original str
    if(!numberOfFoundPatterns)
        return str;

    // lenght of new string = length of initial string - N(length of pattern) + N(length of altPattern)
    int size = strlen(str) + numberOfFoundPatterns * (strlen(altPattern) - strlen(pattern));

    // Allocating memory in the heap
    char* newString = (char*)malloc(size);

    // First pattern
    char* positionPattern = strstr(str, pattern);

    int position = 0;
    int patternLen = strlen(pattern);

    // As long as the pattern is found in str, the string will be copied up to where the pattern was located (position)
    // Then, concatenate the altPattern instead of pattern. Finally, increment the str pointer to keep checking if
    // pattern is found again
    while(positionPattern){
        position = positionPattern - str;
        strncat(newString, str, position);
        strcat(newString, altPattern);
        str = str + position + patternLen;
        positionPattern = strstr(str, pattern);
    }
    strcat(newString, str);

    return newString;
}

int main(){
    char str[97] = "Hello nice. I am glad that you are my friend and hopefully you will always be my friend. Love!";
    char pattern[7] = "nice";
    char altPattern[6] = "world";

    char* nstr = findAndReplace(str, pattern, altPattern);

    printf("%s\n", nstr);


    return 0;
}