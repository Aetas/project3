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

//**************
//=BEACON BLOCK=
//**************
beacon::beacon()
{
	next = NULL;
}

template<typename T>
beacon::beacon(T k)
{
	next = NULL;
	key = k;
}

string beacon::get_key()
{
	return key;
}

string beacon::get_message()
{
	return message;
}

beacon* beacon::get_next()
{
	return next;
}

void beacon::set_message(string arg)
{
	message = arg;
}

void beacon::set_key(string arg)
{
	key = arg;
}

void beacon::set_next(beacon *nxt)
{
	next = nxt;
}
//***************
//=END BEACON=
//***************

//***************
//=NETWORK BLOCK=
//***************
network::network()
{
	crawler = NULL;
	head = NULL;
}
network::~network()
{
	crawler = head;
	beacon* hitman;
	while (crawler != NULL)
	{
		hitman = crawler;
		crawler = crawler->get_next();
		delete hitman;
	}
}

void network::build_net()
{
	crawler = new beacon;
	head = crawler;
	crawler->set_key("Los Angeles");

	//repeat this forever, pretty much. Hard-coding initial build.
	beacon* n = new beacon("Phoenix");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Denver");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Dallas");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("St. Louis");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Chicago");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Atlanta");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Washington, D.C.");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("New York");
	crawler->set_next(n);
	crawler = n;
	n = new beacon("Boston");
	crawler->set_next(n);
	crawler = n;

	print_path();
}

void network::print_path()
{
		crawler = head;						//take it from the top
		cout << "===CURRENT PATH===" << endl;
		while (crawler/*->get_next()*/ != NULL)	//while it isnt the end of the list
		{
			cout << crawler->get_key() << " -> " ;
			crawler = crawler->get_next();
		}
		cout << " NULL";
		cout << endl << "=================" << endl;;
}

void network::transfer_msg()
{
	std::ifstream infile;			//set up infile
	infile.open("messageIn.txt");	//open infile
	if (infile.is_open())			//if it is open, proceed. Could use error handling if it doesn't open, but this is hard coded, so it is an environment issue if that is the case
	{
		string buffer;
		while (infile >> buffer && !infile.eof())	//while there are still words to grab (delim by spaces)
		{
			crawler = head;						//set to top of the chain
			while (crawler != NULL)	//while it is not the last one
			{
				crawler->set_message(buffer);	//commit word
				cout << crawler->get_key() << " recieved " << crawler->get_message() << endl ;	//print condition
				crawler = crawler->get_next();	//update condition
			}
		}
	}
}

template<typename T>
beacon* network::find_city(T name)
{
	crawler = head;	//start at head
	while (crawler->get_next() != NULL)	//while it is not the end of the chain
	{
		if (crawler->get_key() == name)	//if it finds a match, return chain
			return crawler;
		crawler = crawler->get_next();	//else move on to the next city
	}
	return NULL;	//same as returning the last crawler iteration, really.
}

void network::add_city()
{
	string ncity, pcity;				//control strings
	cout << "Enter a city name: " << endl;
	cin.ignore(1000, '\n');
	getline(cin, ncity);				//get new city
	cout << endl << "Enter a previous city name: " << endl;
	getline(cin, pcity);				//get previous city

	crawler = find_city(pcity);			//sets crawler to previous
	beacon* temp = new beacon(ncity);	//creates new node with specified name
	temp->set_next(crawler->get_next());//sets it's link to the original next
	crawler->set_next(temp);			//sets the previous node to the new one in the chain
}

void network::delete_city()
{
	cout << "Name of the city:" << endl;
	string dcity;							//to store city name
	cin.ignore(1000, '\n');
	getline(cin, dcity);					//grab name
	beacon* temp;
	temp = find_city(dcity);				//make a temporary that points to the deleted-to-be
	crawler = head;
	while (crawler->get_next() != temp)		//find node right before delete
		crawler = crawler->get_next();		//^^
	crawler->set_next(temp->get_next());	//set the node prior to temp (the to-be-deleted) to point to the node after the one to be deleted
	delete temp;							//delete node
}
//*************
//=END NETWORK=
//*************
