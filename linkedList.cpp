#include <iostream>
using namespace std;
//CLASS NODE DEFENITION
class Node
{
public:
	int data;
	Node *next;
};
//FUNCTION TO CREATE NEW NODE
Node *createNode(int val)
{
	Node *node = new Node();
	node->data = val;
	node->next = NULL;
	return node;
}
//FUNCTION TO INSERT VALUE AT BEGINNING OF LIST
void insertAtBeginning(Node **head,int val)
{
	Node *node = createNode(val);
	if (head == NULL)
		*head = node;
	else
	{
		node->next = *head;
		*head = node;
	}
}
//FUNCTION TO INSERT VALUE AT END OF LIST
void insertAtEnd(Node *head, int val)
{
	Node *node = createNode(val);
	Node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}
//FUNCTION TO INSERT VALUE AT A PARTICULAR POSITION
void insertAtPosition(Node **head, int val, int pos)
{
	Node *node = createNode(val);
	if (pos == 1)
	{
		insertAtBeginning(head,val);
		return;
	}
	int count = 1;
	Node *temp = *head;
	Node *curr = *head;
	while (count != pos)
	{
		temp = curr;
		curr = curr->next;
		count++;
	}
	temp->next = node;
	node->next = curr;
}
//FUNCTION TO DELETE NODE
void deleteNode(Node **head, int val)
{
	Node *temp = *head;
	if (temp->data == val)
	{
		*head = temp->next;
		temp->next = NULL;
	}
	else
	{
		Node *curr = *head;
		temp = temp->next;
		while (temp != NULL)
		{
			if (temp->data == val)
			{
				curr->next = temp->next;
				temp->next = NULL;
				break;
			}
			temp = temp->next;
			curr = curr->next;
		}
		if (temp == NULL)
			cout << "Element to deleted not found!!"<<endl;
	}
}
//FUNCTION TO SEARCH FOR A VALUE
void search(Node *head, int val)
{
	int pos = 1;
	while (head != NULL)
	{
		if (head->data == val)
		{
			cout << "Value found at position " << pos << endl;
			break;
		}
		pos++;
	}
	if (head == NULL)
		cout << "Value not found!!" << endl;
}
//FUNCTION TO DISPLAY LIST
void display(Node *temp)
{
	if (temp == NULL)
		cout << "List is empty!!";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;
	int choice;
	char my_choice;
	do {
		cout << "========================================================================"<<endl;
		cout << "1.Insert\t 2.Delete\t 3.Search\t 4.Display\t 5.Exit" << endl;
		cout << "Enter choice(1-4): ";
		cin >> choice;

		switch (choice)
		{
		case 1: int ch;
				int val;
				cout << "1.Beginning\t 2.End\t 3.Particular position" << endl;
				cout << "Enter your choice(1-3): ";
				cin >> ch;
				cout << "Enter data to be inserted: ";
				cin >> val;
				if (ch == 1)
					insertAtBeginning(&head, val);
				else if (ch == 2)
					insertAtEnd(head, val);
				else
				{
					int pos;
					cout << "Enter position to insert data: ";
					cin >> pos;
					insertAtPosition(&head, val, pos);
				}
				break;
		case 2: cout << "Enter value to be deleted: ";
				cin >> val;
				deleteNode(&head, val);
				break;
		case 3: cout << "Enter value to be searched: ";
				cin >> val;
				search(head, val);
				break;
		case 4: display(head);
				break;
		case 5: break;
		default: break;
		}
		if (choice == 5)
			break;
		cout << "Do you want to continue(y/n)? ";
		cin >> my_choice;
		cout << endl;
	} while (my_choice != 'n');
}

