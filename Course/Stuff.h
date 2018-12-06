#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <list>
#include <Windows.h>
using namespace std;

template<int txt = 7, int bg = 0>
ostream& color(ostream &text);

template <typename T>
void enter_number(T & variable,int length);

template <class T>
void read_information_from_file(list<T> &list,string filename);

template <class T>
void write_information_in_file(list<T> &list, string filename);

template <class T>
void show_information(list<T> &list);