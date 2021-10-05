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
�ļ��ڶ�д֮ǰӦ���ȴ��ļ�
֮��Ҫ�ر��ļ�
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
		printf("���ִ���\n");
		printf("%s\n", strerror(errno));
		return 0;

	}
	//fputc("hello", pt);
	fclose(pt);
	pt = NULL;
	pt = fopen("test.txt", "a+");
	if (pt == NULL)
	{
		printf("���ִ���\n");
		printf("%s\n", strerror(errno));
		return 0;
	}
	printf("�ļ��򿪳ɹ�\n");
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
	//��ʽ�ļ����뺯��
	fclose(pf);
	pf = NULL;
	return 0;
}

/*
C �⺯�� int fprintf(FILE *stream, const char *format, ...) 
���͸�ʽ��������� stream �С�

����
������ fprintf() ������������

int fprintf(FILE *stream, const char *format, ...)
����
stream -- ����ָ�� FILE �����ָ�룬�� FILE �����ʶ������
format -- ���� C �ַ�����������Ҫ��д�뵽�� stream �е��ı���
�����԰���Ƕ��� format ��ǩ��format ��ǩ�ɱ����ĸ��Ӳ�����ָ����ֵ�滻������������и�ʽ����format ��ǩ������ %[flags][width][.precision][length]specifier�����彲�����£�
specifier��˵������	���
c	�ַ�
d �� i	�з���ʮ��������
e	ʹ�� e �ַ��Ŀ�ѧ��ѧ��������β����ָ����
E	ʹ�� E �ַ��Ŀ�ѧ��ѧ��������β����ָ����
f	ʮ���Ƹ�����
g	�Զ�ѡ�� %e �� %f �к��ʵı�ʾ��
G	�Զ�ѡ�� %E �� %f �к��ʵı�ʾ��
o	�з��Ű˽���
s	�ַ����ַ���
u	�޷���ʮ��������
x	�޷���ʮ����������
X	�޷���ʮ��������������д��ĸ��
p	ָ���ַ
n	�����
%	�ַ�

flags����ʶ��	����
-	�ڸ������ֶο��������룬Ĭ�����Ҷ��루�μ� width ��˵��������
+	ǿ���ڽ��֮ǰ��ʾ�ӺŻ���ţ�+ �� -����������ǰ�����ʾ + �š�
Ĭ������£�ֻ�и���ǰ�����ʾһ�� - �š�
(space)	���û��д���κη��ţ����ڸ�ֵǰ�����һ���ո�
#	�� o��x �� X ˵����һ��ʹ��ʱ������ֵǰ���ֱ���ʾ 0��0x �� 0X��
�� e��E �� f һ��ʹ��ʱ����ǿ���������һ��С���㣬
��ʹ���û������ʱҲ����ʾС���㡣Ĭ������£�������û������ʱ�򣬲�����ʾ��ʾС���㡣
�� g �� G һ��ʹ��ʱ�������ʹ�� e �� E ʱ��ͬ������β�����㲻�ᱻ�Ƴ���
0	��ָ����� padding ��������߷����㣨0���������ǿո񣨲μ� width ��˵��������

width����ȣ�	����
(number)	Ҫ������ַ�����С��Ŀ��
��������ֵ���ڸ�����������ÿո���䡣
��������ֵ���ڸ�����������ᱻ�ضϡ�
*	����� format �ַ�����δָ�������ǻ���Ϊ��������ֵ����������Ҫ����ʽ���Ĳ���֮ǰ��

.precision�����ȣ�	����
.number	��������˵������d��i��o��u��x��X����
	precision ָ����Ҫд������ֵ���Сλ�������д���ֵ���ڸ������������ǰ��������䡣���д���ֵ���ڸ�����������ᱻ�ضϡ�����Ϊ 0 ��ζ�Ų�д���κ��ַ���
���� e��E �� f ˵������Ҫ��С����������С��λ����
���� g �� G ˵������Ҫ����������Чλ����
���� s: Ҫ���������ַ�����Ĭ������£�
�����ַ����ᱻ�����ֱ������ĩβ�Ŀ��ַ���
���� c ���ͣ�û���κ�Ӱ�졣
��δָ���κξ���ʱ��Ĭ��Ϊ 1�����ָ��ʱ������һ����ʽֵ����ٶ�Ϊ 0��
.*	������ format �ַ�����δָ����
���ǻ���Ϊ��������ֵ����������Ҫ����ʽ���Ĳ���֮ǰ��

length�����ȣ�	����
h	����������Ϊ�����ͻ��޷��Ŷ����ͣ�������������˵������i��d��o��u��x �� X����
l	����������Ϊ�����ͻ��޷��ų����ͣ���
	��������˵������i��d��o��u��x �� X����˵���� c����ʾһ�����ַ����� s����ʾ���ַ��ַ�������
L	����������Ϊ��˫�����ͣ��������ڸ�����˵������e��E��f��g �� G����
���Ӳ��� -- ���ݲ�ͬ�� format �ַ���������������Ҫһϵ�еĸ��Ӳ�����ÿ������������һ��Ҫ�������ֵ���滻�� format ������ָ����ÿ�� % ��ǩ�������ĸ���Ӧ�� % ��ǩ�ĸ�����ͬ��
����ֵ
����ɹ����򷵻�д����ַ����������򷵻�һ��������

ʵ��
�����ʵ����ʾ�� fprintf() �������÷���

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
�����Ǳ��벢��������ĳ����⽫�����ļ� file.txt�������������£�

We are in 2014
����������ʹ������ĳ���鿴�����ļ������ݣ�

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
scanf/printf ����Ա�׼������/��׼����� ��ʽ������\������
fscanf/fprintf ���������������/��������� ��ʽ������\������


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
C �⺯�� size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) �� ptr ��ָ��������е�����д�뵽������ stream �С�

����
������ fwrite() ������������

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
����
ptr -- ����ָ��Ҫ��д���Ԫ�������ָ�롣
size -- ����Ҫ��д���ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
nmemb -- ����Ԫ�صĸ�����ÿ��Ԫ�صĴ�СΪ size �ֽڡ�
stream -- ����ָ�� FILE �����ָ�룬�� FILE ����ָ����һ���������
����ֵ
����ɹ����ú�������һ�� size_t ���󣬱�ʾԪ�ص��������ö�����һ�������������͡������������ nmemb ������ͬ�������ʾһ������

ʵ��
�����ʵ����ʾ�� fwrite() �������÷���

ʵ��
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
	//д�����ݵĵ�ַ һ�����ݵĴ�С �м������� д�����ݵ��ļ���ַ
	fread(&tmp, sizeof(struct A), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;

	return 0;
}

/*
�ļ��������ȡ
C �⺯�� - fseek()
C ��׼�� - <stdio.h> C ��׼�� - <stdio.h>

����
C �⺯�� int fseek(FILE *stream, long int offset, int whence) ������ stream ���ļ�λ��Ϊ������ƫ�� offset������ offset ��ζ�ŴӸ����� whence λ�ò��ҵ��ֽ�����

����
������ fseek() ������������

int fseek(FILE *stream, long int offset, int whence)
����
stream -- ����ָ�� FILE �����ָ�룬�� FILE �����ʶ������
offset -- ������� whence ��ƫ���������ֽ�Ϊ��λ��
whence -- ���Ǳ�ʾ��ʼ���ƫ�� offset ��λ�á���һ��ָ��Ϊ���г���֮һ��
����	����
SEEK_SET	�ļ��Ŀ�ͷ
SEEK_CUR	�ļ�ָ��ĵ�ǰλ��
SEEK_END	�ļ���ĩβ
����ֵ
����ɹ�����ú��������㣬���򷵻ط���ֵ��

ʵ��
�����ʵ����ʾ�� fseek() �������÷���

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
�����Ǳ��벢��������ĳ����⽫�����ļ� file.txt�������������¡�������򴴽��ļ���д�� This is runoob.com������֮�������ڵ��߸�λ��������дָ�룬��ʹ�� puts() �������д�ļ����������£�

This is C Programming Langauge
����������ʹ������ĳ���鿴�����ļ������ݣ�

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
	SEEK_CUR �ļ�ָ��ĵ�ǰλ��
	SEEK_END �ļ���ĩβλ��
	SEEK_SET �ļ�����ʼλ��
	*/
	//rewind(pf)�ص���ʼλ��

	fclose(pf);
	pf = NULL;

	return 0;
}

int lesson_0916_8()
{
	/*
	feof() - �ļ�������־
	�ж����ļ���ȡʧ�ܽ���
	���������ļ���β����
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





















