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
void enter_bool(bool &var);

//Show functions
void show_users();
void rent_bus();
void rent_driver();