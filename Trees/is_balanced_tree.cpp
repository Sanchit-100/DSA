#include<iostream>
#include<cmath>
#include<utility>
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


//Top down approach --O(N^2)
//At every node, we try to find height of the tree

// bool isBalanced(node* root){
//     //base case
//     if(root==NULL) return true;

//     //rec case
//     if (abs(height(root->left)-height(root->right))<=1){
//         if(isBalanced(root->left)){
//             if(isBalanced(root->right)){
//                 return true;
//             }
//         }
//     }

//     return false;
// }


//Bottom up approach --O(N)
//we will do a postorder traversal ie. left-right-root
//we will return the height and the bool value 
// of isbalanced or not

pair<int,bool> isBalanced(node* root){
    pair<int,bool> p;
    //here first will denote the height of the tree
    // second will denote the bool value

    //base case
    if(root==NULL){
        p.first=0;
        p.second=true;

        return p;
    }

    //rec case
    pair<int,bool> p1;
    pair<int,bool> p2;

    p1=isBalanced(root->left);
    p2=isBalanced(root->right);

    int height=max(p1.first,p2.first)+1;

    if(abs(p1.first-p2.first)<=1 and (p1.second) and (p2.second)){
        p.first=height;
        p.second=true;
        return p;
    }

    else{
        p.first=height;
        p.second=false;
        return p;
    }

}
        




int main(){
    node* root=buildTree();
    printTree(root);
    cout<<endl;
    
    cout<<"Height "<<isBalanced(root).first<<endl;
    cout<<"Balanced "<<isBalanced(root).second<<endl;

    return 0;
}