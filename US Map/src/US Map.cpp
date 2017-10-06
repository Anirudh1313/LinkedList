#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;



const double MAX_LATITUDE  =   49.373112;
const double MIN_LONGITUDE = -124.769867;


struct City
{
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    double x;      // latitude
    double y;      // longitude
    City *next;
};

class LinkedList_city
{

public:
    void addValue_c(string city, string st, int val_1, int val_2);
    friend istream& operator >>(istream& ins, LinkedList_city& list);
    void print();
    void read();

private:
    City *top;
};

void LinkedList_city::read()
{
	City *p = top;
	int f;
	int k = 0;
	if(p != nullptr)
	{
		cout << p->x << "," << p->y << " ";
		f = round(p->x);
		p = p->next;
		k++;
		while(p != nullptr)
		{
			int x = round(p->x);
			int len = p->name.size();
			if(p->name != "000")
			{
				if((x) == f)
				{
					cout << p->x << "," << p->y << "," << p->name << "," << p->state << " ";
					k++;
				}
				else
				{
					cout << "\n";
					cout << p->x << "," << p->y << "," << p->name << "," << p->state << " ";
					k++;

			    }
			}
			else
			{
					if((x) == f)
					{
						cout << p->x << "," << p->y << " ";
					}
					else
					{
						cout << "\n";
						cout << p->x << "," << p->y << " ";
					}
					//f = (x);
					//p = p->next;

			}
			f = (x);
			p = p->next;
		}
	}
}

istream& operator >>(istream& ins, LinkedList_city& list)
{
	double c1, c2;
	string str;
	string city, state;
	char ch;
	ch = ins.peek();
	if(isdigit(ch))
	{
	    getline(ins, str, ',');
	    c1 = stod(str);
	    getline(ins, str);
	    c2 = stod(str);
	    state = "000";
	    city = "000";
		int i_1 = round(2*(MAX_LATITUDE - c1));
		int i_2 = round(2*(c2 - (MIN_LONGITUDE)));
		list.addValue_c(city, state, i_1, i_2);
	}
	else
	{
		getline(ins, city, ',');
		getline(ins, state, ',');
	    getline(ins, str, ',');
	    c1 = stod(str);
	    getline(ins, str);
	    c2 = stod(str);
		int i_1 = round(2*(MAX_LATITUDE - c1));
		int i_2 = round(2*(c2 - (MIN_LONGITUDE)));
	    list.addValue_c(city, state, i_1, i_2);
	}
	return ins;
}


void LinkedList_city::addValue_c(string city, string st, int val_1, int val_2)
{
    City *n = new City();
    n->name = city;
    n->state = st;
    n->x = val_1;
    n->y = val_2;
    if(top == nullptr)
    	top = n;         // make the node point to the next node.
    else if((val_1 < round(top->x)) || ((val_1 == round(top->x)) && (val_2 < top->y)))
    {
    	n->next = top;
    	top = n;
    }
    else if(val_1 >= round(top->x))
    {
    	City *prev = 0;
    	City *p = top;
    	while ((p != nullptr) && ((val_1) >= round(p->x)))
    	{
			if((val_1) == round(p->x))
			{
				if(val_2 < round(p->y))
				{
					break;
				}
				else if(val_2 >= round(p->y))
				{
		        	prev = p;
		            p = p->next;
				}
			}
			else if((val_1) > round(p->x))
			{
	       	    prev = p;
	       	    p = p->next;
			}
    	}
    	prev->next = n;
    	n->next = p;

    }
}



