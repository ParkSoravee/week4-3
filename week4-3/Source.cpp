//0033
#include<iostream>
using namespace std;

void getComments(int*, int);
void sortComments(int*, int );
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
	int f = 0;
	int mode[1000] = {0};
	int x = *pComment;
	
//	mode[0] = *pComment;
	int fMode = 0;
	int j = 0;
	*(pComment + n + 1) = -1;
	for (int i = 0; i <= n; i++)
	{
		if (*(pComment + i) == x)
		{
			f++;
			
		} 
		else
		{
			if (f > fMode)
			{
				fMode = f;
				mode[j] = *(pComment + i -1);
			}
			else if(f == fMode)
			{
				
				j++;
				mode[j] = *(pComment + i -1);
			}
			x = *(pComment + i);
			f = 1;
		}
	}
	
	for (int i=0;i<j+1;i++)
	{
		cout << mode[i] << " ";
	}
}