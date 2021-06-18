#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void TestList1()
{
	SListNode* plist = NULL;  
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
    SListPrint(plist);
	
	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

void TestList2()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

}

void TestList3()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		//�˴����Լ���޸����ݵĹ���
		//pos->data = 30;
		printf("�ҵ���\n");
	}
	else
	{
		printf("û���ҵ�\n");
	}

	SListPrint(plist);
}

void TestList4()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SLTNode* pos = SListFind(plist, 3);

	SListInserAfter(pos,30);
	SListInserBefore(pos, 40, &plist);
	SListPrint(plist);

	SListEraseAfter(pos);
	SListPrint(plist);
}

int main()
{
	struct SListNode* node1 = malloc(sizeof(struct SListNode));
	struct SListNode* node2 = malloc(sizeof(struct SListNode));
	struct SListNode* node3 = malloc(sizeof(struct SListNode));
	struct SListNode* node4 = malloc(sizeof(struct SListNode));
	
	//�ӵ�ַ���Կ�������Ĵ洢������������
	/*printf("%p\n", node1);
	printf("%p\n", node2);
	printf("%p\n", node3);
	printf("%p\n", node4);*/

	TestList1();
	TestList2();
	TestList3();
	TestList4();

	return 0;
}