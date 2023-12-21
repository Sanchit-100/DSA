//LINKED LIST PRACTICE

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=NULL;
    } 
};

int length(Node* head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    
    return cnt;
}


void insertAtHead(Node* &head,int val){
    Node* n=new Node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    n->next=head;
    head=n;
    
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

void display(Node* &head){
    Node * temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
    cout<<"NULL"<<endl;
}


void insertInMiddle(Node* &head, int val, int index){
    Node* n=new Node(val);
    
    Node* temp=head;
    
    if(head==NULL){
        head=n;
        return;
    }
    
    if(index>=length(head)){
        insertAtTail(head,val);
        return;
    }
    int cnt=1;
    
    while(cnt!=index){
        temp=temp->next;
        cnt++;
    }
    n->next=temp->next;
    temp->next=n;
    
}
void deleteHead(Node* &head){
    Node* temp=head->next;
    delete head;
    head=temp;
}
void deleteElement(Node* head,int index){
    if(head==NULL) return;
    int cnt=0;
    while(cnt!=index-1){
        head=head->next;
        cnt++;
    }
    
    Node* temp=head->next;
    head->next=temp->next;
    delete temp;
}
int LinearSearch(Node* head, int key){
    int index=0;
    while(head!=NULL){
        if(head->data==key) return index;
        index++;
        head=head->next;
    }
    return -1;
}

int main(){
    Node* head=NULL;
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,9);
    display(head);

    
    insertInMiddle(head,10,2);
    display(head);

    cout<<LinearSearch(head,5)<<endl;
    
    deleteElement(head,3);
    display(head);

    deleteHead(head);
    display(head);
    
    return 0;
    
}
