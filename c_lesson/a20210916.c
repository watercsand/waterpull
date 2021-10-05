#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <errno.h>
/*--------------------------------------------------------------------
Author: watercsand
git:	waterpull
email: 1337259688@qq.com
area:	China

this file only upload on the github
only for learning
if you see this file on any other website
!!!!!that all without permisson!!!!!
!!!!!   prohibit commercial    !!!!!
Any illegal act will be investigated
if you find any of this illegal activity
please send me an email (although I only check email occasionally)
thank you

in addition
I copied some of this stuff from the internet
especially the comments section
If you find out that I have infringed
Please contact with me
I'll delete it
--------------------------------------------------------------------*/

/*
文件在读写之前应该先打开文件
之后要关闭文件
FILE* open(constr char* filename, const char* mode)
int fclose(file* stream)

Opening Modes in Standard I/O
Mode	Meaning of Mode	During Inexistence of file
r	Open for reading.	If the file does not exist, fopen() returns NULL.


rb	Open for reading in binary mode.	If the file does not exist, fopen() returns NULL.


w	Open for writing.	If the file exists, its contents are overwritten.

				If the file does not exist, it will be created.

				
wb	Open for writing in binary mode.	If the file exists, its contents are overwritten.

				If the file does not exist, it will be created.

				
a	Open for append.

				Data is added to the end of the file.	If the file does not exist, it will be created.

				
ab	Open for append in binary mode.

				Data is added to the end of the file.	If the file does not exist, it will be created.


r+	Open for both reading and writing.	If the file does not exist, fopen() returns NULL.


rb+	Open for both reading and writing in binary mode.	If the file does not exist, fopen() returns NULL.


w+	Open for both reading and writing.	If the file exists, its contents are overwritten.

				If the file does not exist, it will be created.


wb+	Open for both reading and writing in binary mode.	If the file exists, its contents are overwritten.

				If the file does not exist, it will be created.


a+	Open for both reading and appending.	If the file does not exist, it will be created.


ab+	Open for both reading and appending in binary mode.	If the file does not exist, it will be created.
Closing a File
--------------------------------------------------------------------------
The file (both text and binary) should be closed after reading/writing.

Closing a file is performed using the fclose() function.

fclose(fptr);
Here, fptr is a file pointer associated with the file to be closed.
---------------------------------------------------------------------------


*/
int lesson_0916_1()
{

	FILE* pt = fopen("test.txt", "w");

	if (pt == NULL)
	{
		printf("出现错误\n");
		printf("%s\n", strerror(errno));
		return 0;

	}
	//fputc("hello", pt);
	fclose(pt);
	pt = NULL;
	pt = fopen("test.txt", "a+");
	if (pt == NULL)
	{
		printf("出现错误\n");
		printf("%s\n", strerror(errno));
		return 0;
	}
	printf("文件打开成功\n");
	int i = 0;
	for (i = 1; i < 100; i++)
	{
		fputc('b', pt);
		fputc('i', pt);//only one char
		fputc(' ', pt);
		if ((i % 10 == 0) && (i != 0))
		{
			fputc('\n', pt);
		}
	}
	fputc('\n', pt);
	fputc('`', pt);
	fclose(pt);
	pt = NULL;
	pt = fopen("test.txt", "r");
	printf("file:\n");
	while (fgetc(pt) != '`')
	{
		printf("%c", fgetc(pt));
		break;
	}
	printf("\n");
	/*
	stdin keyboard
	stdout monitor
	stderr wrong
	
	*/
	
	fclose(pt);
	pt = NULL;
	return 0;
}

struct s
{
	int n;
	float score;
	char arr[10];
};

int lesson_0916_2()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s \n", strerror(errno));
		return 0;
	}
	char buf[1024];
	fgets(buf, 1024, pf);
	printf("%s", buf);
	fgets(buf, 1024, pf);
	printf("%s", buf);

	fclose(pf);
	pf = NULL;
	//printf("a\n");
	pf = fopen("test.txt", "w+");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	fputs("hello world\n", pf);
	fputs("hello world\n", pf);
	fputs("hello world\n", pf);
	fputs("hello world\n", pf);
	fputs("hello world\n", pf);
	fputs("hello world\n", pf);
	struct s s = { 100, 3.14f, "bit" };
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	//格式文件输入函数
	fclose(pf);
	pf = NULL;
	return 0;
}

