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

node *removeElement(node *root, int k){
    node *trav = root;
    for(int i=0; i<k-1; i++){
        trav = trav->next;
    }
    node *temp = trav -> next;
    trav -> next = trav -> next -> next;
    free(temp);
    return root;
}

node *removeHead(node *root){
    node *temp = root;
    root = root -> next;
    free(temp);
    return root;
}

node *removeTail(node *root){
    node *trav = root;
    while(trav -> next -> next != NULL){
        trav = trav -> next;
    }
    node *temp = trav -> next;
    trav -> next = NULL;
    free(temp);
    return root;
}

void printLL(node *root){
    node *cur = root;
    for(cur = root; cur != NULL; cur = cur->next){
        printf("%d ", cur -> data);
    }
    return;
}

int main(){
    int n;
    cin>> n;
    node *l, *p;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        if( i== 0){
            l = createNode(x);
            p = l;
            continue;
        }
        p = addElement(p, x);
    }
    int k;
    cin>> k;
    if(k==0)
        l = removeHead(l);
    else if(k==n) removeTail(l);
    else l = removeElement(l, k);
    printLL(l);
    return 0;
}