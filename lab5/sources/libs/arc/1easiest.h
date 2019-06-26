#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node // Структура дерева
{
	int data;
	struct node *left;
	struct node *right;
	int priority;
} node;

void swap(node *a, node *b)
{
	node t = *a;
	*a = *b;
	*b = t;
}

char *concat(char *a, char *b) // Совмещение строк
{
	int i, j;
	char *str = (char *) malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
	for (i = 0; i < strlen(a); i++)
		str[i] = a[i];
	for (j = 0; j < strlen(b); j++)
		str[strlen(a) + j] = b[j];
	str[strlen(a) + strlen(b)] = '\0';

	return str;	 
}

void siftDown(int i, node **heap, int heapSize)
{
	int left, right, j;
	while (2 * i + 1 < heapSize) {
		left = 2 * i + 1;
		right = 2 * i + 2;
		j = left;
		if (right < heapSize && heap[right]->priority < heap[left]->priority)
			j = right;
		if (heap[i]->priority <= heap[j]->priority)
			break;
		swap(heap[i], heap[j]);
		i = j;
	}
}

void siftUp(int i, node **heap)
{
	while (heap[i]->priority < heap[(i - 1) / 2]->priority) {
		swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void insert(node *key, node **heap, int *heapSize)
{
	*heapSize += 1;
	heap[*heapSize - 1] = key;
	siftUp(*heapSize - 1, heap);
}

node *extractMin(node **heap, int *heapSize)
{
	node *min = heap[0];
	heap[0] = heap[*heapSize - 1];
	*heapSize -= 1;
	siftDown(0, heap, *heapSize);
	return min;
}