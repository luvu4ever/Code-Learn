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

void printLLfromto(node *root, int n, int k){
    node *trav = root;
    for(int i=0; i<k; i++){
        trav = trav -> next;
    }
    for(int i = 0; i<n; i++){
        printf("%d ", trav -> data);
        trav = trav -> next;
    }
    return;
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
        p = addElement(p , x);
    }
    p -> next = l;
    int k;
    cin>>k;
    printLLfromto(l, n, k);
    return 0;
}