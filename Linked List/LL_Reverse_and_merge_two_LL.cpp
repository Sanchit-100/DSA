//LINKED LIST REVERSE AND MERGE TWO OF THEM
#include<iostream>
using namespace std;


class Node{
    public:
        int val;
        Node* next;
        
        Node(int x){
            val=x;
            next=NULL;
        }
};

void insertAtHead(Node* &head,int val){
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    
    n->next=head;
    head=n;
    
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;;
}

void reverse(Node* &head){
    Node* temp=head;
    Node* curr=temp;
    Node* prev=NULL;
    
    while(curr!=NULL){
        curr=temp->next;
        temp->next=prev;
        prev=temp;
        temp=curr;
        
    }
    head=prev;
}

void insertAtTail(Node* &head,int val){
    Node* n=new Node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    Node* temp=head;
    while(temp-> next!=NULL){
        temp=temp->next;
    }
    
    temp->next=n;
    
}

void mergeLL(Node* head,Node* head2,Node* &head_f){
    Node* p1=head;
    Node* p2=head2;
    
    while(p2!=NULL and p1!=NULL){
        if((p2->val)>(p1->val)){
            insertAtTail(head_f,(p1->val));
            p1=p1->next;
        }
        
        else{
            insertAtTail(head_f,(p2->val));
            p2=p2->next;
        }
    }
    
    while(p2!=NULL){
        insertAtTail(head_f,(p2->val));
        p2=p2->next;
    }
    
    while(p1!=NULL){
        insertAtTail(head_f,(p1->val));
        p1=p1->next;
    }
}
int main(){
    Node* head=NULL;
    Node* head2=NULL;
    Node* head_f=NULL;
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,4);
    insertAtHead(head,2);
    
    insertAtHead(head2,9);
    insertAtHead(head2,6);
    insertAtHead(head2,6);
    insertAtHead(head2,1);
    
    mergeLL(head,head2,head_f);
    print(head);
    print(head2);
    print(head_f);

    reverse(head);
    print(head);
    
    return 0;
}
