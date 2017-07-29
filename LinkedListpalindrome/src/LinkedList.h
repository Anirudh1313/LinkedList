/*
 * LinkedList.h
 *
 *  Created on: May 31, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <string>

using namespace std;

class LinkedList
{

public:
	LinkedList();
	LinkedList(Node *h);
	~LinkedList();
	void clear();
	void set_head(Node *ptr);
	void clear(Node *ptr);
	Node* get_head() { return head; }
	void set_head();
    void addValue(double val);
    void addvalue_sorted(double value);
    void clear1();
    void print();
    void point_last_node(Node* ptr2, int j);
    void firsthalf();
    bool operator ==(const LinkedList& other);

private:
    Node *head;
};



#endif /* LINKEDLIST_H_ */
