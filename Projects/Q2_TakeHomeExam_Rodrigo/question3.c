#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node * next;

} node;

node * createLinkedList(int n);
void displayList(node *head);
node * reverse(node **root);
double findAverage(node *head);


int main(){

    int n = 0;
    node *HEAD = NULL;
    printf("How many nodes: ");
    scanf("%d", &n);

    HEAD = createLinkedList(n);

    displayList(HEAD);

    printf("The average of data is: %.2f\n", findAverage(HEAD));

    HEAD = reverse(&HEAD);

    displayList(HEAD);

    return 0;
}

node * createLinkedList(int n)
{
    int i = 0;
    node * head = NULL; //initial node that will be returned
    node * temp = NULL; //create a temporary node
    node * tail = NULL; // to iterate over the list

    for(i = 0; i < n; i++){
        // create individual isolated node
        temp = (node*)malloc(sizeof(node));
        temp->data = i; //integer or data of the node
        temp->next = NULL;

        // if the list is empty, temp will be the first node
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}
////////////////////////////////////////////

double findAverage(node *head){

    // If the head is NULL, then return nan
    if(!head){
        return nan("");
    }

    // Set a current node, variable to store the average, and length of all the nodes.
    node *curr = head;
    double ave = 0;
    int length = 0;

    // While a node exists, get the value and add it to ave
    while(curr){
        ave += curr->data;
        length++;
        curr = curr->next;
    }

    // return the average by diving ave by the total number of nodes
    return ave / length;
}

////////////////////////////////////////////

void displayList(node *head){
    node * p = head;

    while(p != NULL){
        printf("%d%s", p->data, (p->next != NULL) ? "->" : "\n");
        p = p->next;
    }
}

node * reverse(node **root){
    node* prev = NULL;
    node* curr = *root;

    while(curr != NULL){
        node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}