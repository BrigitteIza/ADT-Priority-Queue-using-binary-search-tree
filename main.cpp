#include <fstream>
#include "PQBST.h"
#include <iostream>
#include "Human.h"
#include <Windows.h>
#include "Tests.h"

using namespace std;
/*
void displayRescued(PQBST temp, int m)
{
	Human h;
	while ((m > 0) && (!temp.isEmpty()))
	{
		try
		{
			h = temp.pop();
		}
		catch (std::string message)
		{
			cout << "There are no people to be saved! \n";
		}
		cout << h;
		m -= 1;
	}
}

PQBST createPQBSTwithHumans()
{
	PQBST pqbst{};
	Human h;
	fstream f("data.txt", ios::in);
	while (!f.eof())
	{
		f >> h;
		pqbst.push(h);
	}
	
	return pqbst;
}
*/

int main()
{ 
	Tests::testPQBST();
	
	PQBST pqbst;
	Human h;
	int m;
	cout << "Give the size of the spaceship: ";
	cin >> m;
	pqbst.setM(m);
	fstream f("data.txt", ios::in);
	while (!f.eof())
	{
		f >> h;
		pqbst.push(h);
	}
	
	while ((m > 0) && (!pqbst.isEmpty()))
	{
		try
		{
			h = pqbst.pop();
		}
		catch (std::string message)
		{
			cout << "There are no people to be saved! \n";
		}
		cout << h;
		m -= 1;
	}
	
	system("pause");
	
	return 0;
}