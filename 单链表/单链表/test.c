#include"SList.h"
void ShowSList(SList*pl)
{
	assert(pl);
	Node *cur = pl->Head;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->Next;
	}
	printf("NULL\n");
}
int main()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 2);
	SListPushBack(&s, 4);
	SListPushBack(&s, 2);
	SListRemoveAll(&s, 2);
	/*SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);*/
	ShowSList(&s);
	/*SListRemove(&s, 2);
	ShowSList(&s);*/

	//printf("%d\n", SListEmpty(&s));

	/*printf("%d\n",SListSize(&s));*/

	//SListInsertAfter(SListFind(&s, 1), 0);
	//ShowSList(&s);

	//SListErase(&s,SListFind(&s, 1));


	//SListPushFront(&s,0);
	//SListPopFront(&s);
	//SListPopFront(&s);

	//SListPopBack(&s);
	//SListPopBack(&s);

	SListDestroy(&s);


	return 0;
}