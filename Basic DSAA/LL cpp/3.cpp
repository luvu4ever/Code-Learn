#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp-> data = x;
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
    return ;
}

node *removeHead(node *l){
    node *temp = l-> next;
    l-> next = NULL;
    l = temp;
    return l;
}

node *removeElement(node *l, int k){
    node *p = l;
    for(int i=0; i< k-1; i++){
        p = p-> next;
    }
    // node *temp = p->next->next;
    // p->next = temp;
    p->next = p->next->next;
    return l;
}

int main(){
    int n;
    cin>>n;
    node *l ,*p;
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
    int k;
    cin>>k;
    //l = removeElement(l, k);
    if(k == 0) l = removeHead(l);
    else l = removeElement(l, k);
    printLL(l);
    return 0;
}