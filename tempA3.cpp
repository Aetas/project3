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


class beacon : network
{
public:
	beacon();
	beacon(beacon* next);

	string get_key();
	string get_message();
	void commit_message();	
private:
	string key;		//name, really.
	string message;
	class* next;
}

class network
{
private:
	//some number or stats, probably.
public:
	network();
	network(beacon* head);
	void build_net();	//pass head? 
		
}

//still needs a while(!~~~) or do{}... while(); loop until exit. control on switch, 
//
int main()
{
	beacon* head;
	beacon* crawler = new beacon;
	head = crawler;

	int direction;
	
	while(switch != 5)
	{
	//switch
	}
	cout << endl
		<< endl;
	return 0;
}

