#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stddef.h>

/*
����Ļ�����Ԥ����
Ԥ����ķ��ŵĽ���
Ԥ����ָ��
��ͺ����ĶԱ�
�����
Ԥ����ָ��#include
Ԥ����ָ��#undef
��������

Դ�ļ� 
�����ļ�
object 

extern int XXX(XXX,XXX);
���������ⲿ�ĺ���
������

****���뻷��************************************ **���л���***
*****����(������)******* ******����(������)*****
*Ԥ����* *����* **���** 

	1.Ԥ����ѡ�� gcc -E test.c -o test.i Ԥ�������֮���ͣ������
Ԥ����֮������Ľ��������test.i�ļ���
	2.���� ѡ�� gcc -S test.c �������֮���ͣ���������������test.s��
	3.��� gcc -C test.c ������֮���ͣ���������������test.o��

Ԥ���� 
	#include		ͷ�ļ��İ���
	ɾ��ע��
	#define

����
	��c���Է���ɻ������
	�﷨����
	�ʷ�����
	�������
	���Ż���

����ԭ�� -- �������޿�
������Ա������������

elf �ļ���ʽ


*/


/*
https://coolshell.cn/articles/5426.html
��һ�� �C ���
��װ vim
���� vim
ʲôҲ��ɣ������Ķ�
���㰲װ��һ���༭����
��һ�����������������ʲô������
Ȼ�󿴿�����༭����ʲô���ӡ�
��vim���������ģ��밴����������������

����Vim��vim�� Normal ģʽ�¡�
�����ǽ��� Insert ģʽ���밴�¼� i ��
(��ῴ��vim���½���һ���Cinsert�C��������ʾ��
������Բ���ķ�ʽ�����ˣ�
��ʱ������������ı��ˣ��������á����±���һ����
������뷵�� Normal ģʽ���밴 ESC ����
���ڣ���֪������� Insert �� Normal ģʽ���л��ˡ�
������һЩ������������� Normal ģʽ���Ҵ�������

i �� Insert ģʽ���� ESC �ص� Normal ģʽ.
x �� ɾ��ǰ������ڵ�һ���ַ���
:wq �� ���� + �˳� (:w ����, :q �˳�)   ��  :w ����Ը��ļ�����
dd �� ɾ����ǰ�У�����ɾ�����д浽��������
p �� ճ��������
�Ƽ�:

hjkl (ǿ���Ƽ�ʹ�����ƶ���꣬��������) ��
��Ҳ����ʹ�ù��� (��������). ע: j �����¼�ͷ��
:help <command> �� ��ʾ�������İ�����
��Ҳ���Ծ����� :help �����������  �˳�������Ҫ����:q��
������vim�Ҵ�����ֻ��Ҫ��������5�����
��Ϳ��Ա༭�ı��ˣ���һ��Ҫ����Щ��������һ������ʶ��״̬��
������Ϳ��Կ�ʼ���׵��ڶ����ˡ�

���ǣ��������ڶ���ʱ����Ҫ��˵һ�� Normal ģʽ��
��һ��ı༭���£�������Ҫcopyһ�����ֵ�ʱ��
����Ҫʹ�� Ctrl �������磺Ctrl-C��
Ҳ����˵��Ctrl���ͺ����ܼ�һ����
���㰴���˹��ܼ�Ctrl��C�Ͳ�����C�ˣ�
���Ҿ���һ���������һ��������ˣ�
��VIM��Normalģʽ�£����еļ����ǹ��ܼ��ˡ��������Ҫ֪����

���:

����������У������ Ctrl-���һ�д�� <C-��>.
�� : ��ʼ����������Ҫ���� <enter>�س���
���� �� �����д�� :q Ҳ����˵��Ҫ���� :q<enter>.
�ڶ��� �C �о�����
�������Щ����ֻ��������������
������ʱ��ѧϰһЩ����������ˣ��������ҵĽ��飺
�����е������Ҫ��Normalģʽ��ʹ�ã�����㲻֪��������ʲô����ģʽ����Ϳ񰴼���ESC����

���ֲ���ģʽ
a �� �ڹ������
o �� �ڵ�ǰ�к����һ������
O �� �ڵ�ǰ��ǰ����һ������
cw �� �滻�ӹ������λ�ú�һ�����ʽ�β���ַ�
�򵥵��ƶ����
0 �� �����㣬����ͷ
^ �� �����е�һ������blank�ַ���λ�ã�
	��νblank�ַ����ǿո�tab�����У��س��ȣ�
$ �� ��������β
g_ �� ���������һ������blank�ַ���λ�á�
/pattern �� ���� pattern ���ַ�����  ������������ƥ�䣬�ɰ�n������һ����
����/ճ�� ��  p/P�����ԣ�p�Ǳ�ʾ�ڵ�ǰλ��֮��P��ʾ�ڵ�ǰλ��֮ǰ��
P �� ճ��
yy �� ������ǰ�е����� ddP
Undo/Redo
u �� undo
<C-r> �� redo
��/����/�˳�/�ı��ļ�(Buffer)
:e <path/to/file> �� ��һ���ļ�
:w �� ����
:saveas <path/to/file> �� ����Ϊ <path/to/file>
:x�� ZZ �� :wq �� ���沢�˳� (:x ��ʾ������Ҫʱ���棬ZZ����Ҫ����ð�Ų��س�)
:q! �� �˳������� :qa! ǿ���˳����е����ڱ༭���ļ����������ļ��и��ġ�
:bn �� :bp �� �����ͬʱ�򿪺ܶ��ļ���
ʹ���������������л���һ������һ���ļ���
��  ��ϲ��ʹ��:n����һ���ļ���
����ʱ����Ϥһ����������
һ�������������ˣ���ͼ������Ը������༭�����ܸɵ����ˡ�
���ǵ�����Ϊֹ���㻹�Ǿ���ʹ��vim�����е㱿׾��
����û��ϵ������Խ��׵��������ˡ�

������ �C ���ã���ǿ������
�ȹ�ϲ�㣡��ɵĺܲ��������ǿ��Կ�ʼһЩ��Ϊ��Ȥ�����ˡ�
�ڵ�����������̸ֻ��Щ��vi���Լ��ݵ����

����
���棬�����ǿ�һ��vim����ô�ظ��Լ��ģ�

. �� (С����) �����ظ���һ�ε�����
N<command> �� �ظ�ĳ������N��
������һ��ʾ�����ҿ�һ���ļ������������������

2dd �� ɾ��2��
3p �� ճ���ı�3��
100idesu [ESC] �� ��д�� ��desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu ��
. �� �ظ���һ������� 100 ��desu ��.
3. �� �ظ� 3 �� ��desu�� (ע�⣺���� 300���㿴��VIM�������).
��ǿ
��Ҫ����Ĺ���ƶ�����Ч�ʣ���һ��Ҫ�˽��������Щ���ǧ���������

NG �� ���� N �� 
��  ע�������е�G�Ǵ�д�ģ�����һ��ʹ�� : N ����N�У��� :137 ����137�У�
gg �� ����һ�С���  �൱��1G���� :1��
G �� �����һ�С�
�������ƶ���
w �� ����һ�����ʵĿ�ͷ��
e �� ����һ�����ʵĽ�β��
> �������Ϊ��������Ĭ�Ϸ�ʽ����ô����Сд��e��w��
Ĭ������˵��һ����������ĸ�����ֺ��»�����ɣ�  ���������

> �������Ϊ��������blank�ַ��ָ�������ô����Ҫʹ�ô�д��E��W��
��  ������䣩

Word moves example

���棬������˵˵��ǿ�Ĺ���ƶ���

% : ƥ�������ƶ������� (, {, [. ��  ����Ҫ�ѹ�����Ƶ������ϣ�
* �� #:  ƥ���굱ǰ���ڵĵ��ʣ�
�ƶ���굽��һ��������һ����ƥ�䵥�ʣ�*����һ����#����һ����
�����ң���������������Գ���Ա��˵���൱ǿ��ġ�

����
��һ��Ҫ��ס�����ƶ�����Ϊ�ܶ�������Ժ���Щ�ƶ���������������
�ܶ���������������ɣ�

<start position><command><end position>

���� 0y$ ������ζ�ţ�

0 �� �ȵ���ͷ
y �� �����￪ʼ����
$ �� �������������һ���ַ�
��ɿ������� ye���ӵ�ǰλ�ÿ����������ʵ����һ���ַ���

��Ҳ�������� y2/foo ������2�� ��foo�� ֮����ַ�����

���кܶ�ʱ�䲢��һ�����һ��Ҫ��y�Ż´�������������Ҳ�ᱻ������

d (ɾ�� )
v (���ӻ���ѡ��)
gU (���д)
gu (��Сд)
�ȵ�
��  ���ӻ�ѡ����һ��������˼�����������Ȱ�v��
Ȼ���ƶ���꣬��ͻῴ���ı���ѡ��Ȼ�������d��Ҳ��y��Ҳ���Ա��д�ȣ�
���ļ� �C Vim ������
��ֻ��Ҫ����ǰ��������Ϳ��Ժ������ʹ��VIM�ˡ�
���ǣ����ڣ�����������ܵ���VIMɱ�ּ��Ĺ��ܡ�������Щ��������ֻ��vim��ԭ��

�ڵ�ǰ�����ƶ����: 0 ^ $ f F t T , ;
0 �� ����ͷ
^ �� �����еĵ�һ����blank�ַ�
$ �� ����β
g_ �� ���������һ������blank�ַ���λ�á�
fa �� ����һ��Ϊa���ַ�������Ҳ����fs����һ��Ϊs���ַ���
t, �� ������ǰ�ĵ�һ���ַ������ſ��Ա�������ַ���
3fa �� �ڵ�ǰ�в��ҵ��������ֵ�a��
F �� T �� �� f �� t һ����ֻ�������෴����
Line moves
����һ�������õ������� dt" �� ɾ�����е����ݣ�ֱ������˫���š��� "��

����ѡ�� <action>a<object> �� <action>i<object>
��visual ģʽ�£���Щ�����ǿ���������ʽΪ

<action>a<object> �� <action>i<object>

action�������κε������ d (ɾ��), y (����), v (������ģʽѡ��)��
object �����ǣ� w һ�����ʣ� W һ���Կո�Ϊ�ָ��ĵ��ʣ� 
s һ�����֣� p һ�����䡣Ҳ������һ���ر���ַ���"�� '�� )�� }�� ]��
��������һ���ַ��� (map (+) ("foo")).�������ڵ�һ�� o ��λ�á�

vi" �� ��ѡ�� foo.
va" �� ��ѡ�� "foo".
vi) �� ��ѡ�� "foo".
va) �� ��ѡ��("foo").
v2i) �� ��ѡ�� map (+) ("foo")
v2a) �� ��ѡ�� (map (+) ("foo"))
Text objects selection

�����: <C-v>
����������͵Ĳ����� 0 <C-v> <C-d> I-- [ESC]

^ �� ����ͷ
<C-v> �� ��ʼ�����
<C-d> �� �����ƶ� (��Ҳ����ʹ��hjkl���ƶ���꣬����ʹ��%�����Ǳ��)
I-- [ESC] �� I�ǲ��룬���롰--������ESC����Ϊÿһ����Ч��
Rectangular blocks

��Windows�µ�vim������Ҫʹ�� <C-q> ������ <C-v> ��<C-v> �ǿ��������塣

�Զ���ʾ�� <C-n> �� <C-p>
�� Insert ģʽ�£����������һ���ʵĿ�ͷ��
Ȼ�� <C-p>����<C-n>���Զ����빦�ܾͳ����ˡ���

Completion

��¼�ƣ� qa �������� q, @a, @@
qa ����Ĳ�����¼�ڼĴ��� a��
���� @a ��replay��¼�Ƶĺꡣ
@@ ��һ����ݼ�����replay����¼�Ƶĺꡣ
ʾ��

��һ��ֻ��һ������һ��ֻ�С�1�����ı��У������������

qaYp<C-a>q��
qa ��ʼ¼��
Yp ������.
<C-a> ����1.
q ֹͣ¼��.
@a �� ��1����д�� 2
@@ �� ��2 ����д��3
������ 100@@ �ᴴ���µ�100�У������������ӵ� 103.
Macros

���ӻ�ѡ�� v,V,<C-v>
ǰ�棬���ǿ����� <C-v>��ʾ�� 
����Windows��Ӧ����<C-q>�������ǿ���ʹ�� v �� V��
һ����ѡ���ˣ��������������£�

J �� �����е����������������һ�У�
< �� > �� ��������
= �� �Զ������� ��  ��������൱ǿ����̫ϲ���ˣ�
Autoindent

�����б�ѡ����к���ϵ㶫����

<C-v>
ѡ����ص��� (��ʹ�� j �� <C-d> ���� /pattern ���� % �ȡ���)
$ �������
A, �����ַ������� ESC��
Append to many lines

����: :split �� vsplit.
��������Ҫ����������ʹ��VIM�İ��� :help split. 
����Բο���վ��ǰ��һƪ����VIM������

:split �� �������� (:vsplit������ֱ����)
<C-w><dir> : dir���Ƿ��򣬿����� hjkl ���� �������� �е�һ����
�������л�������
<C-w>_ (�� <C-w>|) : ��󻯳ߴ� (<C-w>| ��ֱ����)
<C-w>+ (�� <C-w>-) : ���ӳߴ�
Split

������
������������õ�90%�����
�ҽ�����ÿ�춼ѧ1��2���µ����
���������ܺ����е�vim��ǿ��ġ�
��ʱ��ѧϰVIM������������һЩ������
���˵��ǣ�vim�кܶ�ܲ����Ĺ��ߺ�������ĵ���
����vimtutorֱ������Ϥ����Щ�������
�����߰����ĵ�����Ӧ��Ҫ��ϸ�Ķ����� :help usr_02.txt.
���ѧϰ������  !�� Ŀ¼���Ĵ���������Ⱥܶ������Ĺ��ܡ�
ѧϰvim����ѧ������һ����һ��ѧ�ᣬ�������

�����������������������Ľ�����������������������

����vi/vimֻ�ǵ���һ�㣺����һ���㲻��Ҫʹ����꣬����ʹ��С���̣�ֻ
��Ҫʹ�ô���̾Ϳ�����ɺܶิ�ӹ����ı��༭�ı༭����
��Ȼ��Visual StudioҲ���ͻ���vim�Ĳ���ˡ�

*/

