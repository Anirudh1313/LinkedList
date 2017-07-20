#include <iostream>
#include <iomanip>
#include <vector>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

void rhombus(int size);
void manipulation(LinkedList list);
void list(int input);

int main()
{
	int input;
	cout << "Choose your operation to be done:" << endl;
	cout << "1) Create different shapes using linked list" << endl;
	cout << "2) Create a Linked List with your own inputs" << endl;
	cout << "3) Create a sorted Linked List with your own inputs" << endl;

	list(input);

//    LinkedList a;
//    int N[] = {2,3,4,2,3,4,2,3,4};
//    for(int n : N)
//    {
//    	a.addValue(n);
//    }
//    a.remove_dups();
//    a.add_value_position(1,10);
//    //a.add_value_position(7,23);
//    a.print();
//    if(a.circularList())
//    {
//    	cout << "List is circular" << endl;
//    }
//    else
//    {
//    	cout << "List is Straight" << endl;
//    }
//    int removed_value = a.remove_value_position(8);
//    cout << "The value of the Node you removed is " << removed_value << endl;
//    a.print();
//    int k = 1;
//    int pos = a.value(k);
//    if(pos == 0.001)
//    {
//    	cout << "The number you entered is more than the List Size" << endl;
//    }
//    else
//    {
//    	if(k == 3)
//    	{
//    		cout << k << "rd term value is " << a.value(k) << endl;
//    	}
//    	else if(k == 1)
//    	{
//    		cout << k << "st term value is " << a.value(k) << endl;
//    	}
//    	else if(k == 2)
//    	{
//    		cout << k << "nd term value is " << a.value(k) << endl;
//    	}
//    	else
//    	{
//    		cout << k << "th term value is " << a.value(k) << endl;
//    	}
//    }

//    string x;
//    while(x != ".")
//    {
//    	cout << "\nEnter a value to search: ";
//        cin >> x;
//    	if(x != ".")
//    	{
//            if(isdigit(x[0]))
//            {
//                int a = stoi(x);
//                if(list.search(a))
//                {
//                	int p = list.position(a);
//                	cout << "found the value in " << p;
//
//                	if(p == 3)
//                	{
//                		cout << "'rd Node." << endl;
//                	}
//                	else if(p == 1)
//                	{
//                		cout << "'st Node." << endl;
//                	}
//                	else if(p == 2)
//                	{
//                		cout << "'nd Node." << endl;
//                	}
//                	else
//                	{
//                		cout << "'th Node." << endl;
//                	}
//                }
//                else
//                {
//                	cout << "Value not found" << endl;
//                }
//            }
//            else
//            {
//            	cout << "Enter an integer" << endl;
//            }
//    	}
//    }
//
//    cout << "\ndone!" << endl;


    //list


    /*
    for(int i=0; i < 10; i++)
    {
        for(int j = 9; j >= 0; j--)
        {
        	pint
        	cout << setw(4) << right << list[i].popValue();

        }
        cout << "\n";
    }*/
    //cout << list.popValue() << endl;
    //cout << list.popValue() << endl;
    // because there is no error checking in popValue(), the following
    // is undefined behavior. Probably the program will crash, because
    // there are no more values in the list.
    // cout << list.popValue() << endl;
    return 0;
}

void rhombus(int size)
{
	LinkedList list;
	size /= 2;

	for(int j = 0; j < 4*size; j++)
	{
		list.addValue(j);
	}

	int i = 0, j = 2*size, k = 2*size;

    while(i < size)
    {
        list.find(j, k);
        j -= 1;
	    k += 1;
    	i++;
    }
	//    j--;
	//    k++;
	    //i = size-2;
    while(i >= 0)
    {
    	list.find(j, k);
	    j += 1;
	    k -= 1;
	   	i--;
    }
}

