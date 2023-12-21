#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data=d;
        }

};


node* build(int pre[], int in[], int s, int e){

    static int i=0;
    //base case
    if(s>e) return NULL;

    //rec case
    node* root=new node(pre[i]);

    //Searching for ith element in inorder arr
    int j=0;
    while(in[j]!=pre[i]){
        j++;
    }

    //moving to the next element in the preorder arr
    i++;

    root->left=build(pre,in,s,j-1);
    root->right=build(pre,in,j+1,e);
    return root;
}

void preOrd(node* root){

    //base case
    if(root==NULL) return;

    //rec case
    cout<<root->data<<" ";
    preOrd(root->left);
    preOrd(root->right);

}

void inOrd(node* root){
    //base case
    if(root==NULL) return;

    //rec case
    inOrd(root->left);
    cout<<root->data<<" ";
    inOrd(root->right);
}

void postOrd(node* root){
    //base case
    if(root==NULL) return;

    //rec case
    postOrd(root->left);
    postOrd(root->right);
    cout<<root->data<<" ";
}

int main(){
    int n;
    cin>>n;
    
    int pre[n]={0};
    int in[n]={0};

    cout<<"Enter preorder arr "<<endl;
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }

    cout<<"Enter inorder arr "<<endl;

    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root=build(pre,in,0,n-1);
    preOrd(root);
    
    cout<<endl;
    inOrd(root);

    cout<<endl;
    postOrd(root);

    return 0;
}
