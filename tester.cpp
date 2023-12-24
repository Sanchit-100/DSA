#include<iostream>
#include<cmath>
#include<vector>
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

int sum=0;
int sumNodes(node* root, int sum){
    //base case
    if(root==NULL) return sum;

    //rec case
    sum+=root->val;
    sumNodes(root->left,sum);
    sumNodes(root->right,sum);
    return sum;
}
 
int main(){
    node* root=buildTree();
    sumNodes(root->left);
    cout<<sum<<endl;

    return 0;
}

