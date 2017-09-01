#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct Node
{
    T x;
    Node<T> *next;
};

template <typename T>
class LinkedList
{

public:
    void addValue(T val);
    T popValue(/*int val, string nam*/);


private:
    Node<T> *head;
};

template <typename T>
void LinkedList<T>::addValue(T val)
{
    Node<T> *n = new Node<T>();
    n->x = val;
    n->next = head;         // make the node point to the next node.
                            //  If the list is empty, this is NULL, so the end of the list --> OK
    head = n;               // last but not least, make the head point at the new node.
}

template <typename T>
T LinkedList<T>::popValue()
{
	T val;
    Node<T> *n = head;
    val = n->x;
	delete n;
	head = head->next;
    return val;
}



int main()
{
    LinkedList<int> list[10];
    LinkedList<double> list_1[10];
    double k = 1.34;
    for(int i=0; i < 10; i++)
    {

        for(int j = 0; j < 10; j++)
        {
        	//cout << "Enter your value: ";
        	//cin >> v;
        	list[i].addValue(j);
        	list_1[i].addValue(k);
        	k += 1.00;
        }
    }

    for(int i=0; i < 10; i++)
    {
        for(int j = 9; j >= 0; j--)
        {

        	cout << setw(2) << right << list[i].popValue();

        }
        cout << "    ";
        for(int j = 9; j >= 0; j--)
        {

        	cout << setw(7) << right << list_1[i].popValue();

        }
        cout << "\n";
    }
//    cout << "\n****\n";
//    for(int i=0; i < 10; i++)
//    {
//        for(int j = 9; j >= 0; j--)
//        {
//
//        	cout << setw(7) << right << list_1[i].popValue();
//
//        }
//        cout << "\n";
//    }
    return 0;
}
