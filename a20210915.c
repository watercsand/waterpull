#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int lesson_0915_1()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;

}
/*
文件缓冲区
ANSIC标准采用 文件缓冲系统
自动地在内存中为程序中每一个正在使用的文件开辟一块 文件 缓冲区
从内存向磁盘输出数据会先送到么的话中的缓冲区，装潢缓冲区后才一起送到磁盘上。
如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区）
然后再从缓冲区逐个将数据送到程序数据区（程序变量）。缓冲区的大小根据C编译系统决定

文件类型指针，
每个使用的文件都在内存中开辟了一个相应的文件信息区，

*/















