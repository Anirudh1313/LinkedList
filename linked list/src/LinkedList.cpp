/*
 * LinkedList.cpp

 *
 *  Created on: May 31, 2017
 *      Author: krishnasaianirudhkatamreddy
 */
#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(Node *h) : head(h) {}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	Node *ptr = head;
	clear(ptr);
}

void LinkedList::clear(Node *ptr)
{
	if(ptr != nullptr)
	{
		clear(ptr);
		delete ptr;
		ptr = nullptr;
	}
}

void LinkedList::addValue(double val)
{
    Node *n = new Node(val);
    if(head == nullptr)
    {
    	head = n;
    }
    else
    {
 	   Node *p = head;
 	   Node *prev;
 	   while(p != nullptr)
 	   {
 		   prev = p;
 		   p = p->next;
 	   }
 	   //if(p != nullptr)
 	   {
 		  prev->next = n;
 		  n->next = p;
 	   }
// 	   else
// 	   {
//  		  prev->next = n;
//  		  n->next = nullptr;
// 	   }
    }
	//Node *n;
    //n = Node(val);
    //n->set_x(val);
    //n->set_next(nullptr);         // make the node point to the next node.
                            //  If the list is empty, this is NULL, so the end of the list --> OK
    //head = n;               // last but not least, make the head point at the new node.
}

void LinkedList::clear1()
{
	head = nullptr;
}

void LinkedList::remove_dups()
{
	Node *ptr = head;
	Node *prev;
	while(ptr != nullptr)
	{
		Node *ptr2 = ptr->next;
		prev = ptr;
		while(ptr2 != nullptr)
		{
			if(ptr2->get_x() == ptr->get_x())
			{
				prev->next = ptr2->next;
			}
			prev = ptr2;
			ptr2 = ptr2->next;

		}
		ptr = ptr->next;
	}
}

void LinkedList::print()
{
	Node *ptr = head;
	while(ptr != nullptr)
	{
		cout << ptr->get_x();
		if(ptr->next != nullptr)
		{
			cout << ", ";
		}
		ptr = ptr->next;
	}
	cout << "." << endl;
}

void LinkedList::addValue_1(double val) //inserting values to the linked list while sorting
{
    Node *n = new Node(val);
    if(head == nullptr)
    {
    	head = n;
    }
    else if(val < head->get_x())
    {
    	n->next = head;
    	head = n;
    }
    else
    {
 	   Node *p = head;
 	   Node *prev = p;
 	   while(p != nullptr && val >= p->get_x())
 	   {
 		   prev = p;
 		   p = p->next;
 	   }
	   prev->next = n;
	   n->next = p;
    }
}

int LinkedList::popValue(/*int val, string nam*/) //deleting the first node and returning the value of the deleted node.
{
	double val;
    Node *n = head;
    val = n->get_x();
	delete n;
	head = head->next;
    return val;
}

void LinkedList::find(int value) const  //finding the position of the a single value
{
    Node *p = head;
    while (p != nullptr)
    {
        if ((p != nullptr) && (value == p->get_x()))
        {
        	cout << " #";
        }
        else
        {
        	cout << setw(2) << right << " ";
        }
    	p = p->next;
   	}
    cout << "\n";

}

void LinkedList::find(int val_1, int val_2) const //finding the position of the two value's at a time
{
    Node *p = head;
    while (p != nullptr)
    {
        if ((p != nullptr) && ((val_1 == p->get_x()) || val_2 == p->get_x()))
        {
        	cout << " #";
        }
        else
        {
        	cout << setw(2) << right << " ";
        }
    	p = p->next;
   	}
    cout << "\n";
}

void LinkedList::find(int val_1, int val_2, int val_3) const //finding the position of the three value's
{
    Node *p = head;

    while (p != nullptr)
    {
        if ((p != nullptr) && ((val_1 == p->get_x()) || val_2 == p->get_x() || val_3 == p->get_x()))
        {
        	cout << " #";
        }
        else
        {
        	cout << setw(2) << right << " ";
        }
    	p = p->next;
   	}
    cout << "\n";
}

bool LinkedList::search(double val) const  //checking whether the value is present in the list or not.
{
	Node *ptr = head;
	while(ptr != nullptr)
	{
		if(ptr->get_x() == val)
		{
			return true;
		}
		ptr = ptr->next;
	}

	return false;
}

int LinkedList::position(double val) const   //takes a value and returns the position of the value
{
	Node *ptr = head;
	int i = 0;
	while(ptr != nullptr)
	{
		if(ptr->get_x() == val)
			return i;
		i++;
		ptr = ptr->next;
	}

	return -1;
}

double LinkedList::value(int k) //takes the position and returns the value in the position
{
	Node *ptr = head;
	int i = 0;
	while(ptr != nullptr)
	{
		if(i == k)
		{
			return ptr->get_x();
		}

		ptr = ptr->next;
		i++;
	}

	//if the entered position is greater than the size of the list, returns 0.001 or we can throw an exception too.
	return 0.001;
}

