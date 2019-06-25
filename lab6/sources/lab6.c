#include "lab6.h"

void freeNode(PNODE pNode)
{
	if (!pNode)
		return;

	if (pNode->left)
		freeNode(pNode->left);

	if (pNode->right)
		freeNode(pNode->right);

	free(pNode);
}

unsigned char getNodeHeight(PNODE pNode)
{
	return (pNode ? pNode->data.height : 0);
}

int getNodeBalanceFactor(PNODE pNode)
{
	return (pNode ? (getNodeHeight(pNode->right) - getNodeHeight(pNode->left)) : 0);
}

void fixNodeHeight(PNODE pNode)
{
	unsigned char hl, hr;
	if (!pNode)
		return;

	hl = getNodeHeight(pNode->left);
	hr = getNodeHeight(pNode->right);

	pNode->data.height = (hl > hr ? hl : hr) + 1;
}

PNODE rightRotateNode(PNODE pNode)
{
	PNODE pLeftNode = NULL;

	if (pNode) {
		pLeftNode = pNode->left;
		pNode->left = pLeftNode->right;
		pLeftNode->right = pNode;

		fixNodeHeight(pNode);
		fixNodeHeight(pLeftNode);
	}

	return pLeftNode;
}

PNODE leftRotateNode(PNODE pNode)
{
	PNODE pRightNode = NULL;

	if (pNode) {
		pRightNode = pNode->right;
		pNode->right = pRightNode->left;
		pRightNode->left = pNode;

		fixNodeHeight(pNode);
		fixNodeHeight(pRightNode);
	}

	return pRightNode;
}

PNODE balanceNode(PNODE pNode)
{
	if (!pNode)
		return NULL;

	fixNodeHeight(pNode);

	if (getNodeBalanceFactor(pNode) == 2) {
		if (getNodeBalanceFactor(pNode->right) < 0)
			pNode->right = rightRotateNode(pNode->right);

		return leftRotateNode(pNode);
	}

	if (getNodeBalanceFactor(pNode) == -2) {
		if (getNodeBalanceFactor(pNode->left) > 0)
			pNode->left = leftRotateNode(pNode->left);

		return rightRotateNode(pNode);
	}

	return pNode;
}

PNODE insertKeyNode(PNODE pNode, unsigned int key)
{
	if (!pNode) {
		pNode = (PNODE)malloc(sizeof(*pNode));
		pNode->left = NULL;
		pNode->right = NULL;
		pNode->data.height = 1;
		pNode->data.key = key;
		return pNode;
	}

	if (key < pNode->data.key)
		pNode->left = insertKeyNode(pNode->left, key);
	else
		pNode->right = insertKeyNode(pNode->right, key);

	return balanceNode(pNode);
}

int main()
{
	PNODE pNode = NULL;
	FILE *fileIn, *fileOut;
	int n, i, data;

	fileIn = fopen("in.txt", "r");
	if (!fileIn)
		return 1;

	fileOut = fopen("out.txt", "w");
	if (!fileOut)
		return 1;

	fscanf(fileIn, "%d", &n);

	if (n == 0) {
		fprintf(fileOut, "%d", 0);
		return 0;
	} 

	for (i = 0; i < n; i++) {
		fscanf(fileIn, "%d", &data);
		pNode = insertKeyNode(pNode, data);
	}

	fprintf(fileOut, "%d", pNode->data.height);
	fclose(fileIn);
	fclose(fileOut);

	freeNode(pNode);

	return 0;
}