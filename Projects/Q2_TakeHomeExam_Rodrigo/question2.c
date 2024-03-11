#include <stdio.h>
#include <string.h>
#define error(code, message) do{fprintf(stderr, "%s\n", message); return code;}while(0)

int isPalindrome(char* word, int lengthWord){
    // Assume it is a palindrome
    int cond = 1;
    char* lp = word;
    char* rp = word + lengthWord - 1;

    // Iterate over each character from left and right, and check if they are equal
    while(lp < rp){
        if(*lp != *rp){
            cond = 0;
            break;
        }
        lp++;
        rp--;
    }

    return cond;
}

int main(int argc, char* argv[]){

    // Throw an error if the number of CLAs does not match 2
    if(argc > 2 || argc == 1){
        error(1, "Fatal Error: Invalid number of CLAs.");
    }

    // Get length of the word to be analyzed
    int lengthWord = strlen(argv[1]);

    // If cond is still 1, then it is a palindrome
    if (isPalindrome(argv[1], lengthWord)){
        printf("palindrome\n");
    }
    else{
        // Print the reversed string
        for(int i = lengthWord - 1; i >= 0; i--){
            printf("%c", argv[1][i]);
        }
        printf("\n");
    }

    return 0;
}

/*int isPalindrome(char* argv[], int lengthWord){
    int cond = 1;

    // iterate over each character to check if it is palindrome.
    for(int i = 0; i < (lengthWord / 2); i++){
        if (argv[1][i] != argv[1][lengthWord - 1 - i]){
            cond = 0;
            break;
        }
    }
    return cond;
}*/