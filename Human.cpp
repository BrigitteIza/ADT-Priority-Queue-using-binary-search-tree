#include "Human.h"

using namespace std;

Human::Human()
{
	this->priority = -1;
	this->info = "";
}

Human::Human(int priority, const std::string & info)
{
	this->priority = priority;
	this->info = info;
}

Human& Human::operator=(const Human& h)
{
	priority = h.priority;
	info = h.info;

	return *this;
}

bool Human::operator==(Human temp)
{
	return (this->info == temp.getInfo()) && (this->priority == temp.getPriority());
}

Human::~Human()
{
}

void Human::setPriority(int temp)
{
	this->priority = temp;
}

void Human::setInfo(std::string temp)
{
	this->info = temp; 
}

bool Human::operator<(Human temp)
{
	return (this->priority <= temp.getPriority());
}

ostream & operator<<(ostream & os, const Human & h)
{
	os << h.priority << " - " << h.info << "\n";
	return os;
}

std::vector<std::string> split(std::string data, char delimiter)
{
	std::vector<std::string> splitString;
	std::stringstream strStream(data);
	std::string token;

	while (getline(strStream, token, delimiter))
		splitString.push_back(token);
	return splitString;
}

std::istream & operator>>(std::istream & input, Human& h)
{
	std::string data;

	getline(input, data);

	std::vector<std::string> dataSplit = split(data, '-');

	if (dataSplit.size() == 2) {
		h.priority = stoi(dataSplit[0]);
		h.info = dataSplit[1];
	}

	return input;

}