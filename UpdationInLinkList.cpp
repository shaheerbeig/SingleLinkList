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
		
		//function to add value after a value that the user entered.
		void InsertAfterNode(int value , int data){
				Node *temp = head;
				bool flag = false;
				while(temp != NULL){
					if(temp->data == value){
						Node *newnode = new Node(data);
						newnode->next = temp->next;
						temp->next = newnode;
						flag = true;
					}
					temp = temp->next;
				}
				if(flag==false){
					cout<<"NODE DOESNOT EXSISTS"<<endl;
				}
		}
		
		//function to delete the value
		void deletenode(int value){
			Node *current=head;
			Node *previous = NULL;
			if(current->data == value){
				head = head->next;
				delete(current);
			}	
			else{
				while(current->data != value){
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
				delete(current);
			}
		}
		
		//function to update
		void updatenode(int value , int newdata){
			bool flag = false;
			Node *temp = head;
			while(temp != NULL){
					if(temp->data == value){
						temp->data = newdata;
						return;
					}
					temp = temp->next;
				}
				if(flag==false){
					cout<<"NODE DOESNOT EXSISTS"<<endl;
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
	
	obj1.InsertAfterNode(1,7);
	
	obj1.deletenode(4);
	
	obj1.updatenode(5,10);
	
	obj1.display();
}