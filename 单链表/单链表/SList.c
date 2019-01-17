#include"SList.h"
void SListInit(SList* pl)
{
	assert(pl);
	pl->Head = NULL;
}
// 销毁链表 
void SListDestroy(SList* pl)
{
	assert(pl);
	Node* cur = pl->Head;
	Node* pos = NULL;
	while (cur)
	{
		pos = cur;
		cur = cur->Next;
		free(pos);
	}
	pl->Head = NULL;
}
Node *BuyNewNode(SDataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->data = data;
	NewNode->Next = NULL;
	return NewNode;
}
void SListPushBack(SList* pl, SDataType data)
{
	Node *NewNode = NULL;
	assert(pl);
	Node* Cur = pl->Head;
	NewNode = BuyNewNode(data);
	if (NULL == pl->Head)
	{
		pl->Head = NewNode;
	}
	else if (Cur->Next != NULL)
	{
		
		while (Cur->Next != NULL)
		{
			Cur = Cur->Next;
		}
		Cur->Next = NewNode;
	}
	else
	{
		Cur->Next = NewNode;
	}
}
void SListPopBack(SList* pl)
{
	assert(pl);
	Node *cur = pl->Head;
	if (pl->Head == NULL)
	{
		return;
	}
	else if (cur->Next!=NULL)
	{
		cur = pl->Head;
		while (cur->Next->Next)
		{
			cur = cur->Next;
		}
		free(cur->Next);
		cur->Next = NULL;
	}
	else
	{
		free(cur);
		cur = NULL;
		pl->Head = NULL;
	}

}
// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	assert(pl);
	Node* NewNode = BuyNewNode(data);
	NewNode->Next = pl->Head;
	pl->Head = NewNode;
}
// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	assert(pl);
	if (pl->Head == NULL)
	{
		return;
	}
	Node* p = pl->Head;
	pl->Head = pl->Head->Next;
	free(p);
	p = NULL;
}
// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data)
{
	assert(pl);
	Node *cur = pl->Head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->Next;
	}
	return NULL;
}
// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data)
{
	assert(pos);
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Next = pos->Next;
	NewNode->data = data;
	pos->Next = NewNode;
}

void SListErase(SList* pl, Node* pos)
{
	assert(pl);
	assert(pos);
	Node* tmp = NULL;
	if (pl->Head == NULL)
	{
		return;
	}
	tmp = pos->Next->Next;
	free(pos->Next);
	pos->Next = tmp;
}
// 获取链表中有效节点的个数 
int SListSize(SList* pl)
{
	int count = 0;
	Node* tmp = pl->Head;
	while (tmp)
	{
		count++;
		tmp = tmp->Next;
	}
	return count;
}
// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	if (pl->Head == NULL)
	return 0;
	else
	return 1;
}
// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	return pl->Head;
}
// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	return pl->Head->Next;
}
//删除第一次出现data的节点
void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	Node *tmp = pl->Head;
	Node *pos = NULL;
	while (tmp)
	{
		if (tmp->data == data)
		{
			pl->Head = tmp->Next;
			free(tmp);
			tmp = NULL;
			return;
		}
		else if (tmp->Next->data == data)
		{
			pos = tmp;
			SListErase(pl, pos);
			return;
		}
		tmp = tmp->Next;
	}
}
//删除所有值为data的节点
void SListRemoveAll(SList* pl, SDataType data)
{
	Node* tmp = pl->Head;
	while (tmp)
	{
		SListRemove(pl, data);
		tmp = tmp->Next;
	}
}