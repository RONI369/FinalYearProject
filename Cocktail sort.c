#include<stdio.h>
#include<time.h>
#include<stdbool.h>

void bidirectional(int *arr,int n)
{
	bool swapped;
	int i,temp;	
	
	do
	{
		swapped = false;
		for(i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swapped = true;
			}
		}
		if(!swapped)
		{
			break;
		}
		swapped = false;
		
		for(i=n-2;i>=0;i--)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swapped = true;
			}
		}	
	}
	while(swapped);
}

/*int main()
{
	int n,i;
	printf("\nNumber of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bidirectional(arr,n);
	for(i=0;i<n;i++)
		printf("\n%d",arr[i]);
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
	bidirectional(arr,n);						//function call
	end=clock();							//end time
	
				//printing the sorted array
		
	double total = ((double)(end-start))/CLOCKS_PER_SEC	;		//total time taken for sorting process
	printf("\nTime taken: %f secs\n", total);
	
	return 0;
}
