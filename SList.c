#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
	//链表的遍历
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x) //指针之间发生交换,要传二级指针
{
	//创建一个新的结点
	SListNode* newnode = BuySLTNode(x);

	//判断要插入的链表是不是空表,是空表就让plist指向newnode
	if (pplist == NULL)
	{
		pplist = newnode;
	}

	//遍历链表找尾
	SLTNode* tail = pplist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	//把尾插的结点链接起来
	tail->next = newnode;
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	//创建一个新的结点
	SListNode* newnode = BuySLTNode(x);

	//新插入结点存放下一个结点的地址
	newnode->next = *pplist;

	//将plist指向newnode
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	///创建一个前驱指针(目的是记录tail指向的前一个结点)
	SLTNode* prev = NULL;

	//第一种情况:链表为空表
	if (*pplist == NULL)
	{
		return;
	}
	//第二种情况:链表只有一个结点
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//第三种情况:多个结点
	else
	{
		//遍历表找尾
		SLTNode* tail = pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pplist)
{
	//判断是否为空表
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;
		free(*pplist);

		*pplist = next;
	}
}

SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

void SListInserAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInserBefore(SLTNode* pos, SLTDataType x,SLTNode** pplist)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);

	//判断pos是不是链表的第一个结点
	//就相当于头插
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}

		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}
