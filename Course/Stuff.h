#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <list>
#include <algorithm>
#include <Windows.h>
using namespace std;

template<int txt, int bg>
ostream& color(ostream &text);

template <typename T>
void enter_number(T & variable,int length);

template <class T>
void read_information_from_file(list<T> &list,string filename);

template <class T>
void write_information_in_file(list<T> &list, string filename);

template <class T>
void show_information(T variable, string filename);

template <class T>
void delete_information(T variable , string filename,string what);

template <class T>
void add_information(T variable, string filename);

template <class T>
bool check_information(T check,string filename);

template <class T>
void edit_information(T variable, string filename, string what);

template <class T>
void sort_information(T variable, string filename, bool(*comparator)(const void *, const void *));

template <class T>
void filtr_information(T variable, string filename, void(*filtrator)(const void *,string,string));

template <class T>
void search_information(T variable, string filename, void(*searcher)(const void*, string));