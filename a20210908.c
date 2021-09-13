#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>


int find_num(int arr[3][3], int k, int* row, int* col)
{
	int x = 0;
	int y = (*col) - 1;
	while (y >= 0 && x <= (*row) - 1)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*row = x;
			*col = y;
			return 1;
		}

	}
	*row = -1;
	*col = -1;
	return 0;
}

int lesson_0908_1()
{
	int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
	int ret;
	int x_place, y_place;
	x_place = 3;
	y_place = 3;
	ret = find_num(arr, 6, &x_place, &y_place);
	printf("%d %d %d\n", x_place, y_place, ret);
	return 0;
}

int lesson_0908_2()
{
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("1\n");
	}
	else
	{
		printf("2\n");
	}
	return 0;
}

//寻找匹配的字符串，返回开始的值，找不到时返回NULL
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}

int lesson_0908_3()
{
	char a[] = "hello anybody";
	char b[] = "any";
	char* place = my_strstr(a, b);
	printf("%p\n", place);
	printf("%s\n", place);
	return 0;
}

/*
strtok
第一个参数：指定一个字符串，包含\0
第二个参数：切分的符号
要从第二段开始切分，需要传入参数NULL

*/

int lesson_0908_4()
{
	//char arr[] = "hello@163.com";
	//char* p = "@.";
	//char buf[256] = { 0 };
	//strcpy_s(buf, sizeof(buf) + sizeof(arr) + 1, arr);
	//char contest[1000];
	//char* locate[100];
	//char* ret = strtok_s(arr, p, contest, locate);
	//printf("%s\n", ret);
	int i = 0;
	for (i = 0; i < 141; i++)
	{
		if (i < 43 || i >100)
		{
			char* str = strerror(i);
			printf("%d ---- %s\n", i, str);
		}
		
	}
	return 0;
}
/*
errno 是一个全局的错误码的变量
当c语言的函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
*/

int lesson_0908_5()
{
	FILE* pf = fopen("a20210908.c", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	return 0;
}

int lesson_0908_6()
{
	char ch = 'a';
	int ret = islower(ch);
	printf("%d\n", ret);
	char a = '2';
	ret = isdigit(a);
	printf("%d\n", ret);
	ret = isdigit(ch);
	printf("%d\n", ret);
	return 0;
}

void str_to_lower(char* p1, int len)
{
	int i = 0;
	while (*(p1 + i))
	{
		if (isupper(*(p1 + i)))
		{
			*(p1 + i) = tolower(*(p1 + i));
		}
		i++;
	}
}

int lesson_0908_7()
{
	char arr[] = "I am a STudent who FoRM xinghUa university";
	printf("%s\n", arr);
	int arr_len = strlen(arr);
	str_to_lower(arr, arr_len);
	printf("%s\n", arr);
	return 0;
}

int lesson_0908_8()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	strcpy((char*)arr2, (char*)arr1);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}

/*
void memcpy(void* destination, const void* source, size_t count);
*/

int lesson_0908_9()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return 0;
}

struct s
{
	char name[20];
	int age;
};

void s_print(struct s* arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//printf("%p", arr + i);
		//printf("%s", (*(arr + i)).name);
		printf("name:%s age:%d\n", (char*)((arr + i)->name), (int)((arr + i)->age));
	}
}


int lesson_0908_10()
{
	struct s arr3[] = { {"zhangsan", 20}, {"lisi", 30} };
	struct s arr4[3] = { 0 };
	memcpy(arr3, arr4, sizeof(arr3));
	s_print(arr3, 2);
	s_print(arr4, 2);

	return 0;
}

void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}

int lesson_0908_11()
{
	int arr1[] = { 2,3,4,21,32,44 };
	int arr2[6];
	my_memcpy(arr2, arr1, sizeof(arr1));
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}









