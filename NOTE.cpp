#include "NOTE.h"
NOTE::NOTE() : name("Not set"), number("Not set"), birthday(0)
{
cout << "The constructor of NOTE is called" << endl;
}
NOTE::NOTE(string name, string number, int birthday[3]) : name(name), number(number),birthday(birthday)
{
cout << "The constructor of NOTE is called" << endl;
}
NOTE::NOTE(const NOTE& note) : name(note.name), number(note.number), birthday(note.birthday)
{
cout << "The copy constructor of NOTE is called" << endl;
}
NOTE::~NOTE()
{
cout << "The destructor of NOTE is called" << endl;
}
void NOTE::inputFromConsole()
{
cout << "Enter the user's first and last name: ";
getline(cin, name);
cout << "Enter the user's phone number: ";
getline(cin, number);
cout << "Enter the user's date of birth: ";
birthday[0] = safeInput(1, INT32_MAX);
birthday[1] = safeInput(1, INT32_MAX);
birthday[2] = safeInput(1, INT32_MAX);
}
void NOTE::printToConsole()
{
cout << "First and last name: " << name << endl;
cout << "Phone number: " << number << endl;
cout << "Date of birth: " << birthday << endl;
}
void NOTE::change()
{
cout << "Enter the new user's first and last name: ";
getline(cin, name);
cout << "Enter the new user's phone number: ";
getline(cin, number);
cout << "Enter the new user's date of birth: ";
birthday[0] = safeInput(1, INT32_MAX);
birthday[1] = safeInput(1, INT32_MAX);
birthday[2] = safeInput(1, INT32_MAX);
}
NOTE& NOTE::operator=(const NOTE& note)
{
if (this == &note)
return *this;
name = note.name;
number = note.number;
birthday[0] = note.birthday[0];
birthday[1] = note.birthday[1];
birthday[2] = note.birthday[2];
return *this;
}
bool NOTE::operator>(const NOTE& note)
{
return name > note.name;
}
