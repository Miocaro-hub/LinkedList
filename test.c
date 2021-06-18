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
		//此处可以兼具修改数据的功能
		//pos->data = 30;
		printf("找到了\n");
	}
	else
	{
		printf("没有找到\n");
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
	
	//从地址可以看出链表的存储并不是连续的
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