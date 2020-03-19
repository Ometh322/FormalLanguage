#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iterator>


using namespace std;

ifstream in("input.txt");

class Automate {
public:
	set<string> Alphabit; //������� �������
	set<string> StartSt; //��������� ���������
	set<string> AllowSt;//���������� ��������� ��������
	set<string> EndSt;//�������������� ���������
	map<string, map<string, set<string>>> ConversionTable; //������� ���������

	Automate() {}
	
	void initAutomate()
	{
		int k = 0;
		string s;
		string tmp;
		
		while (in.peek() != '\n') //��������� �������
		{
			in >> s;
			Alphabit.insert(s);
		}
		
		do
		{
			in >> s;
			AllowSt.insert(s);
		} while (in.peek() != '\n'); //���������� ���������

		do
		{
			in >> s;
			StartSt.insert(s);
		} while (in.peek() != '\n'); // ��������� ���������

		do
		{
			in >> s;
			EndSt.insert(s);
		} while (in.peek() != '\n'); // �������� ���������

		string start, jump, end;

		do
		{
			in >> start >> jump >> end;
			ConversionTable[start][jump].insert(end);
		} while (in.peek() != EOF); //������� ���������

		cout << "������� ������� :" << endl;
		set<string> ::iterator it;
		for (it = Alphabit.begin(); it != Alphabit.end(); it++)
		{
			cout << *it << " ";
		}

		cout << endl << "���������� ��������� �������� : " << endl;
		for (it = AllowSt.begin(); it != AllowSt.end(); it++)
		{
			cout << *it << " ";
		}

		cout << endl << "��������� ��������� �������� : " << endl;
		for (it = StartSt.begin(); it != StartSt.end(); it++)
		{
			cout << *it << " ";
		}

		cout << endl << "�������� ��������� �������� : " << endl;
		for (it = EndSt.begin(); it != EndSt.end(); it++)
		{
			cout << *it << " ";
		}

		map<string, map<string, set<string>>> ::iterator it1;

		/*cout << endl << "������� ��������� : " << endl;
		for (it1 = ConversionTable.begin(); it1 != ConversionTable.end(); it1++)
		{
			cout << *it1 << endl;
		}*/
	}

};

int main() {
	setlocale(LC_ALL, "RUS");
	Automate A;
	A.initAutomate();
}