#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp -> data  = x;
    temp -> next = NULL;
    return temp;
}

void printLL(node *l){
    node *p = l;
    while(p != NULL){
        cout<< p-> data <<" ";
        p = p-> next;
    }
    return;
}

node *addElement(node *p, int x){
    node *temp = createNode(x);
    p -> next = temp;
    return temp;
}

int main(){
    int n;
    cin >> n;
    node *p, *l;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(i == 1){
            l = createNode(x);
            p = l;
            continue;
        }
        p = addElement(p , x);
    }
    printLL(l);
    return 1;
}