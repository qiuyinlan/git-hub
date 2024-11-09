/*10.编写一个函数，把两个数组中相对应的元素相加，然后把结果储存
到第 3 个数组中。也就是说，如果数组1中包含的值是2、4、5、8，数组2中
包含的值是1、0、4、6，那么该函数把3、4、9、14赋给第3个数组。函数接
受3个数组名和一个数组大小。在一个简单的程序中测试该函数。*/
#include <stdio.h>
void jia(int n,int a[n],int b[n],int c[n])
{
    int i=0;
    for(i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
        printf("%d ",c[i]);
    }
}
int main()
{
    int n;
    printf("请输入数组的大小：");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    jia(n,a,b,c);
    return 0;
}
