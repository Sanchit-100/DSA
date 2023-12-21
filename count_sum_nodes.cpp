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

int count_nodes(node* root){

    //base case
    if(root==NULL) return 0;

    //rec case
    int c1=count_nodes(root->left);
    int c2=count_nodes(root->right);
    return 1+c1+c2;


}

int sum_nodes(node* root){

    //base case
    if(root==NULL) return 0;

    //rec case
    int s1=sum_nodes(root->left);
    int s2=sum_nodes(root->right);
    return s1+s2+(root->data);
}

int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;

    cout<<count_nodes(root)<<endl;
    cout<<sum_nodes(root)<<endl;
    return 0;
}