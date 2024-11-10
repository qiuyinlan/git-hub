

```
Copyright © 2024 西邮Linux兴趣小组, All Rights Reserved. 本试题使用采用知识共享 署名-非商业性使用-相同方式共享 4.0 国际许可协议 (CC BY-NC-SA 4.0) 进行许可。
```

# ==西邮Linux兴趣小组 2024 纳新面试题==

>解释学长寄语 ：长期以来，西邮Linux兴趣小组的面试题以难度之高名扬西邮校内。我们作为出题人也清楚的知道这份试题略有难度。 请你动手敲一敲代码。 别担心，若有同学能完成一半的题目，就已经十分优秀。其次，相比于题目的答案，我们对你的思路和过程更感兴趣，或许你的答案略有瑕疵，但你正确的思路和对知识的理解足以为你赢得绝大多数的分数。最后，做题的过程也是学习和成长的过程，相信本试题对你更加熟悉地掌握C语言一定有所帮助。祝你好运。我们东区逸夫楼FZ103 见！本题目只作为西邮Linux兴趣小组 2024 纳新面试的有限参考。为节省版面，本试题的程序源码省去了#include指令。本试题中的程序源码仅用于考察C语言基础，不应当作为C语言「代码风格」的范例。所有题目编译并运行于x86_64 GNU/Linux环境。


## 0. 聪明的吗喽

 一个小猴子边上有 100 根香蕉，它要走过 50 米才能到家，每次它最多搬 50 根香蕉，（多了就

 拿不动了），它每走 1 米就要吃掉一根，请问它最多能把多少根香蕉搬到家里。

 （提示：他可以把香蕉放下往返的走，但是必须保证它每走一米都能有香蕉吃。也可以走到 n

 米时，放下一些香蕉，拿着n根香蕉走回去重新搬 50 根。）



## 1. 西邮Linux欢迎你啊

### 请解释以下代码的运行结果。

```
解释int main () {
unsigned int a = 2024 ;
for (; a >= 0 ; a--)
printf ("%d\n", printf ("Hi guys! Join Linux - 2%d", printf ("")));
return 0 ;
}
```
printf函数嵌套，先执行最里面的。printf“”什么都不打印，而printf函数返回值是0，所以前面对应输出20，即中间的printf函数%d被替换，打印Xiyou Linux Group - 20
而最外层的printf打印中间printf的返回值24,没有换行符，所以24就接着前面打印出来的
最后输出Xiyou Linux Group - 2024

>在c语言环境中，嵌套的printf函数是从内到外调用的顺序来执行，这样保证在进行格式化输出的时候，所有参数都已经计算完毕。

## 2. 眼见不一定为实

### 输出为什么和想象中不太一样？

### 你了解sizeof()和 strlen ()吗？他们的区别是什么？

```
解释int main () {
char p0[] = "I love Linux";
const char *p1 = "I love Linux\0 Group";
char p2[] = "I love Linux\0 ";
printf ("%d\n%d\n", strcmp (p0, p1), strcmp (p0, p2));
printf ("%d\n%d\n", sizeof(p0) == sizeof(p1), strlen (p0) == strlen (p1));
return 0 ;
}
```

>sizeof()是运算符，计算占空间字节数，计\0
>而strlen()是函数，计算字符串长度且不计\0
> strcmp是一个字符比较函数，读取到\0截止


1.strcmp读取到\0截止，所以p0和p1相等，返回0
2.p2,已经显式补了\0,所以p2不会再自动在字符串末尾补\0。而p0识别到字符串末尾的自动添加的\0那里，所以p0和p2也相等，返回0
3.sizeof(p0)返回数组p0的大小（包括空格），即13,sizeof(p1)返回指针p1的大小（在64位系统上为8，32位系统上为4）
二者不相等，逻辑判断表达式返回0,为假
4.strlen(p0)和strlen(p1)计算字符串长度，识别到\0截止，所以二者均返回12，因此strlen(p0)==strlen(p1)的结果为1
> 所以最终输出0001





## 3. 1.1 - 1.0 != 0.

### 为什么会这样，除了下面给出的一种方法，还有什么方法可以避免这个问题？

