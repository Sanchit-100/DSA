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

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int height(node* root){
    if(root==NULL) return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    return max(h1,h2)+1;
}

void printKthLevel(node* root, int k){
    if(root==NULL) return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

}
int main(){
    node* root=buildTree();
    // printTree(root);
    // cout<<endl;
    // cout<<height(root)<<endl;

    for(int i=1;i<height(root)+1;i++){
        printKthLevel(root,i);
        cout<<endl;
    }

    return 0;
}