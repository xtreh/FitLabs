#include "2easiest.h"

void scanBin(FILE *fin, unsigned char *buff, char *cnt, unsigned char *a)
{
	if (*cnt == 0)
		fread(buff, 1, 1, fin);

	*cnt = (*cnt + 1) % 8;
	*a = *buff / 128;
	*buff = *buff << 1;
}

int scanChar(FILE *fin, unsigned char *buff, char *cnt)
{
	unsigned char a;
	int k = 0;
	for (int i = 0; i < 8; i++) {
		scanBin(fin, buff, cnt, &a);
		k = k * 2 + a;
	}
	return k;
}

void scanTree(tree *T, FILE *fin, unsigned char *buff, char *cnt)
{
	unsigned char a;
	scanBin(fin, buff, cnt, &a);
	if (a == 0) {
		T->left = createTree();
		T->right = createTree();
		scanTree(T->left, fin, buff, cnt);
		scanTree(T->right, fin, buff, cnt);
	} else
		T->data = scanChar(fin, buff, cnt);
}

void scanFile(tree *T, FILE *fin, FILE *fout, unsigned char *buff, char *cnt, int lenght)
{
	unsigned char a;
	tree *tmp = T;

	while (lenght) {
		scanBin(fin, buff, cnt, &a);
		if (a == 0 && tmp->left != NULL)
			tmp = tmp->left;
		else if (a == 1 && tmp->right != NULL)
			tmp = tmp->right;
		if (tmp->left == NULL) {
			fwrite(&tmp->data, 1, 1, fout);
			tmp = T;
			lenght--;
		}
	}
}