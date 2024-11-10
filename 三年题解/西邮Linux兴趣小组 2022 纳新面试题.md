# 西邮Linux兴趣小组2022纳新面试题

感谢 [Zhilu](https://github.com/L33Z22L11) 重新录入题目原件。好人一生平安。

- 本题目只作为`Xiyou Linux兴趣小组`2022纳新面试的有限参考。
- 为节省版面，本试题的程序源码省去了`#include`指令。
- 本试题中的程序源码仅用于考察C语言基础，不应当作为C语言「代码风格」的范例。
- 题目难度随机排列。
- 所有题目编译并运行于`x86_64 GNU/Linux`环境。

> 学长寄语：
> 长期以来，西邮Linux兴趣小组的面试题以难度之高名扬西邮校内。我们作为出题人也清楚的知道这份试题略有难度。请别担心。**若有同学能完成一半的题目，就已经十分优秀。** 其次，相比于题目的答案，我们对你的思路和过程更感兴趣，或许你的答案略有瑕疵，但你正确的思路和对知识的理解足以为你赢得绝大多数的分数。最后，做题的过程也是学习和成长的过程，相信本试题对你更加熟悉的掌握C语言的一定有所帮助。祝你好运。我们FZ103见！

Copyright © 2022 西邮Linux兴趣小组, All Rights Reserved.
本试题使用采用 [知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议](http://creativecommons.org/licenses/by-nc-sa/4.0/) 进行许可。

## 0. 我的计算器坏了？！

`2^10 = 1024`对应于十进制的4位，那么`2^10000`对应于十进制的多少位呢?

> -lg​(X) 的意思是“10 的几次方等于 X”。10的1次方是2位数,10的2次方是3位数,以此类推,所以可以通过k=lg⁡(X)来判断2的几次方的位数
取lg,向下取整再加1即可

>对2^10 取log10，得3,再加1,得4,对2^10000取lg10，得3010,加1 得3011

## 1. printf还能这么玩？

尝试着解释程序的输出。

```c
int main(void) {
    if ((3 + 2 < 2) > (3 + 2 > 2))
        printf("Welcome to Xiyou Linux Group\n");
    else
        printf("%d\n", printf("Xiyou Linux Group - 2%d", printf("")));
}
```
- 3 + 2 < 2为假，3 + 2 > 2为真，则0>1 ---if语句判断为假，执行else语句。
printf函数嵌套，先执行最里面的。printf“”什么都不打印，而printf函数返回值是0，所以前面对应输出20，即中间的printf函数%d被替换，打印Xiyou Linux Group - 20
而最外层的printf打印中间printf的返回值22,没有换行符，所以22就接着前面打印出来的
最后输出Xiyou Linux Group - 2022
- 接连的打印
>在c语言环境中，嵌套的printf函数是从内到外调用的顺序来执行，这样保证在进行格式化输出的时候，所有参数都已经计算完毕。

## 2. 你好你好你好呀！

- 程序的输出有点奇怪，请尝试解释一下程序的输出吧。
- 请谈谈对`sizeof()`及`strlen()`的理解吧。

```c
int main(void) {
    char p0[] = "Hello,Linux";
    i;
    char p2[11] = "Hello,Linux";
    printf("p0 == p1: %d, strcmp(p0, p2): %d\n", p0 == p1, strcmp(p0, p2));
    printf("sizeof(p0): %zu, sizeof(p1): %zu, sizeof(*p2): %zu\n",
           sizeof(p0), sizeof(p1), sizeof(*p2));
    printf("strlen(p0): %zu, strlen(p1): %zu\n", strlen(p0), strlen(p1));
}
```
>sizeof()是运算符，计算占空间字节数,包括\0
>而strlen()是函数，计算字符串长度且不计\0

- p0==p1比较两个地址的值，不同，所以为0。
- strcmp 函数接受的是指向字符串的指针,具体来说，strcmp 的参数类型是 const char *
- 因为 p2 末尾没有 \0，strcmp 将会读取 p0 的 \0 之前的所有字符，以及之后 p2 后的字符，直到找到 \0。所以
对应的值是一个随机值，所以strcmp的返回值也是一个随机的值,编译器运行后是-72
- sizeof(p0)求出的是字符串包含\0的大小 12
- sizeof(p1)求出的指针的大小,对应64位系统上是8
- *p2表示字符数组的第一个元素,sizeof(*p2)求出的是一个字符的大小 1个字节
- strlen函数计算字符串长度且不计\0，所以都为11



## 3. 换个变量名不行吗？

请结合本题，分别谈谈你对C语言中「全局变量」和「局部变量」的「生命周期」理解。

```c
int a = 3;
void test() {
    int a = 1;
    a += 1;
    {
        int a = a + 1;
        printf("a = %d\n", a);
    }
    printf("a = %d\n", a);
}
int main(void) {
    test();
    printf("a= %d\n", a);
}
```


>生命周期描述了变量从创建到销毁的整个过程。不同类型的变量有不同的生命周期：
*全局变量*：在程序开始时分配内存，程序结束时释放内存，生命周期覆盖整个程序运行时间。
*局部变量*：在进入函数或代码块时分配内存，离开时释放内存，生命周期只在该函数或代码块的执行期间存在。
全局变量 a 在函数中仍然是可以访问的，但由于局部变量的作用域优先于全局变量，因此在函数内部，如果定义了一个同名的局部变量，就会遮蔽  即在函数内部，局部变量会优先被使用

- 打印的第一个a，在{}内，未被定义，所以输出随机值
- 第二个a的值的生命周期在test函数中，所以为2；- 打印的第三个a是全局变量，为3
【主函数是可以访问全局变量的，只要没有遮蔽的局部变量，前面函数内定义的a在函数外生命周期不存在】。



## 4. 内存对不齐

`union`与`struct`各有什么特点呢，你了解他们的内存分配模式吗。

```c
typedef union {
    long l;
    int i[5];
    char c;
} UNION;
typedef struct {
    int like;
    UNION coin;
    double collect;
} STRUCT;
int main(void) {
    printf("sizeof (UNION) = %zu\n", sizeof(UNION)); 
    printf("sizeof (STRUCT) = %zu\n", sizeof(STRUCT));
}
```
>首先,union 和 struct 是 C 语言中用于组织数据的复合数据类型

struct 的特点

    内存分配:
        struct 中的每个成员都有独立的内存空间，所有成员的总大小是各个成员大小的总和，并可能因为对齐要求而增加。

    用途:
        适合用来表示一个复合数据结构，比如一个学生的记录（姓名、年龄、成绩等）。

    成员访问:
        所有成员可以同时存在并被独立访问，修改一个成员不会影响其他成员。
union 的特点

    内存分配:
        union 中的所有成员共享同一块内存，union 的大小为最大成员的大小。这意味着在任意时刻只能存储一个成员的值。

    用途:
        适合用于需要节省内存的场景，例如表示一个变量可以是多种类型中的一种（例如整数或浮点数）。

    成员访问:
        访问某个成员会覆盖其他成员的值，因为它们共享同一内存空间。

- UNION 的大小由其最大成员决定。在这里，最大成员是 int i[5]（20 字节），而 long l 通常是 8 字节。所以 sizeof(UNION) 将是 20 字节。
> 但是，由于内存对齐的原因，联合体的大小可能会被填充到某个边界。通常，联合体的大小会是其最大成员大小的倍数，通常是 8 字节或 4 字节。为了保持对齐，UNION 的最终大小会是 24 字节（20 字节加上 4 字节的填充）。
- 结构体所占内存为各成员总和:4+24+8=36
由于内存对齐,结构体应该对齐变为8的倍数,40
所以输出数字分别为:24  40





## 5. Bitwise

- 请使用纸笔推导出程序的输出结果。
- 请谈谈你对位运算的理解。

```c
int main(void) {
    unsigned char a = 4 | 7;
    a <<= 3;
    unsigned char b = 5 & 7;
    b >>= 3;
    unsigned char c = 6 ^ 7;
    c = ~c;
    unsigned short d = (a ^ c) << 3;
    signed char e = -63;
    e <<= 2;
    printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, (char)d);
    printf("e: %#x\n", e);
}
```
1. 4的二进制表示是100，7的二进制表示是111，按位或结果为111即7。
a左移3位，就是111000，乘以2^3=8,等于56
2. 5&7是按位与运算。
然后向右移动3位
3. 6^7 是按位异或运算。
之后再取反
4.先按位异或操作,再左移 

## 6. 英译汉

请说说下面数据类型的含义，谈谈`const`的作用。
1. `char *const p`。
2. `char const *p`。
3. `const char *p`。
- const关键字用于指示数据不能被修改
- 使用const可以明确哪些变量是不可变的

1. char *const p是const指针，即该指针只能指向该地址
2. char const *p; 和 const char *p  两者都表示指向const char的指针,表示一个指向不可修改字符的指针
(也即无法通过该指针改变所指地址的值。)

## 7. 汉译英

请用变量`p`给出下面的定义:
1. 含有10个指向`int`的指针的数组。
2. 指向含有10个`int`数组的指针。
3. 含有3个「指向函数的指针」的数组，被指向的函数有1个`int`参数并返回`int`。
1.int *p[10]
2.int (*p)[10]
3.int (*p[3])(int)

## 8. 混乱中建立秩序

你对排序算法了解多少呢?  
请谈谈你所了解的排序算法的思想、稳定性、时间复杂度、空间复杂度。

提示：动动你的小手敲出来更好哦~

冒泡排序
```
void bubblesort(int* arr, int n)
{
int flag = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)break;
	}
}
```
选择排序
```
void selectionsort(int* arr, int n)
{
	int min = arr[0];
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n ; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
				flag = 1;
			}
			int temp;
			if (i != min) {
				temp = arr[j];
				arr[j] = arr[min];
				arr[min] = temp;
			}
		}
		if (flag == 0)break;
	}
}
```
插入排序
```
void insertionsort(int *arr,int n)
{
    int temp;
    for(int i = 0;i <= n;i++)
    {
        int j = i - 1;
        temp = arr[i];
        while(arr[j] > temp && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
 
}
```


## 9. 手脑并用

请实现ConvertAndMerge函数：  
拼接输入的两个字符串，并翻转拼接后得到的新字符串中所有字母的大小写。

提示:你需要为新字符串分配空间。

```c
char* convertAndMerge(/*补全签名*/);
int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
```
>字符串函数的使用
```
#include <stdio.h>
#include <string.h>
char *convertAndMerge(char strs[2][20])
{
    char *arr = (char *)malloc(sizeof(char) * 40);
    strcpy(arr, strs[0]);
    strcat(arr, strs[1]);
    int len = strlen(strs[0]) + strlen(strs[1]);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            arr[i] += 32;
        else if (arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] -= 32;
    }
    return arr;
}
int main(void)
{
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
```

## 10. 给你我的指针，访问我的心声

程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv) {
    int arr[5][5];
    int a = 0;
    for (int i = 0; i < 5; i++) {
        int *temp = *(arr + i);
        for (; temp < arr[5]; temp++) *temp = a++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
}
```
考点是赋值会覆盖
程序输出为

    0 1 2 3 4
    25 26 27 28 29
    45 46 47 48 49
    60 61 62 63 64
    70 71 72 73 74

- 程序通过temp指针给二维数组赋值，for循环中temp<arr[5]，所以第一次赋值时给整个数组赋值，从a[0][0]到a[4][4]
- 之后从a[1][0]到a[4][4],前面的一些赋值会被后面的数值覆盖，所以数值不连续。

## 11. 奇怪的参数

你了解argc和argv吗？  
直接运行程序argc的值为什么是1？  
程序会出现死循环吗？

```c
#include <stdio.h>
int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    while (1) {
        argc++;
        if (argc < 0) {
            printf("%s\n", (char *)argv[0]);
            break;
        }
    }
}
```
- argc是参数个数，argv是指向字符的指针数组

- argc的最小值为1,因为程序执行时至少会有一个参数，即程序本身的名称
此时的argv[0]是程序的启动路径/名称。
- 程序不会死循环，在c语言中,int类型通常是有符号的
在自增的时候,argc的值会溢出，变成一个负值,然后打印出argv的值。

## 12. 奇怪的字符

程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv) {
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *)data1;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);//Welcome to Xiyou Lin
    strcat(buf, b);//ux Group 2022
    printf("%s \n", buf);
}
```
输出Welcome to Xiyou Linux Group 2022
考察大小端
- 大小端是指在计算机存储多字节数据（如整数、浮点数等）时，字节的顺序。主要有两种类型：大端和小端。
- 大端（存储）模式：是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中
- 小端（存储）模式:是指数据的低位保存在内存的低地址中，而数据的高位，保存在内存的高地址中
> strcpy 是 C 语言中的一个标准库函数，用于将一个字符串复制到另一个字符串
strcat 是 C 语言中的一个标准库函数，用于将一个字符串附加到另一个字符串的末尾
- 十六进制数,被强制类型转化为字符
在处理多字节数据（如整数）时，按照字节的顺序逐个获取字节
参照ASCII码表，得出结果正是输出值。

## 13. 小试宏刀

- 请谈谈你对`#define`的理解。
- 请尝试着解释程序的输出。

```c
#define SWAP(a, b, t) t = a; a = b; b = t
#define SQUARE(a) a *a
#define SWAPWHEN(a, b, t, cond) if (cond) SWAP(a, b, t)
int main() {
    int tmp;
    int x = 1;
    int y = 2;
    int z = 3;
    int w = 3;
    SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    if (x>y) SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);
    printf("x = %d, y = %d\n", x, y, tmp);
    printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);
}
```
- 宏定义是预处理命令的一种，在被预处理时是直接的文本替换，要注意括号的使用

- 宏定义中,第一个就是交换a,b的值,第三个的意思是,条件为真的时候,交换a和b的值
其中,SQUARE(1 + 2 + z++ + ++w) == 100,因为是直接文本替换,所以条件为假,不进行交换.
- if后跟的t = a; a = b; b = t,由于没有加大括号,所以无论如何,a=b和b=t都会执行!
- 因为是SQUARE(a) a *a,执行了两遍,所以z和w都变为5
最后输出:
x = 2, y = 1, tmp = 1
x = 1, y = 2, tmp = 2
x = 2, y = 2
z = 5, w = 5, tmp = 2

## 14. GNU/Linux命令 (选做)

你知道以下命令的含义和用法吗：

注：
嘿！你或许对Linux命令不是很熟悉，甚至你没听说过Linux。  
但别担心，这是选做题，不会对你的面试产生很大的影响！  
了解Linux是加分项，但不了解也不扣分哦！
- `ls`
- `rm`
- `whoami`

请问你还了解哪些GNU/Linux的命令呢。

>ls:这个命令可以帮助用户查看当前目录或指定目录中的内容
rm:用于删除文件和目录的命令。这个命令是非常强大的，因此使用时需要小心，因为删除的文件通常无法恢复

ls命令是list的缩写，用来打印当前目录的清单。可以列出目录的内容，包括文件和子目录的名称。

ls                查看当前目录下的所有目录和文件
ls -a            查看当前目录下的所有目录和文件（包括隐藏的文件）
ls -l 或 ll       列表查看当前目录下的所有目录和文件（列表查看，显示更多信息）
ls /dir            查看指定目录下的所有目录和文件   如：ls /usr

\bullet l/指根目录，即所有目录最顶层的目录

\bullet ～表示主目录，也就是当前登陆用户的用户目录

\bullet ..表示上级目录

\bullet ./表示当前目录

\bullet rwx为“read write execute”的缩写，即对文件查看，编辑（移动，新建，修改，删除），运行该文件和目录。

其他：

\bullet cd 目录

cd /        切换到根目录
cd /usr        切换到根目录下的usr目录
cd ../        切换到上一级目录 或者  cd ..
cd ~        切换到home目录
cd -        切换到上次访问的目录

