#include"SqList.h"
#include<iostream>
using namespace std;

template<typename T>
T DelMinElem(SqList<T>& list1)
{
	T min_data; //��ʼ�� ����Сֵ�ı���1
	list1.GetElem(1,min_data); // ��ʼ�� ����Сֵ�ı���2
	int min_index = 1;  //��ʼ����Сֵλ��
	T tmp2;  //�ݴ�����ĳ�ʼ��
	for (int i = 1; i <= list1.GetLength(); i++) //��������Ԫ��
	{
		
		list1.GetElem(i, tmp2); // ȡ����ǰλ�õ�ֵ
		if (min_data > tmp2) //�жϴ�λ��ֵ�Ƿ��С
		{
			min_index = i; //����Сֵ������Ϊ���λ��
			min_data = tmp2; //��Ϊ��Сֵ
		}
	}
	
	if (min_index != list1.GetLength()) //�ж���Сֵ�Ƿ��������ʵ������Ҫ��������ִ��
	{
		list1.GetElem(list1.GetLength(), tmp2); //ȡ������ֵ
		list1.SetElem(min_index, tmp2); // ������ֵ�滻��Сֵ
	}
		
	list1.DeleteElem(list1.GetLength(), tmp2);  //ɾ������Ԫ��

	return min_data; //������Сֵ
}

template<typename T>
void DelValue(SqList<T>& list1, const T& data)
{
	T tmp; // ��ʱ���������ڴ洢��ǰ��������Ԫ��
	for (int i = 1; i <= list1.GetLength(); i++)// ����˳����е�ÿһ��Ԫ��
	{
		list1.GetElem(i, tmp);// ��ȡ��ǰ��������Ԫ��ֵ
		if (tmp == data) // �����Ԫ�ص�����Ҫɾ����ֵ
		{
			list1.DeleteElem(i, tmp);// ɾ����Ԫ��
			i--;  // ��Ϊɾ����Ԫ�أ�������Ҫ����һ���������жϴ�λ���Ƿ����
		}

	}
}

template<typename T>
void DelRepElem(SqList<T>& list1)
{
	T tmp1,tmp2;// ����������ʱ����
	for (int i = 1; i <= list1.GetLength(); i++)// ����˳����е�ÿһ��Ԫ��
	{
		list1.GetElem(i, tmp1);// ��ȡ��ǰ��������Ԫ��ֵ
		for (int j = i + 1; j <= list1.GetLength(); j++)// �ٴα���˳����е�ÿһ��Ԫ�أ���i+1��ʼ����Ϊ����Ҫ�Ƚ�����
		{
			list1.GetElem(j, tmp2);// ��ȡ��ǰ��������Ԫ��ֵ
			if (tmp1 == tmp2) //�жϺ���Ԫ���Ƿ���ǰ��Ԫ�����
			{
				list1.DeleteElem(j, tmp2); //ɾ������Ԫ��
				j--; // ��Ϊɾ����Ԫ�أ�������Ҫ����һ���������жϴ�λ���Ƿ����
			}
		}
	}
}

#include <iostream>
#include <assert.h>
using namespace std;
#include "Status.h"
#include "SqList.h"

//����˳���Ԫ�ص����
template <class DataType>
void Display(const DataType& e)
{
	cout << e << "  ";
}

