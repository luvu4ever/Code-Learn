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
    p-> next = temp;
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

node *removeElementGreaterThan(node *l, int x){
    node *p = l;
    node *newLL = new node;
    node *newLLhead = new node;
    while(p!= NULL){
        if(p-> data <= x){
            newLLhead= createNode(p-> data);
            newLL = newLLhead;
            p = p-> next;
            break;
        }
        p = p-> next;
    }
    while(p!= NULL){
        if(p-> data <=x){
            newLL = addElement(newLL, p-> data);
        }
        p = p-> next;
    }
    return newLLhead;
}

int main(){
    int n;
    cin>>n;
    node *p, *l;
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
    int k, deleteValue;
    cin >> k;
    p = l;
    for(int i=0; i<k; i++){
        p = p-> next;
    }
    deleteValue = p -> data;
    printLL(removeElementGreaterThan(l, deleteValue));
    //printLL(l);
    return 0;
}