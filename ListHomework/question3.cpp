#include<iostream>
#include"LinkList.h"
using namespace std;

template<typename T>
int Frequency(LinkList<T>& list1,const T& data) 
{
	int count = 0;// 初始化计数器
	int i = list1.LocateElem(data);
	if (!i) return 0;// 如果找不到该元素，直接返回0
	T tmp;// 查找数据元素第一次出现的位置
	for (; i <= list1.GetLength(); i++)// 从第一次出现的位置开始遍历
	{
		list1.GetElem(i, tmp); // 获取当前索引处的元素值
		if (data == tmp) count++;// 如果该元素等于 data，则计数器加一
	}
	return count;// 返回计数结果
}





