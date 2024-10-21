#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
		
void bubblesort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void insertionsort(int arr[], int n) 
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = arr[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= arr[j]) 
        {    
            arr[j+1] = arr[j];     
            j = j-1;    
        }    
        arr[j+1] = temp;    
    }  
}  
void fork1()
{
 	int arr[25],arr1[25],n,i,status;
 	printf("\n Enter the no of values in array :");
 	scanf("%d",&n);
 	printf("\n Enter the array elements :");
 	for(i=0;i<n;i++)
    		scanf("%d",&arr[i]);
 	int pid=fork();
  	if(pid==0)
   	{
      		//sleep(10);
      		printf("\n child process\n");
      		printf("child process id=%d\n",getpid());
      		insertionsort(arr,n);
       		printf("\n Elements Sorted Using insertion sort:");
     		printf("\n");
       		for(i=0;i<n;i++)
    			printf("%d,",arr[i]);
    		printf("\b");
     		printf("\n parent process id=%d\n",getppid());
     		//system("ps -x");
       }    
      else
       {
             	wait(NULL);
     		printf("\n parent process\n");
     		printf("\n parent process id=%d\n",getppid());
	 	bubblesort(arr,n);	      
		printf("Elements Sorted Using bubble sort:");
     		printf("\n");
      		for(i=0;i<n;i++)
    			printf("%d,",arr[i]);
    		printf("\n\n\n"); 
      } 
 }     
 int main()
 {
   	fork1();
   	return 0;
 }  
