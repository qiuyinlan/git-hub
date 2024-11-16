

```
Copyright © 202 3 西邮Linux兴趣小组, All Rights Reserved. 本试题使用采用知识共享署名-非商业性使用-相同方式共享4.0 国际许可协议(CC BY-NC-SA 4.0)进行许可。
```

# 西邮Linux兴趣小组 2023 纳新面试题

```
解释①本题目只作为西邮Linux兴趣小组 2023 纳新面试的有限参考。
②为节省版面，本试题的程序源码省去了#include指令。
③本试题中的程序源码仅用于考察C语言基础，不应当作为C语言「代码风格」的范例。
④所有题目编译并运行于x86_64 GNU/Linux环境。
```

## 0.鼠鼠我啊，要被祸害了

### 有 1000 瓶水，其中有一瓶有毒，小白鼠只要尝一点带毒的水， 24 小时后就会准时死亡。

### 至少要多少只小白鼠才能在 24 小时内鉴别出哪瓶水有毒？

10瓶。
- 1000 可以用二进制表示为 10 位,1和0就可以表示死亡情况( 2^9 = 512 )，不够.2^10 = 1024 ，够
所以每一瓶水都可以标一个二进制的编号,2的十次方是1024
- 小白鼠按照编号,喝水.1表示喝了0表示没喝
24小时之后,根据10只小鼠的死亡情况可以得出喝了or没喝--即得出编码,then根据瓶子的编码判断哪瓶水有毒
## 1.先预测一下~

### 按照函数要求输入自己的姓名试试~

```
char *welcome() {
// 请你返回自己的姓名
}
int main(void) {
char *a = welcome();
printf("Hi, 我相信 %s 可以面试成功!\n", a);
return 0 ;
}
```
- 在welcome函数里面,然而return自己的姓名即可
> (在使用 %s 打印字符串时，不需要解引用指针 a，因为 %s 期望的是一个指向字符的指针，而不是字符本身)
```
char *welcome() {
return xxx;
}
int main(void) {
char *a = welcome();
printf("Hi, 我相信 %s 可以面试成功!\n", a);
return 0;
}
```

## 2.欢迎来到Linux兴趣小组

### 有趣的输出，为什么会这样子呢~

```
解释int main(void) {
char *ptr0 = "Welcome to Xiyou Linux!";
char ptr1[] = "Welcome to Xiyou Linux!";
if (*ptr0 == *ptr1) {
printf("%d\n", printf("Hello, Linux Group - 2 %d", printf("")));
}
int diff = ptr0 - ptr1;
printf("Pointer Difference: %d\n", diff);
}
```
- if语句比较了两个字符数组的首元素值，W=W，所以执行语句
- printf函数嵌套，先执行括号里的，所以最里面的括号里的先执行,
什么也不打印，返回0，
- 然后中层的printf打印双引号里的字符并将占位符%d替换为里面函数的返回值0。
- 最后，最外面的printf函数打印中间函数的返回值23。
> 最后结果就为“Hello, LinuxGroup - 2023"。

最后一个printf打印两个地址之差，由于不指向同一个数组，是未定义行为,会随机输出值.
>在c语言环境中，嵌套的printf函数是从内到外调用的顺序来执行，这样保证在进行格式化输出的时候，所有参数都已经计算完毕。

## 3.一切都翻倍了吗

### ①请尝试解释一下程序的输出。

### ②请谈谈对 sizeof ()和strlen()的理解吧。

### ③什么是sprintf()，它的参数以及返回值又是什么呢？

```
解释int main(void) {
char arr[] = {'L', 'i', 'n', 'u', 'x', '\ 0 ', '!'}, str[ 20 ];
short num = 520 ;
int num2 = 1314 ;
解释printf("%zu\t%zu\t%zu\n", sizeof (*&arr), sizeof (arr + 0 ),
sizeof (num = num2 + 4 ));
printf("%d\n", sprintf(str, "0x%x", num) == num);
printf("%zu\t%zu\n", strlen(&str[ 0 ] + 1 ), strlen(arr + 0 ));
}
```
> sizeof运算符计算占空间字节数,strlen函数计算字符串长度且不计\0
sizeof是运算符，strlen是函数，sizeof 参数可以是数据类型、变量,streln接收的参数是字符指针
程序输出:
```
7       8       2
0
4       5
```
> #数组与指针(if表示第一个元素关系) arr大多数情况下会退化成指向数组第一个元素的指针,但在特殊情况下,如sizeof和取地址操作,会保持原本的数组类型

