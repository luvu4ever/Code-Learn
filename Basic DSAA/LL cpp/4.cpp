//---------LuvU--------------
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
    int k;
    cin >> k;
    p = l;
    for(int i=0; i<k; i++){
        p = p-> next;
    }
    printf("%d", p-> data);
    return 0;
}