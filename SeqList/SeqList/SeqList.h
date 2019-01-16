#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int DataType;


typedef struct SeqList
{
	DataType* array;
	int size;
	int capacity;
}SeqList;


void SeqListPushBack(SeqList* p, DataType data);//尾插
void SeqListInit(SeqList* p);//初始化
void SeqListPopback(SeqList* p);//尾删
void SeqListPushFront(SeqList* p, DataType Data);//头插
void SeqListPopFront(SeqList* p);//头删
void SeqListInsert(SeqList* p, int pos, DataType data);//任意插
void SeqListDestroy(SeqList*p);//销毁顺序表
void SeqListDelete(SeqList* p, int pos);//任意删
int SeqListFind(SeqList* p, DataType data);//查找data的下标
void SeqListRemove(SeqList* p, DataType data);//移除顺序表中第一个值为data的元素
void SeqListRemoveAll(SeqList* p, DataType data);// 移除顺序表中所有值为data的元素 
 
int SeqListSize(SeqList* p);// 获取顺序表有效元素个数

int SeqListCapacity(SeqList* p);// 获取顺序表的容量 
 
int SeqListEmpty(SeqList *p);// 检测顺序表是否为空

DataType SeqListFront(SeqList *p);// 获取顺序表中第一个元素 


DataType SeqListBack(SeqList* p);// 获取顺序表中最后一个元素 