```
解释int main () {
float a = 1.0, b = 1.1, ex = 0.1;
printf ("b - a == ex is %s\n", (b - a == ex)? "true" : "false");
int A = a * 10 , B = b * 10 , EX = ex * 10 ;
printf ("B - A == EX is %s\n", (B - A == EX)? "true" : "false");
}
```
> 条件运算符?:
条件运算符为三目运算符，其运算方法如下
<表达式1>?<表达式2>:<表达式3>
首先对第一个表达式进行检验，若为真，则返回表达式2的值，若为假，则返回表达式3的值。

- 代码分析
    `1.b - a == ex：`
    由于浮点数运算的精度问题，b - a 的结果并不完全等于 0.1，返回的结果是 false。
    `2.B - A == EX：`
    这里将浮点数乘以 10 转换为整数，避开了浮点数精度的限制
            A = 1.0 * 10 = 10，B = 1.1 * 10 = 11，EX = 0.1 * 10 = 1。
            这里的比较应该返回 true，因为 11 - 10 == 1。

- 其他方法：
eg使用容差（Epsilon）比较
 使用一个很小的值（称为容差或 epsilon）来判断两个浮点数是否“足够接近”，而不是直接比较它们的值

 ```
 float epsilon = 0.0001;
if (fabs(b - a - ex) < epsilon) 
    printf("b - a is approximately equal to ex\n");
  将相减后的绝对值和这个极小值比较即可
```
 

## 4. 听说爱用位运算的人技术都不太差

### 解释函数的原理，并分析使用位运算求平均值的优缺点。

```
解释int average (int nums [], int start , int end ) {
if ( start == end )
return nums [ start ];
int mid = ( start + end ) / 2 ;
int leftAvg = average ( nums , start , mid);
int rightAvg = average ( nums , mid + 1 , end );
return (leftAvg & rightAvg) + ((leftAvg ^ rightAvg) >> 1 );
}
```
> start和end表示数组的起始索引和结束索引，start==end时，表示只有一个元素，所以直接返回nums[start]

> 有多个元素时，分为左半部分和右半部分调用递归函数，最后再将结果合并


优点：处理较大数的时候，位运算可以避免溢出，更高效
函数逻辑清晰异动
缺点：可读性较差




## 5. 全局还是局部!!!

### 先思考输出是什么，再动动小手运行下代码，看跟自己想得结果一样不一样 >-<

```
解释int i = 1 ;
static int j = 15 ;
int func () {
int i = 10 ;
if (i > 5 ) i++;
printf ("i = %d, j = %d\n", i, j);
return i % j;
}
解释int main () {
int a = func ();
printf ("a = %d\n", a);
printf ("i = %d, j = %d\n", i, j);
return 0 ;
}
```

> 全局和局部变量
- 全局变量：在所有函数之外定义的变量，整个程序都可以访问和使用。
- 局部变量：在函数内部定义的变量，只有函数内部才能访问。
- static关键字：用于定义变量和函数的存储方式和作用域
> 局部变量和全局变量名字相同，局部变量优先级更高。

> 详细分析：
第一个判断语句，由于 i 的值为 10，条件 i > 5 为真，因此执行 i++，i 的值变为 11。
`printf("i = %d, j = %d\n", i, j)`：打印当前局部变量 i 和静态全局变量 j 的值。输出为 i = 11, j = 15。
`return i % j`：返回 i 除以 j 的余数。这里 11 % 15 的结果是 11，因为 11 小于 15。
`int a = func()`：调用 func 函数，将其返回值赋给变量 a。a 的值为 11（从上面 func 函数返回的结果）。
``printf("a = %d\n", a)``：打印 a 的值，输出为 a = 11。
`printf("i = %d, j = %d\n", i, j)`：打印全局变量 i 和静态全局变量 j 的值。由于全局变量 i 的值仍然是 1，j 的值仍然是 15，因此输出为 i = 1, j = 15。
`return 0`：返回 0，表示程序正常结束。

所以最后输出的数字分别为：11 15 11 1 15

## 6. 指针的修罗场：改还是不改，这是个问题

### 指出以下代码中存在的问题，并帮粗心的学长改正问题。

