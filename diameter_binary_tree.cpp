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


//Pre-order traversal
void printTree(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

//finding the height of tree

int max(int a,int b,int c=-10){
    if ((a>=b) and (a>=c)) return a;
    if(b>=a and b>=c ) return b;
    if(c>=a and c>=b ) return c;
}



int height(node* root){
    if(root==NULL) return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    return max(h1,h2)+1;
}


//Top-Down approach-- O(N^2)
int diameter(node*root){

    //base case
    if(root==NULL) return 0;
    
    int op1=height(root->left)+height(root->right)+1;
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,op2,op3);
}

//Bottom-up approach
int diameter(node*root){
    
}



int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;
    cout<<height(root)<<endl;

    cout<<"Diameter: "<<diameter(root)<<endl;

    return 0;
}