//============================================================================
// Name        : LinkedList_intersection.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

void inter(LinkedList l1, LinkedList l2);
Node* ll(Node* ptr, Node* ptr2);

int main()
{
	LinkedList list1, list2;
	for(int i = 0; i < 5; i++)
	{
		list1.addValue(i);
	}

	for(int i = 0; i < 7; i++)
	{
		list2.addValue(i);
	}

	Node* ptr2 = list2.get_head();

	list1.point_last_node(ptr2, 5); //pointing the list1's last node to the 3rd node from the ptr2.

	list1.print();

	inter(list1, list2);

	return 0;
}

void inter(LinkedList l1, LinkedList l2)
{
	Node *ptr = l1.get_head();
	Node *ptr2 = l2.get_head();
	int i = 0;
	//calculating the length of the list1!
	while(ptr != nullptr)
	{
		i++;
		ptr = ptr->next;
	}
	//calculating the length of the list2!
	int j = 0;
	while(ptr2 != nullptr)
	{
		j++;
		ptr2 = ptr2->next;
	}
	//finding the difference in the length
	int len = i-j;

	//replacing the pointers to the head of the lists!
	ptr = l1.get_head();
	ptr2 = l2.get_head();
	//if list 1's length is greater than list2
	if(len > 0)
	{
		while(len > 0)
		{
			ptr = ptr->next;
			len--;
		}
	}
	//else if list2's length is greater than list1
	else
	{
		while(len < 0)
		{
			ptr2 = ptr2->next;
			len++;
		}
	}
	//moving the pointer to the same level!

	//comparing both lists if they have any equal node so that its an intersection!
	Node* itr = ll(ptr, ptr2);  //returns node if found an intersection and returns 'nullptr' if not found any intersection.

	if(itr == nullptr)
	{
		cout << "No intersection" << endl;
	}
	else
	{
		cout << "Yes! intersection is at " << itr->x << endl;
	}



}

Node* ll(Node* ptr, Node* ptr2)
{
	//comparing the pointers called in the function, checking all the nodes till the nullptr, to find the equality!
	while(ptr != nullptr && ptr2 != nullptr)
	{
		//if any equal node found return the node
		if(ptr->next == ptr2->next)
		{
			return ptr->next;
		}

		//moving each node in an equal pace
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}

	//if not found any equal node returning nullptr!
	return nullptr;
}