void list(int input)
{
//	int input;
//	cout << "Choose your operation to be done:" << endl;
//	cout << "1) Create different shapes using linked list" << endl;
//	cout << "2) Create a Linked List with your own inputs" << endl;
//	cout << "3) Create a sorted Linked List with your own inputs" << endl;
//	cout << "4) " << endl;
//	cout << "5) " << endl;
	cout << "\nYour operation: ";
	cin >> input;
	cout << endl << endl;

	if(input == 1)
	{
		int inp1;
		cout << "Choose your Shape:" << endl;
		cout << "1) Rhombus" << endl;
		cout << "shape: ";
		cin >> inp1;
		cout << endl << endl;
		if(inp1 == 1)
		{
			int inp2;
			cout << "enter the base diagonal size of your Rhombus: " << endl;
			cin >> inp2;
			if(inp2 % 2 == 0)
				rhombus(inp2);
			else
			{
				cout << "Printing is not possible with odd diagonal length" << endl;
			}
//			do
//			{
//				cout << "enter the base diagonal size of your Rhombus: " << endl;
//				cin >> inp2;
//				if(inp2 % 2 == 0)
//					rhombus(inp2);
//				else
//				{
//					cout << "Printing is not possible with odd diagonal length" << endl;
//				}
//			} while(inp2 % 2 != 0);

			while(inp2 % 2 != 0)
			{
				cout << "enter a new even base diagonal size of your Rhombus: " << endl;
				cin >> inp2;
				if(inp2 % 2 == 0)
					rhombus(inp2);
				else
				{
					cout << "Printing is not possible with odd diagonal length" << endl;
				}
			}
		}

	}

	else if (input == 2)
	{
		vector<double> vec;
		string val;
		double v;
		LinkedList list;
		cout << "Enter your inputs with 'enter' after each value and end it with a '.'" << endl;
		do
		{
			cin >> val;
			if(isdigit(val[0]) || (val[0] == '-' && isdigit(val[1])))
			{
				v = stod(val);
				vec.push_back(v);
			}
			else if(val[0] != '.' && !(isdigit(val[0])))
			{
				cout << "Enter a valid rational number" << endl;
			}

		} while(val[0] != '.');

		cout << "Vector:";
		for(int i = 0; i < vec.size(); i++)
		{
			cout << " " << vec[i];
			if(i != vec.size()-1)
				cout << ",";
			else
				cout << ".";
		}
		cout << endl;
		list.clear();
		cout << "List:   ";
		for(int i = 0; i < vec.size(); i++)
		{
			list.addValue(vec[i]);
			//cout << vec[i] << " ";

		}
		list.print();
		bool b;
		cout << "\nWant to make any changes to the list? if 'Yes' press '1' if 'No' press '0' ";
		cin >> b;
		if(b)
			manipulation(list);
		else
			cout << "\nYour list has been created!" << endl;
	}

	else if (input == 3)
	{
		vector<double> vec;
		string val;
		double v;
		LinkedList list;
		cout << "Enter your inputs with 'enter' after each value and end it with a '.' : " << endl;
		do
		{
			cin >> val;
			if(isdigit(val[0]) || (val[0] == '-' && isdigit(val[1])))
			{
				v = stod(val);
				vec.push_back(v);
			}
			else if(val[0] != '.' && !(isdigit(val[0])))
			{
				cout << "Enter a valid rational number" << endl;
			}

		} while(val[0] != '.');
		cout << "Vector:";
		for(int i = 0; i < vec.size(); i++)
		{
			cout << " " << vec[i];
			if(i != vec.size()-1)
				cout << ",";
			else
				cout << ".";

		}
		cout << endl;
		list.clear();
		cout << "List:   ";
		for(int i = 0; i < vec.size(); i++)
		{
			list.addValue_1(vec[i]);
			//cout << vec[i] << " ";

		}
		list.print();
		bool b;
		cout << "\nWant to make any changes to the list? if 'Yes' press '1' if 'No' press '0' : ";
		cin >> b;
		if(b)
			manipulation(list);
		else
			cout << "\nYour list has been created!" << endl;
	}
	else
	{
		cout << "Enter a valid integer:" << endl;
		int int2;
		list(int2);
	}
}

