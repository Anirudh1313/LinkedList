//============================================================================
// Name        : LinkedListpalindrome.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.h"
using namespace std;

Node* reverse(Node* ptr);
Node* middle(Node* ptr);

int main()
{

	LinkedList l1, l2;
	l1.clear1();
	l2.clear1();

	string in;
	int f = 0;
	cout << "Enter a list of integers: ";
	while(in[0] != '.')
	{
		if(f == 1)
		{
			if(isdigit(in[0]))
			{
				double k = stod(in);
				l1.addValue(k);
				l2.addValue(k);
			}
			else
			{
				cout << "Enter a valid integer" << endl;
			}
		}
		f = 1;
		cin >> in;
	}
	//setting up a linkedlist while giving input values!

// ALGORITHM-1: REVERSING THE WHOLE LIST AND EQUATING BOTH THE LISTS, IF EQUAL ITS A PLAINDROME
//	Node *ptr = l1.get_head();
	Node *ptr2 = l2.get_head();

	l1.print();

	Node *p = reverse(ptr2); //reversing the node's starting from the input node.
	
	
/* AGORITHM-2: FINDING THE MIDDLE ELEMENT &  REVERSING THE SECOND HALF OF THE LIST AND EQUATING 
 *THE FIRSTHALF AND THE SECOND HALF OF THE REVERSED LIST.
 */
//	Node *mid = middle(ptr2); //finding the middle node of the list
//
//	Node *p = reverse(mid); //reversing the node's starting from the input node.
//
//	l1.print();
//	l1.firsthalf(); //making the list to half the size!
//
//	cout << "l1 half: ";
//	l1.print();
//      l2.set_head(p);
	
    l2.set_head(p); //setting the list to the reversed list head
	
    cout << "list after reversing: "; l2.print();

    if(l1 == l2)
    {
    	cout << "Yes! the list you entered is a Palindrome" << endl;
    }
    else
    {
    	cout << "No! the list you entered is not a Palindrome" << endl;
    }

	return 0;
}

Node* middle(Node* ptr)
{
	Node *ptr2 = ptr;
	while(ptr2 != nullptr && ptr2->next != nullptr)
	{
		ptr = ptr->next;
		ptr2 = ptr2->next->next;
	}
	return ptr->next;
}

Node* reverse(Node* ptr)
{
    Node* prev   = nullptr;
    Node* current = ptr;
    Node* next;
    while (current != nullptr)
    {
    	next = current->next;
    	current->next = prev;
    	prev = current;

    	current = next;

    }
	
    ptr = prev;
    return ptr;

}

