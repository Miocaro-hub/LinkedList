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
	//����ı���
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x) //ָ��֮�䷢������,Ҫ������ָ��
{
	//����һ���µĽ��
	SListNode* newnode = BuySLTNode(x);

	//�ж�Ҫ����������ǲ��ǿձ�,�ǿձ����plistָ��newnode
	if (pplist == NULL)
	{
		pplist = newnode;
	}

	//����������β
	SLTNode* tail = pplist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	//��β��Ľ����������
	tail->next = newnode;
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	//����һ���µĽ��
	SListNode* newnode = BuySLTNode(x);

	//�²���������һ�����ĵ�ַ
	newnode->next = *pplist;

	//��plistָ��newnode
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	///����һ��ǰ��ָ��(Ŀ���Ǽ�¼tailָ���ǰһ�����)
	SLTNode* prev = NULL;

	//��һ�����:����Ϊ�ձ�
	if (*pplist == NULL)
	{
		return;
	}
	//�ڶ������:����ֻ��һ�����
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//���������:������
	else
	{
		//��������β
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
	//�ж��Ƿ�Ϊ�ձ�
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

	//�ж�pos�ǲ�������ĵ�һ�����
	//���൱��ͷ��
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
