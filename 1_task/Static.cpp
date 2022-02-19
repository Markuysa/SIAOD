#include <iostream>
#include <vector>
using namespace std;

int* zap_mas(int* mas_static, int len1);
void outpit_mas(int* mas_static, int len1);
int static1(int* mas_static, int len1);
bool checker(int args);
int checker2(int* mas_dinamic, int len1);
int* func3d(int* mas_dinamic, int len1,int* mas2);
int* offs(int* mas_static, int index2, int len1, int replace);
int len1 = 0;
int main() {
	int menu;
	cout << "Practical work#1  IKBO-03-21 Kushkhov.I.A. V15\nTask1- Static array\n\n===============MENU===============\n\n";
	int  mas_static[1000];
	unsigned int modearr = 1;

	do {

		cout << "1)Fill the array\n2)Find the index of an element that has all the digits the same\n3)Insert an element after (2))\n4)Delete all elements with all digits the same\n0)Exit the programm" << endl;
		cin >> modearr;
		switch (modearr) {
		case 1: {
			cout << "Enter the length of ur array (<=1000): ";
			cin >> len1;
			if (len1 > 1000 || len1 == 0) {
				cout << "ERROR! The length should be <=1000 and > 0." << endl;
				len1=0;
				break;

			}
			else {
				cout << "Enter the element of the array: " << endl;
				zap_mas(mas_static, len1);
				cout << "Your array is:";
				outpit_mas(mas_static, len1);
			}
			break;
		}
		case 2: {
			if (len1 == 0) {
				cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
				len1 = 0;
				break;
			}
			else {
				int index1 = static1(mas_static, len1);
				if (index1 != -1) {

					cout << "The result index is: " << index1 << endl;
				}
				else
					cout << "Not found..." << endl;
			}
			break;
		}
		case 3: {
			if (len1 == 0) {
				cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
				len1 = 0;
				break;
			}
			else {
				int index2 = static1(mas_static, len1), replace;
				cout << "Enter the adding velue: ";
				cin >> replace;
				if (index2 == -1)
					cout << "Not found.." << endl;
				else {
					offs(mas_static, index2, len1, replace);
					outpit_mas(mas_static, len1 + 1);
				}
				break;
			}
			break;
		}
		case 4: {
			if (len1 == 0) {
				cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
				len1 = 0;
				break;
			}
			if (len1 == 1000) {
				cout << "Not enough space, please reduce the length of your array" << endl;
				break;
			}
			else {
				int mas2[1000];
				int count = checker2(mas_static, len1);
				func3d(mas_static, len1,mas2);
				outpit_mas(mas2, len1 - count);
				cout << endl;
				break;
			}
		}
		}
	} while (modearr != 0);
}


int* zap_mas(int* mas_static, int len1) {
	int temp;
	for (int i = 0; i < len1; i++) {
		cin >> temp;
		mas_static[i] = temp;
	}
	return mas_static;
}
void outpit_mas(int* mas_static, int len1) {

	for (int i = 0; i < len1; i++) {
		cout << mas_static[i] << ' ';
	}
	cout << endl;
}
int static1(int* mas_static, int len1) {

	for (int i = 0; i <= len1 - 1; i++) {
		if (checker(mas_static[i]))
			return i;
	}
	return -1;
}
bool checker(int args) {
	bool flag = true;
	int temp = args % 10;
	while (args != 0) {
		if (temp != args % 10)
			flag = false;
		args /= 10;
	}
	if (flag)
		return true;
	return false;
}
int checker2(int* mas_dinamic, int len1) {
	int count = 0;
	for (int i = 0; i < len1; i++) {
		bool flag = true;

		int N = mas_dinamic[i];
		int d = 0, dold = 0;
		dold = N % 10;
		while (N != 0)
		{
			d = N % 10;
			if (d != dold)
			{
				flag = false;
			}
			N = N / 10;
			dold = d;
		}
		if (flag)
			count++;
	}
	return count;
}
int* func3d(int* mas_dinamic, int len1,int* mas2) {
	int n=0;
	for (int i = 0; i < len1; i++) {
		if (!checker(mas_dinamic[i])) {
			mas2[n] = mas_dinamic[i];
			n++;
		}
	}
	return mas2;
}
int* offs(int* mas_static, int index2, int len1, int replace) {
	int n = len1 + 1;
	while (n != index2 + 1) {
		mas_static[n] = mas_static[n - 1];
		n--;
	}
	mas_static[n] = replace;
	return mas_static;
}