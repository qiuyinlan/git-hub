#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit ( const int N, const int D ){
    int count=0,i,n;
    n=N;
    for(i=n;n%10!=0;){
        if(D==n%10){
            count++;
        }
        n=n/10;
    }
    return count;
}
/* 你的代码将被嵌在这里 */