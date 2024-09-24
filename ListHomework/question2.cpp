#include<iostream>
#include"SqList.h"
using namespace std;

template<typename T>
void OrdListInsertElem(SqList<T>& list1, T& data)
{
	int index = 0;// ��ʼ������
	T tmp1;//������ʱ����
	do{ 
		index++; //�Ƶ� ��һ/��һ����
		list1.GetElem(index , tmp1); // ��ȡ��ǰ��������Ԫ��
		
	} while (tmp1 <= data && index <= list1.GetLength()); // ֪��ǰ��Ԫ�ض����ڴ���Ԫ�ػ� һֱ�����
	list1.InsertElem(index, data); // ���ҵ���λ�ò�������Ԫ�� data
}

template<typename T>
void OrdListDeleteElem(SqList<T>& list1, T& data)
{

	int index = 0; // ��ʼ������
	T tmp1; //������ʱ����
	do {
		index++; //�Ƶ� ��һ/��һ����
		list1.GetElem(index, tmp1); // ��ȡ��ǰ��������Ԫ��
		if (tmp1 == data) // ����ҵ�ֵΪ data ��Ԫ��
		{
			list1.DeleteElem(index,tmp1); // ɾ����Ԫ��
			index--; //���¼�鵱ǰλ��
		}

	} while (tmp1 <= data && index < list1.GetLength()); //��ǰԪ��С�ڵ���data������δ��������ʱ

}


template<typename T>
Status OrdListMerge(SqList<T>& list1, SqList<T>& list2, SqList<T>& list3)
{
	//if (list3.maxSize < (list1.GetLength() + list2.GetLength())) return OVER_FLOW;  //��ôû��֪����󳤶ȵĺ���
	Status sts = SUCCESS;//Ĭ�� ��ʼ��״̬Ϊ�ɹ�
	list3.Clear();// ���Ŀ���б� ��ֹ�б�ǿ�
	int index1 = 1;// ��ʼ�������б������
	int index2 = 1;// ��ʼ�������б������
	T tmp1, tmp2; //������ʱ����
	while (index1 <= list1.GetLength() && index2 <= list2.GetLength()) //һֱѭ��ֱ������һ����ȫ������
	{
		list1.GetElem(index1, tmp1); // ��ȡ��һ���б�ĵ�ǰԪ��
		list2.GetElem(index2, tmp2); // ��ȡ�ڶ����б�ĵ�ǰԪ��
		if (tmp1 <= tmp2) // �����һ���б��Ԫ��С�ڵ��ڵڶ����б��Ԫ�� ����СԪ�ؼ���
		{
			list3.InsertElem(list3.GetLength()+1, tmp1);// ����С��Ԫ�ز��뵽���б���
			index1++; // ���ӵ�һ���б������
		}
		else
		{
			list3.InsertElem(list3.GetLength()+1, tmp2);//ͬ�� ����С��Ԫ�ز��뵽���б���
			index2++; // ���ӵ�һ���б������
		}
	}
	
	while ( index1 <= list1.GetLength() ) //Ԫ�ز�Ϊ����ʣ��Ԫ�ؼ����3
	{
		list1.GetElem(index1, tmp1); //��ȡ��ǰλ��Ԫ��
		sts =  list3.InsertElem(list3.GetLength() + 1, tmp1); //�����3   һ��ֻ��Ҫ֪�����Ĳ����Ƿ���ȷ�Ϳ���֪�� �б��Ƿ�װ��
		index1++; //����
	}

	while (index2 <= list2.GetLength()) //�Եڶ����б������ͬ���� ������ֻ����һ���ǿգ�
	{
		list2.GetElem(index2, tmp2);  //ͬ��
		sts = list3.InsertElem(list3.GetLength() + 1, tmp2); //ͬ��
		index2++; //ͬ��
	}
	return sts; // �������յ�״̬
	              
}

template<typename T>
Status OrdListIntervalDelete(SqList<T>& list1, int s, int t)
{
	if (s > t || list1.IsEmpty()) return FAILED;// ��� s ���� t �����б�Ϊ�գ���ʧ��
	int index = 0;// ��ʼ������
	T tmp1; //������ʱ����
	do {
		index++; // ��������ֵ
		list1.GetElem(index, tmp1);// ��ȡ��ǰ��������Ԫ��
		if (tmp1>=s && tmp1 <= t ) // ���Ԫ���� [s, t] ������ ɾ��
		{
			list1.DeleteElem(index, tmp1); // ɾ����Ԫ��
			index--; // ��С����ֵ�����¼�鵱ǰλ��
		}

	} while (tmp1 <= t && index < list1.GetLength()); // �ж�����Ϊ��ǰԪ��С�ڵ��� t ������δ��������ʱ������ѭ��
	return SUCCESS; //ȫ��������ɹ�
}




