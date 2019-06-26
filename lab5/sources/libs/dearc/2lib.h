#include "2scan.h"

void dearc(FILE *fin)
{
	FILE *fout = fopen("out.txt", "wb");

	unsigned char buff = 0;
	char cnt = 0;

	tree *T = createTree();

	int lenght;

	fread(&lenght, sizeof(int), 1, fin);

	if (feof(fin))
		return;

	scanTree(T, fin, &buff, &cnt); // Воссоздаем дерево

	scanFile(T, fin, fout, &buff, &cnt, lenght); // Перемещаясь по дереву, декодируем

	fclose(fin);
	fclose(fout);
}