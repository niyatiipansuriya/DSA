#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the size : ");
	scanf("%d" ,&n);

	int s[n];
	int e[n];

	printf("intial : ");

	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&s[i]);
	}

	printf("\nfinal : ");
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&e[i]);
	}

	for(int i=0 ; i<n ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			if(e[i]>=e[j])
			{
				int x = e[i];
				e[i] = e[j];
				e[j] = x;

				int y = s[i];
				s[i] = s[j];
				s[j] = y;
			}
		}
	}

	int cnt = 0;

	for(int i=0 ; i<n ; i++)
	{
		int j=i+1;
		if(e[i]<=s[j])
		{
			cnt++; 
		}
		else
		{
			j++;
		}
	}

	printf("ans : %d",cnt);
	return 0;
}
