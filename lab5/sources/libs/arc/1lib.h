#include "1print.h"

void arc(FILE *fin)
{
	FILE *fout = fopen("out.txt", "wb");

	unsigned char buff = 0;
	char cnt = 0;

	int M[256];
	char *code[256];
	node *heap[256];
	int heapSize = 0;
	node *last;
	int lenght = 0;

	for (int i = 0; i < 256; i++) {
		M[i] = 0;
		code[i] = (char *) malloc(sizeof(char));
		code[i][0] = '\0';
		heap[i] = NULL;
	}

	lenght = countFreq(fin, M);
	if (!lenght)
		return;

	makeHeap(heap, &heapSize, M); // Создаем кучу

	makeTree(heap, &heapSize); // Создаем дерево, объединяя элементы кучи

	last = extractMin(heap, &heapSize); // Достаем последний и единственный элемент кучи - вершину дерева
	if (last->data == -1) // Если в вершине нет символа
		makeCodes(last, code, "\0"); // Делаем коды по этому дереву
	else // Иначе (если в вершине символ)
		code[last->data] = "1\0"; // Дерево состоит из одного элемента, т.е. в файле 1 символ => его код - "1"

	fwrite(&lenght, sizeof(int), 1, fout);

	printTree(fout, &buff, &cnt, last); // Выводим дерево в начало файла для дальнейшего декодирования

	printFile(fin, fout, &buff, &cnt, code); // Выводим коды для каждого символа из файла + хвост

	fclose(fin);
	fclose(fout);
}