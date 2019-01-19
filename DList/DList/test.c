#include"DList.h"
void DListShow(Node* p)
{
	assert(p);
	if (p->Next == p)
	{
		return;
	}
	else
	{
		Node* cur = p->Next;
		while (cur != p)
		{
			printf("%d  ", cur->data);
			cur = cur->Next;
		}
		printf("\n");
	}
}
int main()
{
	Node * d = NULL;
	DListInit(&d);
	DListPushBack(d, 1);
	DListPushBack(d, 2);
	DListPushBack(d, 3);
	DListPushBack(d, 4);
	DListPushBack(d, 3);
	DListPushBack(d, 4);
	DListPushBack(d, 3);
	DListShow(d);
	DListRemoveAll(d, 3);
	/*DListRemove(d,3);*/
	/*DListErase(DListFind(d, 3));*/
	/*DListPopFront(d);*/


	/*DListInsert(DListFind(d, 3), 9);*/
	//DListPushFront(d, 9);


	/*DListPopBack(d);
	DListShow(d);*/


	DListShow(d);
	system("pause");
	return 0;
}