void LinkedList_city::print()
{
	int k = 0;
	City *p = top;
	//int prev = 0;
	//int prev_1 = 0;
	int prev_name = 0, prev_state = 0;
	int l = 0;
	int i_1 = p->x;
	int i_2 = p->y;

	int prev_i_1 = 0;
	int prev_i_2 = 0;


	for(l = i_2; l > prev_i_2; l--)
	{
		cout << " ";
	}
	if(l == prev_i_2)
	{
		//cout << p->x << " ";
		cout << "#";
		//cout << p->y;
		k++;
	}
	prev_i_2 = i_2;
	p = p->next;
	i_1 = p->x;
	i_2 = p->y;

	for(l = i_2-1; l > prev_i_2; l--)
	{
		cout << " ";
	}
	if(l == prev_i_2)
	{
		cout << "#";
		k++;
	}
	p = p->next;

	while(p != nullptr)
	{
		int check = 0;
		int no_print = 0;
		i_1 = p->x;
		i_2 = p->y;
		int nop = 0;

		if(p->name == "000")
		{
			for(int i = i_1; i > prev_i_1; i--)
			{
				cout << "\n";
				prev_i_2 = 0;
				prev_state = 0;
				prev_name = 0;
				check = 1;

			}
			if(check == 1)
			{
				for(l = prev_i_2+prev_name+prev_state; l < i_2; l++)
				{
					cout << " ";
				}
				if(l == i_2)
				{
					cout << "#";
					k++;
					nop = 1;
				}
			}
			else
			{

				for(l = prev_i_2+1+prev_name+prev_state; l < i_2; l++)
				{
					cout << " ";
				}
				if(l == i_2)
				{
					cout << "#";
					k++;
					nop = 1;
				}
			}
			if(nop == 1)
			{
				prev_name = 0;
				prev_state = 0;
				prev_i_1 = i_1;
				prev_i_2 = i_2;
			}
		}
		else
		{
			for(int i = i_1; i > prev_i_1; i--)
			{
				cout << "\n";
				prev_i_2 = 0;
				prev_name = 0;
				prev_state = 0;
				check = 1;

			}
			if(check == 1)
			{
				for(l = prev_i_2+prev_name+prev_state; l < i_2; l++)
				{
					cout << " ";
				}
				if(l == i_2)
				{
					cout << "*" << p->name << " " << p->state;
					k++;
					no_print = 1;
				}
			}
			else
			{
				for(l = prev_i_2+1+prev_name+prev_state; l < i_2; l++)
				{
					cout << " ";
				}
				if(l == i_2)
				{
					cout << "*" << p->name << " " << p->state;
					k++;
					no_print = 1;
				}
			}
			if(no_print == 1)
			{
				prev_name = p->name.size();
				prev_state = p->state.size()+1;
				prev_i_1 = i_1;
				prev_i_2 = i_2;
			}
		}

		p = p->next;
	}
}

/**
 * The main. Read the boundary data and city data files.
 * Print a map of the U.S. boundary. Print a map of the U.S. with cities.
 */

void do_boundary(ifstream& input, LinkedList_city& list);
void do_cities(ifstream& input, LinkedList_city& list);


const string CITY_FILE_NAME     = "city-data.csv";
const string BOUNDARY_FILE_NAME = "boundary-data.csv";

int main()
{
    ifstream input;         // input stream
    // sorted linked list of Node objects
    LinkedList_city list;
    // Open the boundary data file.
    input.open(BOUNDARY_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << BOUNDARY_FILE_NAME << endl;
        return -1;
    }

    do_boundary(input, list);

    input.close();

    cout << endl;

    input.open(CITY_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << CITY_FILE_NAME << endl;
        return -1;
    }


    // Process the U.S. cities.;
    do_cities(input, list);
    input.close();
     //Open the city data file.

    cout << endl << "Done!" << endl;
    return 0;
}

/**
 * Read and process the boundary data, then print the boundary map.
 */
void do_boundary(ifstream& input, LinkedList_city& list)
{

    // Loop to input each boundary coordinate
    // and insert it into the sorted linked list.
    while (!input.eof())
    {
        input >> list;

    }

    cout << "=============" << endl;
    cout << "U.S. boundary" << endl;
    cout << "=============" << endl << endl;
    list.print();


    // Print the boundary map.
}

void do_cities(ifstream& input, LinkedList_city& list)
{

    // Loop to input each city and insert it into the sorted linked list.
    // The city nodes will be merged with the boundary coordinate nodes.
    while (!input.eof())
    {
        input >> list;
    }
    list.read();
    // Print the city map.
    cout << "===========" << endl;
    cout << "U.S. Cities" << endl;
    cout << "===========" << endl << endl;

    list.print();
}
