#include"SeqList.h"

void ShowSeqList(SeqList* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->array[i]);
	}
	printf("\n");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
			
	SeqListPushBack(&s, 0);						//尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 6);
	ShowSeqList(&s);
	//SeqListRemoveAll(&s, 2);  // 移除顺序表中所有值为data的元素 
	//ShowSeqList(&s);
	//printf("尾插0 1 2 3 4 5 6\n");
	//ShowSeqList(&s);
	//SeqListPopback(&s);							//尾删一位
	//printf("尾删\n");
	//ShowSeqList(&s);
	//SeqListPushFront(&s, 9);					//头插 9
	//printf("头插 9\n");
	//ShowSeqList(&s);
	//SeqListPopFront(&s);
	//printf("头删\n");
	//ShowSeqList(&s);
	//SeqListInsert(&s, 2, 10);					//在第下标为n的位置插入data
	/*ShowSeqList(&s);*/
	//SeqListDelete(&s, 0);							//删除第n个下标的数
	//ShowSeqList(&s);
	//int find = SeqListFind(&s, 1);
	//if (find >= 0)
	//	printf("1的下标为%d\n", find);
	//else
	//	printf("没找到\n");
	//SeqListRemove(&s, 1);					//移除一个第一次出现的数
	//printf("移除顺序表中第一个值为1的元素\n");
	//ShowSeqList(&s);
	//printf("有效元素个数为%d\n",SeqListSize(&s));
	//printf("容量为%d\n", SeqListCapacity(&s));
	//int ret = SeqListEmpty(&s);
	//if (0 == ret)
	//{
	//	printf("为空\n");
	//}
	//else
	//{
	//	printf("不为空\n");
	//}
	//printf("第一个元素为%d\n", SeqListFront(&s));
	//printf("最后一个元素为%d\n", SeqListBack(&s));
	SeqListDestroy(&s);
	return 0;
}