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

void LinkedList::set_head(Node *ptr)
{
	head = ptr;
}

//void LinkedList::clear()
//{
//	Node *ptr = head;
//	clear(ptr);
//}
//
//void LinkedList::clear(Node *ptr)
//{
//	if(ptr != nullptr)
//	{
//		clear(ptr);
//		delete ptr;
//		ptr = nullptr;
//	}
//}

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

void LinkedList::addvalue_sorted(double value)
{
	Node *ptr1 = new Node(value);

	if(head ==  nullptr)
	{
		head = ptr1;
	}
	else if(value < head->x)
	{
		ptr1->next = head;
		head = ptr1;
	}
	else
	{
		Node *ptr = head;
		Node *next = ptr->next;
		Node *prev = ptr;

		while(next != nullptr && ptr->x <= value)
		{
			prev = ptr;
			ptr = ptr->next;
			next = ptr->next;
		}

		{
			prev->next = ptr1;
			ptr1->next = ptr;
		}

	}
}

void LinkedList::clear1()
{
	head = nullptr;
}

void LinkedList::point_last_node(Node* ptr2, int j)
{
	Node* ptr = head;
	Node* prev = ptr;

	while(ptr != nullptr)
	{
		prev = ptr;
		ptr = ptr->next;
	}


	for(int i = 0; i < j; i++)
	{
		ptr2 = ptr2->next;
	}

	prev->next = ptr2;
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

void LinkedList::firsthalf()
{
	Node* ptr = head;
	Node* ptr2 = head;
	Node* prev;

	while(ptr2->next != nullptr && ptr2->next->next != nullptr)
	{
		prev = ptr;
		ptr = ptr->next;
		ptr2 = ptr2->next->next;
	}

	if(ptr2->next == nullptr)
	{
		prev->next = nullptr;
	}
	else
	{
		ptr->next = nullptr;
	}
}

bool LinkedList::operator ==(const LinkedList& other)
{
	Node *ptr = head;
	Node *ptr2 = other.head;
	while(ptr2 != nullptr)
	{
		if(ptr->x != ptr2->x)
			return false;

		ptr = ptr->next;
		ptr2 = ptr2->next;
	}

	return true;
}
