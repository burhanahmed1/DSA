
#include<iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


int circle(int* pet, int* dist, int s,int i)
{
    int ck = -1;
    if (i < s-1)
    {
        i++;
        ck=circle(pet, dist, s, i);

    }
    int p=0, d=pet[i];
    if (ck == -1)
    {
        for (int y = i, z = 0;z < s - 1; z++)
        {
            p = d - dist[y];
            if (p >= 0)
            {
                y = (y + 1) % s;
                d = p + pet[y];

            }
            else
                return -1;
        }
        return i;
    }
    return ck;
}

int main()
{
    int* petrol = new int[4];
    int* dist = new int[4];
    petrol[0] = 4;
    petrol[1] = 6;
    petrol[2] = 7;
    petrol[3] = 4;

    dist[0] = 6;
    dist[1] = 5;
    dist[2] = 6;
    dist[3] = 5;

    int res = circle(petrol, dist, 4,0);

    cout << res;
	return 0;
}