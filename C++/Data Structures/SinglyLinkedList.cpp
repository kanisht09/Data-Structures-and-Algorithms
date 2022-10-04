#include<iostream>
using namespace std;

//Node class
class Node{
	private:
		int value;
		Node* next;
	public:
		Node(int,Node*);
		friend class SLL;
};

//constructor for Node Class
Node::Node(int data=0,Node* ptr=NULL)
{
	value = data;
	next = ptr;
}

//destructor for Node Class
//Node::~Node()
//{
//	cout<<"Node deleted\n";	
//}


//Singly linked list Class
class SLL{
	private:
		Node* head;
	public:
		SLL();
		~SLL();
		void insertAtbeg(int val);
		void insertAtpos(int val , int pos);
		void removeFrombeg();
		void removeFrompos(int pos);
		void insertAtend(int val);
		Node* search(int val);
		void concat(SLL* list);
		void display();
};

//constructor for Singly Linked List
SLL::SLL()
{
	head = NULL;
}

//destructor for Singly Linked List
SLL::~SLL()
{
	Node* current;
	while(head)
	{
		current=head->next;
		delete head;
		head = current;
	}
	current=0;
}

//Function to add at beginning of the list
void SLL::insertAtbeg(int val)
{
	head = new Node(val,head);
}

//Function to remove from beginning of the list
void SLL::removeFrombeg()
{
	if(head==NULL)
	{
		cout<<"\nList is empty!\n";
		return;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		cout<<"Node containing value "<<temp->value<<" is deleted from the list.\n";
		delete temp;
	}
	return;
}

//Function to insert at a particular position
void SLL::insertAtpos(int val,int pos)
{	
	if(pos<=0)
	{
		cout<<"\nInvalid Position!\n";
		return;
	}
	
	//for an empty list
	if(head==NULL)
	{
		insertAtbeg(val);
		return;
	}
	
	Node* current = head;
	int counter = 1;
	
	for(; (current!=0)&&(counter<pos-1) ; current=current->next , counter++);
	
	if(current)
	{	
		if(pos==1)
		{
			insertAtbeg(val);
		}
		else
		{
			current->next = new Node(val,current->next);
			return;
		}
	}
	else
	{
		insertAtend(val);
	}
	
}

//Function to add element at the end of the list
void SLL::insertAtend(int val)
{
	if(head)
	{
		Node* current = head;
		for(;current->next!=0 ; current=current->next);
		current->next = new Node(val,NULL);
	}
	else
	{
		head = new Node(val,head);
	}	
}
//Function to remove from a particular position
void SLL::removeFrompos(int pos)
{
	if(head)
	{
		Node* current = head;
		int counter = 1;
		Node* temp;
		temp = current->next;
	
		for(;(temp!=0)&&(counter<pos-1);current=current->next,temp=temp->next,counter++);
	
		if(temp)
		{
			if(pos==1)
			{
				removeFrombeg();	
			}
			else
			{
				current->next = temp->next;
				cout<<"Node containing value "<<temp->value<<" is deleted from the list.\n";
				delete temp;
				//cout<<"test";
			}
		}
	}
	else
	{
		cout<<"\nList is empty !\n";
		return;
	}
	
}

//Function to search and return a node with a particular value
Node* SLL::search(int val)
{
	if(head)
	{
		Node* temp = head;
		
		while(temp!=0)
		{
			if(temp->value==val)
			{
				return temp;
			}
			temp = temp->next;
		}
	}
	return NULL;
}

//Function to display the list
void SLL::display()
{
	if(head)
	{
		Node* current = head;
		for(;current!=0 ; current=current->next)
		{
			cout<<"("<<current->value<<")"<<"--> ";	
		}
		cout<<endl;
		return;	
	}
	else
	{
		cout<<"\nList is empty !\n";
		return;
	}
}

//Function to concatenate two linked lists
void SLL::concat(SLL* list)
{
	Node* ptr = this->head;
	
	while(ptr->next != 0)
	{
		ptr = ptr->next;
	}
	
	ptr->next = list->head;
	return;
}


//Driver Function for the program
int main()
{
	SLL *L1 = new SLL();
	SLL *L2 = new SLL();
	int choice_1,choice_2;
	int value;
	int position;
	
	do{
		
		cout<<"\nEnter the choice for the operation you want to perform on the stack - Enter 0 to exit.\n";
		cout<<"1. Insert element in the list\n";
		cout<<"2. Remove element from the list\n";
		cout<<"3. Search an element in the list()\n";
		cout<<"4. To concatenate two Lists()\n";
		cout<<"5. clearing the screen !\n";
		
		cin>>choice_1;
		switch(choice_1)
		{
			case 0:
				break;
				
			case 1:
				cout<<"\t1. To add element at the beginning of the list.\n";
				cout<<"\t2. To add element at a particular postion in the list.\n";
				cin>>choice_2;
				switch(choice_2)
				{
					case 1:
						cout<<"Enter value of the element : ";
						cin>>value;
						L1->insertAtbeg(value);
						cout<<"List : ";
						L1->display();
						break;
					
					case 2:
						cout<<"Enter value of the element : ";
						cin>>value;
						cout<<"Enter the position where you want to add the element : ";
						cin>>position;
						L1->insertAtpos(value,position);
						cout<<"List : ";
						L1->display();
						break;
					
					default:
						cout<<"Invalid choice\n";
				}
				break;
				
			case 2:
				cout<<"\t1. To remove element from the beginning\n";
				cout<<"\t2. To remove element from a particular position\n";
				cin>>choice_2;
				switch(choice_2)
				{
					case 1:
						cout<<"List before deleting : ";
						L1->display();
						L1->removeFrombeg();
						cout<<"List after deleting : ";
						L1->display();
						break;
						
					case 2:
						cout<<"List before deleting: ";
						L1->display();
						cout<<"Enter position : ";
						cin>>position;
						L1->removeFrompos(position);
						cout<<"List after deleting : ";
						L1->display();
						break;
						
					default:
						cout<<"Invalid choice\n";
						
				}
				break;
				
			case 3:
				cout<<"Enter a value you want to search in the list : ";
				cin>>value;
				
				if(L1->search(value))
					cout<<"Node with value "<<value<<" found in the list. \n";
				else
					cout<<"Node with value "<<value<<" not found in the list. \n";
				
				break;
				
			case 4:
				cout<<"List 1 : ";
				L1->display();
				cout<<"Creating another list to concatenate with List 1.\n";
				int size;
				cout<<"Enter size of the list : ";
				cin>>size;
				cout<<"Enter elements of List 2 : ";
				
				for(int i=0;i<size;i++)
				{
					cin>>value;
					L2->insertAtend(value);
				}
				cout<<"List 2 : ";
				L2->display();
				L1->concat(L2);
				cout<<"Final List after concatenating both lists : ";
				L1->display();
				delete L2;
				break;
				
			case 5:
				system("cls");
				break;	
							
			default:
				cout<<"Invalid Choice!";
		}
	}while(choice_1!=0);
	
	return 1;
}














