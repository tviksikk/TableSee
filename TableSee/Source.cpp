#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{

	int **dMass = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		dMass[i] = new int[2];
	}
	dMass[0][0] = 15;
	dMass[0][1] = 31321;
	dMass[1][0] = 305;
	dMass[1][1] = 321;
	dMass[2][0] = 1;
	dMass[2][1] = 0;


	table<int,int> v(dMass,3);

	cout << v[15] << endl;
	cout << v[305] << endl;
	cout << v[1] << endl;

	
	cin.get();
}