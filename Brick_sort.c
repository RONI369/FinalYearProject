#include<stdio.h>
#include<stdbool.h>
#include<time.h>

void oddEvenSort(int arr[], int n)
{
    bool isSorted = false;
	int i,temp; // Initially array is unsorted
 
    while (!isSorted)
    {
        isSorted = true;
 
        // Perform Bubble sort on odd indexed element
        for (i=1; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
             {
                //swap(arr[i], arr[i+1]);
                temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
                isSorted = false;
              }
        }
 
        // Perform Bubble sort on even indexed element
        for (i=0; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                //swap(arr[i], arr[i+1]);
                temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
                isSorted = false;
            }
        }
    }
 
//    return;
}


/*int main()
{
	int n,i;
	printf("\nNumber of elements: ");
	scanf("%d",&n);
	
	int arr[n];
	

	
	
	
	oddEvenSort(arr,n);
	
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
	oddEvenSort(arr,n);						//function call
	end=clock();							//end time
	
				//printing the sorted array
		
	double total = ((double)(end-start))/CLOCKS_PER_SEC	;		//total time taken for sorting process
	printf("\nTime taken: %f secs\n", total);
	
	return 0;
}
