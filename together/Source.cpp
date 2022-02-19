#include <iostream>
#include <vector>
using namespace std;

void outpit_mas(int* mas_static, int len1);
void outpit_mas_v(vector <int> mas_static, int len1);
int static1(int* mas_static, int len1);
int* zap_mas(int* mas_static, int len1);
bool checker(int args);
int vector1(vector <int> mas_vec, int len1);
vector <int> zap_vec(vector <int> vec_mas, int len1);
void outpit_mas_v(vector <int> mas_static, int len1);	
int* offs(int* mas_dinamic, int index2, int len1, int replace);
int* offd(int*& mas_dinamic, int index2, int len1, int replace);
int* func3d(int* mas_dinamic, int len1);
int checker2(int* mas_dinamic, int len1);

int main() {
	int mode;
	cout << "Enter the number of task (enter 0 to exit) : ";
	cin >> mode;
	do {
		switch (mode) {
			int modearr, len1, mas_static[1000];
		case 1: {
			cout << "Choose the type of array:\n1.Static array\n2.Dinamic array\n3.Vector\n";
			cin >> modearr;
			cout << "Enter the length of ur array (<=1000): ";
			cin >> len1;
			switch (modearr) {
			case 1: {
				int  temp;
				if (len1 > 1000)
					cout << "Error! Length is > 1000";
				else {
					cout << "Enter the elemets of ur array (<=1000): " << endl;
					zap_mas(mas_static, len1);
					int index1 = static1(mas_static, len1);
					if (index1 != -1) {

						cout << "The result index is: " << index1 << endl;
					}
					else
						cout << "Not found..." << endl;
				}
				break;
			}
			case 2: {

				int* mas_dinamic = new int[len1];
				zap_mas(mas_dinamic, len1);
				int res = static1(mas_dinamic, len1);
				if (res != -1) {

					cout << "The result index is: " << res << endl;
				}
				else
					cout << "Not found..." << endl;
				delete mas_dinamic;
				break;
			}
			case 3: {
				vector <int> vec_mas;
				cout << "Enter the elemets of ur array (<=1000): " << endl;
				zap_vec(vec_mas, len1);
				outpit_mas_v(vec_mas, len1);
				break;
			}
			}
		}
		case 2: {
			cout << "Choose the type of array:\n1.Static array\n2.Dinamic array\n3.Vector\n";
			cin >> modearr;
			cout << "Enter the length of ur array (<=1000): ";
			cin >> len1;
			int replace;
			cout << "Enter the replace value: " << endl;
			cin >> replace;
			switch (modearr) {
			case 1: {

				cout << "Enter the elemets of ur array (<=1000): " << endl;
				zap_mas(mas_static, len1);
				int index2 = static1(mas_static, len1);

				if (index2 == -1)
					cout << "Not found.." << endl;
				else {
					offs(mas_static, index2, len1, replace);
					outpit_mas(mas_static, len1 + 1);
				}
				break;
			}
			case 2: {
				int* mas_dinamic = new int[len1];
				cout << "Enter ur array:: " << endl;
				zap_mas(mas_dinamic, len1);
				mas_dinamic = (int*)realloc(mas_dinamic, (len1 + 1) * sizeof(int));
				int index2 = static1(mas_dinamic, len1);
				offd(mas_dinamic, index2, len1, replace);
				outpit_mas(mas_dinamic, len1 + 1);
				break;

			}
			case 3: {

			}
			}
		}
		case 3: {
			cout << "Choose the type of array:\n1.Static array\n2.Dinamic array\n3.Vector\n";
			cin >> modearr;
			cout << "Enter the length of ur array (<=1000): ";
			cin >> len1;
			switch (modearr) {

			case 1: {
				cout << "Enter the elemets of ur array (<=1000): " << endl;
				zap_mas(mas_static, len1);
				int count = checker2(mas_static, len1);

				func3d(mas_static, len1);
				outpit_mas(mas_static, len1 - count);
				break;
			}
			case 2: {
				int* mas_dinamic = new int[len1];

				zap_mas(mas_dinamic, len1);
				int count = checker2(mas_dinamic, len1);

				func3d(mas_dinamic, len1);
				mas_dinamic = (int*)realloc(mas_dinamic, (len1 - count) * sizeof(int));
				outpit_mas(mas_dinamic, len1 - count);
				delete mas_dinamic;
			}
			case 3: {

			}
			}
		}
		}

	} while (mode != 0);
}
int static1(int* mas_static, int len1) {

	for (int i = 0; i < len1 - 1; i++) {
		if (checker(mas_static[i]))
			return i;
	}
	return -1;
}
int vector1(vector <int> mas_vec, int len1) {
	for (int i = 0; i < len1; i++) {
		if (checker(mas_vec[i]))
			return i;
	}
	return -1;
}
void outpit_mas(int* mas_static, int len1) {

	for (int i = 0; i < len1; i++) {
		cout << mas_static[i] << ' ';
	}
}
void outpit_mas_v(vector <int> vec_mas, int len1) {

	for (vector<int>::iterator i = vec_mas.begin(); i != vec_mas.end(); i++) {
		cout << *i << " ";
	}

	cout << endl;

}
int* zap_mas(int* mas_static, int len1) {
	int temp;
	for (int i = 0; i < len1; i++) {
		cin >> temp;
		mas_static[i] = temp;
	}
	return mas_static;
}
vector <int> zap_vec(vector <int> vec_mas, int len1) {
	int temp;

	for (int i = 0; i < len1; i++) {
		cin >> temp;
		vec_mas.push_back(temp);
	}
	return vec_mas;
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
int* offs(int* mas_static, int index2, int len1, int replace) {
	int n = len1 + 1;
	while (n != index2 + 1) {
		mas_static[n] = mas_static[n - 1];
		n--;
	}
	mas_static[n] = replace;
	return mas_static;
}
int* offd(int*& mas_dinamic, int index2, int len1, int replace) {
	int n = len1 + 1;
	while (n != index2 + 1) {
		mas_dinamic[n] = mas_dinamic[n - 1];
		n--;
	}
	mas_dinamic[n] = replace;
	return mas_dinamic;
}
int* func3d(int* mas_dinamic, int len1) {
	for (int i = 0; i < len1; i++) {
		if (checker(mas_dinamic[i])) {
			swap(mas_dinamic[i], mas_dinamic[i + 1]);
		}
	}
	return mas_dinamic;
}