1. &arr代表整个数组的地址,*&arr表示再解引用,得到整个数组arr,所以sizeof(arr)是7
在 C 语言中，如果用字符数组初始化的方式定义 char arr[] = {'L', 'i', 'n', 'u', 'x', '\0', '!'}，编译器不会自动在末尾添加 '\0'，所以是7个字节,输出7
2. 在表达式中,arr大多是情况会退化为指向数组首元素的指针,所以sizeif(arr+0)中arr表示指针,指针在64系统中,占用字节数为8
3. 第三个打印里面整个表达式的结果占字节数，结果num是short int 类型，所以为2。
第二行printf函数打印sprintf函数的返回值与num相等是否为真的值。
sprintf函数至少有两个参数，若有三个，则第二个参数中有转换说明，这个sprintf函数将num的值拷贝到str数组里，然后返回拷贝的字符数，为3，与520不相等，所以printf函数打印0;
4. 第三行，strlen函数与sizeof运算符不同的是，strlen函数接收地址，printf函数第一个参数为str从第二个元素开始计算的字符串长度，为4,第二个参数为从第一个元素开始，为5。


## 4.奇怪的输出

### 程序的输出结果是什么？解释一下为什么出现该结果吧~

```
解释int main(void) {
char a = 64 & 127 ;
char b = 64 ^ 127 ;
char c = - 64 >> 6 ;
char ch = a + b - c;
printf("a = %d b = %d c = %d\n", a, b, c);
printf("ch = %d\n", ch);
}
```
- &运算符是同位都为1才是1其他情况都是0
- ^运算符是同位相同则为1,不同则为0
- 右移运算符，各二进位全部右移若干位，无符号数高位补0，负数高位补1 

位运算，第一行为a,b,c三个位运算之后的值，分别为64,63,-1，
- char c = -64 >> 6;
-64 的二进制表示为补码。在 8 位系统中，-64 是 11000000。

右移 6 位会将 11000000 变为 11111111（在有符号右移时，符号位填充）。
因此，c 的值为 -1（即 11111111） 在补码中表示
-  ch：因为是char类型，它的符号位是第八位，127原码为01111111,1的原码为00000001,相加后为10000000,为-128的原码，所以答案为-128

## 5.乍一看就不想看的函数

#### “人们常说互联网凛冬已至，要提高自己的竞争力，可我怎么卷都卷不过别人，只好用一些奇技淫巧让我的代码变得高深莫测。”
 这个func()函数的功能是什么？是如何实现的？

```
解释int func(int a, int b) {
if (!a) return b;
return func((a & b) << 1 , a ^ b);
}
int main(void) {
int a = 4 , b = 9 , c = - 7 ;
printf("%d\n", func(a, func(b, c)));
}
```
打印出的值为6。
- func函数的功能是将传入的两个参数相加并返回相加结果
> if (!a) return b;：如果 a 为 0，直接返回 b。这是因为任何数加 0 等于它本身。
> 如果a不是0,
通过函数递归和位运算使得倒数第二次函数调用时第一个参数为零，第二个参数为初始两参数和。在最后一次调用里返回两初始参数和。
该函数涉及使用位运算实现加法,递归情况：
eturn func((a & b) << 1, a ^ b);：
 a & b：计算 a 和 b 的位与运算，得到的结果是所有相同位为 1 的部分（即进位）。
 (a & b) << 1：将进位左移一位，以便在下一次递归中加到正确的位置。
 a ^ b：计算 a 和 b 的位异或运算，得到不考虑进位的结果。
 func((a & b) << 1, a ^ b)：递归调用 func，将进位和当前的和作为新的参数继续计算。

