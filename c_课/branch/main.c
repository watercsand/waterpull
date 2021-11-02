#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <string.h>

#include "kmp.h"
#include "virus.h"
#include "tree.h"

#include "kmp_test.h"
#include "compare_test.h"
#include "tree_test.h"

int main()
{
	tree_test1();
	tree_test2();
	system("pause");
}

