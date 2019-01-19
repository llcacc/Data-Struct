#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;


typedef struct DListNode
{
	DataType data;
	struct DListNode* Pre;
	struct DListNode* Next;
}Node;

void DListInit(Node** pHead);
void DListPushBack(Node* p, DataType data);
void DListPopBack(Node* p);
void DListPushFront(Node* p, DataType data);
void DListPopFront(Node* p);
void DListInsert(Node* p,DataType data);
Node* DListFind(Node* p,DataType data);
void DListErase(Node* pos);
void DListRemove(Node* p, DataType data);
void DListRemoveAll(Node* p, DataType data);

