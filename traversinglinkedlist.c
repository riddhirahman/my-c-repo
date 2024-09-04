#include <stdio.h>
#include <stdlib.h>

//creating node two parts data and link(pointer to next node)
struct node{
    int data;
    struct node *link;
};


void count_print_of_nodes(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("Linked list is empty");
    }
    struct node *ptr =  NULL;
    ptr = head;
    while (ptr != NULL) {
        count++;
        printf("%d->",ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
    printf("\n%d",count);
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45; //data 
    head->link = NULL; //link
    
    struct node *current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link = current; //first node link is now pointing to current node
    
    current = malloc(sizeof(struct node)); //current pointer now moving to third node from second node
    current->data = 35;
    current->link = NULL;

    head->link->link = current; //linking second node to third node

    printf("%d",head->data);
    printf("\n%d",head->link->data);
    printf("\n%d\n",current->data);
    count_print_of_nodes(head);
    return 0;
}