void manipulation(LinkedList list)
{
	char x1;
	cout << "\nChoose an operation:" << endl;
	cout << "1) add value at k'th position." << endl;
	cout << "2) remove duplicates." << endl;
	cout << "3) check for a loop in the list" << endl;
	cout << "4) remove node from k'th position" << endl;
	cout << "5) search for a value by position" << endl;
	cout << "6) search for a position by value" << endl;
	cout << "7) search for a value at k'th position from reverse" << endl;
	cout << "8) find the minimum value in the list" << endl;
	cout << "9) find the maximum value in the list" << endl;
	cout << "0) print" << endl;
	cout << "a) remove middle node in the list and print the whole list after removal" << endl;
	cout << "b) attach all values in the list to string in reverse order and print" << endl;
	while(x1 != '.')
	{
		cout << "\nChoose operation? : ";
		cin >> x1;

		if(x1 != '.')
		{
			if(isdigit(x1))
			{
				int x = x1 - '0';
				if(x == 1)
				{
					double val;
					int k;
					cout << "Enter the Value you want to insert: ";
					cin >> val;
					cout << "Enter the index at which insertion has to be done: ";
					cin >> k;
					list.add_value_position(k, val);
					cout << "Value inserted!" << endl;
				}
				else if(x == 2)
				{
					list.remove_dups();
					cout << "Duplicates removed!" << endl;
				}
				else if(x == 3)
				{
				    if(list.circularList())
				    {
				    	cout << "List is circular" << endl;
				    }
				    else
				    {
				    	cout << "List is Straight" << endl;
				    }
				}
				else if(x == 4)
				{
					int k;
					cout << "enter position to remove the Node form that position: ";
					cin >> k;
				    int removed_value = list.remove_value_position(k);
				    cout << "The value of the Node you removed is " << removed_value << endl;
				}
				else if(x == 5)
				{
					int k;
					cout << "enter position to search the Node at that position: ";
					cin >> k;
					double val = list.value(k);
				    if(val == 0.001)
				    {
				    	cout << "The number you entered is more than the List Size" << endl;
				    }
				    else
				    {
				    	if(k == 3)
				    	{
				    		cout << k << "rd term value is " << list.value(k) << endl;
				    	}
				    	else if(k == 1)
				    	{
				    		cout << k << "st term value is " << list.value(k) << endl;
				    	}
				    	else if(k == 2)
				    	{
				    		cout << k << "nd term value is " << list.value(k) << endl;
				    	}
				    	else
				    	{
				    		cout << k << "th term value is " << list.value(k) << endl;
				    	}
				    }
				}
				else if(x == 6)
				{
//					double val;
//					cout << "Enter a value to search its position: ";
//					cin >> val;
//					int k = list.position(val);
//					cout << "The position of the Node containing " << val << " is " << k << endl;
				    string x;

				    while(x != ".")
				    {
				    	cout << "\nEnter a value to search its position and enter '.' to end the search: ";
				        cin >> x;
				    	if(x != ".")
				    	{
				            if(isdigit(x[0]))
				            {
				                double a = stod(x);
				                if(list.search(a))
				                {
				                	int p = list.position(a);
				                	cout << "found the value in " << p;

				                	if(p == 3)
				                	{
				                		cout << "'rd Node." << endl;
				                	}
				                	else if(p == 1)
				                	{
				                		cout << "'st Node." << endl;
				                	}
				                	else if(p == 2)
				                	{
				                		cout << "'nd Node." << endl;
				                	}
				                	else
				                	{
				                		cout << "'th Node." << endl;
				                	}
				                }
				                else
				                {
				                	cout << "Value not found" << endl;
				                }
				            }
				            else
				            {
				            	cout << "Enter an integer" << endl;
				            }
				    	}
				    }
				}
				else if(x == 7)
				{
//					int k;
//					cout << "enter position to get the value of the Node at the reverse position: ";
//					cin >> k;
//					double val = list.reverse_value(k);
//					cout << "The value of the Node at k'th position from reverse is " << val << endl;
					int k;
					cout << "enter position to search the Node at that position: ";
					cin >> k;
					double val = list.reverse_value(k);
				    if(val == 0.001)
				    {
				    	cout << "The number you entered is more than the List Size" << endl;
				    }
				    else
				    {
//				    	if(k == 3)
//				    	{
//				    		cout << k << "rd term value is " << list.value(k) << endl;
//				    	}
//				    	else if(k == 1)
//				    	{
//				    		cout << k << "st term value is " << list.value(k) << endl;
//				    	}
//				    	else if(k == 2)
//				    	{
//				    		cout << k << "nd term value is " << list.value(k) << endl;
//				    	}
//				    	else
//				    	{
//				    		cout << k << "th term value is " << list.value(k) << endl;
//				    	}
				    	cout << "Value is " << val << endl;
				    }
				}
				else if(x == 8)
				{
					Node *p = list.findmin();
					cout << "The minimum value in the list is ' " << p->get_x() << " '. " << endl;
				}
				else if(x == 9)
				{
					Node *p = list.findmax();
					cout << "The maximum value in the list is ' " << p->get_x() << " '. " << endl;
				}
				else if(x == 0)
				{
					cout << "list: ";
					list.print();
				}
			}
			else if(x1 == 'a')
			{
				if(list.remove_middle())
					list.print();
			}
			else if (x1 == 'b')
			{
				string k = "";
				string f = list.reverseAttachAll();
				cout << "output: " << f << endl;
			}
//			else if (x1 == 'c')
//			{
//				//LinkedList l1;
//			    if(list.palindrome())
//			    	cout << "Yes!" << endl;
//			    else
//			    	cout << "No!" << endl;
//			}
			else
			{
				cout << "Enter a valid input!" << endl;
			}
		}
	}
	cout << "\nDone!" << endl;
}
