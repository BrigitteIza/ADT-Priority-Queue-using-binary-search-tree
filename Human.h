#pragma once
#include <string>
#include <vector>
#include <sstream>

class Human
{
private:
	int priority;
	std::string info; // info is the name of the human, since we can deduce his "status" (politician, priest, doctor, commoner, scientist) from the priority level

public:
	
	Human();
	Human(int priority, const std::string& info);
	Human& operator=(const Human& h);
	bool operator==(Human temp);
	~Human();
	int getPriority() const { return priority; }
	void setPriority(int temp);
	void setInfo(std::string temp);
	std::string getInfo() const { return info; }
	bool operator<(Human temp);

	friend std::ostream& operator<<(std::ostream& os, const Human& h);
	friend std::istream & operator>>(std::istream & input, Human& h);
};