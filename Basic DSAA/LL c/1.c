#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    node *next;
};

struct node* addHead(struct node* root, int x){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = x;
    newNode -> next = NULL;

    if(root != NULL)
        newNode -> next = root;
    return newNode;
}

struct node* addElement(struct node* root, struct node *cur, int x){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = x;
    newNode -> next = NULL;
    struct node *p = cur -> next;
    cur -> next = newNode;
    newNode -> next = p;
    return root;
}

void printLL(struct node* root){
    struct node *p;
    for(p = root; p!= NULL; p=p->next){
            printf("%d ", p-> data );
    }
}

void freeLL(struct node* root){
    if(root == NULL) return;
    struct node *p = NULL;
    for(; root!= NULL;){
        p = root;
        root = root -> next;
        free(p);
    }
}