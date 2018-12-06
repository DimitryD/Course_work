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
class Driver;

//Utilities
Admin authorization(string filename);
string stars();
string encryption(string &str,int key);


//Show functions
void show_users();


//Filtr functions