``` c
解释int main (int argc , char ** argv ) {
int a = 1 , b = 2 ;
const int *p = &a;
int * const q = &b;
*p = 3 , q = &a;
const int * const r = &a;
*r = 4 , r = &b;
return 0 ;
}
```
> 考察关键字const与指针结合

代码分析：
```
int main(int argc, char **argv) {
    int a = 1, b = 2;
    const int *p = &a;       // 指向常量的指针，不能修改 *p 所指向的值
    int * const q = &b;      // 常量指针，不能修改 q 指向的地址
    *p = 3;                   // 错误：试图修改 const 指针所指向的值
    q = &a;                   // 错误：试图修改常量指针 q 的指向
    const int * const r = &a; // 常量指针，既不能修改指向的值，也不能修改指向的地址
    *r = 4;                   // 错误：试图修改 const 指针所指向的值
    r = &b;                   // 错误：试图修改常量指针 r 的指向
    return 0;
}
```
修改的代码：
```

int main(int argc, char **argv) {
    int a = 1, b = 2;
    const int *p = &a;          // p 可以指向 a，但不能修改 a
    int * const q = &b;         // q 是一个常量指针，可以通过它修改 b 的值
    *q = 3;                     // 通过常量指针 q 修改 b 的值为 3
    const int * const r = &a;   // r 是一个常量指针，既不能修改 r 的指向，也不能修改 r 指向的值
}
```

## 7. 物极必反？

### 你了解 argc 和 argv 吗，这个程序里的 argc 和 argv 是什么？

### 程序输出是什么？解释一下为什么。

```
解释int main (int argc , char * argv []) {
while ( argc ++ > 0 );
int a = 1 , b = argc , c = 0 ;
if (--a || b++ && c--)
for (int i = 0 ; argv [i] != NULL; i++)
printf ("argv[%d] = %s\n", i, argv [i]);
printf ("a = %d, b = %d, c = %d\n", a, b, c);
return 0 ;
}
```
- argc: argc 是一个整数，表示命令行参数的数量，argc 的值至少为 1，因为第一个参数总是程序自身的名称。
- argv: argv 是一个字符串数组（字符指针数组），每个元素都是一个命令行参数的字符串。argv[0] 是程序的名称，argv[1] 是第一个命令行参数，依此类推。最后一个元素通常是 NULL，用来标识数组的结束。
int的范围为-2,147,483,647—2,147,483,647。而argc在while循环中一直加到2,147,483,647后再加一，变成-2,147,483,647，退出循环对a，b，c进行运算并判断直到溢出,跳出while循环.if中条件为假,不执行for循环
- b是负数,为真,所以c进行自减操作,变为-1.右边最后为假,左边a进行执行,进行自减
- 最终,a为0，b为-2,147,483,646，c为-1


## 8. 指针？数组？数组指针？指针数组？

### 在主函数中定义如下变量：

```
解释int main () {
int a[ 2 ] = { 4 , 8 };
int(*b)[ 2 ] = &a;
int *c[ 2 ] = {a, a + 1 };
return 0 ;
}
```

### 说说输出分别是什么？

```
a, a + 1 , &a, &a + 1 , *(a + 1 ), sizeof(a), sizeof(&a)
*b, *b + 1 , b, b + 1 , *(*b + 1 ), sizeof(*b), sizeof(b)
c, c + 1 , &c, &c + 1 , **(c + 1 ), sizeof(c), sizeof(&c)
```
> 1.数组指针是指向数组的指针，本质是指针
2.指针数组是里面元素都是指针的数组本质是数组

- int(*b)[ 2 ] 是数组指针，因为[]的优先级比\*高，所以用括号括起来保证了b先和\*结合，使得其本质为指针
- int *c[ 2 ]是指针数组，c先和[]结合，则其本质为数组


1.第一行

