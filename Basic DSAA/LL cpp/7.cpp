#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct douList{
    node *head;
    node *tail;
};

douList *createList(int x){
    douList *l = new douList;
    l -> head = new node;
    l -> head -> data = x;
    l -> head -> next = NULL;
    l -> head -> prev = NULL;
    l -> tail = l -> head;
    return l;
}

douList *addHead(douList *l, int x){
    node *temp = new node;
    temp -> data =x;
    temp -> prev = NULL;
    temp -> next = l -> head;
    l -> head -> prev = temp;
    l -> head = temp;
    return l;
}

douList *addTail(douList *l, int x){
    node *temp = new node;
    temp -> data =x;
    temp -> next = NULL;
    temp -> prev = l -> tail;
    l -> tail -> next = temp;
    l -> tail = temp;
    return l;
}

void printLL(douList *l){
    node *p = l -> head;
    while(p != NULL){
        printf("%d ", p-> data);
        p = p-> next;
    }
    return ;
}

void reverseLL(douList *l){
    node *p = l -> tail;
    while(p != NULL){
        printf("%d ", p -> data);
        p = p -> prev;
    }
    return ;
}

int main(){
    int n;
    cin>> n;
    douList *l = createList(1);
    for(int i=2; i<=n; i++){
        l = addHead(l, i);
        l = addTail(l,i);
    }
    printLL(l);
    return 0;
}
