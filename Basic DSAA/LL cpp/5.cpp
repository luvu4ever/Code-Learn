#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp -> next = NULL;
    temp -> data = x;
    return temp;
}

node *addElement(node *p, int x){
    node *temp = createNode(x);
    p -> next = temp;
    return temp;
}

void printLL(node *l){
    node *p = l;
    while(p != NULL){
        printf("%d ", p-> data);
        p = p-> next;
    }
    return;
}

node *changeNode(node *l, int from, int to){
    node *p = l;
    while(p != NULL){
        if(p-> data == from) p-> data = to;
        p = p-> next;
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    node *l, *p;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(i==0){
            l = createNode(x);
            p = l;
            continue;
        }
        p = addElement(p, x);
    }
    int from, to;
    cin>> from >> to;
    l = changeNode(l, from, to);
    printLL(l);
    return 0;
}