/*
���� ����ʱ��ջ

Ԥ�������
__FILE__



*/

int lesson_0918_1()
{
	FILE* pf = fopen("log.txt", "w");
	int i = 0;
	int arr[10] = { 0 };
	printf("%s\n", __FILE__);//�������ڵ��ļ�
	printf("%d\n", __LINE__);//�������ڵ��к�
	printf("%s\n", __DATE__);//���������е�ʱ��
	printf("%s\n", __TIME__);//���������еľ�׼ʱ��
	
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", (char*)__FILE__,
			(int)__LINE__, 
			(char*)__DATE__, (char*)__TIME__, i);
	}
	printf("%s\n", __FUNCTION__);
	fclose(pf);
	pf = NULL;
	return 0;
}

/*
c
���ݽṹ
c++
�߼����ݽṹ
linux
mysql
������


*/

#define square(x) (x)*(x)

int lesson_0918_2()
{
	int ret = square(5);
	printf("%d\n", ret);
	ret = square(5 + 1);
	printf("%d\n", ret);
	ret = square((5 + 1));
	printf("%d\n", ret);
	return 0;
}


int lesson_0918_3()
{






	return 0;
}


/*
undef �Ƴ�һ���궨��
�����ж���
��������
����������ָ��
#if 1
	XXXXXXX
#endif

#if define(debug)
	XXXXX
#endif


#if !define(degub)
	XXXXXX
#endif

��ֹͷ�ļ�����ΰ���
#pragma once


#ifndef __XXX_H__
#define __XXX_H__

XXXXXXXX();

#endif

Ԥ����ָ��
#pragma once
#line
#error
#if
#elif
#else
 
��c���Գ��Խ��ʡ�

*/

