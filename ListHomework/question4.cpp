#include<iostream>
#include"LinkList.h"
using namespace std;

template<typename T>
void OrdListInsertElem(LinkList<T>& list1, T& data)
{
	int index = 0;// 初始化插入位置索引
	T tmp;// 临时变量，用于存储当前遍历到的元素
	for (int i = 1; i <= list1.GetLength(); i++) // 遍历链表，找到合适的位置
	{
		list1.GetElem(i, tmp);// 获取当前索引处的元素值
		if (data < tmp) //当后面元素大于此元素，即为合适位置
		{
			index = i;// 记录插入位置
			break;// 结束循环 
		}
	}
	if (index) list1.InsertElem(index, data); // 如果找到了插入位置
	else list1.InsertElem(list1.GetLength() + 1, data);// 如果没有找到插入位置，则插入到链表末尾
}

template<typename T>
void OrdListDeleteElem(LinkList<T>& list1, T& data) //链表顺不顺序都能用， 效率不低于不改变类的情况下 我能想到的最快的函数
{
	T tmp; // 临时变量，仅用于调用del方法
	int i = list1.LocateElem(data);// 查找数据元素第一次出现的位置
	while (i)
	{
		list1.DeleteElem(i, tmp);// 删除当前索引处的元素
		i = list1.LocateElem(data); // 继续查找下一个相同值的元素
	}

}

