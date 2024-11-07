#include<stdio.h>
int main()
{
   int a,i,j;
    if(scanf("%d",&a)==1&&a>=0)
    {
      
        for(i=2;i<a;i++)
        {
            int flag=1;
            for(j=2;j*j<=i;j++)
            {
                    if(i%j==0)
                    {
                        flag=0;               
                        break;
                    }

                   
            }
            if(flag)
                printf("%d\n",i);
                
            
        }
        
        
    }

        
    return 0;
    

}