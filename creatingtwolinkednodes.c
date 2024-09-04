#include <stdio.h>
#include <stdlib.h>

//creating node two parts data and link(pointer to next node)
struct node{
    int data;
    struct node *link;
};


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45; //data 
    head->link = NULL; //link
    
    struct node *current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link = current; //first node link is now pointing to current node
    printf("%d",head->data);
    printf("\n%d",current->data);
    return 0;
}