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

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Still needs to set names. Hardcoding is probably simplest and fastest. ugly though.
 *
*/

class beacon
{
public:
	beacon();						//initial build
	beacon(string key);				//builds with key

	string get_key();				//returns key (aka name here)
	string get_message();			//return value
	beacon* get_next();				//return next node
	void set_message(string &arg);	//commits values
	void set_key(string &arg);		//commits key/name
	void set_next(beacon &nxt);		//commits next in chain
private:
	string key;		//name, really.
	string message;	//value(s)
	beacon* next;	//next in the chain
}

class network /*: beacon*/
{
private:
	beacon* head;
	beacon* crawler;
public:
	network();
	template<typename T>
	network(T length);			//builds the network without being asked.
	template<typename T>
	void build_net(T length);
	template<typename T>
	T find_message(T msg);		//iterates through and returns the match	
}

//
int main()
{
	network* net = new network;

	unsigned int select = 0;
	while(select != 5)
	{
	//switch
	}

	cout << endl
		<< endl;
	return 0;
}

network::network()
{
	crawler = NULL;
	head = NULL;

}

template<typename T>
void network::build_net(T length)
{
	unsigned int i = 0;
	crawler = new beacon;	//creates head
	head = crawler;			//assigns head to top.

	while(i < length)		//creates chain to specified length
	{
		beacon n = new beacon();
		crawler.set_next(n);
		crawler = n;
		i++;
	}
}

beacon::beacon()
{
	next = NULL;	 
}




