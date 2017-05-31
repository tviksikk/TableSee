#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{
	table<int,unsigned char> v(9);

	setlocale(LC_ALL, "Russian");
	v.add(2, 'à');
	v.add(1, 'á');
	v.add(3, 'ñ');

	cout << v[2] << endl;
	cout << v[1] << endl;
	cout << v[3] << endl;

	v.resize(6);
	
	
	cin.get();
}