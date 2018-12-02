#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
//#include <vector>
#include "Admin.h"
#include "Stuff.cpp"
using namespace std;

class Admin;
Admin authorization(string filename);
string stars();
string encryption(string &str,int key);
void add_user();