#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    
    temp->data= data;
    temp->link=NULL;

    ptr->link=temp; // Update ptr to point to the new node
    return temp; // Return the new node as the updated ptr
}


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45; //data 
    head->link = NULL; //link
    
    struct node *ptr = head;

    ptr=add_at_end(ptr, 50);
    ptr=add_at_end(ptr, 55);
    ptr=add_at_end(ptr, 60);

    ptr = head;

    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
    return 0;
}