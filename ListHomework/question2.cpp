#include<iostream>
#include"SqList.h"
using namespace std;

template<typename T>
void OrdListInsertElem(SqList<T>& list1, T& data)
{
	int index = 0;// 初始化索引
	T tmp1;//声明临时变量
	do{ 
		index++; //移到 第一/下一索引
		list1.GetElem(index , tmp1); // 获取当前索引处的元素
		
	} while (tmp1 <= data && index <= list1.GetLength()); // 知道前面元素都大于待定元素或 一直到最后
	list1.InsertElem(index, data); // 在找到的位置插入数据元素 data
}

template<typename T>
void OrdListDeleteElem(SqList<T>& list1, T& data)
{

	int index = 0; // 初始化索引
	T tmp1; //声明临时变量
	do {
		index++; //移到 第一/下一索引
		list1.GetElem(index, tmp1); // 获取当前索引处的元素
		if (tmp1 == data) // 如果找到值为 data 的元素
		{
			list1.DeleteElem(index,tmp1); // 删除该元素
			index--; //重新检查当前位置
		}

	} while (tmp1 <= data && index < list1.GetLength()); //当前元素小于等于data且索引未超出长度时

}


template<typename T>
Status OrdListMerge(SqList<T>& list1, SqList<T>& list2, SqList<T>& list3)
{
	//if (list3.maxSize < (list1.GetLength() + list2.GetLength())) return OVER_FLOW;  //怎么没有知道最大长度的函数
	Status sts = SUCCESS;//默认 初始化状态为成功
	list3.Clear();// 清空目标列表 防止列表非空
	int index1 = 1;// 初始化两个列表的索引
	int index2 = 1;// 初始化两个列表的索引
	T tmp1, tmp2; //声明临时变量
	while (index1 <= list1.GetLength() && index2 <= list2.GetLength()) //一直循环直到其中一个表全部插入
	{
		list1.GetElem(index1, tmp1); // 获取第一个列表的当前元素
		list2.GetElem(index2, tmp2); // 获取第二个列表的当前元素
		if (tmp1 <= tmp2) // 如果第一个列表的元素小于等于第二个列表的元素 将最小元素加入
		{
			list3.InsertElem(list3.GetLength()+1, tmp1);// 将较小的元素插入到新列表中
			index1++; // 增加第一个列表的索引
		}
		else
		{
			list3.InsertElem(list3.GetLength()+1, tmp2);//同理 将较小的元素插入到新列表中
			index2++; // 增加第一个列表的索引
		}
	}
	
	while ( index1 <= list1.GetLength() ) //元素不为空则将剩下元素加入表3
	{
		list1.GetElem(index1, tmp1); //获取当前位置元素
		sts =  list3.InsertElem(list3.GetLength() + 1, tmp1); //插入表3   一般只需要知道最后的步骤是否正确就可以知道 列表是否装满
		index1++; //继续
	}

	while (index2 <= list2.GetLength()) //对第二个列表进行相同操作 （两个只会有一个非空）
	{
		list2.GetElem(index2, tmp2);  //同理
		sts = list3.InsertElem(list3.GetLength() + 1, tmp2); //同理
		index2++; //同理
	}
	return sts; // 返回最终的状态
	              
}

template<typename T>
Status OrdListIntervalDelete(SqList<T>& list1, int s, int t)
{
	if (s > t || list1.IsEmpty()) return FAILED;// 如果 s 大于 t 或者列表为空，则失败
	int index = 0;// 初始化索引
	T tmp1; //定义临时变量
	do {
		index++; // 增加索引值
		list1.GetElem(index, tmp1);// 获取当前索引处的元素
		if (tmp1>=s && tmp1 <= t ) // 如果元素在 [s, t] 区间内 删掉
		{
			list1.DeleteElem(index, tmp1); // 删除该元素
			index--; // 减小索引值，重新检查当前位置
		}

	} while (tmp1 <= t && index < list1.GetLength()); // 判断条件为当前元素小于等于 t 且索引未超出长度时，继续循环
	return SUCCESS; //全部结束则成功
}




