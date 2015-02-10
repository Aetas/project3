/*
 * Derek Prince
 * CU CSCI 2270
 * Rhonda Hoeningman
 * Assignment 3
 * Lord of the Rings, Taking the Ring to Boston
 *
*/
#include<iostream>
#include<string>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

class beacon
{
public:
	beacon();						//initial build
	template<typename T>
	beacon(T k);					//builds with key

	string get_key();				//returns key (aka name here)
	string get_message();			//return value
	beacon* get_next();				//return next node
	void set_message(string arg);	//commits values
	void set_key(string arg);		//commits key/name
	void set_next(beacon *nxt);		//commits next in chain

private:
	string key;		//name, really.
	string message;	//value(s)
	beacon* next;	//next in the chain
};

class network /*: public beacon*/
{
public:
	network();					//standard start
	~network();					//destructor
	template<typename T>
	beacon* find_city(T name);	//returns city location by name
	void build_net();			//builds the network. hardcoded initial names
	void print_path();			//prints whole chain with names
	template<typename T>
	T find_key(T k);			//finds a city by name
	void transfer_msg();		//pushes a message through the nodes.
	void add_city();			//inserts city
	void delete_city();			//calls the delete query

private:
	beacon* head;
	beacon* crawler;
};

//MAIN
int main()
{
	network* net = new network;

	unsigned int select = 0;

	while(select != 7)
	{
		//cout list of options.
		cout << "======Main Menu=====" << endl
			<< "1. Build Network" << endl
			<< "2. Print Network Path" << endl
			<< "3. Transmit Message Coast-To-Coast" << endl
			<< "4. Add City" << endl
			<< "5. Delete City" << endl
			<< "6. Clear Network" << endl
			<< "7. Quit" << endl;

	//switch
		cin >> select;
		switch (select)
		{
		case 1:	//build net
			net->build_net();
			break;
		case 2:	//print path
			net->print_path();
			break;
		case 3:	//transmit a message
			net->transfer_msg();
			break;
		case 4:	//add city
			net->add_city();
			break;
		case 5:	//delete city
			net->delete_city();
			break;
		case 6:	//clear net
			delete net;
			cout << "Deleted network" << endl;
			break;
		case 7: //quit
			cout << "Goodbye!" << endl;
			break;
		default:	//no match
			cout << "\n That was not an option.";
		}
	}

	cout << endl
		<< endl;
	return 0;
}
