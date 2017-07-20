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
	LinkedList(Node *head);
	~LinkedList();
	void clear();
	void clear(Node *ptr);
	Node* get_head() { return head; }
    void addValue(double val);
    void addValue_1(double val);
    int popValue(/*int val, string nam*/);
    void find(int value) const;
    void find(int val_1, int val_2) const;
    void find(int val_1, int val_2, int val_3) const;
    bool search(double val) const;
    int position(double val) const;
    void clear1();
    void remove_dups();
    void print();
    double value(int k);    //input K'th term, outputs value of the K'th Node.
    void add_value_position(int i, double val);
    double remove_value_position(int i);
    int remove_value(double val);
    double reverse_value(int k);  //input K'th term from back, outputs value of the K'th Node from back.
    bool circularList();
    bool remove_middle();

    string reverseAttachAll();
    string reverseAttachAll(Node* &ptr, string &k);

    bool palindrome();
    Node* pal(Node *ptr, LinkedList l1);

    Node* findmin();
    Node* findmax();

private:
    Node *head;
};



#endif /* LINKEDLIST_H_ */
