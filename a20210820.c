#include <stdio.h>
int lesson_89()
{
	int arr[10] = { 0 };
	printf("arr--------->%p\n", arr);
	printf("arr[0]------>%p\n", & arr[0]);
	printf("&arr-------->%p\n", &arr);
	printf("arr+1------->%p\n", arr+1);
	printf("&arr[0]+1--->%p\n", &arr[0] + 1);
	printf("&arr+1------>%p\n", &arr+1);
	//&arr+1是加了一个数组，40
	int* p = arr;
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%p===%p\n", p + i, &arr[i]);
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	return 0;
}

int lesson_89_1()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	int*** pppa = &ppa;
	int b = 20;
	int c = 30;
	int* arr[] = { &a,&b,&c };
	//指针数组
	printf("%p %p %p\n", arr[0], arr[1], arr[2]);
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", *(arr[i]));

	}
	printf("\n");
	char aa[] = "abc";
	char bb[] = { 'a','b','c' };
	printf("%d %d \n", sizeof(aa), sizeof(bb));
	return 0;
}

void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	
}

int lesson_89_2()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr, sz);//把数组 初始化为0
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	return 0;
}















