#include<stdio.h>
#define t 60
int main()
{
    int hour=0,min=0;
    while(scanf("%d",&min)==1&&min>0)
    {
        hour=min/t;
        min=min-hour*t;
        printf("%d小时%d分钟\n",hour,min);
        printf("如果想要退出,请输入小于等于0的数字");
    }
    return 0;
}
