#include<iostream>

using namespace std;

class node{

public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void printTree(node* root){
    //base case
    if(root==NULL) return;

    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
    return;
}


node* insertInBST(node* root, int data){

    //base case
    if(root==NULL){
        return new node(data);
    } 

    if(root->data>=data){
        root->left=insertInBST(root->left, data);
    }

    else root->right=insertInBST(root->right, data);

    return root; 

}

node* build(){
    int d;
    cin>>d;

    node* root=NULL;

    while(d!=-1){
        insertInBST(root, d);
        cin>>d;
    }
    return root;
    
}


int main(){
    node* root=build();
    printTree(root);

    
    return 0;
}