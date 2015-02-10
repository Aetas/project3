#include "Network.h"
#include<iostream>
#include<string>
#include<fstream>

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

std::string beacon::get_key()
{
	return key;
}

std::string beacon::get_message()
{
	return message;
}

beacon* beacon::get_next()
{
	return next;
}

void beacon::set_message(std::string arg)
{
	message = arg;
}

void beacon::set_key(std::string arg)
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
	std::cout << "===CURRENT PATH===" << std::endl;
	std::cout << crawler->get_key();			//just to keep the arrows out of the end of the print
	crawler = crawler->get_next();		//
	while (crawler->get_next() != NULL)	//while it isnt the end of the list
	{
		std::cout << " -> " << crawler->get_key();
		crawler = crawler->get_next();
	}
	std::cout << std::endl << "==================" << std::endl;
}

void network::transfer_msg()
{
	std::ifstream infile;			//set up infile
	infile.open("messageIn.txt");	//open infile
	if (infile.is_open())			//if it is open, proceed. Could use error handling if it doesn't open, but this is hard coded, so it is an environment issue if that is the case
	{
		std::string buffer;
		while (getline(infile, buffer, ' '))	//while there are still words to grab (delim by spaces)
		{
			crawler = head;						//set to top of the chain
			while (crawler->get_next() != NULL)	//while it is not the last one
			{
				crawler->set_message(buffer);	//commit word
				std::cout << crawler->get_key() << " recieved " << crawler->get_message() << std::endl;	//print condition
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
	std::string ncity, pcity;				//control strings
	std::cout << "Enter a city name:" << std::endl;
	std::cin.ignore(1000, '\n');
	getline(std::cin, ncity);				//get new city
	std::cout << std::endl << "Enter a previous city name:" << std::endl;
	getline(std::cin, pcity);				//get previous city

	crawler = find_city(pcity);			//sets crawler to previous
	beacon* temp = new beacon(ncity);	//creates new node with specified name
	temp->set_next(crawler->get_next());//sets it's link to the original next
	crawler->set_next(temp);			//sets the previous node to the new one in the chain
}

void network::delete_city()
{
	std::cout << "Name of the city:" << std::endl;
	std::string dcity;							//to store city name
	std::cin.ignore(1000, '\n');
	getline(std::cin, dcity);					//grab name
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