// hw5.cpp : 
/*
Leonard Blam 900086
HW 5 DS2
Graphs*/
#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	try {
		string v1, v2, name;
		Graph g;
		int choice;
		cout << "choose one of the following:\n";
		cout << "1 - add a writer\n";
		cout << "2 - delete a writer\n";
		cout << "3 - add a follow up\n";
		cout << "4 - delete a follow up\n";
		cout << "5 - print all followed\n";
		cout << "6 - print all followers\n";
		cout << "7 - print suggested followed (distance 2)\n";
		cout << "8 - print all the graph\n";
		cout << "10 - exit";
		cout << endl;

		do
		{
			cin >> choice;
			switch (choice)
			{
			case 1:cout << "enter the writer name\n";
				cin >> v1;
				g.addvertex(v1);
				break;
			case 2:cout << "enter the writer name\n";
				cin >> v1;
				if (g.delvertex(v1))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 3:cout << "enter the follower and the writer\n";
				cin >> v1 >> v2;
				if (g.addedge(v1, v2))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 4:cout << "enter the follower and the writer\n";
				cin >> v1 >> v2;
				if (g.deledge(v1, v2))
					cout << "success";
				else
					cout << "ERROR";
				break;
			case 5:cout << "enter the v you want to print its neighbours\n";
				cin >> v1;
				g.printNeighbors(v1);
				break;
			case 6:cout << "enter the v you want to its followers\n";
				cin >> v1;
				g.printFollowers(v1);
				break;
			case 7:
				cout << "enter writer\n";
				cin >> v1;
				g.printDistance2NotFollowedYet(v1);
				break;

			case 8:
				cout << "The graph:\n";
				g.printAll();
				break;

			case 10:cout << "byebye";  break;
			default:cout << "ERROR";

			}
			cout << endl;
		} while (choice != 10);
	}
	catch (string s)
	{
		cout << s << endl;
	}
	return 0;
}