## 6.自定义过滤

### 请实现filter()函数：过滤满足条件的数组元素。

#### 提示：使用函数指针作为函数参数并且你需要为新数组分配空间。

```
解释typedef int (*Predicate)(int);
int *filter(int *array, int length, Predicate predicate,
int *resultLength); /*补全函数*/
int isPositive(int num) { return num > 0 ; }
int main(void) {
int array[] = {- 3 , - 2 , - 1 , 0 , 1 , 2 , 3 , 4 , 5 , 6 };
int length = sizeof (array) / sizeof (array[ 0 ]);
int resultLength;
int *filteredNumbers = filter(array, length, isPositive,
&resultLength);
for (int i = 0 ; i < resultLength; i++) {
printf("%d ", filteredNumbers[i]);
}
printf("\n");
free(filteredNumbers);
return 0 ;
}

```
如下:
```
typedef int (*Predicate)(int);//定义一个函数指针类型
int* filter(int* array, int length, Predicate predicate,//传参时通过函数指针传递回调函数
	int* resultLength)/*补全函数*/
{
	int x = 0;//新数组的下标
	int *filteredNumbers = (int*)malloc(10 * sizeof(int));//为新数组分配空间
	for (int j = 0; j <= length; j++)//遍历原数组
		if (predicate(array[j]))//过滤条件
		{
			filteredNumbers[x] = array[j];//符合条件的原数组被填入新数组
			x++;//指向新数组下一个元素
		}
*resultLength=x;//通过指针将新数组长度传递给主函数
return  filteredNumbers;
}
int isPositive(int num) { return num > 0;}
int main(void) {
	int array[] = { -3, -2, -1, 0, 1, 2, 3, 4, 5, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	int resultLength;
	int* filteredNumbers = filter(array, length, isPositive,
		&resultLength);
	for (int i = 0; i < resultLength; i++) {
		printf("%d ", filteredNumbers[i]);
	}
	printf("\n");
	free(filteredNumbers);//释放动态分配的空间
	return 0;
}
```
在这个函数实现时，我们将ispositive函数作为参数传递给filter函数，需要使用回调函数，通过函数指针来传递函数



## 7.静...态...

### ①如何理解关键字static？

### ②static与变量结合后有什么作用？

### ③static与函数结合后有什么作用？

### ④static与指针结合后有什么作用？

### ⑤static如何影响内存分配？

1. 生命周期描述了变量从创建到销毁的整个过程。不同类型的变量有不同的生命周期
  static关键字可以将变量静态化，以static关键字修饰的值会被存储在静态区。生命周期会延长到整个程序。
2. 与局部变量结合可以使它的生命周期扩展到整个程序。
与全局变量结合会让全局变量的链接属性改变，使它的作用域变小到本文件。
3. 与函数结合也会使函数的链接属性改变，使其不能在其他文件中被调用。
4. static 关键字本身并不直接影响指针，但可以与指针类型结合使用.使用指针指向静态变量，可以在多个函数中访问该变量，而不需要传递它的值。
5. 使用 static 定义的变量在静态存储区中分配内存，而不是在栈或堆中。
静态存储区：包含所有静态变量、全局变量和常量，其生命周期与程序的运行周期相同。静态变量在程序启动时分配内存，并在程序结束时释放，不管变量是在函数内还是外定义。

## 8.救命！指针！

### 数组指针是什么？指针数组是什么？函数指针呢？用自己的话说出来更好哦，下面数据类型的含义都是什么呢？

```
int (*p)[ 10 ];
const int* p[ 10 ];
int (*f1(int))(int*, int);
```
- 数组指针是指向数组的指针，本质是指针
- 指针数组是里面元素都是指针的数组,本质是数组
- 函数指针是指向函数的指针,本质是指针
- 第一个是数组指针，因为[]的优先级比\*高，所以用括号括起来保证了p先和\*结合，使得其本质为指针，但是指向一个有十个int类型元素的数组 
- 第二个是指向const的指针数组，p先和[]结合，则其本质为数组，数组有十个元素，包含 10 个指向 const int 的指针，即指向的值无法被改变的指针。
- 第三个是一个函数指针，函数名为fl,这个函数指针指向的函数是返回值为int，两个参数第一个是int类型指针，第二个是int的类型。
函数指针：指向特定函数类型的指针，允许通过指针调用该函数。

