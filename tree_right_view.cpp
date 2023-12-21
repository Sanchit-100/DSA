#include<iostream>
#include<cmath>
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

node* buildTree(){
    int d;
    cin>>d;

    //If -1, we dont't need further nodes
    if(d==-1) return NULL;

    //Otherwise, if not -1
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
}

void rightView(node* root, int level, int max_level){
    //base case
    if(root==NULL) return;

    //rec case
    if(level>max_level){
        cout<<root->data<<" ";
        max_level=level;
    }
    rightView(root->right,level+1,max_level);
    rightView(root->left,level+1,max_level);
    
}

//Pre-order traversal
void printTree(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}




int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;

    rightView(root,0,-1);
    return 0;
}