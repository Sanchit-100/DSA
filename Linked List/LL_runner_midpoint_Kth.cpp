#include<iostream>
using namespace std;


class node{
    public:
        int val;
        node* next;
        node(int data){
            val=data;
            next=NULL;
    }
};

void print(node* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void addAtTail(int data, node* &head){
    node* n=new node(data);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
    return;
}

//Finding mid-point of a linked list
//Runner Technique
int find_mid(node* head){
    node* fast=head;
    node* slow=head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return slow->val;
}

//Finding Kth node from end in one traversal
//Using the same Runner Technique

int k_node(int k, node* head){
    node* ahead=head;
    node* behind=head;
    
    while(k--){
        ahead=ahead->next;
    }
    
    while(ahead!=NULL){
        ahead=ahead->next;
        behind=behind->next;
    }
    
    return behind->val;
}

int main(){
    node* head=NULL;
    addAtTail(1,head);
    addAtTail(2,head);
    addAtTail(3,head);
    addAtTail(2,head);
    addAtTail(8,head);
    addAtTail(6,head);
    addAtTail(11,head);
    
    print(head);
    cout<<find_mid(head)<<endl;
    
    int k;
    cin>>k;
    cout<<k_node(k,head)<<endl;
    
    
    return 0;
}
