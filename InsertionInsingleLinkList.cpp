#include<iostream>
using namespace std;

class Node{
	public:
		
	int key;
	int data;
	Node *next;
	
		//parametrized constructor
		 Node(int data ){
		 	this->data = data;
		 	next = NULL;
		 }
		 //default constructor
		 Node(){
		 	data = 0;
		 	key = 0;
		 	next = NULL; 
		 }
		 
};

class singlelist{
	public:
		Node *head;
		Node *tail;
		
		//default constructor
		singlelist(){
			head = tail =NULL;
		}
		
		//parametrized constructor
		singlelist(Node *n){
			head  = n;
		}
		
		// function to insert at tail
		void Insertattail(int data){
			//creating a node
			Node *temp = new Node(data);
			if(head == NULL ){
				//if initially there were no node in the list
				head = tail = temp;
			}
			else
			{
			tail->next = temp;
			tail =  temp;
			}
		}
		
		// function to insert at head
		void Insertathead(int data){
			//creating a node
			Node *temp = new Node(data);
			if(head == NULL ){
				//if initially there were no node in the list
				head = tail = temp;
			}
			else
			{
			temp->next = head;
			head =  temp;
			}
		}
		
		
		//used to display the data of the node
		void display(){
			Node *temp = head;
			while(temp !=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main(){
	singlelist obj1;
	obj1.Insertattail(1);
	obj1.Insertattail(2);
	obj1.Insertattail(3);
	
	obj1.Insertathead(5);
	obj1.Insertathead(4);
	
	obj1.display();
}