#include "railcipher.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

//Error Verification
#define WRONG_ARGS 1
#define NOT_POS_INT 2
#define NOT_PERMUTATION 3
#define OVER_PERM 4
#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

int check_integer(char* str){
	if(strlen(str) == 0)
		return FALSE;
	if(str[0] == '-' || str[0] == '+')
		return FALSE;
	while(*str)
		if(!isdigit(*(str++)))
			return FALSE;
	return TRUE;
}

int valid_permutation(int argc, char* argv[]){
    int flag[atoi(argv[1])+1]; //Create array with length of m
    flag[0] = TRUE; //Set flag[0] to 1

    for(int i = 2; i < argc; i++){ //Fill the array with TRUE if found in the permutation
        flag[atoi(argv[i])] = TRUE;
    }

    for(int i = 0; i < atoi(argv[1])+1; i++){ //Check if all slots are filled with TRUE (1)
        if(flag[i] != TRUE){
            return FALSE;
        }
    }

    return TRUE;
}

int main(int argc, char *argv[]){

    //Error checking

    for(int i = 1; i < argc; i++){
        if(!check_integer(argv[i])){
            printf("railcipher: Fatal error! First CLA must be a valid integer.");
		    error(NOT_POS_INT, "railcipher: Fatal error! First CLA must be a valid integer.");
        }
    }

    if(!valid_permutation(argc, argv)){
        printf("railcipher: Fatal error! The encryption key passed as CLAs is not valid.");
        error(NOT_PERMUTATION, "railcipher: Fatal error! The encryption key passed as CLAs is not valid.");
    }

    if(atoi(argv[1]) > 26){
        printf("Fatal error! The encryption key length cannot exceed 26.");
        error(OVER_PERM, "Fatal error! The encryption key length cannot exceed 26.");
    }

    if(atoi(argv[1]) != (argc - 2)){
        printf("railcipher: Fatal Error! Incorrect command-line arguments provided!");
		error(WRONG_ARGS, "railcipher: Fatal Error! Incorrect command-line arguments provided!");
    }

    //Loop for the encryption, decryption, and program termination

    while(TRUE){

        char choice[200], string[1000], input[1200];

        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s %[^\n]", choice, string);

        // printf("Choice : %s\n", choice); //TEST
        // printf("String : %s\n", string); //TEST
        
        char* encryption_result;
        char* decryption_result;
        
        if(strcmp(choice, "encrypt") == 0){

            encryption_result = encrypting(argc, argv, string);
            printf("%s\n", encryption_result);

        }else if(strcmp(choice, "decrypt") == 0){

            decryption_result = decrypting(argc, argv, string);
            printf("%s\n", decryption_result); 

        }else if(strcmp(choice, "quit") == 0){

            break;

        }else{

            printf("Invalid input entered\n");

        }

    }
    
    return 0;

}

//Remove spaces and put it in array
//Just array manipulation and use double for loop
//Fatal error after 26
//Check integer function created in math.c file and check if all are positive ints
//Make sure argv[2] to end are perfect permutation (make sure it goes from 1 to 7 for example for length 7)
//Order of n algorithm needed to verify
//Start with for loop to make a flag array
//Also make sure its within range
//1. Encrypt 2. Decrypt 3. Main (Files)
//fgets so get string?
//Quit in main to break the loop
//Invalid command resets while loop