/*
C 库函数 int fprintf(FILE *stream, const char *format, ...) 
发送格式化输出到流 stream 中。

声明
下面是 fprintf() 函数的声明。

int fprintf(FILE *stream, const char *format, ...)
参数
stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了流。
format -- 这是 C 字符串，包含了要被写入到流 stream 中的文本。
它可以包含嵌入的 format 标签，format 标签可被随后的附加参数中指定的值替换，并按需求进行格式化。format 标签属性是 %[flags][width][.precision][length]specifier，具体讲解如下：
specifier（说明符）	输出
c	字符
d 或 i	有符号十进制整数
e	使用 e 字符的科学科学记数法（尾数和指数）
E	使用 E 字符的科学科学记数法（尾数和指数）
f	十进制浮点数
g	自动选择 %e 或 %f 中合适的表示法
G	自动选择 %E 或 %f 中合适的表示法
o	有符号八进制
s	字符的字符串
u	无符号十进制整数
x	无符号十六进制整数
X	无符号十六进制整数（大写字母）
p	指针地址
n	无输出
%	字符

flags（标识）	描述
-	在给定的字段宽度内左对齐，默认是右对齐（参见 width 子说明符）。
+	强制在结果之前显示加号或减号（+ 或 -），即正数前面会显示 + 号。
默认情况下，只有负数前面会显示一个 - 号。
(space)	如果没有写入任何符号，则在该值前面插入一个空格。
#	与 o、x 或 X 说明符一起使用时，非零值前面会分别显示 0、0x 或 0X。
与 e、E 和 f 一起使用时，会强制输出包含一个小数点，
即使后边没有数字时也会显示小数点。默认情况下，如果后边没有数字时候，不会显示显示小数点。
与 g 或 G 一起使用时，结果与使用 e 或 E 时相同，但是尾部的零不会被移除。
0	在指定填充 padding 的数字左边放置零（0），而不是空格（参见 width 子说明符）。

width（宽度）	描述
(number)	要输出的字符的最小数目。
如果输出的值短于该数，结果会用空格填充。
如果输出的值长于该数，结果不会被截断。
*	宽度在 format 字符串中未指定，但是会作为附加整数值参数放置于要被格式化的参数之前。

.precision（精度）	描述
.number	对于整数说明符（d、i、o、u、x、X）：
	precision 指定了要写入的数字的最小位数。如果写入的值短于该数，结果会用前导零来填充。如果写入的值长于该数，结果不会被截断。精度为 0 意味着不写入任何字符。
对于 e、E 和 f 说明符：要在小数点后输出的小数位数。
对于 g 和 G 说明符：要输出的最大有效位数。
对于 s: 要输出的最大字符数。默认情况下，
所有字符都会被输出，直到遇到末尾的空字符。
对于 c 类型：没有任何影响。
当未指定任何精度时，默认为 1。如果指定时不带有一个显式值，则假定为 0。
.*	精度在 format 字符串中未指定，
但是会作为附加整数值参数放置于要被格式化的参数之前。

length（长度）	描述
h	参数被解释为短整型或无符号短整型（仅适用于整数说明符：i、d、o、u、x 和 X）。
l	参数被解释为长整型或无符号长整型，适
	用于整数说明符（i、d、o、u、x 和 X）及说明符 c（表示一个宽字符）和 s（表示宽字符字符串）。
L	参数被解释为长双精度型（仅适用于浮点数说明符：e、E、f、g 和 G）。
附加参数 -- 根据不同的 format 字符串，函数可能需要一系列的附加参数，每个参数包含了一个要被插入的值，替换了 format 参数中指定的每个 % 标签。参数的个数应与 % 标签的个数相同。
返回值
如果成功，则返回写入的字符总数，否则返回一个负数。

实例
下面的实例演示了 fprintf() 函数的用法。

#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);

   fclose(fp);

   return(0);
}
让我们编译并运行上面的程序，这将创建文件 file.txt，它的内容如下：

We are in 2014
现在让我们使用下面的程序查看上面文件的内容：

#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   while(1)
   {
	  c = fgetc(fp);
	  if( feof(fp) )
	  {
		  break ;
	  }
	  printf("%c", c);
   }
   fclose(fp);
   return(0);
}
*/


