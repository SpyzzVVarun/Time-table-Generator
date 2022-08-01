#include <stdio.h>
#include <string.h>

struct week
{
	char monday[8];
	char tuesday[8];
	char wednesda#include <stdio.h>
#include <string.h>

struct week
{
	char monday[8];
	char tuesday[8];
	char wednesday[8];
	char thursday[8];
	char friday[8];
};

int main()
{
	int N,L,M,i,P;
	for (i=0;i<N;i++)
	{
		scanf("%d",&N);
	}
	for (i=0;i<L;i++)
	{
		scanf("%d",&L);
	}
	for (i=0;i<M;i++)
	{
		scanf("%d",&M);
	}
	P = N/2;
	struct week prof[P], ug1[N];
	initialize(
		
	return 0;
}

void initialize(char *p)
{
	for (i=0;i<strlen(p);i++)
	{
		*(p+i) = 'X';
	}
}y[8];
	char thursday[8];
	char friday[8];
};

int main()
{
	int N,L,M,i,P;
	for (i=0;i<N;i++)
	{
		scanf("%d",&N);
	}
	for (i=0;i<L;i++)
	{
		scanf("%d",&L);
	}
	for (i=0;i<M;i++)
	{
		scanf("%d",&M);
	}
	P = N/2;
	struct week prof[P], ug1[N];
	initialize(
		
	return 0;
}

void initialize(char *p)
{
	for (i=0;i<strlen(p);i++)
	{
		*(p+i) = 'X';
	}
}