void LinkedList::add_value_position(int i, double val) //adding value at a particular position
{
	Node *ptr = head;
	Node *prev = ptr;
	int k = 0;
	Node *n = new Node(val);
	while(ptr != nullptr && k <= i)
	{
		if(k == i)
		{
			prev->next = n;
			n->next = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
		k++;
	}
	if(ptr == nullptr)
	{
		prev->next = n;
		n->next = ptr;
	}
}

double LinkedList::remove_value_position(int i) //takes in the position, removes value from particular position and returns the deleted value
{
	Node *ptr = head;
	Node *prev = ptr;
	int val;
	int k = 0;
	while(ptr->next != nullptr && k <= i)
	{
		if(k == i)
		{
			prev->next = ptr->next;
			val = ptr->get_x();
			delete ptr;
			return val;
		}
		prev = ptr;
		ptr = ptr->next;
		k++;
	}

    val = ptr->get_x();
	prev->next = nullptr;
	delete ptr;                      //will delete the last element if the index is more than the list size.

	return val;
}

int LinkedList::remove_value(double val) // takes in a value and removes the value entered
{
	Node* ptr = head;
	Node* prev = ptr;
	int i = 0;
	while(ptr != nullptr)
	{
		if(ptr->get_x() == val)
		{
			prev->next = ptr->next;
			delete ptr;
			return i;
		}
		i++;
		prev = ptr;
		ptr = ptr->next;
	}
	//if the value is not found in the list, returns -1
	return -1; //Exception required i.e., throw function required.
}

double LinkedList::reverse_value(int k) //find the value at the position entered from reverse
{
	Node *ptr = head;
	int len = 0;
	while(ptr != nullptr)
	{
	    len++;
		ptr = ptr->next;
	}
	int rev = len-k;
	ptr = head;
	int i = 1;
	while(ptr != nullptr && i <= rev)
	{
		if(i == rev)
		{
			return ptr->get_x();
		}

		ptr = ptr->next;
		i++;
	}
	return 0.001;
}

bool LinkedList::circularList() //check whether the list is circular or not.
{
	Node *ptr = head;
	Node *ptr1 = ptr->next->next;

	while(ptr != nullptr && ptr1 != nullptr && ptr1->next != nullptr)
	{
		if(ptr == ptr1 || ptr == ptr1->next)
		{
			cout << "found loop!" << endl;
			return true;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next->next;
	}
	cout << "loop not found!" << endl;
	return false;
}

Node* LinkedList::findmin() //find the minimum value in the linked list and return the value.
{
	Node* ptr = head;
	int smallest;
	smallest = ptr->get_x();
	Node* s = ptr;
	while(ptr != nullptr)
	{
		if(ptr->get_x() < smallest)
		{
			smallest = ptr->get_x();
			s = ptr;
		}
		ptr = ptr->next;
	}
	return s;
}

Node* LinkedList::findmax()  //find the maximum value in the linked list and return the value.
{
	Node* ptr = head;
	int largest;
	largest = ptr->get_x();
	Node* s = ptr;
	while(ptr != nullptr)
	{
		if(ptr->get_x() > largest)
		{
			largest = ptr->get_x();
			s = ptr;
		}
		ptr = ptr->next;
	}
	return s;
}

bool LinkedList::remove_middle() //find the middle node in the list and remove the node.
{
	Node *ptr1 = head;
	Node *ptr2 = head;
	Node* prev = ptr1;

	if(head == nullptr || head->next == nullptr)
		return false;

	while(ptr2->next != nullptr && ptr2->next->next != nullptr)
	{
		prev = ptr1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}

	prev->next = ptr1->next;
	delete ptr1;
	return true;
}

string LinkedList::reverseAttachAll() //reverse attach all the values in the list to a string
{
	string k = "";
	string f = reverseAttachAll(head, k);
	return f;
}

string LinkedList::reverseAttachAll(Node* &ptr, string &k)
{
	if(ptr == nullptr)
	{
		return "";
	}

    k = reverseAttachAll(ptr->next, k);
    int i = (ptr->get_x());
	k += to_string(i);
	return k;
}

bool LinkedList::palindrome() //check whether the list is a palindrome or not. 1 2 3 4 5 4 3 2 1,
{
	LinkedList l1;
	l1.clear();
	Node *ptr = head;

	Node *pl1 = pal(ptr, l1);
	ptr = head;

	while(pl1 != nullptr)
	{
		if(pl1->x != ptr->x)
			return false;
		pl1 = pl1->next;
		ptr = ptr->next;
	}

	return true;
}

Node* LinkedList::pal(Node *ptr, LinkedList l1) //reversing the linked list and creating a new list and returning the head of the list.
{
	Node* h;
	if(ptr->next == nullptr)
	{
		return nullptr;
	}

	h = pal(ptr->next, l1);
	l1.addValue(ptr->get_x());
	h = l1.get_head();
	return h;

}
