#include"DList.h"
Node* BuyNewNode(DataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->Pre = NULL;
	NewNode->Next = NULL;
	NewNode->data = data;
	return NewNode;
}
void DListInit(Node** pHead)
{
	assert(pHead);
	Node* New = BuyNewNode(0);
	New->Next = New;
	New->Pre = New;
	*pHead = New;
}
void DListPushBack(Node* p, DataType data)
{
	assert(p);
	Node* NewNode = BuyNewNode(data);
	NewNode->Next = p;
	NewNode->Pre = p->Pre;
	p->Pre->Next = NewNode;
	p->Pre = NewNode;

}
void DListPopBack(Node* p)
{
	assert(p);
	if (p->Next == p)
	{
		return;
	}
	else
	{
		p->Pre = p->Pre->Pre;
		free(p->Pre->Next);
		p->Pre->Next = p;
	}
}
void DListPushFront(Node* p, DataType data)
{
	assert(p);
	Node* NewNode = BuyNewNode(data);
	NewNode->Next = p->Next;
	NewNode->Pre = p;
	p->Next->Pre = NewNode;
	p->Next = NewNode;
}
void DListPopFront(Node* p)
{
	assert(p);
	Node* Del = p->Next;
	p->Next->Next->Pre = p;
	p->Next = p->Next->Next;
	free(Del);
	Del = NULL;
}
Node* DListFind(Node* p,DataType data)
{
	assert(p);
	Node* cur = p->Next;
	while (cur != p)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->Next;
	}
	return NULL;
}
void DListInsert(Node* pos, DataType data)
{
	assert(pos);
	Node* NewNode = BuyNewNode(data);
	NewNode->Next = pos;
	NewNode->Pre = pos->Pre;
	pos->Pre->Next = NewNode;
	pos->Pre = NewNode;
}
void DListErase(Node* pos)
{
	assert(pos);
	pos->Next->Pre = pos->Pre;
	pos->Pre->Next = pos->Next;
	free(pos);
	pos = NULL;
}
void DListRemove(Node* p, DataType data)
{
	assert(p);
	Node *cur = p->Next;
	while (cur->Next!=p)
	{
		if (cur->data == data)
		{
			break;
		}
		cur = cur->Next;
	}
	cur->Next->Pre = cur->Pre;
	cur->Pre->Next = cur->Next;
	free(cur);
	cur = NULL;
}
void DListRemoveAll(Node* p, DataType data)
{
	assert(p);
	Node* pos = p->Next;
	while (pos != p)
	{
		if (pos->data == data)
		{
			Node* cur = pos;
			pos = pos->Next;

			cur->Next->Pre = cur->Pre;
			cur->Pre->Next = cur->Next;
			free(cur);
		}
		else
		{
			pos = pos->Next;
		}
	}
}