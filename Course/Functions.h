#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <list>
#include "Admin.h"
#include "Transport.h"
#include "Driver.h"
#include "Stuff.cpp"
#include <iomanip>
using namespace std;

class Admin;


//Utilities
Admin authorization(string filename);
string stars();
string encryption(string &str,int key);
bool check_uniq_login(Admin user);


//Add functions
void add_user();


//Edit functions
void edit_user();


//Delete functions
void delete_user();



//Show functions
void show_drivers();
void show_users();
void show_transport();


//Sort functions
void sort_drivers(bool(*)(const void *, const void *));



//Filtr functions



