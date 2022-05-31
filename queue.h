#pragma once
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct BinaryTreeNode;

typedef struct BinaryTreeNode* QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Q;

bool isEmptyQueue(Q*);
void initQueue(Q*);
void enQueue(Q*, QueueDataType x);
void deQueue(Q*);
QueueDataType getFrontQueue(Q*);
QueueDataType getBackQueue(Q*);
void destroyQueue(Q*);
int getQueueLength(Q*);