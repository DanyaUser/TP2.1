#include "NOTE.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
void printMenu();
void addObject(Marray<NOTE>& note);
void changeObject(Marray<NOTE>& note);
void deleteObject(Marray<NOTE>& note);
void print(Marray<NOTE>& note);
void searchMonth(Marray<NOTE>& note);
void searchName(Marray<NOTE>& note);
int main() {
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
Marray<NOTE> note;
bool isExit = false;
while (!isExit) {
printMenu();
int method = safeInput(1, 7);
switch (method)
{
case 1:
addObject(note);
break;
case 2:
changeObject(note);
break;
case 3:
deleteObject(note);
break;
case 4:
print(note);
break;
case 5:
searchName(note);
break;
case 6:
searchMonth(note);
break;
case 7:
isExit = true;
break;
}
}
}
void printMenu() {
cout << "Instruction" << endl;
cout << "-----------------" << endl;
cout << "1 - Add object" << endl;
cout << "2 - Change object" << endl;
cout << "3 - Delete object" << endl;
cout << "4 - Display data on screen" << endl;
cout << "5 - Information on the given name " << endl;
cout << "6 - Information on the given month " << endl;
cout << "7 - Exit" << endl;
cout << "-----------------" << endl;
cout << "Select a menu item: ";
}
void addObject(Marray<NOTE>& note) {
NOTE person;
person.inputFromConsole();
note += person;
note.sort();
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
void changeObject(Marray<NOTE>& note) {
if (note.getSize() > 0) {
print(note);
cout << "Enter the number to change: ";
note[safeInput(1, note.getSize()) - 1].change();
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
cout << "The list is empty. Nothing to change" << endl;
cout << "-----------------" << endl;
}
note.sort();
}
void deleteObject(Marray<NOTE>& note) {
if (note.getSize() > 0) {
print(note);
cout << "Enter the number to delete: ";
note -= safeInput(1, note.getSize()) - 1;
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
else {
system("cls");
cout << "The list is empty. Nothing to change" << endl;
cout << "-----------------" << endl;
}
note.sort();
}
void print(Marray<NOTE>& note) {
if (note.getSize() == 0)
{
system("cls");
cout << "The list is empty" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
cout << "Phone book list" << endl;
for (int i = 0; i < note.getSize(); i++) {
cout << i + 1 << ":" << endl;
note[i].printToConsole();
}
cout << "-----------------" << endl;
}
}
void searchName(Marray<NOTE>& note) {
if (note.getSize() == 0)
{
system("cls");
cout << "The list is empty" << endl;
cout << "-----------------" << endl;
}
else
{
bool isPrint = false;
cout << "Enter the name of the person you want to find: ";
string name;
getline(cin, name);
for (int i = 0; i < note.getSize(); i++)
if (note[i].getName() == name) {
isPrint = true;
system("cls");
note[i].printToConsole();
cout << "-----------------" << endl;
}
if (!isPrint)
{
system("cls");
cout << "No person with this name was found" << endl;
cout << "-----------------" << endl;
}
}
}
void searchMonth(Marray<NOTE>& note) {
if (note.getSize() == 0)
{
system("cls");
cout << "The list is empty" << endl;
cout << "-----------------" << endl;
}
else
{
bool isPrint = false;
cout << "Enter the name of the month you want to find: ";
int month;
month = safeInput(1, INT32_MAX);
system("cls");
for (int i = 0; i < note.getSize(); i++)
if (note[i].getMonth() == month)
{
isPrint = true;
note[i].printToConsole();
cout << "-----------------" << endl;
}
if (!isPrint)
{
cout << "No person with this name was found" << endl;
cout << "-----------------" << endl;
}
}
}
