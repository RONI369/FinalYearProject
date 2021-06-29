#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void qureshisort(int a[],int n)
{
	int i,j,k,max=0,min=2147483647;
	int d,D;
	
	for(i=0;i<n;i++)       //extract max  and min element from the array
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	
	D=max-min;			//D is the max value upto which the index may go for the difference and the repition array
	
	int diff[D+1],rept[D+1];
	
	//printf("\nD: %d\n",D);
	
	for(i=0;i<=D;i++)        //initialise the arrays with -1
	{
		diff[i]=-1;
		rept[i]=-1;
	}
	
	//printf(" max: %d \n",max);
	
	for(i=0;i<n;i++)      //scanning every element and setting the difference and repition array values
	{
		d=max-a[i];
		diff[d]=d;
		rept[d]++;
	}
	
/*	for(i=0;i<=D;i++)
	{
		printf(" %d ",diff[i]);
	}
	
	printf("\n");
	
	for(i=0;i<=D;i++)
	{
		printf(" %d ",rept[i]);
	}
	
*/
	
	k=0;                         //initialising the index for the final answer array
	
	for(i=0;i<=D;i++)                         //traversing the difference array
	{
		if(diff[i]==-1)						//skip if the number is absent 
			continue;
		else
			for(j=0;j<=rept[i];j++)         //printing the value number of times it had occured in the original array
			{
				a[k++]=max-diff[i];         
			}
	}
	
}

int main()
{
	int n,i;
	printf("\nSize of array: ");           //size of the input array to be sorted
	scanf("%d",&n);
	int a[n];								//input array
	
	srand(time(0));
	
	for(i=0;i<n;i++)
		a[i]=rand();						//filling array with random numbers
		
	clock_t start,end;
		
	start=clock();                          //start time
	qureshisort(a,n);						//function call
	end=clock();							//end time
	
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);				//printing the sorted array
		
	double total = ((double)(end-start))/CLOCKS_PER_SEC	;		//total time taken for sorting process
	printf("\nTime taken: %f secs\n", total);
	
	return 0;
}