#define a 100
struct s7
{
	char c1;
	int b;
	char c2;
};
int lesson_0918_4()
{
	printf("%d\n", a);
	printf("%c\n", a);
	
	printf("%d %d %d\n", offsetof(struct s7, c1), 
		offsetof(struct s7, b), offsetof(struct s7, c2));
	

	

	return 0;
}
#undef a

#ifndef my_offsetof
#define my_offsetof(struct_name, member_name) (int)&(((struct_name*)0)->member_name)

#endif

int lesson_0918_5()
{
	printf("%d %d %d\n",
		my_offsetof(struct s7, c1),
		my_offsetof(struct s7, b),
		my_offsetof(struct s7, c2));
	return 0;
}

int lesson_0918_6()
{
	unsigned char puc[4];
	struct tagpim
	{
		unsigned char ucpim1;
		unsigned char ucdata0 : 1;
		unsigned char ucdata1 : 2;
		unsigned char ucdata2 : 3;

	}*pst;
	pst = (struct tagpim*)puc;
	memset(puc, 0, 4);
	pst->ucpim1 = 2;
	pst->ucdata0 = 3;
	pst->ucdata1 = 4;
	pst->ucdata2 = 5;
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}

int lesson_0918_7()
{
	union un
	{
		short s[7];
		int n;
	};
	union un a;
	printf("%d\n", sizeof(a));

	return 0;
}





































































