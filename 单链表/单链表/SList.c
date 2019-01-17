#include"SList.h"
void SListInit(SList* pl)
{
	assert(pl);
	pl->Head = NULL;
}
// �������� 
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
// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	assert(pl);
	Node* NewNode = BuyNewNode(data);
	NewNode->Next = pl->Head;
	pl->Head = NewNode;
}
// ɾ�������е�һ���ڵ� 
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
// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
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
// ������posλ�ú������Ϊdata�Ľڵ� 
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
// ��ȡ��������Ч�ڵ�ĸ��� 
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
// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	if (pl->Head == NULL)
	return 0;
	else
	return 1;
}
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	return pl->Head;
}
// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	return pl->Head->Next;
}
//ɾ����һ�γ���data�Ľڵ�
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
//ɾ������ֵΪdata�Ľڵ�
void SListRemoveAll(SList* pl, SDataType data)
{
	Node* tmp = pl->Head;
	while (tmp)
	{
		SListRemove(pl, data);
		tmp = tmp->Next;
	}
}