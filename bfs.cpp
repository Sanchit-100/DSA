#include<iostream>
#include<queue>
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

//Breadth-first search/traversal
//Level order print of binary tree in O(N)
//Uses queue


void bfs(node* root){
    queue<node *> q;
    q.push(root);
    node*temp=new node(-1);
    q.push(temp);
    

    while(!q.empty()){
        if(q.front()->data==-1){
            cout<<endl;
            q.pop();

            if(!q.empty()){
                q.push(temp);
            }
            continue;
        }

        cout<<q.front()->data<<" ";

        if (q.front()->left!=NULL) q.push(q.front()->left);
        if (q.front()->right!=NULL) q.push(q.front()->right);

        q.pop();


    }

}

int main(){
    node* root=buildTree();
    cout<<endl;

    bfs(root);

    return 0;
}