## 9.咋不循环了

### 程序直接运行，输出的内容是什么意思？

```
解释int main(int argc, char* argv[]) {
printf("[%d]\n", argc);
while (argc) {
++argc;
}
int i = - 1 , j = argc, k = 1 ;
i++ && j++ || k++;
printf("i = %d, j = %d, k = %d\n", i, j, k);
return EXIT_SUCCESS;
}
```

> argc被程序唤起的命令行参数的数量，用于统计参数数量.argc的最小值为1,因为程序执行时至少会有一个参数，即程序本身的名称
argc是参数个数，argv 实际上是一个数组，其中的每个元素都是一个指向字符串（字符数组）的指针，这些字符串通常是命令行参数.由于 C 语言的命令行参数传递机制，argv 数组的最后一个元素是 NULL，用来标识数组的结束。

> 短路与&&在前面的表达式为假时，不会计算后面的表达式，
短路或||在前面的表达式为真时，不会计算后面的表达式。

输出分析
这个 while 循环的目的是使 argc 变为 0。循环会不断增加 argc 的值，直到其为 0。在这里，由于 argc 最开始是 1，循环执行一次后将其变为 2，然后执行到 3，最后达到 0 时退出循环。这是人为的
分析i，j，k的值，++和--++和--的运算符优先级 高于&&和||，
所以i的值先使&&短路，然后i增为0
而j的值因为argc溢出变为零，并且先因为短路而保持不变,表达式执行后,自增为1
因为i为假,所以||没有短路，k之后也递增，j为1,k为2。

## 10.到底是不是TWO

```
解释#define CAL(a) a * a * a
#define MAGIC_CAL(a, b) CAL(a) + CAL(b)
int main(void) {
int nums = 1 ;
if ( 16 / CAL( 2 ) == 2 ) {
printf("I'm TWO(ﾉ>ω<)ﾉ\n");
} else {
int nums = MAGIC_CAL(++nums, 2 );
}
printf("%d\n", nums);
}
```
> 宏定义
宏定义是预处理命令的一种,在被预处理时是直接的文本替换，所以一定要注意括号的使用。

- if语句中，16/2×2×2的值为32而非2,所以执行else语句，
- 注意  在else语句中新定义了一个int nums!!
这个新的int的作用范围只是在这个大括号里面,出了大括号之后nums的值仍然是1.

## 11.克隆困境

### 试着运行一下程序，为什么会出现这样的结果？

### 直接将s2赋值给s1会出现哪些问题，应该如何解决？请写出相应代码。

``` c
解释struct Student {
char *name;
int age;
};
解释void initializeStudent( struct Student *student, const char *name,
int age) {
student->name = (char *)malloc(strlen(name) + 1 );
strcpy(student->name, name);
student->age = age;
}
int main(void) {
struct Student s1, s2;
initializeStudent(&s1, "Tom", 18 );
initializeStudent(&s2, "Jerry", 28 );
s1 = s2;
printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
free(s1.name);
free(s2.name);
return 0 ;
}
```
考察深浅拷贝
- 浅拷贝：只复制对象的值，对于指针类型的字段，仅复制指针的地址，多个对象之间共享相同的内存。
- 深拷贝：复制对象的值，并为指针类型的字段分配新的内存，确保每个对象拥有独立的内存。深拷贝通常需要手动实现
- 结构体的模板没有指针时，可以直接拷贝，但当结构体的模板有指针时，直接拷贝的话只拷贝了指针指向的地址，这使得原指针和新指针指向同一个内存空间，如果以后用原指针对地址进行操作可能导致新指针出现问题，需要重新分配内存空间拷贝。
> 这段代码的原本目的是创建两个 Student 结构体实例 (s1 和 s2)，分别初始化它们的姓名和年龄，并打印这两个学生的信息。
- 但是,``s1 = s2;``
这个赋值操作是将 s2 的整个结构体内容赋值给 s1，但 s2 中的 name 字段是一个指针，指向动态分配的内存
导致在赋值后，s1.name 和 s2.name 都指向同一块内存区域，导致两个结构体实例共享同一个字符串数据。这意味着如果你在一个实例上调用 free()，那么另一个实例的 name 指针就会变成一个悬空指针（野指针），因为它仍然指向已经被释放的内存。

