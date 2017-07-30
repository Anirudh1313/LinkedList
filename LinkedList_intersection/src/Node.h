/*
 * Node.h
 *
 *  Created on: May 31, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>

class Node
{
public:
	Node() : x(0), next(nullptr) {}
	Node(double x1) : x(x1), next(nullptr) {}
	~Node() {}

	double get_x() { return x; }
	Node* get_next() {return next; }

	void set_x(double val) { x = val; }
	void set_next(Node *nex) { next = nex; }

	Node *next;
	double x;
private:

};



#endif /* NODE_H_ */