- **`a`** 是一个数组名，指向数组的第一个元素的地址，即 `a[0]` 的地址。
- **`a + 1`** 指向的是 `a` 数组的第二个元素的地址，即 `a[1]` 的地址。
- **`&a`** 是 `a` 数组的地址，表示整个数组的首地址
- **`&a + 1`**：返回整个数组 a 后一个数组地址，类型为 int (*)[2]，即数组在内存中占用的字节数后的位置。
- **`*(a + 1)`** 解引用 `a + 1`，即读取 `a[1]` 的值。因为 `a[1]` 是 8，所以输出为 `8`。
- **`sizeof(a)`** 返回数组 `a` 的大小，`a` 是包含 2 个 `int` 的数组，因此 `sizeof(a)` 的值是 `2 * 4 = 8`（假设 `int` 为 4 字节）。
- **`sizeof(&a)`** 返回的是 `&a` 的大小，即数组的地址的大小。因为这是一个指向数组的指针，通常是 8 个字节（在 64 位系统上，指针大小通常为 8 字节）。

2.第二行
- **`*b`** 解引用 `b`，得到的是 `a` 数组的首地址，也就是 `a`，因此 `*b` 相当于 `a`。
- **`*b + 1`** 指向 `a` 数组的第二个元素的地址，即 `a[1]` 的地址（类似于 `a + 1` 的行为）。
- **`b`** 是指向数组的指针，所以 `b` 的值是 `a` 数组的首地址。
- **`b + 1`**，由于 `b` 是指向一个大小为 2 的 `int` 数组的指针，因此指针加 1 会跳过整个数组，也就是 `b + 1` 指向的是下一个数组的地址，类似于 `&a + 1`。
- **`*(*b + 1)`** 先解引用 `b`，然后对 `*b + 1` 进行解引用，得到 `a[1]` 的值，即 `8`。
- **`sizeof(*b)`** 是数组 `a` 的大小，因为 `*b` 实际上就是 `a` 数组，包含两个 `int`，因此 `sizeof(*b)` 为 `8`。
- **`sizeof(b)`** 返回的是指针 `b` 的大小，通常是 8 字节（64 位系统中）。
所以，第二行实质与第一行相同

3.第三行
- c：返回指向 c 数组首元素的地址，即 &c[0]，类型为 int **。
- c + 1：返回指向 c 数组第二个元素的地址，即 &c[1]。
- &c：返回指针数组 c 的地址，类型为 int (*)[2]。
- &c + 1：返回指向指针数组 c 后一个指针的地址，类型为 int (*)[2]。
- **(c + 1)：解引用 c + 1 得到 a + 1，再解引用得到 8（即 a[1]）。
- sizeof(c)：返回指针数组 c 的大小，通常为 16（在 64 位系统上，每个指针占 8 字节，共 2 个指针）。
- sizeof(&c)：返回指向指针数组的指针的大小，通常为 8（在 64 位系统上）。
## 9. 嘻嘻哈哈，好玩好玩

### 在宏的魔法下，数字与文字交织，猜猜结果是什么？

```
解释
#define SQUARE (x) x *x
#define MAX (a,b) (a > b)? a : b;
#define PRINT (x) printf ("嘻嘻，结果你猜对了吗，包%d滴\n", x);
#define CONCAT (a,b) a##b
int main () {
int CONCAT (x,1) = 5 ;
int CONCAT (y,2) = 3 ;
int max = MAX ( SQUARE (x1 + 1 ), SQUARE (y2))
PRINT (max)
return 0 ;
}
```


> 宏定义：
宏定义是预处理命令的一种,在被预处理时是直接替换（单纯的文本替换），所以一定要注意括号的使用。
1. **`define SQUARE(x) x * x`**
   - 这个宏定义是一个求平方的宏
   但注意此时没有加括号，如果是2+3就会被替换成2 + 3 * 2 + 3，会出现出现符号优先级的问题）

2. **`define MAX(a, b) (a > b) ? a : b`**
   - 这是一个条件选择的宏。用于返回两个值中的较大者，标准的三目运算符（注意，有可能出现符号优先级的问题）

3. **`define PRINT(x) printf("嘻嘻，结果你猜对了吗，包%d滴\n", x);`**
   - 这是一个打印宏，输出

4. **`define CONCAT(a, b) a##b`**
   - 这是宏拼接，它将 `a` 和 `b` 拼接成一个标识符。
   - 在 C 语言中，## 是一个预处理运算符，称为连接运算符（也叫“拼接运算符”或“令牌粘贴运算符”）。它用于将两个标识符或代码片段拼接成一个新的标识符或表达式，通常在宏定义中使用

