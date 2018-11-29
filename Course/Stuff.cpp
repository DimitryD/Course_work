#include "Stuff.h"
#include <Windows.h>

template<int txt = 7, int bg = 0>
ostream& color(ostream &text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

template <typename T>
void GetNumber(T & variable)
{
	if (strcmp(typeid(variable).name(), "int") == 0)
	{
		char c, mas[10];
		int i = 0;
		while (1) {
			do {
				c = _getch();
			} while (!(c >= 48 && c <= 57) && c != '\r' && c != '\b');
			if (c != '\r' && c != '\b'&& i != 5) {
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0) {
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		variable = atoi(mas);
		puts("\r");
		return;
	}
	else if (strcmp(typeid(variable).name(), "float") == 0) {
		char c, mas[10];
		int i = 0, j = 0, number = 4;
		while (1) {
			do {
				c = _getch();
			} while (!(c >= 48 && c <= 57) && c != ',' && c != '\r' && c != '\b');
			if (c != '\r' && c != '\b' &&c != ',' && j < 4) {
				mas[i] = c;
				i++;
				j++;
				printf("%c", c);
			}
			else {
				if (c == '\b' && i != 0 && c != ',') {
					printf("\b \b");
					i--;
					j--;
				}
				else if (c == '\r' && i != 0 && c != ',') {
					break;
				}
				else if (c == ',' && (j > 0 && j < 5)) {
					mas[i] = c;
					i++;
					j = 2;
					printf("%c", c);
				}
			}
		}
		mas[i] = '\0';
		variable = atof(mas);
		puts("\r");
		cout << "\n"<< variable << endl;
		system("pause");
		return;
	}
}