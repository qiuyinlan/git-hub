/*6.编写并测试一个函数，该函数以3个double变量的地址作为参数，把最
小值放入第1个函数，中间值放入第2个变量，最大值放入第3个变量。*/

#include<stdio.h>
double zhi(double *a,double *b,double *c)
{
	double max,min,mid;
    max=*a>*b?*a:*b;
    max=max>*c?max:*c;
    min=*a>*b?*b:*a;
    min=min>*c?*c:min;
    mid=*a>*b?*a:*b;
    mid=mid>*c?*c:mid;
    *a=min;
    *b=mid;
    *c=max;
    return min;

}
int main()
{
    double a,b,c;
    printf("请输入三个数：");
    scanf("%lf%lf%lf",&a,&b,&c);
    zhi(&a,&b,&c);
    printf("%.2lf,%.2lf,%.2lf",zhi(&a,&b,&c),b,c);
    return 0;

}