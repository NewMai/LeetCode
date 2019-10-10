
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<memory.h>
#include<limits.h>
//#include<minmax.h>


#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

#include<unordered_map>
#include<unordered_set>



using namespace std;


static void printV(const vector<int>& ret)
{
	int i = 0;


	puts("[");
	printf("    ");
	for (i = 0; i < ret.size(); i++)
	{
		printf("%-3d, ", ret[i]);
	}
	puts("");
	puts("]");
}


static void printVV1(const vector<vector<int>>& ret)
{
	int i = 0, j = 0;


	puts("[");
	for (i = 0; i < ret.size(); i++)
	{
		printf("    [");
		for (j = 0; j < ret[i].size(); j++)
		{
			printf("%-3d, ", ret[i][j]);
		}
		puts("]");
	}
	puts("]");
}

static void printVV2(const vector<vector<int>>& ret)
{
	int i = 0, j = 0;

	for (i = 0; i < ret.size(); i++)
	{
		for (j = 0; j < ret[i].size(); j++)
		{
			printf("%-2d, ", ret[i][j]);
		}
		puts("");
	}
	puts("");
}
