#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;
class NOTE
{
private:
string name, number;
int birthday[3];
public:
NOTE();
NOTE(string name, string number, int birthday[3]);
NOTE(const NOTE& student);
~NOTE();
void inputFromConsole();
void printToConsole();
void change();
string getName() { return name; }
void setName(string name) { this->name = name; }
string getNumber() { return number; }
void setNumber(string number) { this->number = number; }
int getDay() { return birthday[0]; }
void setBirthday(int birthday[0]) { this->birthday[1] = birthday[0]; }
int getMonth() { return birthday[1]; }
void setBirthday(int birthday[1]) { this->birthday[1] = birthday[1]; }
int getYear() { return birthday[2]; }
void setBirthday(int birthday[2]) { this->birthday[2] = birthday[2]; }
NOTE& operator=(const NOTE& student);
bool operator>(const NOTE& note);
};
