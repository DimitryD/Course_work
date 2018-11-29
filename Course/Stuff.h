#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

template<int txt = 7, int bg = 0>
ostream& color(ostream &text);

template <typename T>
void GetNumber(T & variable);