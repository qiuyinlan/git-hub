#include<stdio.h>
int main()
{
    
    int count=0;
    for(int i=100;i<=200;i++)
    {
        int k=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                k=1;
                break;
            }
        }
         if(k==0)
         {
              printf("%-5d",i);
                count++;
        }
            
        if(count%8==0&&count!=0)
        {   
             printf("\n");
             
        }
       
        
    }
}
