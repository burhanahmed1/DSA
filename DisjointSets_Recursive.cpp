#include<iostream>
using namespace std;


bool chk(int* arr_r, int* arr2, int rec, int s2, int& dis,int i)
{
	bool tr=false;
	if (i <= rec)
	{
		i++;
		tr=chk(arr_r, arr2, rec, s2, dis, i);
	}
	if (tr != true)
	{
		for (int y = 0;y < s2;y++)
		{
			if (arr_r[i] == arr2[y])
			{
				dis = arr2[y];
				return !tr;
			}
		}
		return false;
	}
	else
		return true;
}

bool isDisjoint(int* arr1, int* arr2, int s1, int s2, int& dis)
{
		return chk(arr2, arr1, s2, s1, dis, 0);
	
}


int main()
{
	int* arr1 = new int[5];
	arr1[0] = 2;
	arr1[1] = 3;

	arr1[2] = 4;
	arr1[3] = 5;
	arr1[4] = 6;

	int* arr2 = new int[3];
	arr2[0] = 7;
	arr2[1] = 5;

	arr2[2] = 10;
	int dis = 0;

	if (isDisjoint(arr1, arr2, 5, 3, dis))
	{
		cout << "Not disjoint " << dis << " is common";
	}
	else
		cout << "these are disjoint ";
}