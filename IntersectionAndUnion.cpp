/*Intersection and Union of 2 linked List
  *Time Complexity = O(size(1)*size(2)) 
  *Can we do better? Yes
  1:Sort the list
  2:Hashing  
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void push(Node** head, int data) { // insertion of new node
    struct Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

bool ispresent(Node* head, int item) {
    Node* temp = head;
    while(temp!=NULL) {
        if(temp->data == item) {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

Node* getintersection(Node* head1, Node* head2) {
    struct Node* result = NULL;
    struct Node* t1 = head1;
    while(t1!=NULL) {
        if(ispresent(head2, t1->data)) {
            push(&result, t1->data);
        }
        t1 = t1->next;
    }
    return result;
}
void printList(Node* head) {
    struct Node* temp = head;
    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp->next;
    }
}
Node* getunion(Node* head1, Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;
    struct Node* temp2 = head2;
    while(temp!=NULL) {
        push(&result, temp->data);
        temp = temp->next;
    }

    while(temp2!=NULL) {
        if(ispresent(result, temp2->data)) {
            temp2 = temp2->next;
            continue;
        }
        push(&result, temp2->data);
        temp2 = temp2->next;
    }
    return result;
}


int main() {
    // create the 2 linked list
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* uni = NULL;
    struct Node *inter = NULL;

    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);

    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);
    
    cout << "First Linked List is\n";
    printList(head1);
    cout << "\n";
    cout << "Second Linked List is\n";
    printList(head2);
    cout<<"\n";
    inter = getintersection(head1, head2);
    cout << "Intersection of linked list is\n";
    printList(inter);
    uni = getunion(head1, head2);
    cout << "\n";
    cout << "Union of Linked list is\n";
    printList(uni);
    return 0;


}
