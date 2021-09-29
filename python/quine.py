"""
--------------------------------------------------------------------
Author: watercsand
git:	waterpull
email: 1337259688@qq.com
area:	China

this file only upload on the github
only for learning
if you see this file on any other website
!!!!!that all without permitted!!!!!
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
--------------------------------------------------------------------
"""


# 传入最小项的列表和元素的个数
# 返回一个用二进制表示的最小项列表
def init_min(list_min, var):
    # print(list_min)
    min_bin = []
    for i in list_min:
        each_num1 = "{}".format(bin(i)[2:])
        each_num2 = "{}".format('0'*(var - len(each_num1)))
        each_num = each_num2 + each_num1
        min_bin.append(each_num)
        # print(each_num)
    # print(min_bin)
    return min_bin


# 根据1的个数进行排序,返回一个二层嵌套的列表
# 传入的必须是无嵌套列表
def list_sort(list_change, var):
    list_return = []
    count_one = 0
    for i in range(var + 1):
        list_return.append([])
    # print(list_return)
    length = len(list_change)
    for i in range(length):
        # print(list_change[i], end='  ')
        count_one = 0
        for k in list_change[i]:
            if k == '1':
                count_one += 1
        list_return[count_one].append(list_change[i])
    return list_return


def compare(list_copy, list_return):
    list_return2 = []
    flag_1 = 0
    flag_2 = 0
    p_1 = 0
    var = len(list_copy[0])
    # print("list_copy=", list_copy)
    # print("list_return=", list_return)
    for i in range(len(list_copy)):
        flag_2 = 0
        for j in range(len(list_return)):
            flag_1 = 0
            p_1 = j
            # print(list_return[j], list_copy[i])
            for k in range(var):
                # print(list_copy[i][k], list_return[j][k])
                if list_return[j][k] == '-' or list_return[j][k] == list_copy[i][k]:
                    flag_1 += 1
            if flag_1 == var:
                # print("find\n")
                flag_2 = 1
                break
        if flag_2 == 0:
            list_return2.append(list_copy[i])
    # print("list_return2", list_return2)
    # print("list_return2=", list_return2)
    return list_return2



def merge(list_input, var):
    list_change = list_input
    list_change2 = list_input
    list_return = []    # 能合并的返回列表
    list_return2 = []   # 不能合并的返回列表
    list_copy = []
    change = 0
    flag = 0
    flag_2 = 0
    change_place = -1
    each_str = ''
    each_str2 = ''
    for i in range(var):
        # print(list_change[i])
        # print(list_change[i + 1])
        for k in range(len(list_change[i])):
            for j in range(len(list_change[i + 1])):
                # print(list_change[i][k], end=' ')
                # print(list_change[i + 1][j])
                change = 0
                change_place = -1
                each_str = list_change[i][k]
                each_str2 = ''
                for m in range(var):
                    if list_change[i][k][m] != list_change[i + 1][j][m]:
                        change_place = m
                        change += 1
                    if change >= 2:
                        change = 0
                        change_place = -1
                        break
                # print("each_str", each_str)
                if change > 0:
                    for n in range(var):
                        if n != change_place:
                            each_str2 += each_str[n]
                        else:
                            each_str2 += '-'
                    # print("each_str2", each_str2)
                    list_return.append(each_str2)
                    flag = 1
    # print("list_input=", list_input)
    length_list_return = len(list_return)
    length_list_change2 = len(list_change2)
    # print("list_return=", list_return)
    for i in list_change2:
        for j in i:
            list_copy.append(j)
    # print("list_copy", list_copy)
    list_return2 = compare(list_copy, list_return)
    return list_return, list_return2, flag


def del_same(list_input):
    list_change = list_input
    length = len(list_change)
    i = 0
    j = 0
    while i < length - 1:

        j = i + 1
        while j < length:
            # print(list_change[i], list_change[j])
            if list_change[i] == list_change[j]:

                del list_change[j]
                length -= 1
            j += 1
        # print()
        i += 1
    return list_change


# 化简函数主体，输入一个最小项的列表和元素的个数
def qu(list_input, var):
    list_un_merge = []
    # list_input = [0, 1, 2, 5, 6, 7, 8, 9, 10, 14]
    #
    # var = 4
    list_first = init_min(list_input, var)
    list_change = list_first
    flag = 1
    list_un_merge_each = []
    list_return = []
    # print()
    while flag:
        list_change = list_sort(list_change, var)
        # print("list_sort=", list_change)
        list_change, list_un_merge_each, flag = merge(list_change, var)
        # print("list_merge1=", list_change)
        list_change = del_same(list_change)
        # print("list_merge2=", list_change)
        # print("list_un_merge_each1", list_un_merge_each)
        list_un_merge_each = del_same(list_un_merge_each)
        # print("!!!list_un_merge_each2", list_un_merge_each)
        # print("flag=", flag)
        list_un_merge.append(list_un_merge_each)
    # print(list_un_merge)
    for i in list_un_merge:
        for j in i:
            list_return.append(j)
    return list_return
    # flag = 1
    # print(a)
    # b = list_sort(a, 4)
    # print(b)
    # c, d, flag = merge(b, 4)
    # print(flag)
    # # c, d = merge([[], ['0001', '1000'], ['0110', '1001'], [], ['1111']], 4)
    # # print("aaa", c)
    # # print("bbb", d)
    # print("list_combine=", c)
    # print("list_un_combine=", d)
    # c = del_same(c)
    # print(c)


a = qu([2, 3, 7, 9, 10, 11, 12, 13, 18, 19, 22, 23, 26, 27, 30, 31], 5)
print(a)

