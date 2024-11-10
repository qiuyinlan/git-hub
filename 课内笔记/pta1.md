可以不用这么着急声明变量,直接后面定义即可,一起来
#include<stdio.h>
int main()
{
    int cm,inch1,foot1,m;
    double inch,foot;
    scanf("%d",&cm);
    m=cm/100.0;
    inch=(m/0.3048)/(145.0/12);
    inch1=(int)inch;
    foot=inch/12;
    foot1=(int)foot;
    printf("%d %d",inch1,foot1);
    return 0;
}


#include<stdio.h>
int main()
{
    int cm,inch1,foot1,m;
    double t,foot;
    scanf("%d",&cm);
    m=cm/100.0;
    t=(m/0.3048);
    inch1=(int)t;
    foot=t*12;
    foot1=(int)foot;
    printf("%d %d",inch1,foot1);
    return 0;
}

#include <stdio.h>

int main() {
    int cm;
    scanf("%d", &cm);

    // 将厘米转换为米
    double meters = cm / 100.0;
    // 将米转换为英尺
    double total_feet = meters / 0.3048;
    // 取整数部分作为英尺
    int foot = (int)total_feet;
    // 剩余部分转换为英寸
    int inch = (int)((total_feet - foot) * 12);

    printf("%d %d\n", foot, inch);

    return 0;
}


这道题的要求是将长度转换成 英尺和英寸的组合形式，而不是单纯的英寸数。题目希望输出的结果是英尺和英寸的整数值，中间用空格分开，且英寸部分应小于 12。因此，答案格式应该是“多少英尺 多少英寸”，不是总英寸数。
题目示例

如果输入是厘米数 170，我们要将它转换为 “5 英尺 6 英寸” 的格式，而不是总共多少英寸。
代码实现说明

在代码中，我们首先得到总英尺数的整数部分作为“英尺”，然后将不足 1 英尺的小数部分转化为英寸，这样才能得到英尺和英寸的组合形式输出。