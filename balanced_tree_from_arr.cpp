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

node* build(int arr[], int s, int e){

    //base case
    if(s>e) return NULL;

    //rec case
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=build(arr,s,mid-1);
    root->right=build(arr,mid+1,e);

}

//Pre Order Traversal
//root-left-right

void printTree(node* root){

    //base case
    if(root==NULL) return;

    //rec case
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    node* root=build(arr,0,n-1);
    printTree(root);

    return 0;
}