#include "1hardest.h"

void printBin(FILE *fout, unsigned char *buff, char *cnt, unsigned char a) // Вывод бита
{
	*cnt = (*cnt + 1) % 8;
	*buff = *buff * 2 + a;

	if (*cnt == 0) {
		fwrite(buff, 1, 1, fout);
		*buff = 0;
	}
}

void printChar(FILE *fout, unsigned char *buff, char *cnt, unsigned char a) // Вывод стандартного бинарного кода символа
{
	for (int i = 0; i < 8; i++) {
		printBin(fout, buff, cnt, a / 128);
		a = a << 1;
	}
}

void printTree(FILE *fout, unsigned char *buff, char *cnt, node *tree) // Вывод дерева (побитовый)
{
	if (tree->data != -1) {
		printBin(fout, buff, cnt, 1);
		printChar(fout, buff, cnt, tree->data);
	} else { // Иначе выводим 0 и рекурсивно продолжаем алгоритм для левого и правого поддерева
		printBin(fout, buff, cnt, 0);
		printTree(fout, buff, cnt, tree->left);
		printTree(fout, buff, cnt, tree->right);
	}
}

void printCode(FILE *fout, unsigned char *buff, char *cnt, char *code) // Вывод кода (побитовый)
{
	for (int i = 0; i < strlen(code); i++)
		printBin(fout, buff, cnt, code[i] - '0');
}

void printTail(FILE *fout, unsigned char *buff, char *cnt) // Вывод остатка буфера
{
	for (int i = *cnt; i < 8; i++)
		*buff *= 2;
	fwrite(buff, 1, 1, fout);
}

void printFile(FILE *fin, FILE *fout, unsigned char *buff, char *cnt, char **code) // Кодирование символов
{
	unsigned char a;

	while (fread(&a, 1, 1, fin))
		printCode(fout, buff, cnt, code[a]);
	printTail(fout, buff, cnt);
}