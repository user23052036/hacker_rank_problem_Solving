#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number,swap;
    scanf("%d",&number);
    
    int size[number];
    int **arr = (int**)malloc(number*sizeof(int*));
    
    for(int i=0; i<number; i++)
    {
        scanf("%d",&size[i]);
        
        arr[i] = (int*)malloc(size[i]*sizeof(int));
        for(int j=0; j<size[i]; j++)
            scanf("%d",&arr[i][j]); 
        
        swap=0;
        for(int j=1; j<size[i]; j++)
        {
            for(int k=0; k<size[i]-j; k++)
            {
                if(arr[i][k] > arr[i][k+1])
                {
                    swap++;
                    arr[i][k] = arr[i][k] + arr[i][k+1];
                    arr[i][k+1] = arr[i][k] - arr[i][k+1];
                    arr[i][k] = arr[i][k] - arr[i][k+1];
                }
            }
        }
        printf("%d\n",swap);  
        free(arr[i]);
    }
    free(arr);
    return 0;
}