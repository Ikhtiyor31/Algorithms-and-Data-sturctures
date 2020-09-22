#include <bits/stdc++.h> 

using namespace std;
class Node {
   
   public:
   	Node *next;
   	Node *prev;
   	int data;
};
// global head node that is pointer head of linked list always

class DoublyLinkedList{
    Node *head;
    public: 
    	DoublyLinkedList() {
         head = NULL;
    	}
    	void addBefore(int val, int target);
    	void  addFirst(int val);
    	void addLast(int val);
    	void  printList();
    	void addAfter(int val, int target);

};

void DoublyLinkedList::addBefore(int val,  int target) {
	Node *node = new Node;
	node->next = NULL;
	node->prev = NULL;
	node->data = val;
	Node* temp = head;
	bool found = false;
	while(temp != NULL) {
		if(temp->data == target) {
               found = true;
               break;
		}
		temp = temp->next;
	}

	if(found) {
		node->next = temp->prev->next;
		temp->prev->next = node;
		node->prev = temp->prev;
		temp->prev = node;
	}

}
void DoublyLinkedList::addAfter(int val, int target) {
	Node *node = new Node;
	node->next = NULL;
	node->prev = NULL;
    node->data = val;
    Node* curr = head;
    bool found = false;
    while(curr != NULL) {
       if(curr->data == target) {
       	     found = true;
       	     cout << " found " << " \n";   
       	    break;
       }
       curr = curr->next;
    }
    if(found){
    	node->prev = curr;
    	node->next = curr->next;
    	

    	curr->next->prev = node;

    	curr->next = node;
   }
}
void DoublyLinkedList::addFirst(int val) {
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = val;
	if(head == NULL) {
		head = newnode;

		return;
	}
	newnode->next = head;
	head->prev  = newnode;
	head = newnode;
}
void DoublyLinkedList::printList() {
     Node* curr = head;
     while(curr != NULL)  {
     	cout << curr->data << "-->";
     	curr = curr->next;
     }
     cout <<"NULL";

}
void DoublyLinkedList::addLast(int val) {
	Node *node =  new Node;
	node->next = NULL;
	node->prev = NULL;
	node->data  = val;
	if(head == NULL) {
		head = node;
		return;
	}
	Node* traverse = head;
	while(traverse->next != NULL) {
		traverse =  traverse->next;
	}
	traverse->next = node;
	node->prev = traverse;

}
int main() {

    DoublyLinkedList *obj = new DoublyLinkedList();
    obj->addFirst(10);
    obj->addFirst(20);
    obj->addLast(30);
    obj->addLast(40);
    obj->addBefore(50, 40);
    obj->addBefore(60, 10);
    obj->addAfter(70, 30);
    obj->addAfter(80, 10);
    obj->printList();
   
	return 0;
}