> 赋值:
基本类型：赋值是值的复制，变量独立。
结构体：整个结构体内容被复制，字段独立。
指针：赋值将指针的地址复制，多个指针可以指向同一内存区域。如果你通过一个指针修改了这块内存，另一个指针也会看到这些更改

本题可以用strcpy将名字拷贝，如果只是不想弹出warning的话，只free一次空间也行，解决代码如下：
1.
``` c
struct Student {
char* name;	
int age;
};
void initializeStudent(struct Student* student, const char* name,int age) {
	student->name = (char*)malloc(sizeof name + 1);
	strcpy(student->name,name);
	student->age = age;
}
int main(void) {
	struct Student s1, s2;
	initializeStudent(&s1, "Tom\0", 18);
	initializeStudent(&s2, "Jerry\0", 28);
 s1.age=s2.age;
 strcpy(s1.name, s2.name);
	printf("s1 的姓名: %s 年龄: %d\n", s1.name, s1.age);
	printf("s2 的姓名: %s 年龄: %d\n", s2.name, s2.age);
  free(s1.name);
  free(s2.name);
	return 0;
}
```

## 12 .你好，我是内存

### 作为一名合格的C-Coder，一定对内存很敏感吧~来尝试理解这个程序吧！

``` c
解释struct structure {
int foo;
union {
int integer;
char string[ 11 ];
void *pointer;
} node;
short bar;
long long baz;
int array[ 7 ];
};
int main(void) {
int arr[] = {0x590ff23c, 0x2fbc5a4d, 0x636c6557, 0x20656d6f,
0x58206f74, 0x20545055, 0x6577202c, 0x6d6f636c,
0x6f742065, 0x79695820, 0x4c20756f, 0x78756e69,
0x6f724720, 0x5b207075, 0x33323032, 0x7825005d,
0x636c6557, 0x64fd6d1d};
printf("%s\n", (( struct structure *)arr)->node.string);
}
```
输出为Welcome to XUPT , welcome to Xiyou Linux Group [2023]
考察大小端和结构体的内存对齐
- 大端（存储）模式：是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；

- 小端（存储）模式:是指数据的低位保存在内存的低地址中，而数据的高位,，保存在内存的高地址中。

- x86系统采用小端的模式，数据的左边是高位,右边是低位
而输出的时候,从低地址到高地址输出.最后得到输出结果
- 注意输出的字符为将十六进制的数转换为十进制的数后对应ASCII表上的字符

## 13.GNU/Linux(选做)

```
注：嘿！你或许对Linux命令不是很熟悉，甚至你没听说过Linux。但别担心，这是选做题，了解
Linux是加分项，但不了解也不扣分哦！
```

### 你知道 cd 命令的用法与 /. ~ 这些符号的含义吗？

### 请问你还懂得哪些与GNU/Linux相关的知识呢~

- cd <目录名>: 进入指定的目录。例如，cd Documents 将你带到 Documents 目录。
- cd ..: 返回上一级目录。例如，如果你在 Documents 中，输入 cd .. 将你带到用户主目录。
- cd ~: 进入当前用户的主目录（通常是 /home/用户名）。
cd /: 进入根目录（文件系统的最顶层）。
cd -: 返回到上一个访问的目录。

.: 当前目录。比如，你在一个目录中，./file.txt 表示这个目录下的 file.txt 文件。
..: 上一级目录。用于从当前目录返回到它的父目录。
- ~: 当前用户的主目录。无论你在哪个目录，输入 cd ~ 都会带你到你的主目录。
- /: 根目录，文件系统的起始点，所有目录的父目录。



