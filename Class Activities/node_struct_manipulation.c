#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
node *construct_list(int arr[], int len)
{
    node *head = len ? (node *)malloc(sizeof(node)) : NULL;
    node *temp = head;
    for (int i = 0; i < len; i++)
    {
        temp->value = arr[i]; //(*temp).value = arr[i];
        temp->next = i != len - 1 ? (node *)malloc(sizeof(node)) : NULL;
        temp = temp->next;
    }
    return head;
}
char *tostr(node *head)
{
    if (head == NULL)
        return "";
    char *rv = (char *)malloc(100);
    sprintf(rv, "%d%s%s", head->value, head->next ? " -> " : "", tostr(head->next));
    return rv;
}
char *tostr2(node *head)
{
    char *rv = (char *)malloc(100);
    char *it;
    node *cur;
    int len;
    for (it = rv, cur = head; cur; cur = cur->next, it += len)
        len = sprintf(it, "%d%s", cur->value, cur->next ? " -> " : "");
    return rv;
}
node *reverse(node *head)
{
    node *prev = NULL, *cur = head, *rest;
    while (cur != NULL)
    {
        rest = cur->next;
        cur->next = prev;
        prev = cur;
        cur = rest;
    }
    return prev; // new head of the reversed linked list!
}
void reverse2(node **head_pointer)
{
    node *head = *head_pointer;
    node *prev = NULL, *cur = head, *rest;
    while (cur != NULL)
    {
        rest = cur->next;
        cur->next = prev;
        prev = cur;
        cur = rest;
    }
    *head_pointer = prev; // new head of the reversed linked list!
}
void main(void)
{
    int arr[4] = {1, 2, 3, 4};
    node *head;
    printf("linked list is %s\n", tostr2(head = construct_list(arr, 4)));
    printf("Reverse of this list is equal to %s\n", tostr(head = reverse(head)));
    reverse2(&head);
    printf("Reverse of this list is equal to %s\n", tostr(head));
}