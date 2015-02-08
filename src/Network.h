#ifndef NETWORK_H
#define NETWORK_H
#include<string>

class beacon
{
public:
	beacon();						//initial build
	template<typename T>
	beacon(T k);					//builds with key

	std::string get_key();				//returns key (aka name here)
	std::string get_message();			//return value
	beacon* get_next();					//return next node
	void set_message(std::string arg);	//commits values
	void set_key(std::string arg);		//commits key/name
	void set_next(beacon *nxt);			//commits next in chain

private:
	std::string key;		//name, really.
	std::string message;	//value(s)
	beacon* next;			//next in the chain
};

class network
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

#endif	//NETWORK_H