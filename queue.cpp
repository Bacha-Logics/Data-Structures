#include <iostream>
using namespace std;



class queue
{
	private:
		int *front;
		int *rear;
		int *arr;
		int size;
	public:
		queue(int s);
		~queue();
		void equeue(int info);
		void dqueue();
		void display();
};


queue::queue(int num)
{
	size = num;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		*(arr+i) = 0;
	}
	front = NULL;
	rear = NULL;

}

queue::~queue()
{
	delete [] arr;
	front == NULL;
	rear == NULL;
	size = 0;	
}


void queue::equeue(int info)
{
	if ((front == arr && rear == arr+(size-1)) || front-1 == rear) 
	{
		cout<<"overflow"<<endl;
		return;
	}
	if (rear == NULL) 
	{
		rear = arr;
		*rear = info;
		front = rear;
		return;
	}
	if (front != arr && rear == arr+(size-1))  
	{
		rear = arr;
		*rear = info;
		return;
	}
	rear++;		
	*rear = info;
	return;
}

void queue::dqueue()
{
	if (front == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	if (front == rear) 
	{
		front=NULL;
		rear=NULL;
		return;
	}
	if (front == arr+(size-1) && rear != arr+(size-1)) 
	{
		front = arr;
		return;
	}
	front++;

}


void queue::display()
{
	int *temp = front;
	if (temp == NULL)
	{
		cout<<"Empty queue"<<endl;	
		return;
	}
	while(temp != rear)
	{
		if (temp == arr+(size-1))
		{
			temp = arr;
		}
		cout<<*temp<<" ";
		temp++;
	}
	if (temp == rear)
	{
		cout<<*temp<<endl;
		return;
	}
}


int main()
{

	queue obj(5);
	obj.equeue(83);
	obj.equeue(14);
	obj.equeue(35);
	obj.equeue(88);
	obj.equeue(47);
	obj.display();
    obj.dqueue();
	obj.display();
	return 0;
}
