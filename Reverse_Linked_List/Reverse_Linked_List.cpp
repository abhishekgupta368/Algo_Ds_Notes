#include<bits/stdc++.h>
using namespace std;

class Node{
	/*------------------------*/
		/*
			this class is used to create node
			---------
		   | 0  |   |->NULL
		   ---------
		*/
	/*------------------------*/

	public:
		int data;
		Node* next;
		Node(int n){
			data = n;
			next=NULL;
		}
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList(){
			head=NULL;
			tail=NULL;
		}
		/*
			this will add node to the linkedlist node and refer it to node type pointer
			---------   ---------  	---------
		   | 0  |   |->| 1  |   |->| 2  |   |->NULL
		   ---------   ---------   ---------
		*/
		void addNode(int data){
			if(head==NULL){
				Node* node = new Node(data);
				node->next = head;
				head = node;
				tail = node;
			}
			else{
				Node* node = new Node(data);
				tail->next = node;
				tail = node;
			}
		}
		void rev(){
			// Initialize current=head, previous=NULL and 
        	// next_node=NULL 
			Node* current  = head;
			Node* previous = NULL;
			Node* next_node = NULL;
			while(current!=NULL){
				// Store next 
				next_node = current->next;
				// Reverse current node's pointer 
				current->next = previous;
				// Move pointers one position ahead.
				previous = current;
				current = next_node;
			}
			head = previous;
		}
		void print(){
			Node* temp = head;
			cout<<"Linked List:\n";
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
};
int main(){
	int n;
	LinkedList* linkedList = new LinkedList();
	cout<<"Enter the number of node in linked list: ";
	cin>>n;
	for(int i = 1;i<=n;i++){
		linkedList->addNode(i);
	}
	cout<<"\n";
	cout<<"Before Reverse\n";
	linkedList->print();
	linkedList->rev();
	cout<<"After Reverse\n";
	linkedList->print();
}

