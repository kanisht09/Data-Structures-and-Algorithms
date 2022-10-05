#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;

	// Default constructor
	Node() {
		data = 0;
		next = NULL;
	}

	// Parameterised Constructor
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

// Linkedlist implementation
class Linkedlist {
	Node* head;

public:
	// Default constructor
	Linkedlist() { head = NULL; }

	// Function to insert a node at the end of the linked list.
	void insertNode(int);

	// Function to print the linked list.
	void printList();

	// Function to delete the node at given position
	void deleteNode(int);
};

// Function to delete the node at given position
void Linkedlist::deleteNode(int nodeOffset) {
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	temp1 = head;

	if (nodeOffset == 1) {
		head = head->next;
		delete temp1;
		return;
	}

	while (nodeOffset-- > 1) {
		temp2 = temp1;
		temp1 = temp1->next;
	}

	temp2->next = temp1->next;

	delete temp1;
}

void Linkedlist::insertNode(int data) {
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void Linkedlist::printList() {
	Node* temp = head;

	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	Linkedlist list;

	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);

	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;

	list.deleteNode(2);

	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}
