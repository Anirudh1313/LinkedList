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

void LinkedList::point_last_node(Node* ptr2, int j)  //connecting one list to the second list's node!
{
	Node* ptr = head;
	Node* prev = ptr;

	while(ptr != nullptr)
	{
		prev = ptr;
		ptr = ptr->next;
	}


	for(int i = 0; i < j-1; i++)
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