宏展开分析
1. **`CONCAT(x, 1)`**
   - `CONCAT(x, 1)` 展开为 `x1`，因此定义了一个变量 `x1 = 5`。

2. **`CONCAT(y, 2)`**
   - `CONCAT(y, 2)` 展开为 `y2`，因此定义了一个变量 `y2 = 3`。

3. **`MAX(SQUARE(x1 + 1), SQUARE(y2))`**
   - 首先，`SQUARE(x1 + 1)` 展开为 `x1 + 1 * x1 + 1`，由于没有括号包裹整个表达式，这里会导致优先级错误：
     - 正确的期望应该是 `(x1 + 1) * (x1 + 1)`，但实际展开为 `x1 + (1 * x1) + 1`，即 `5 + (1 * 5) + 1 = 11`。
   - 然后，`SQUARE(y2)` 展开为 `y2 * y2`，正确计算为 `3 * 3 = 9`。
   - 最后，`MAX(11, 9)` 展开为 `(11 > 9) ? 11 : 9`，因此 `max = 11`。

4. **`PRINT(max)`**
   - `PRINT(max)` 展开为 `printf("嘻嘻，结果你猜对了吗，包%d滴\n", max);`，将输出 `11`。

- 所以输出结果是：
嘻嘻，结果你猜对了吗，包11滴

## 10. 我写的排序最快

### 写一个 your_sort 函数，要求不能改动 main 函数里的代码，对arr1和arr 2 两个数组进行升序

### 排序并剔除相同元素，最后将排序结果放入 result 结构体中。

```
int main () {
int arr1[] = { 2 , 3 , 1 , 3 , 2 , 4 , 6 , 7 , 9 , 2 , 10 };
int arr2[] = { 2 , 1 , 4 , 3 , 9 , 6 , 8};
int len1 = sizeof(arr1) / sizeof(arr1[ 0 ]);
int len2 = sizeof(arr2) / sizeof(arr2[ 0 ]);
解释result result;
your_sort (arr1, len1, arr2, len2, &result);
for (int i = 0 ; i < result.len; i++) {
printf ("%d ", result.arr[i]);
}
free (result.arr);
return 0 ;
}
```
大致思路：
1. 将两个数组合并。
2. 对合并后的数组进行排序。
3. 剔除重复元素。
4. 将结果存储在动态分配的数组中，并更新 `result` 结构体。

代码实现：

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;  // 动态分配的数组，用于存储排序后的结果
    int len;   // 数组长度
} result;

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // 用于qsort的比较函数
}

void your_sort(int *arr1, int len1, int *arr2, int len2, result *res) {
    // 分配足够的空间来存储两个数组合并后的结果
    int *merged = (int *)malloc((len1 + len2) * sizeof(int));
    int i, j = 0;

    // 先将两个数组合并到一起
    for (i = 0; i < len1; i++) {
        merged[j++] = arr1[i];
    }
    for (i = 0; i < len2; i++) {
        merged[j++] = arr2[i];
    }

    // 对合并后的数组进行排序
    qsort(merged, len1 + len2, sizeof(int), cmpfunc);

    // 剔除重复元素
    int *unique = (int *)malloc((len1 + len2) * sizeof(int));
    int unique_len = 0;
    unique[unique_len++] = merged[0];  // 第一个元素是必然的

    for (i = 1; i < len1 + len2; i++) {
        if (merged[i] != merged[i - 1]) {
            unique[unique_len++] = merged[i];
        }
    }

    // 将结果存入result结构体
    res->arr = (int *)malloc(unique_len * sizeof(int));
    for (i = 0; i < unique_len; i++) {
        res->arr[i] = unique[i];
    }
    res->len = unique_len;

    // 释放不需要的内存
    free(merged);
    free(unique);
}

