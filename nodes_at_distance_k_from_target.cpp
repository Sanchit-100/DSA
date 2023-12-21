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
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

}

//This function does two tasks- 
//print the nodes at k distance from target
//and also return the distance from the target at each call

int nodes_at_k(node* root, int k, int target){
    //base case
    if(root==NULL) return -1; //Not of any use, distance is -1 from target

    //if target found
    if(root->data==target){
        printKthLevel(root,k);
        return 0; //distance = 0 from target
    }

    int DL=nodes_at_k(root->left,k,target);
    //DL contains the distance of left node from target

    //let's check if the target is present in the left subtree ie. DL!=-1
    //if DL=-1, it means that target is not actually present in the left subtree
    
    if(DL!=-1){
        //Target in left subtree

        if(DL+1==k){ //if the current node is itself k distance away
            cout<<root->data<<" ";
            return k;  //since the current node is k distance away from target
        }

        else{
            //now we need more distanced node... since target itself is in the left subtree
            // we can get more far away nodes in the right subtree only

            //So k-2-DL and print the level of k-2-DL (right subtree will be 2 units away than the current node, which itself is DL units away from the target node)
            printKthLevel(root->right,k-2-DL);
            return 1+DL; //obviously, 1 unit distance from the previous node
        }


    }

    //Now we will do the same above thing if the target is found in the right subtree
    int DR=nodes_at_k(root->right,k,target);
    //Finding distance of right subtree from the target

    //if found in the right subtree
    if(DR!=-1){
        if(1+DR==k){
            cout<<root->data<<" ";
            return k;
        }

        else{
            printKthLevel(root->left,k-2-DR);
            return 1+DR;
        }
    }

    //if neither of above two conditions work, that means
    //target is not in either of root's subtree

    //simply return -1;

    return -1;
}


int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;

    int k,target;
    cout<<"Enter k ";
    cin>>k;

    cout<<"Enter target ";
    cin>>target;

    cout<<endl;
    nodes_at_k(root,k,target);

    return 0;
}