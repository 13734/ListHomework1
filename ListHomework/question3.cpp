#include<iostream>
#include"LinkList.h"
using namespace std;

template<typename T>
int Frequency(LinkList<T>& list1,const T& data) 
{
	int count = 0;// ��ʼ��������
	int i = list1.LocateElem(data);
	if (!i) return 0;// ����Ҳ�����Ԫ�أ�ֱ�ӷ���0
	T tmp;// ��������Ԫ�ص�һ�γ��ֵ�λ��
	for (; i <= list1.GetLength(); i++)// �ӵ�һ�γ��ֵ�λ�ÿ�ʼ����
	{
		list1.GetElem(i, tmp); // ��ȡ��ǰ��������Ԫ��ֵ
		if (data == tmp) count++;// �����Ԫ�ص��� data�����������һ
	}
	return count;// ���ؼ������
}





