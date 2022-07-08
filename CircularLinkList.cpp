#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *pre;
};



class doublyRing
{
	private:
		Node *head;
	public:
		doublyRing();
		~doublyRing();
		void Insert(int info);
		void InsertAtPos(int key, int info);
		void deleteElements(int key);
		void search(int key);
		void display();
};



doublyRing::doublyRing()
{
	head = NULL;
}

doublyRing::~doublyRing()
{
	Node *fun = head->next;
	Node *pre = fun;
	while(fun->next != head)
	{
		pre = fun;
		fun = fun->next;
		delete pre;
	}
	delete head, fun;
}


void doublyRing::Insert(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
		head->pre = head;
	}
	else
	{
		Node *fun = head;
		while(fun->next != head)
		{
			fun = fun->next;
		}
		Node *temp = new Node;
		temp->next = head;
		temp->pre = fun;
		temp->data = info;
		head->pre = temp;
		fun->next = temp;
	}
}



void doublyRing::InsertAtPos(int key, int info)
{
	if (head == NULL)
	{
		cout<<"CircularRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *temp = new Node;
		temp->next = head;
		temp->pre = head;
		temp->data = info;
		head->next = temp;
		head->pre = temp;
	}
	else
	{
		Node *fun = head;
		while(fun->next != head)
		{
			if (fun->data == key)
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
		if (fun->data == key && fun->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->pre = fun;
			temp->data = info;
			head->pre = temp;
			fun->next = temp;
		}
	}
}


void doublyRing::deleteElements(int key)
{
	if (head == NULL)
	{
		cout<<"CircularRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *fun = head;
		delete fun;
		head = NULL; 
	}
	else
	{
		Node *fun = head;
		while(fun->next != head)
		{
			if (fun->data == key && fun == head)
			{
				head = head->next;
				head->pre = fun->pre;
				fun->pre->next = head;
				delete fun;
				fun = head->pre;
			}
			if (fun->data == key)
			{
				fun->pre->next = fun->next;
				fun = fun->pre;
				delete fun->next->pre;
				fun->next->pre = fun; 
			}
			fun = fun->next;
		}
		if (fun->data == key && fun->next == head)
		{
			fun->pre->next = fun->next;
			fun = fun->pre;
			delete fun->next->pre;
			fun->next->pre = fun;
			return;
		}
	}
}


void doublyRing::search(int key)
{
	if (head == NULL)
	{
		cout<<"CircularRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		cout<<key<<" is in CircularRing"<<endl; 
	}
	else
	{
		Node *fun = head;
		while(fun->next != head)
		{
			if (fun->data == key)
			{
				cout<<key<<" is in CircularRing"<<endl; 
			}
			fun = fun->next;
		}
		if (fun->data == key && fun->next == head)
		{
			cout<<key<<" is in CircularRing"<<endl;
		}
	}
}





void doublyRing::display()
{
	if (head == NULL)
	{
		cout<<"CircularRing is empty"<<endl;
		return;
	}
	Node *fun = head;
	if (fun->next == head)
	{
		cout<<fun->data<<" ";
	}
	else
	{
		while(fun->next != head)
		{
			cout<<fun->data<<" ";
			fun = fun->next;
		}	
		cout<<fun->data<<" "<<endl;
	}
}


int main()
{
	doublyRing obj;
	obj.Insert(1);
	obj.Insert(2);
	obj.Insert(7);
	obj.Insert(9);
	obj.InsertAtPos(7,6);
	obj.search(2);
	obj.display();
	cout<<"After Deletion "<<endl;
	obj.deleteElements(7);
	obj.display();
	return 0;
}