int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    
    result res;
    your_sort(arr1, len1, arr2, len2, &res);

    for (int i = 0; i < res.len; i++) {
        printf("%d ", res.arr[i]);
    }

    free(res.arr);
    return 0;
}
```

 解释：
1. **`cmpfunc`** 是用于 `qsort` 函数的比较函数，用于升序排列数组元素。
2. **`your_sort` 函数**首先将 `arr1` 和 `arr2` 合并成一个大数组，然后使用 `qsort` 对其排序。接着，循环遍历该排序后的数组，剔除重复元素，将唯一元素存入新的数组 `unique` 中。
3. 结果存入 `result` 结构体，并在主函数中打印出来。



## 11. 猜猜我是谁

### 在指针的迷宫中，五个数字化身为神秘的符号，等待被逐一揭示。

```
解释int main () {
void *a[] = {(void *) 1 , (void *) 2 , (void *) 3 , (void *) 4 , (void *) 5 };
printf ("%d\n", *((char *)a + 1 ));
printf ("%d\n", *(int *)(char *)a + 1 );
printf ("%d\n", *((int *)a + 2 ));
printf ("%lld\n", *((long long *)a + 3 ));
printf ("%d\n", *((short *)a + 4 ));
return 0 ;
}
```
printf("%d\n", *((char *)a + 1));

    (char *)a 将 a 转换为 char *。a 是一个指针数组，每个元素的大小是 sizeof(void *)（在 64 位系统上通常是 8 字节）。
    *((char *)a + 1) 意味着访问数组 a 中偏移量为 1 的字节，但这并不会直接指向第二个元素的值。它实际上是在访问 a 数组中的第二个字节的值，而不是第一个元素的值。
    在内存中，1 的字节表示为 0x01，所以这里获取的是 0。
    输出: 0。

printf("%d\n", *(int *)(char *)a + 1);

    (char *)a 将 a 转换为 char *，取出 a 的首地址并将其转为 int *。
    *(int *)(char *)a 意味着取出指向的地址中的整数值，虽然这里 a[0] 是 1，但由于我们进行的是指针转换，所以它会取出指针的字节，实际上取出的地址是 1。
    结果为 1 + 1，所以输出是 2。
    输出: 2。

printf("%d\n", *((int *)a + 2));

    (int *)a 将 a 转换为 int *，并通过索引访问第三个元素（索引为 2），即 (void *)3 的地址。
    由于 void * 是被直接存储的，所以 *((int *)a + 2) 取出的是 3，但由于测试中假设了输出的内容，所以这里实际上取到的是 2。
    输出: 2。

printf("%lld\n", *((long long *)a + 3));

    (long long *)a 将 a 转换为 long long *，并访问第四个元素（索引为 3），即 (void *)4。
    输出: 4。

printf("%d\n", *((short *)a + 4));

    (short *)a 将 a 转换为 short *，并通过偏移访问第五个元素（索引为 4），即 (void *)5。
    由于 void * 是指向的存储，所以最后的结果为 2。
    输出: 2。

最后输出结果 0 2 2 4 2



## 12. 结构体变小写奇遇记

### 计算出 Node 结构体的大小，并解释以下代码的运行结果。

```
解释union data {
int a;
double b;
short c;
};
typedef struct node {
long long a;
union data b;
void (*change)( struct node *n);
char string[ 0 ];
} Node ;
void func ( Node * node ) {
for (size_t i = 0 ; node - >string[i] != '\ 0 '; i++)
node - >string[i] = tolower ( node - >string[i]);
}
int main () {
const char *s = "WELCOME TO XIYOULINUX_GROUP!";
Node *P = ( Node *) malloc (sizeof( Node ) + ( strlen (s) + 1 ) * sizeof(char));
strcpy (P->string, s);
P->change = func ;
P-> change (P);
printf ("%s\n", P->string);
return 0 ;
}
```
在 64 位系统上，Node 结构体的大小计算如下：

    sizeof(long long) = 8
    sizeof(union data) = 8
    sizeof(void *) = 8（假设为 64 位系统）
结构体大小：Node 的大小为 8 + 8 + 8 = 24 bytes
- Node *P = (Node *)malloc(sizeof(Node) + (strlen(s) + 1) * sizeof(char));
- malloc在堆区为Node和柔性数组开辟空间
- strcpy(P->string, s);将字符串s复制到柔性数组P->string中
- P->change = func;改变了函数指针change的指向，使其指向func()
- P->change(P);调用P->change指向的函数func(),在func()中用tolower将大写转换为小写
- 最后printf打印:welcome to xiyoulinux_group!








## 13. GNU/Linux (选做)

### 注：嘿！你或许对Linux命令不是很熟悉，甚至没听说过Linux。

### 但别担心，这是选做题，了解Linux是加分项，不了解也不扣分哦！

```
你知道 ls 命令的用法与 /. ~ 这些符号的含义吗？
你知道 Linux 中权限 rwx 的含义吗？
请问你还懂得哪些与 GNU/Linux 相关的知识呢~
```

 **1. `ls`命令的用法**

`ls` 是 Linux 中用于列出目录内容的命令，显示文件和目录的名称。它有很多选项可以调整输出格式或显示详细信息。常见用法如下：

- **`ls`**：列出当前目录的文件和目录。
  
- **`ls /path/to/directory`**：列出指定路径下的文件和目录。

- **`ls -l`**：显示文件详细信息（如权限、所有者、大小、修改时间等）。

- **`ls -a`**：显示所有文件，包括隐藏文件（以`.`开头的文件）。

- **`ls -h`**：将文件大小以可读格式显示（比如 KB、MB 而不是字节）。

- **`ls -lh`**：组合选项，显示详细信息并且以可读格式显示文件大小。

- **`ls -R`**：递归列出所有子目录的内容。

- **`ls -t`**：根据修改时间排序。

 **2. `/.`、`~/` 等符号的含义**

这些符号表示不同的路径概念：

- **`/`**：根目录，所有文件系统的起点。在 Linux 中，一切都在根目录之下，类似 Windows 的 C:\。

- **`.`**：当前目录。比如，`./file` 表示当前目录下的文件`file`。

- **`..`**：上一级目录。比如，`../` 表示当前目录的上一级目录。

- **`~`**：用户的主目录。每个用户在系统中都有自己的主目录，通常在 `/home/username/` 下。
  - 例如：`~/Documents` 表示当前用户主目录下的 `Documents` 目录。

- **`/.`**：根目录的当前目录。因为根目录本身就是最高层级，所以它通常没有实际用途。

**3. Linux 中权限 `rwx` 的含义**

在 Linux 文件系统中，每个文件或目录都有一组权限，分为**三种类型**的权限，并且权限可以分配给**三个级别**的用户（所有者、组、其他人）。

 **权限类型**
- **`r`（read）**：读权限，表示可以查看文件内容或列出目录内容。
- **`w`（write）**：写权限，表示可以修改文件内容或在目录中创建、删除文件。
- **`x`（execute）**：执行权限，表示可以执行文件（如果是脚本或程序），或者进入目录（目录的执行权限允许进入目录）。

 **权限分配的三种级别**
- **文件所有者**（`user`）：文件的创建者或指定的用户。
- **所属组**（`group`）：与文件或目录相关联的用户组。组内的用户共享这些权限。
- **其他人**（`others`）：系统上的其他所有用户。

 **权限表示法**
每个文件或目录的权限由10个字符表示。以`ls -l`显示的结果为例：

```
-rwxr-xr--
```

- 第一个字符表示文件类型：`-`表示普通文件，`d`表示目录。
- 后面的九个字符分成三组，每组三个字符，分别代表**所有者**、**组**和**其他人**的权限：
  - `rwx`：所有者的权限，读、写、执行权限。
  - `r-x`：组的权限，读和执行权限，但没有写权限。
  - `r--`：其他人的权限，只有读权限。

 **修改权限**
使用 `chmod` 命令可以修改文件或目录的权限。例如：

- **`chmod 755 filename`**：将文件的权限设置为 `rwxr-xr-x`，即所有者有读、写、执行权限，组和其他人只有读和执行权限。

 **总结**
- `ls`命令列出目录内容，可以通过选项显示更多详细信息。
- `/` 是根目录，`.` 表示当前目录，`~` 表示主目录，`..` 表示上一级目录。
- `rwx` 权限代表读、写、执行，分别作用于文件所有者、组和其他人，决定文件或目录的可访问性和操作权限。



#### 恭喜你成功完成了所有挑战！(^▽^)/！这是一项了不起的成就。

```
无论结果如何，相信这个过程已经让你对 C 语言和 Linux 有了更深入的了解。
记住，编程是一个持续学习的过程。
唯有脚踏实地，笃行不怠，方能拨云雾而见青天！
```

