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
//	l1.addvalue_sorted(10);
//	l1.addvalue_sorted(2);
	l1.print();
	string in;
	int f = 0;
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
	Node *ptr = l1.get_head();
	Node *ptr2 = l2.get_head();

	Node *mid = middle(ptr2);

	Node *p = reverse(mid);

	l1.print();
	l1.firsthalf();
	cout << "l1 half: ";
	l1.print();

    l2.set_head(p);
    l2.print();

    if(l1 == l2)
    {
    	cout <<"Yes! the list you entered is a Palindrome" << endl;
    }
    else
    {
    	cout <<"No! the list you entered is not a Palindrome" << endl;
    }

    LinkedList l3(ptr);
	l3.print();


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

