// Write a function and a recursive function to find the maximum element in a Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create (int A[], int n)
{
	int i; 
	struct Node *t, *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1; i<n; i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

int Max(struct Node *p)
{
	int max=-32767;
	while(p)
	{
		if(p->data>max)
		max=p->data;
		p=p->next; 
	}
	return max;
}

int RMax(struct Node *p)
{
	int x=0;
	if(p==0)
	return -32767;
	x=RMax(p->next);
	if(x>p->data)
	return x;
	else
	return p->data;
}

int main()
{
	int A[]={8, 5, 7, 2, 4, 14, 21, 2};
	create(A, 8);
	printf("Max element is : %d\n", Max(first));
	printf("Max element is : %d\n", RMax(first));
	return 0;
}
 

/*

Output:- 

Max element is : 21
Max element is : 21


*/
