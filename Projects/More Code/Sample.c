// Part 1 :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findAndReplace(char *str, char *pattern, char *altPattern) {

    if(str == NULL || pattern == NULL || altPattern == NULL){
        return NULL;
    }

    int strLen = strlen(str);
    int patLen = strlen(pattern);
    int altLen = strlen(altPattern);
    int index = 0;
    char *result = (char *) malloc (strLen + 1000); //FIX MALLOC BY USING THE RIGHT AMOUNT

    for (int i = 0; i < strLen; i++) {
        if (strncmp(str + i, pattern, patLen) == 0){
            strcpy(result + index, altPattern);
            index += altLen;
            i += patLen - 1;
        } else {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
    return result;
}

int main(void) {
    char* str = "I was enamoured looking at cars. I just was enamoured staring at them like an old man.";
    char* pattern = "was enamoured";
    char* altPattern = "love";
    char* result = findAndReplace(str, pattern, altPattern);

    printf("Before : %s\n", str);
    printf("After : %s\n", result);

    free(result);
    return 0;
}





// Part 2 :

int palindrome(char *word) {

    int len = strlen(word);

    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {

    if(argc != 2) {
        return 1;
    }

    char* word = argv[1];

    if (palindrome(word)) {

        printf("palindrome\n");

    } else {

        for (int i = strlen(word) - 1; i >= 0; i--) {
            printf("%c", word[i]);
        }

        printf("\n");
    }
}





// Part 3

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

double calcAvg(node* node){

    if(node == NULL){
        return 0;
    }

    double sum = 0.0;
    int counter = 0;

    while(node != NULL){
        sum += node->value;
        counter++;
        node = node->next;
    }

    return (sum / counter);

}

int main() {

    node* head = (node*)malloc(sizeof(node));
    head->value = 1;

    head->next = (node*)malloc(sizeof(node));
    head->next->value = 2;

    head->next->next = (node*)malloc(sizeof(node));
    head->next->next->value = 3;

    head->next->next->next = NULL;

    double average = calcAvg(head);
    printf("Average: %.2f\n", average);

    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
void main()
{
    int i = 10;
    for(;;i-=2){
        if(i==12){
            break;
        }
        if(i%1000000000){
            continue;
        }
        printf("hi!");
    }
}
