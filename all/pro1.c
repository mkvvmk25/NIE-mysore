#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]); 
    }

    int b[n + 1]; // 8 
    for(int i = 0; i < n + 1; i++)
    {
        b[i] = 0; 
    }


    for(int i = 0; i < n; i++)
    {
        int ind_b = a[i]; 
        b[ind_b] = b[ind_b] + 1;  
    }

    int maxRep = 0;
    int maxRepInd = 0; 
    for(int i = 1; i < n + 1; i++)
    {
         if( b[i] > maxRep)
         {
            maxRep = b[i];
            maxRepInd = i; 
         }
    }

    printf("%d", maxRepInd); 







    
}