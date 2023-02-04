//-----LuvU---

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
    // tuong duong 3 dong tren vs l tail   
    return l;
}

douList *addHead(douList *root, int x){
    node *head = new node;
    head -> data = x;
    head -> prev = NULL;
    head -> next = root -> head;
    root -> head -> prev = head;
    root -> head = head;
    return root;
}

douList *addTail(douList *root, int x){
    node *tail = new node;
    tail -> data = x;
    tail -> next = NULL;
    tail -> prev = root -> tail;
    root -> tail -> next = tail;
    root -> tail = tail;
    return root;
}

douList *addElementAt(douList *root, int k, int x){
    node *cur = root -> head;
    for(int i=0; i<k-1; i++){
        cur = cur -> next;
    }
    node *aftercur = cur -> next;
    node *add = new node;
    add -> data = x;
    add -> next = aftercur;
    add -> prev = cur;
    cur -> next = add;
    aftercur -> prev = add;
    return root;
}

void printLL(douList *root){
    node *cur = root -> head;
    for(cur = root-> head; cur!= NULL; cur = cur -> next){
        printf("%d ", cur -> data);
    }
    return;
}

int main(){
    int n, x;
    cin>>n;
    cin>> x;
    douList *l = createList(x);
    for(int i=1; i<n; i++){
        cin>>x;
        addTail(l, x);
    }
    int k;
    cin>> k>> x;
    if(k == 0) addHead(l, x);
    else
        if(k == n) addTail(l, x);
        else
            addElementAt(l, k, x);
    printLL(l);
    return 0;
}