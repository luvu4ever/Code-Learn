#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
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
        cout<< p-> data << " ";
        p = p->next;
    }
    return ;
}

node *AddHead(node *l, int x){
    node *temp = new node;
    temp -> next = l;
    temp -> data = x;
    l = temp;
    return l;
}

node *AddAt(node *l, int k, int x){
    node *p = l;
    for(int i=0; i<k-1; i++){
        p = p-> next;
    }
    node *temp = new node;
    temp -> data = x;
    temp-> next = p -> next;
    p-> next = temp;

    return l;
}

node *AddTail(node *l, int x){
    node *p = l;
    while(p-> next != NULL){
        p = p-> next;
    }
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    p -> next = temp;
    return l;
}

int main(){
    int n;
    cin >> n;
    node *l, *p;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(i==1){
            l = createNode(x);
            p = l;
            continue;
        }
        p = addElement(p, x);
    }
    int k, x;
    cin>>k>>x;
    if(k == 0) l =AddHead(l, x);
    else if(k==n) l=AddTail(l, x);
    else l=AddAt(l, k, x);
    printLL(l); 
    return 1;
}