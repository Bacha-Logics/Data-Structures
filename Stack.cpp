#include <iostream>
using namespace std;



class stack
{
	private:
		int *top;
		int *arr;
		int size;
	public:
		stack(int s);
		~stack();
		void push(int info);
		void pop();
		void display();	
};



stack::stack(int num)
{ 
	size = num;
	arr = new int [size];
	for (int i = 0; i < size; i++)
	{
		*(arr+i) = 0;
	}
	top = NULL;
}



stack::~stack()
{
	delete [] arr;
}





void stack::push(int info)
{
	if (top == arr+(size-1))
	{
		cout<<"overflow"<<endl;
		return;
	}
	if (top == NULL)
	{
		top = arr;
		*top = info;
		return;
	}
	top++;
	*top = info;
	return;
	
}



void stack::pop()
{
	if (top == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	if (top == arr)
	{
		top == NULL;
		return;
	}
	top--;
	return;
}




void stack::display()
{
	int temp = 0;
	if (arr == NULL)
	{
		cout<<"stack is empty"<<endl;
		return;
	}
	while(temp+arr <= top)
	{
		cout<<*(arr+temp)<<" ";
		temp++;
	}
	cout<<endl;
}



int main()
{
	stack obj(5);
	obj.push(2);
	obj.push(3);
	obj.push(6);
	obj.display();
	obj.pop();
	obj.display();

	return 0;
}