int lesson_0916_3()
{
	struct s s = { 10, 3.14f, "bit" };
	struct s s1 = { 0 };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}

	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	/*-----------------------------------------------------------*/
	pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//fscanf(pf, "%d %f %s", &(s1.n), &(s1.score), &(s1.arr));
	printf("%d %f %s\n", s.n, s.score, s.arr);
	
	fclose(pf);
	pf = NULL;
	return 0;
}

/*
scanf/printf 是针对标准输入流/标准输出流 格式化输入\输出语句
fscanf/fprintf 是针对所有输入流/所有输出流 格式化输入\输出语句


*/

int lesson_0916_4()
{
	struct s s = { 100, 3.14f, "abcdef" };
	char buf[1024] = { 0 };
	sprintf(buf, "%d %.2f %s \n", s.n, s.score, s.arr);
	printf("%s\n", buf);
	struct s tmp = { 0 };
	int a = sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
	return 0;
}

struct A
{
	char name[20];
	int age;
	double score;
};

/*
C 库函数 size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) 把 ptr 所指向的数组中的数据写入到给定流 stream 中。

声明
下面是 fwrite() 函数的声明。

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
参数
ptr -- 这是指向要被写入的元素数组的指针。
size -- 这是要被写入的每个元素的大小，以字节为单位。
nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。
返回值
如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误。

实例
下面的实例演示了 fwrite() 函数的用法。

实例
#include<stdio.h>

int main ()
{
   FILE *fp;
   char str[] = "This is runoob.com";

   fp = fopen( "file.txt" , "w" );
   fwrite(str, sizeof(str) , 1, fp );

   fclose(fp);

   return(0);
}
*/


int lesson_0916_5()
{
	struct A s = { "zhangsan", 20, 55.6 };
	FILE* pf = NULL;
	pf = fopen("test.txt", "wb");
	if (pf == NULL)
	{
		return 0;
	}
	fwrite(&s, sizeof(struct A), 1, pf);
	fclose(pf);
	pf = NULL;

	return 0;
}

/*
* https://overiq.com/c-programming-101/fread-function-in-c/
fread() Function in C
 Last updated on July 27, 2020

The fread() function is the complementary of fwrite() function. fread() function is commonly used to read binary data. It accepts the same arguments as fwrite() function does. The syntax of fread() function is as follows:

Syntax: size_t fread(void *ptr, size_t size, size_t n, FILE *fp);

The ptr is the starting address of the memory block where data will be stored after reading from the file. 
The function reads n items from the file where each item occupies the number of bytes specified in the second argument. 
On success, it reads n items from the file and returns n. On error or end of the file, it returns a number less than n.

Let's take some examples:

Example 1: Reading a float value from the file


int val;

fread(&val, sizeof(int), 1, fp);
This reads a float value from the file and stores it in the variable val.

Example 2: Reading an array from the file


int arr[10];

fread(arr, sizeof(arr), 1, fp);
This reads an array of 10 integers from the file and stores it in the variable arr.

Example 3: Reading the first 5 elements of an array


int arr[10];

fread(arr, sizeof(int), 5, fp);
This reads 5 integers from the file and stores it in the variable arr.

Example 4: Reading the first 5 elements of an array

int arr[10];

fread(arr, sizeof(int), 5, fp);
This reads 5 integers from the file and stores it in the variable arr.

Example 5: Reading the structure variable

struct student
{
	char name[10];
	int roll;
	float marks;
};

struct student student_1;

fread(&student_1, sizeof(student_1), 1, fp);
This reads the contents of a structure variable from the file and stores it in the variable student_1.

Example 6: Reading an array of structure

struct student
{
	char name[10];
	int roll;
	float marks;
};

struct student arr_student[100];

fread(&arr_student, sizeof(struct student), 10, fp);
This reads first 10 elements of type struct student from the file and stores them in the variable arr_student.

The following program demonstrates how we can use fread() function.


#include<stdio.h>
#include<stdlib.h>

struct employee
{
	char name[50];
	char designation[50];
	int age;
	float salary
} emp;

int main()
{
	FILE *fp;
	fp = fopen("employee.txt", "rb");

	if(fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	printf("Testing fread() function: \n\n");

	while( fread(&emp, sizeof(emp), 1, fp) == 1 )
	{
		printf("Name: %s \n", emp.name);
		printf("Designation: %s \n", emp.designation);
		printf("Age: %d \n", emp.age);
		printf("Salary: %.2f \n\n", emp.salary);
	}

	fclose(fp);
	return 0;
}
Expected Output:


Testing fread() function:

Name: Bob
Designation: Manager
Age: 29
Salary: 34000.00

Name: Jake
Designation: Developer
Age: 34
Salary: 56000.00
How it works:

In lines 4-10, a structure employee is declared along with a variable emp . The structure employee has four members namely: name, designation, age and salary.

In line 14, a structure pointer fp of type struct FILE is declared.

In line 15, fopen() function is called with two arguments namely "employee.txt" and "rb". On success, it returns a pointer to file employee.txt and opens the file employee.txt in read-only mode. On failure, it returns NULL.

In lines 17-21, if statement is used to test the value of fp. If it is NULL, printf() statement prints the error message and program terminates. Otherwise, the program continues with the statement following the if statement.

In lines 25-31, a while loop is used along with fread() to read the contents of the file. The fread() function reads the records stored in the file one by one and stores it in the structure variable emp. The fread() function will keep returning 1 until there are records in the file. As soon as the end of the file is encountered fread() will return a value less than 1 and the condition in the while loop become false and the control comes out of the while loop.

In line 33, fclose() function is used to close the file.

 fwrite() Function in C
*/

