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

node* buildTree(){
    int d;
    cin>>d;

    //Since this is a recursive way, it must have a base case
    // base case

    if(d==-1) return NULL;

    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;

}

void printTree(node* root){

    //base case for recursive algo
    if(root==NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int height(node* root){
    //base case
    if(root==NULL) return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    return max(h1,h2)+1;
}

void printKth(node*root, int k){
    //base case
    if(root==NULL) return;

    //base case 2
    if(k==1){
        cout<<root->data<<" ";
        return;
    }

    //rec case
    printKth(root->left,k-1);
    printKth(root->right,k-1);


}
int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;
    cout<<height(root)<<endl;

    for(int i=0;i<height(root);i++){
        printKth(root,i);
        cout<<endl;
    }


    return 0;
}