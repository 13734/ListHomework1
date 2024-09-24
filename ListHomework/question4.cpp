#include<iostream>
#include"LinkList.h"
using namespace std;

template<typename T>
void OrdListInsertElem(LinkList<T>& list1, T& data)
{
	int index = 0;// ��ʼ������λ������
	T tmp;// ��ʱ���������ڴ洢��ǰ��������Ԫ��
	for (int i = 1; i <= list1.GetLength(); i++) // ���������ҵ����ʵ�λ��
	{
		list1.GetElem(i, tmp);// ��ȡ��ǰ��������Ԫ��ֵ
		if (data < tmp) //������Ԫ�ش��ڴ�Ԫ�أ���Ϊ����λ��
		{
			index = i;// ��¼����λ��
			break;// ����ѭ�� 
		}
	}
	if (index) list1.InsertElem(index, data); // ����ҵ��˲���λ��
	else list1.InsertElem(list1.GetLength() + 1, data);// ���û���ҵ�����λ�ã�����뵽����ĩβ
}

template<typename T>
void OrdListDeleteElem(LinkList<T>& list1, T& data) //����˳��˳�����ã� Ч�ʲ����ڲ��ı��������� �����뵽�����ĺ���
{
	T tmp; // ��ʱ�����������ڵ���del����
	int i = list1.LocateElem(data);// ��������Ԫ�ص�һ�γ��ֵ�λ��
	while (i)
	{
		list1.DeleteElem(i, tmp);// ɾ����ǰ��������Ԫ��
		i = list1.LocateElem(data); // ����������һ����ֵͬ��Ԫ��
	}

}

