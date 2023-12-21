//Binary Tree Practice

#include<iostream>
using namespace std;


class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* build(){
    int d;
    cin>>d;
    
    //base case
    if(d==-1) return NULL;

    node* root=new node(d);
    root->left=build();
    root->right=build();

}

int height(node* root){

    if(root==NULL) return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    return max(h1,h2)+1;
}

//level-order traversal
void printKlevel(node* root, int k){
    //base case
    if(root==NULL) return;
    if(k==1) cout<<root->data<<" ";

    printKlevel(root->left,k-1);
    printKlevel(root->right,k-1);
}


void pre_order_print(node* root){
    if (root==NULL) return;

    cout<<root->data<<" ";
    pre_order_print(root->left);
    pre_order_print(root->right);
}


int main(){
    node* root=build();
    pre_order_print(root);
    cout<<endl;

    for(int i=0;i<height(root);i++){
        printKlevel(root,i+1);
        cout<<endl;
    }
    return 0;
}