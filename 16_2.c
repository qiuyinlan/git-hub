/*2.两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数
的平均值，最后取计算结果的倒数。使用#define指令定义一个宏“函数”，执
行该运算。编写一个简单的程序测试该宏。*/
#include <stdio.h>
#include <math.h>
#define PI 3.1415926

typedef struct
{
    double length;
    double angle;
} polar;

typedef struct
{
    double x;
    double y;
} rect;

rect polar_to_rect(const polar *temp);

int main(void)
{
    polar input;
    rect answer;

    printf("Enter magnitude and angle in degrees (q tu quit): ");
    while (scanf("%lf %lf", &input.length, &input.angle) == 2)
    {
        answer = polar_to_rect(&input);
        printf("polar coord: %g %g\n", input.length, input.angle);
        printf("rectangular coord: %g %g\n", answer.x, answer.y);
        printf("You can enter again (q tu quit): ");
    }
    puts("Done.");

    return 0;
}

rect polar_to_rect(const polar *temp)
{
    rect res;
    double ang = temp->angle * (PI / 180.0);

    res.x = temp->length * cos(ang);
    res.y = temp->length * sin(ang);

    return res;
}
