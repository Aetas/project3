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
#include "Network.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

//MAIN
int main()
{
	network* net = new network;

	unsigned int select = 0;
	//cout list of options.
	cout << "======Main Menu======" << endl
		<< "1. Build Network" << endl
		<< "2. Print Network Path" << endl
		<< "3. Transmit Message Coast-To-Coast" << endl
		<< "4. Add City" << endl
		<< "5. Delete City" << endl
		<< "6. Clear Network" << endl
		<< "7. Quit" << endl;

	while(select != 7)
	{
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
			break;
		case 7: //quit
			break;
		default:	//no match
			cout << "\n That was not an option.";
		}
	}

	cout << endl
		<< endl;
	return 0;
}

