#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	//存储单个数据的独立空间称为节点
	//一个节点包含数据域和指针域
	int data;
	struct SListNode* next;

}SListNode, SLTNode;



//单项+不带头+不循环的链表
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//单链表在pos位置之后插入x
//同时考虑一下为什么不在pos位置之前插入
void SListInserAfter(SLTNode* pos, SLTDataType x);

//在pos前面插入一个结点有一个非常麻烦的点就是需要前一个结点的next来指向新插入的结点
//而且还要考虑链表中是不是只有pos一个结点或者pos就是第一个结点的情况
void SListInserBefore(SLTNode* pos, SLTDataType x, SLTNode** pplist);

void SListEraseAfter(SLTNode* pos);