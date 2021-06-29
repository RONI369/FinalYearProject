#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void p_move(int *,int,int,int,int,int);
void p_sort(int *,int *,int *,int *,int,int,int,int,int);

void p_scan(int *arr,int n)
{
	int a,max,min,nop,non;
	if(n>1)
	{
		max=arr[0];
		min=arr[0];
		nop=0;
		non=0;
		for(a=0;a<n;a++)
		{
			if(arr[a]>max)
				max=arr[a];
			else
				min=arr[a];
			if(arr[a]>=0)
				nop++;
			else
				non++;
		}
		if(min!=max)
			p_move(arr,n,nop,non,max,min);
	}
}

void p_move(int *arr,int n,int nop,int non,int max,int min)
{
	int b,c,d,i;
	int x=fabs(min);
	int farr[n];
	int posarr[max+1];
	int negarr[x+1];
	for(i=0;i<n;i++)
		farr[i]=min-1;
	i=0;
	if(nop>0)
	{
		
		for(b=0;b<=max;b++)
			posarr[b]=min-1;
	}
	if(non>0)
	{
		for(c=0;c<=x;c++)
			negarr[c]=min-1;
	}
	for(d=0;d<n;d++)
	{
		if(arr[d]>=0)
		{
			if(posarr[arr[d]]==min-1)
				posarr[arr[d]]=arr[d];
			else
				{
					farr[i]=arr[d];
					i++;
				}
		}
		else
		{
			if(negarr[abs(arr[d])]==min-1)
				negarr[abs(arr[d])]=arr[d];
			else
				{
					farr[i]=arr[d];
					i++;
				}
		}
	}
	p_sort(arr,negarr,posarr,farr,non,nop,max,min,i);
}

void p_sort(int *arr,int *negarr,int *posarr,int *farr,int non,int nop,int max,int min,int i)
{
	int index,x,y;
	index=0;
	if(non>0)
	{
		for(x=fabs(min);x>=0;x--)
		{
			if(negarr[x]!=min-1)
				{
					arr[index]=negarr[x];
					index++;
				}
				for(y=0;y<=i;y++)
				{
					if(farr[y]==arr[index-1])
						{
							arr[index]=farr[y];
							index++;
						}
				}
		}
	}
	if(nop>0)
	{
		for(x=0;x<=max;x++)
		{
			if(posarr[x]!=min-1)
				{
					arr[index]=posarr[x];
					index++;
					for(y=0;y<=i;y++)
					{
						if(farr[y]==arr[index-1])
						{
							arr[index]=farr[y];
							index++;
						}
					}
				}
		}
		
	}
}

/*int main()
{
	int i;
	printf("\nNumber of numbers: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	p_scan(arr,n);
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
	return 0;
}*/

int main()
{
	int n,i;
	printf("\nSize of array: ");           //size of the input array to be sorted
	scanf("%d",&n);	
	int arr[n];						
	
	srand(time(0));
	
	for(i=0;i<n;i++)
		arr[i]=rand();						//filling array with random numbers
		
	clock_t start,end;
		
	start=clock();                          //start time
	p_scan(arr,n);							//function call
	end=clock();							//end time
	
	//for(i=0;i<n;i++)
		//printf(" %d ",arr[i]);				//printing the sorted array
		
	double total = ((double)(end-start))/CLOCKS_PER_SEC	;		//total time taken for sorting process
	printf("\nTime taken: %f secs\n", total);
	
	return 0;
}

