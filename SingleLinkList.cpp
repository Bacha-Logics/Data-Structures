#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linklist
{
	protected:
		Node *head;
		Node *tail;
	public:
		linklist();
		~linklist();
		void Insert(int info);
		void InsertAtPos(int info,int val);
		void Remove(int info);
		void search(int info);
		void SwapNode(int x, int y);
		void print();
};


linklist::linklist()
{
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
{
	Node *pre;
	Node *link;
	link = head;
	while(link != NULL)
	{
		pre = link;
		link = link->next;
		delete pre;
	}
	delete link;
	delete head;
}

void linklist::Insert(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
}

void linklist::print()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<endl;
			temp = temp->next;
			i++;
		}
	}
}

void linklist::Remove(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *link;
		Node *pre;
		link = head;
		pre = link;		
		if(head->data == info)
		{
			head = head->next;
			delete link;
			return;
		}
		while(link != NULL)
		{
			if(link->data == tail->data && link->data == info)
			{
				tail = pre;
				tail->next = NULL;
				delete link;
			}
			else if(link->data == info)
			{
				pre->next = link->next;
				delete link;
				return;
			}
			else
			{
				pre = link;
				link = link->next;
			}
		}
	
	}
}


void linklist::search(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			cout<<info<<" is in linklist"<<endl;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *link;
		link = head;
		while(link != NULL)
		{	
			if(link->data == info)
			{
				cout<<info<<" is in linklist"<<endl;	
			}
			link = link->next;
		}
	
	}
}


void linklist::SwapNode( int x, int y)
{	
   if (x == y)
   {
      return;
   }
    Node *x_pre = NULL; 
	Node *x_next = head;
   while (x_next && x_next->data != x)
   {
       x_pre = x_next;
       x_next = x_next->next;
   }
 
   Node *y_pre = NULL;
   Node *y_next = head;
   while (y_next && y_next->data != y)
   {
       y_pre = y_next;
       y_next = y_next->next;
   }

   if (x_next == NULL || y_next == NULL)
   {
       return;
   }
   if (x_pre != NULL)
   {
       x_pre->next = y_next;
   }
   else
   { 
       head = y_next;  
   }
   if (y_pre != NULL)
       y_pre->next = x_next;
   else
   {  
       head = x_next;
   }

   Node *temp = y_next->next;
   y_next->next = x_next->next;
   x_next->next  = temp;
   
   cout<<endl;
   cout<<"Values After Swapping Is :"<<endl;
}


void linklist::InsertAtPos(int info, int val)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
			tail = temp;
		}
		else
		{
			cout<<info<<" There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *link;
		link = head;	
		while(link != NULL)
		{
			if(link->next == tail->next && link->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
			else if(link->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = link->next;
				link->next = temp;
			}	
			link = link->next;
		}
	}
}



int main()
{

	linklist l;
	l.Insert(30);
	l.Insert(55);
	l.Insert(88);
	l.Insert(22);
	l.Insert(66);
	l.Insert(99);
	l.InsertAtPos(88,100);
	l.InsertAtPos(99,101);
	l.print();
	cout<<endl;
	l.Remove(22);
    l.search(88);
    cout<<endl;
    l.SwapNode(30,101);
	l.print();
	return 0;
}


