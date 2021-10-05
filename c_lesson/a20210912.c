#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <windows.h>



/*
动态内存
malloc
free
calloc
realloc
常见的内存错误
柔性数组



栈区
局部变量
函数的形式参数

堆区
动态内存的分配

静态区
全局变量
静态变量

c99 可以创建变化长度的数组
linux centos 7 8 支持c99





*/

int lesson_0912_1()
{
	int k = 0;
	while (k < 10)
	{
		int a = 10;
		int* p = (int*)malloc(40);
		if (p == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			printf("正常开辟空间\n");
			int i = 0;
			for (i = 0; i < a; i++)
			{
				*(p + i) = i;
			}
			for (i = 0; i < a; i++)
			{
				printf("%d ", *(p + i));
			}
			printf("\n");
			//Sleep(3000);
			k++;
			free(p);
			//Sleep(3000);
			p = NULL;//防止再次使用指针
		}
		
		//当动态申请的空间不再使用的时候
		//应该还给操作系统
		//free对动态内存进行回收
	}
	/*
	malloc向内存中申请一块连续可用的空间，并返回指向这块空间的指针
	返回值默认值void*
	如果参数ptr指向的空间不是动态开辟的，那么free函数的行为是未定义的
	如果参数ptr是NULL指针，则函数什么事情不做
	*/

	return 0;
}

int lesson_0912_2()
{
	//calloc会初始化内容为0
	//malloc不会进行初始化，效率较高
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p+i));
		}
	}
	printf("\n");
	//释放空间
	free(p);
	p = NULL;


	return 0;
}

int lesson_0912_3()
{
	//realloc
	/*
	调整动态内存的大小

	*/
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	//就是在使用malloc开辟的20个字节的空间
	//假设这里，20个字节不能满足我们的使用
	//希望能开辟40个字节的空间
	//使用realloc来调整动态开辟的内存空间
	/*
	realloc
	void* realloc()
	
	*/
	int* p2 = realloc(p, 40);
	if (p2 == NULL)
	{
		printf("fail to realloc\n");
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (p2 == NULL)
		{
			free(p);
			break;
		}
		printf("%d ", *(p2 + i));
	}
	printf("\n");
	free(p2);
	p2 = NULL;
	return 0;
	/*
	realloc使用的注意事项
	如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
	如果p指向的空间之后没有足够的内存空间可以追加，
	则realloc函数会重新找一个新的内存区域，重新找一个新的内存区域
	开辟与你满足需求的空间，并且把原来内存的数据拷贝回来，释放旧的空间
	
	*
	*/

}
















