#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SDataType;
typedef struct SListNode
{
	SDataType data;
	struct SListNode* Next;
}Node;
typedef struct SList
{
	Node* Head;
}SList;
//// ����ĳ�ʼ�� 
void SListInit(SList* pl);
//
//// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data);
//
// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl);
//
// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data);
//
// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl);
//
// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, SDataType data);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data);

// �������� 
void SListDestroy(SList* pl);

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);
//
// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl);
//ɾ����һ�γ���data�Ľڵ�
void SListRemove(SList* pl, SDataType data);
//ɾ������ֵΪdata�Ľڵ�
void SListRemoveAll(SList* pl, SDataType data);