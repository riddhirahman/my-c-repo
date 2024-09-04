#include <stdio.h>
#include <stdlib.h>

//creating node two parts data and link(pointer to next node)
struct node{
    int data;
    struct node *link;
};


int main(){
    struct node *head = NULL; //set head pointer to null(also typecast to hold reference)
    head = (struct node *)malloc(sizeof(struct node)); //set head pointer to allocated address to the node
    head->data = 45; //data 
    head->link = NULL; //link
    printf("%d",head->data);
    return 0;
}