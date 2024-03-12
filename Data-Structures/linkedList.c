#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MIN_VAL INT_MIN
#define MAX_VAL INT_MAX

// Node struct
typedef struct node
{
    int data;
    struct node * next;

} node;

// Methods
node * createLinkedList(int n);
void displayList(node *head);
node * reverse(node **root);
double average(node *head);
int minimum(node *head);
int maximum(node *head);
int sizeLinkedList(node *head);
void insertElement(node *head, int position, int value);
void deleteElement(node *head, int position);
void deleteLinkedList(node **head);

// Main function
int main(){

    int n = 0;
    node *HEAD = NULL;
    printf("How many nodes: ");
    scanf("%d", &n);

    // Creating a Linked List
    HEAD = createLinkedList(n);

    // Displaying a Linked List
    displayList(HEAD);

    // Reversing a Linked List
    HEAD = reverse(&HEAD);

    // Printing the reversed Linked List
    displayList(HEAD);

    // Finding total average
    printf("The average of the Linked List --> %.2f\n", average(HEAD));

    // Finding min value in the linked list
    printf("The minimum data of the Linked List --> %d\n", minimum(HEAD));

    // Finding max value in the linked list
    printf("The maximum data of the Linked List --> %d\n", maximum(HEAD));

    // Size of linked list
    printf("The size of the linked list  --> %d\n", sizeLinkedList(HEAD));

    // Insert element
    printf("Inserting new node with data 10 at position 1...\n");
    insertElement(HEAD, 1, 10);

    displayList(HEAD);

    // Delete element
    printf("Deleting node at position 3...\n");
    deleteElement(HEAD, 3);

    displayList(HEAD);

    // Delete Linked List
    deleteLinkedList(&HEAD);

    return 0;
}

// Creating a Linked List
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

// Displaying a List by using malloc (temporary allocation)
void displayList(node *head){
    node * p = (node*)malloc(sizeof(node));
    p = head;

    // Print the value of the node as long as the node is not null
    while(p != NULL){
        printf("%d%s", p->data, (p->next != NULL) ? "->" : "\n");
        p = p->next;
    }
    free(p);
}

// Reverseing a Linked List. It returns the new Head
node * reverse(node **root){
    node* prev = NULL;
    node* curr = *root;

    // Iterating over each node in the Linked List. Stop when reaching to the end
    while(curr != NULL){
        node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//Find average of nodes
double average(node* head){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    double ave = 0;
    int instances = 0;

    // If the head is null then return nan
    if(!temp){
        free(temp);
        return nan("");
    }

    // Iterate over each node and count the number of nodes and adding the data into ave
    while(temp){
        ave += temp->data;
        instances++;
        temp = temp->next;
    }
    free(temp);
    // return the average
    return ave / instances;
}

// Find minimum data in the Linked List
int minimum(node* head){
    node* temp = (node*)malloc(sizeof(node));
    int lowest_value = MAX_VAL;
    temp = head;
    
    // If the head is null then return nan
    if(!temp){
        free(temp);
        return MIN_VAL;
    }

    while(temp){
        if(temp->data < lowest_value)
            lowest_value = temp->data;
        temp = temp->next;
    }

    free(temp);

    return lowest_value;
}

// Find Maximum data in the Linked List
int maximum(node *head){
    node* temp = (node*)malloc(sizeof(node));
    int highest_value = MIN_VAL;
    temp = head;
    
    // If the head is null then return nan
    if(!temp){
        free(temp);
        return MAX_VAL;
    }

    while(temp){
        if(temp->data > highest_value)
            highest_value = temp->data;
        temp = temp->next;
    }

    free(temp);

    return highest_value;
}

// Find size of the linked List
int sizeLinkedList(node *head){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    int size = 0;

    if(!temp){
        free(temp);
        return -1;
    }

    while(temp){
        size++;
        temp = temp->next;
    }

    return size;
}

void insertElement(node *head, int position, int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    node* curr = (node*)malloc(sizeof(node));
    curr = head;
    node* prev = NULL;
    
    for(int i=0; i<position; i++){
        prev = curr;
        curr = curr->next;
    }

    prev->next = new_node;
    new_node->next = curr;
}

void deleteElement(node* head, int position){
    node* curr = (node*)malloc(sizeof(node));
    curr = head;
    node* prev = NULL;
    node* next = curr->next;
    int curr_pos = 0;

    while(curr_pos != position){
        prev = curr;
        curr = curr->next;
        next = curr->next;
        curr_pos++;
    }

    prev->next = next;
    free(curr);
}

void deleteLinkedList(node **head){
    node* curr = *head;
    node* next;

    while(curr){
        next = curr->next;
        free(curr);
        curr = next;
    }

    *head = NULL;
}