#include <iostream>
using namespace std;

class Array
{
	private:
		int *arr;
		int *curr;
		int size;  //size is for filled index
		int length;	// length is total index
	public:
		Array(int len);   // constructor
		~Array();     // destructor
		void insertElement(int val);   // inserting value
		void insertElementAt(int ind, int val);     // inserting value at desire index in array
		void search(int val);     //  searching element
		void deleteElement(int val);   //  deleting element by value
		void insertInstart(int );    //  inserting element at very first index
		int lengthArray();    // length of array
		void printList();     // printing array 
		void sort();     // sorting array elements
		void reverse();   // reversing array element
		void copylist();    //  copy array elements into another array
		bool isempty();     // showing array is empty or not
		bool isfull();       // showing array is full or not

};

// constructor

Array::Array(int len)
{
	arr = new int[len];
	length = len;
	curr == NULL;
	size = 0;
}

// destructor

Array::~Array()
{
	delete[] arr;
	delete curr;
}

// insert function
void Array::insertElement(int val)
{
	curr = arr;
	if (size == 0)
	{
		*curr = val;
		size += 1;
		curr++;
	}
	else if (size < length)
	{
		*(curr + size) = val;
		curr++;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}

// insert element at desire index function

void Array::insertElementAt(int ind, int val)
{
	if (size < length)
	{
		if (ind == 0)
		{
		insertInstart(val);
			return;
		}
	else if (ind == size)
		{
			insertElement(val);
		}
		else 
		{
			curr = arr+size;
			ind = size - ind;
			while(ind != 0)
			{
				curr--;
				*(curr+1) = *curr;
				ind -= 1;
			}
			*curr = val;
			size += 1; 
		}
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}

// inserting element on very first position

void Array::insertInstart(int val)
{
	curr = arr + size;
	if (curr == arr)
	{
		*curr = val;
		size += 1;
	}
	else if (size < length)
	{
		while(curr != arr)
		{
			curr--;
			*(curr+1) = *curr;
		}
		*curr = val;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}

// search function
void Array::search(int val)
{
	
	curr = arr;
	while(curr != arr + size)
	{
		if (*curr == val)
		{
			cout<<val<<" is in list "<<endl;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}

// delete function

void Array::deleteElement(int val)
{
	curr = arr;
	while(curr != arr + size)
	{
		if (*curr == val)
		{
			while(curr != arr + size)
			{
				*curr = *(curr+1);
				curr++;
			}
			size -= 1;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}
// length function
int Array::lengthArray()
{
	cout<<"length of array is "<<endl;
	cout<< length<<endl;
}

// printing function
void Array::printList()
{
	cout<<"[";
	curr = arr;
	while(curr != arr + size)
	{
		cout<<*curr;
		if (curr != arr+(size-1))
		{
			cout<<",";
		}
		curr++;
	}
	curr = NULL;
	cout<<"]"<<endl;
	cout<<length-size<<" place empty"<<endl;
}

// sorting function
void Array::sort()
{
	curr = arr;
	int temp;
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(*(arr+i)>*(curr+j))
			{
				temp = *(arr+i);
				*(arr+i)=*(curr+j);
				*(curr+j)=temp;
			}
		}
		
	}
	cout<<"Sorted Array is "<<endl;
	cout<<"[";
	for(int z=0;z<size;z++)
	{
		cout <<*(arr+z);
		cout<<" ";
	}
	cout<<"]"<<endl;
}

// reverse function
void Array::reverse()
{
	cout<<"Reverse Array is "<<endl;
	cout<<"[";
	for(int i=size-1;i>=0;i--)
	{
	  cout<<*(arr+i);
	  cout<<" ";	
	}
	cout<<"]"<<endl;
}

//  copy function
void Array::copylist()
{
    int * arr1 = new int[size];
    int temp;
   for(int j = 0;j<size;j++)
   {
   	    temp = *(arr +j);
   	  *(arr1+j) = temp;
   }
   cout<<"copy of Array is "<<endl;
   cout<<"[";
   for(int i=0;i<size;i++)
   {
   	 cout<<*(arr1+i);
   	 cout<<" ";
   }
   cout<<"]"<<endl;	
   delete[] arr1;
}

// isfull function
bool Array::isfull()
{
	if(size==length)
	return true;
	else
	  return false;
}

// isempty function
bool Array::isempty()
{
	if(size<length)
	return true;
	else
	  return false;
}

// int main
int main()
{
	Array a(6);
	a.insertElement(5);
	a.insertElement(4);
	a.insertElement(9);
	a.insertElement(6);
	a.insertInstart(3);
	a.lengthArray();
	a.printList();
	a.copylist();
	cout<<"inserting 7 at index 2 "<<endl;
	a.insertElementAt(2,7);
	a.printList();
	cout<<"deleting 5 from list "<<endl;
    a.deleteElement(5);
    a.printList();
    a.search(9);
    a.reverse();
    a.sort();
    a.isempty();
    a.isfull();

	
	return 0;
} 
