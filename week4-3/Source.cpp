//0033
#include<iostream>
#include<algorithm>
using namespace std;

void getComments(int*, int);
void sortComments(int*, int);
void showVals(int*, int);
void findMost(int*, int);

int main()
{
	int like;
	int comments[1000];
	int *pComment = &comments[0];
	cin >> like;
	getComments(pComment, like);
	sortComments(pComment, like);
//	showVals(pComment, like);
//	cout << endl;
	findMost(pComment, like);

	return 0;
}
void getComments(int* pComment, int n)
{
	for (int i=0;i<n;i++)
	{
		cin >> *(pComment + i);
	}
}
void sortComments(int* pComment, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(pComment + i) > * (pComment + j))
			{
				temp = *(pComment + i);
				*(pComment + i) = *(pComment + j);
				*(pComment + j) = temp;
			}
		}
	}
}
void showVals(int* pComment, int n)
{
	for (int i=0;i<n;i++)
	{
		cout << *(pComment + i) << endl;
	}
}
void findMost(int* pComment, int n)
{
	
	int mode[1000];
	int fMode[1000];
	int x = *pComment;
	int f = 0;
	int j = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (*(pComment + i) == x)
		{
			f++;
		} 
		else
		{
			x = *(pComment + i);
			f = 1;
		}

		if (*(pComment + i + 1) != x or i == n - 1)
		{
			fMode[j] = f;
			mode[j] = *(pComment + i);
			j++;
		}
	}
	
	int max = 0;
	for (int i=0;i<j;i++)
	{
		if (fMode[i] >= max)
		{
			max = fMode[i];
		}
	}
	
	for (int i=0;i<j;i++)
	{
		if (fMode[i] == max)
		{
			cout << mode[i] << " ";
		}
	}
}