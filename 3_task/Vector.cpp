#include <iostream>
#include <vector>
using namespace std;

int static1(int* mas_static, int len1);
bool checker(int args);
void zap_vec(vector<int>& a, int p);
void output_vec(vector<int>& a);
int vector1(vector <int>& mas_vec, int len1);
void filter(vector<int>vec_mas, int len1);
void insert_v(vector<int>& mas_vec, int value, int len1);
int len1 = 0;
int main() {
	int menu;
	cout << "Practical work#1  IKBO-03-21 Kushkhov.I.A. V15\nTask1- Static array\n\n===============MENU===============\n\n";
	vector<int> vec_mas;
	unsigned int modearr = 1;

	do {

		cout << "1)Fill the array\n2)Find the index of an element that has all the digits the same\n3)Insert an element after (2))\n4)Delete all elements with all digits the same\n0)Exit the programm" << endl;
		cin >> modearr;
		if (!(modearr > 4 || modearr < 0)) {
			switch (modearr) {
			case 1: {
				cout << "Enter the length of ur array (<=1000): ";
				cin >> len1;
				if (len1 > 1000 || len1 <= 0) {
					cout << "ERROR! The length should be <=1000 and > 0." << endl;
					break;

				}
				else {
					cout << "Enter the element of the array: " << endl;
					zap_vec(vec_mas, len1);
					cout << "Your array is:";
					output_vec(vec_mas);
				}
				break;
			}
			case 2: {
				if (len1 == 0) {
					cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
					break;
				}
				else {
					vector <int> vec_mas;
					cout << "Enter the elemets of ur array (<=1000): " << endl;
					zap_vec(vec_mas, len1);
					int index = vector1(vec_mas, len1);
					if (index == -1)
						cout << "Not found..." << endl;
					else
						cout << index << endl;
					break;
				}
			case 3: {
				if (len1 == 0) {
					cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
					break;
				}
				else {
					if (len1 != 1000) {
						int replace;
						cout << "Enter the adding value: ";
						cin >> replace;
						vec_mas.reserve(len1 + 1);
						int index = vector1(vec_mas, len1);
						if (index == -1)
							cout << "Not found..." << endl;
						else
						{
							insert_v(vec_mas, replace, len1);
							output_vec(vec_mas);
						}
					}
					else
						cout << "No more space to add the value( Try to reduce it" << endl;
				}
				break;
			}
			case 4: {
				if (len1 == 0) {
					cout << "Error! YOu should enter the array before starting the programm:( Try again " << endl;
					break;
				}
				else {
					filter(vec_mas, len1);
					break;
				}
			}
			case 0:
				return 0;
			}
			}
		}
		else
			cout << "Error! You can enter nums from 1 to 4 and 0. Try again.." << endl;
	} while (modearr != 0);
}




int static1(int* mas_static, int len1) {

	for (int i = 0; i <= len1 - 1; i++) {
		if (checker(mas_static[i]))
			return i;
	}
	return -1;
}	
void output_vec(vector<int>&a)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it << " ";
}
void zap_vec(vector<int>&a, int p)
{
	int x;
	for (int i = 0; i < p; i++) {
		cin >> x;
		a.push_back(x);
	}
}
int vector1(vector <int>&mas_vec, int len1) {
	for (int i = 0; i < len1; i++) {
		if (checker(mas_vec[i]))
			return i;
	}
	return -1;
}
void insert_v(vector<int>&mas_vec, int value, int len1) {
	vector<int>::iterator it = mas_vec.begin() + vector1(mas_vec, len1) + 1;
	mas_vec.insert(it, value);
	return;
}
void filter(vector<int>vec_mas, int len1) {
	for (int i = 0; i < len1; i++) {
		if (checker(vec_mas[i])) {
			vec_mas.erase(vec_mas.begin() + i);
			len1--;
			i--;
		}
	}
	output_vec(vec_mas);
	cout << endl;
	return;
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
	