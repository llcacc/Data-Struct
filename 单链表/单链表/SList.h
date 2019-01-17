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
//// 链表的初始化 
void SListInit(SList* pl);
//
//// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, SDataType data);
//
// 删除链表最后一个节点 
void SListPopBack(SList* pl);
//
// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data);
//
// 删除链表中第一个节点 
void SListPopFront(SList* pl);
//
// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data);

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data);

// 销毁链表 
void SListDestroy(SList* pl);

// 获取链表中有效节点的个数 
int SListSize(SList* pl);
//
// 检测链表是否为空 
int SListEmpty(SList* pl);
// 获取链表的第一个节点 
Node* SListFront(SList* pl);

// 获取链表的第二个节点 
Node* SListBack(SList* pl);
//删除第一次出现data的节点
void SListRemove(SList* pl, SDataType data);
//删除所有值为data的节点
void SListRemoveAll(SList* pl, SDataType data);