int lesson_0916_6()
{
	lesson_0916_5();
	struct A tmp = { 0 };
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//写入数据的地址 一个数据的大小 有几个数据 写入数据的文件地址
	fread(&tmp, sizeof(struct A), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;

	return 0;
}

/*
文件的随机读取
C 库函数 - fseek()
C 标准库 - <stdio.h> C 标准库 - <stdio.h>

描述
C 库函数 int fseek(FILE *stream, long int offset, int whence) 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。

声明
下面是 fseek() 函数的声明。

int fseek(FILE *stream, long int offset, int whence)
参数
stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了流。
offset -- 这是相对 whence 的偏移量，以字节为单位。
whence -- 这是表示开始添加偏移 offset 的位置。它一般指定为下列常量之一：
常量	描述
SEEK_SET	文件的开头
SEEK_CUR	文件指针的当前位置
SEEK_END	文件的末尾
返回值
如果成功，则该函数返回零，否则返回非零值。

实例
下面的实例演示了 fseek() 函数的用法。

#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("This is runoob.com", fp);

   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Langauge", fp);
   fclose(fp);

   return(0);
}
让我们编译并运行上面的程序，这将创建文件 file.txt，它的内容如下。最初程序创建文件和写入 This is runoob.com，但是之后我们在第七个位置重置了写指针，并使用 puts() 语句来重写文件，内容如下：

This is C Programming Langauge
现在让我们使用下面的程序查看上面文件的内容：

#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   while(1)
   {
	  c = fgetc(fp);
	  if( feof(fp) )
	  {
		  break ;
	  }
	  printf("%c", c);
   }
   fclose(fp);
   return(0);
}
*/

int lesson_0916_7()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	fseek(pf, 2, SEEK_CUR);
	int ch = fgetc(pf);
	printf("%c\n", ch);
	/*
	SEEK_CUR 文件指针的当前位置
	SEEK_END 文件的末尾位置
	SEEK_SET 文件的起始位置
	*/
	//rewind(pf)回到初始位置

	fclose(pf);
	pf = NULL;

	return 0;
}

int lesson_0916_8()
{
	/*
	feof() - 文件结束标志
	判断是文件读取失败结束
	还是遇到文件结尾结束
	*/
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	int ch = fgetc(pf);
	printf("%d\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}

int lesson_0916_9()
{
	FILE* pf = fopen("test2.txt", "r");
	if (pf == NULL)
	{
		perror("file error --> test2.txt");
		return 0;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

int lesson_0916_10()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("open test.txt error:");
		return 0;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	printf("\n");
	if (ferror(pf))
	{
		printf("error\n");
	}
	else if (feof(pf))
	{
		printf("end of file\n");
	}
	fclose(pf);
	pf = NULL;
}





















