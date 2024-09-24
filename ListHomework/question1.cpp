#include"SqList.h"
#include<iostream>
using namespace std;

template<typename T>
T DelMinElem(SqList<T>& list1)
{
	T min_data; //初始化 存最小值的变量1
	list1.GetElem(1,min_data); // 初始化 存最小值的变量2
	int min_index = 1;  //初始化最小值位置
	T tmp2;  //暂存变量的初始化
	for (int i = 1; i <= list1.GetLength(); i++) //遍历所有元素
	{
		
		list1.GetElem(i, tmp2); // 取出当前位置的值
		if (min_data > tmp2) //判断此位置值是否更小
		{
			min_index = i; //将最小值索引改为这个位置
			min_data = tmp2; //改为更小值
		}
	}
	
	if (min_index != list1.GetLength()) //判断最小值是否在最后（其实并不需要）不是则执行
	{
		list1.GetElem(list1.GetLength(), tmp2); //取出最后的值
		list1.SetElem(min_index, tmp2); // 用最后的值替换最小值
	}
		
	list1.DeleteElem(list1.GetLength(), tmp2);  //删除最后的元素

	return min_data; //返回最小值
}

template<typename T>
void DelValue(SqList<T>& list1, const T& data)
{
	T tmp; // 临时变量，用于存储当前遍历到的元素
	for (int i = 1; i <= list1.GetLength(); i++)// 遍历顺序表中的每一个元素
	{
		list1.GetElem(i, tmp);// 获取当前索引处的元素值
		if (tmp == data) // 如果该元素等于需要删除的值
		{
			list1.DeleteElem(i, tmp);// 删除该元素
			i--;  // 因为删除了元素，所以需要回退一步，重新判断此位置是否相等
		}

	}
}

template<typename T>
void DelRepElem(SqList<T>& list1)
{
	T tmp1,tmp2;// 定义两个临时变量
	for (int i = 1; i <= list1.GetLength(); i++)// 遍历顺序表中的每一个元素
	{
		list1.GetElem(i, tmp1);// 获取当前索引处的元素值
		for (int j = i + 1; j <= list1.GetLength(); j++)// 再次遍历顺序表中的每一个元素（从i+1开始，因为不需要比较自身
		{
			list1.GetElem(j, tmp2);// 获取当前索引处的元素值
			if (tmp1 == tmp2) //判断后面元素是否与前面元素相等
			{
				list1.DeleteElem(j, tmp2); //删除后面元素
				j--; // 因为删除了元素，所以需要回退一步，重新判断此位置是否相等
			}
		}
	}
}

#include <iostream>
#include <assert.h>
using namespace std;
#include "Status.h"
#include "SqList.h"

//用于顺序表元素的输出
template <class DataType>
void Display(const DataType& e)
{
	cout << e << "  ";
}

