#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *pre;
};


class doublyLinkList
{
	private:
		Node *head;

	public:
		doublyLinkList();        // constructor
		~doublyLinkList();      // destructor
		void Insert(int info);
		void InsertAtPos(int key, int info);
		void deleteElements(int info);
		void search(int info);
		void display();
};


doublyLinkList::doublyLinkList()
{
	head = NULL;
}

doublyLinkList::~doublyLinkList()
{
	Node *pre;
	Node *fun;
	fun = head;
	while(fun != NULL)
	{
		pre = fun;
		fun = fun->next;
		delete pre;
	}
}




void doublyLinkList::Insert(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->next = NULL;
		head->pre = NULL;
		head->data = info; 
	}
	else
	{
		Node *fun;
		fun = head;
		while(fun != NULL)
		{
			if (fun->next == NULL)
			{
				Node *temp = new Node;
				temp->data = info;
				temp->next = NULL;
				temp->pre = fun;
				fun->next = temp;
				return;
			}
			fun = fun->next;
		}
	}
}



void doublyLinkList::InsertAtPos(int key, int info)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		Node *temp = new Node;
		temp->next = NULL;
		temp->pre = head;
		temp->data = info;
		head->next = temp;

	}	
	else
	{
		Node *fun;
		fun = head;
		while(fun != NULL)
		{
			if (fun == head && fun->data == key)
			{
				Node *temp = new Node;
				temp->next = head->next;
				temp->pre = head;
				temp->data = info;
				head->next->pre = temp;
				head->next = temp;
				fun = fun->next;
			}
			else if (fun->data == key && fun->next == NULL)
			{
				Node *temp = new Node;
				temp->next = fun->next;
				temp->pre = fun;
				temp->data = info;
				fun->next = temp;
				fun = fun->next;
			}
			else if (fun->data == key)
			{
				Node *temp = new Node;
				temp->next = fun->next;
				temp->pre = fun;
				temp->data = info;
				fun->next->pre = temp;
				fun->next = temp;
				fun = fun->next;
				
			}
			fun = fun->next;
		}
	}
}


void doublyLinkList::deleteElements(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		head = NULL;

	}	
	else
	{
		Node *fun;
		fun = head;
		while(fun != NULL)
		{
			if (fun == head && fun->data == key)
			{
				head = head->next;
				delete fun;
				fun = head;
			}
			else if (fun->data == key && fun->next == NULL)
			{
				fun->pre->next = fun->next;
				delete fun;
				return;
			}

			else if (fun->data == key)
			{
				fun->pre->next = fun->next;
				fun = fun->pre;
				delete fun->next->pre;
				fun->next->pre = fun;
			}
		    fun = fun->next;
		}
	}
}


void doublyLinkList::search(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		cout<<key<<" is in doublyLinkList "<<endl;

	}	
	else
	{
		Node *fun;
		fun = head;
		while(fun != NULL)
		{
			if (fun->data == key)
			{
				cout<<key<<" is in doublyLinkList "<<endl;
			}
			fun = fun->next;
		}
	}
}

void doublyLinkList::display()
{
	Node *fun;
	fun = head;
	int count = 1;
	while(fun != NULL)
	{
		cout<<count<<" : "<<fun->data<<endl;
		fun = fun->next;
		count += 1;
	}
}


int main()
{
	doublyLinkList d;
	
	d.Insert(2);
	d.Insert(6);
	d.Insert(8);
	d.Insert(3);
	d.InsertAtPos(6,7);
	d.Insert(9);
	d.search(8);
	d.display();
	cout<<"After Deletion "<<endl;
	d.deleteElements(3);
	d.display();
	

	return 0;
}
