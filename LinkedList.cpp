#include <bits/stdc++.h>
using namespace std;
#define size 100
struct node{
    int data;
    node*next;
};
node*head = nullptr;
void insertBegin(int value);
void insertEnd(int value);
void insertAtPos(int pos , int value);
void deleteBegin();
void deleteEnd();
void deleteAtPos(int pos);
void deletevalue(int value);
int countnodes();
void display();
int main(){
    insertEnd(5);
    insertEnd(6);
    insertBegin(56);
    insertAtPos(2,34);
    insertBegin(45);
    // 45 56 34 5 6
    display();
    deleteAtPos(1);
    display();
    deleteAtPos(4);
    display();

}
void insertBegin(int value){
    node*New = new node;
    New->data = value;
    New->next = head;
    head = New;
}
void insertEnd(int value){
    node*New = new node;
    New->data = value;
    New->next = nullptr;
    if(head == nullptr){
        head = New;
    }
    else{
        node*curr = head;
        while(curr->next != nullptr){
            curr= curr->next;
        }
        curr->next = New;
    }
}
void insertAtPos(int pos, int value){
    if(pos < 1 || pos > countnodes()){
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 1){
        insertBegin(value);
        return;
    }
    int cnt = 1;
    node*New = new node;
    New->data = value;
    node*curr = head;
    node*prev = head;
    while(cnt != pos){
        cnt++;
        prev = curr;
        curr = curr->next;
    }
    prev->next = New;
    New->next = curr;
}
void deleteBegin(){
    if(head == nullptr){
        cout << "Linked list is empty" << endl;
        return;
    }
    node*curr = head;
    head = head->next;
    delete curr;
}
void deleteEnd(){
    if(head == nullptr){
        cout << "Linked list is empty" << endl;
        return;
    }
    else if(head->next == nullptr){
        deleteBegin();
        return;
    }
    node*curr = head;
    node*prev = head;
    while(curr->next != nullptr){
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}
void deleteAtPos(int pos){
    if(pos < 1 || pos > countnodes()){
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 1){
        deleteBegin();
        return;
    }
    int cnt = 1;
    node*curr = head;
    node*prev = head;
    while(cnt != pos){
        cnt++;
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}
void deletevalue(int value){



    node*curr = head ;
    node *prev = head;
    if(head == nullptr){
        cout << "Linked list is empty" << endl;
        return ;
    }
    else if(curr->data == value){
        deleteBegin();
    }
    else{
        while(curr->data != value){
            prev = curr;
            curr= curr->next;
        }
        prev->next = curr->next;
        delete curr;

    }

}
int countnodes(){
    node*curr = head;
    int cnt= 0;
    while(curr != nullptr){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}
void display(){
    
    if(head == nullptr){
        cout << "Linked list is empty" << endl;
        return;
    }
    node*curr = head;
    while(curr != nullptr){
        cout << curr->data << " " ;
        curr = curr->next;
    }
    cout << endl;

}