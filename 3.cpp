#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node{
    public :
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


Node* insert(Node* head,int data){
    Node *temp = new Node(data);
    temp->next = head ;
    head = temp;
    return head;
}

void insertAt(Node* head,int pos,int data){
    Node* temp = head;
    Node* prev;
    while(pos > 1){
        prev= temp;
        temp=temp->next;
        pos --;
    }
    Node* tempNode = new Node(data);
    tempNode->next= temp;
    prev->next= tempNode;

}

Node* unique(Node* head){
    unordered_map<int,int>m;
    Node* temp = head;
    while(temp!= NULL){
        m[temp->data]++;
        temp= temp->next;
    }

    Node* head1 = NULL;
    Node* head2;
    temp = head;
    while(temp != NULL){
        if(m[temp->data] > 1){
            temp = temp->next;
        }
        else{
            if(head1 == NULL){
                head1 = temp;
                head2 = head1;
            }
               
            else{
                head1->next = temp;
                head1 = head1->next;
            }
            temp = temp->next;
        }
    }

    return head2;
       
}

Node* removeDup(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<"\n";
       
}

Node* reverse(Node* head){
    Node* prev = NULL;
    while(head != NULL){
        Node* next = head->next;
        head->next = prev;
        prev= head ;
        head = next;
    }
    return prev;
}
int main(){

    Node* head = new Node(1);
    head = insert(head,2);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    head = insert(head,5);
    head = insert(head,5);

    print(head);
    // head = removeDup(head);
    // head = unique(head);
    // print(head);   
    head = reverse(head);
    print(head);
    return 0;
}