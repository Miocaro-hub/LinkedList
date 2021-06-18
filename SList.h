#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	//�洢�������ݵĶ����ռ��Ϊ�ڵ�
	//һ���ڵ�����������ָ����
	int data;
	struct SListNode* next;

}SListNode, SLTNode;



//����+����ͷ+��ѭ��������
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//��������posλ��֮�����x
//ͬʱ����һ��Ϊʲô����posλ��֮ǰ����
void SListInserAfter(SLTNode* pos, SLTDataType x);

//��posǰ�����һ�������һ���ǳ��鷳�ĵ������Ҫǰһ������next��ָ���²���Ľ��
//���һ�Ҫ�����������ǲ���ֻ��posһ��������pos���ǵ�һ���������
void SListInserBefore(SLTNode* pos, SLTDataType x, SLTNode** pplist);

void SListEraseAfter(SLTNode* pos);