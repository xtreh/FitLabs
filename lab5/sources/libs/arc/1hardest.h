#include "1easiest.h"

int countFreq(FILE *fin, int *M) // Подсчет частот символов
{
	unsigned char a;
	int b = 0;

	while (fread(&a, 1, 1, fin)) {
		M[a] += 1;
		b += 1;
	}

	fseek(fin, 3, SEEK_SET);
	return b;
}

void makeHeap(node **heap, int *heapSize, int *M) // Создание кучи
{
	node *tmp;
	for (int i = 0; i < 256; i++)
		if (M[i]) {
			tmp = (node *) malloc(sizeof(node));
			tmp->data = i;
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->priority = M[i];
			insert(tmp, heap, heapSize);
		}
}

void makeTree(node **heap, int *heapSize) // Создание дерева
{
	node *tmp1, *tmp2, *tmp;

	while (*heapSize > 1) { // Пока в куче больше 1 элемента
		tmp1 = extractMin(heap, heapSize);
		tmp2 = extractMin(heap, heapSize); // Достаем 2 минимальных по приоритету (частоте)

		tmp = (node *) malloc(sizeof(node));
		tmp->data = -1;
		tmp->priority = tmp1->priority + tmp2->priority;
		tmp->left = tmp1;
		tmp->right = tmp2;

		insert(tmp, heap, heapSize);
	}
}

void makeCodes(node *N, char **code, char *s) // Создание кода для каждого символа
{
	if (N->data != -1) {
		code[N->data] = (char *) malloc((strlen(s) + 1) * sizeof(char));
		for (int i = 0; i < strlen(s); i++)
			code[N->data][i] = s[i];
		code[N->data][strlen(s)] = '\0';
	} else {
		makeCodes(N->left, code, concat(s, "0\0"));
		makeCodes(N->right, code, concat(s, "1\0"));
	}
}