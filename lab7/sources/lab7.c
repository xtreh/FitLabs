#include "lab7.h"

int g_adjMatrix[MAX_SIZE][MAX_SIZE];

int createGraph(FILE *fileInput, FILE *fileOutput, int *n)
{
	int i, j;
	int origin = -123, destin = -123; // ������������� � ���������� ����
	int min;
	int node = -1;
	int m = -1;	// ���������� �����

	fscanf(fileInput, "%d", n);
	if (!n || (*n > 1000)) {
		fprintf(fileOutput, "%s", "bad number of vertices");
		return -1;
	}

	fscanf(fileInput, "%d", &m);
	if (m == -1) {
		fprintf(fileOutput, "%s", "bad number of lines");
		return -1;
	}

	// ��� �����
	if (m == 0)	{ 
		for (i = 1; i <= *n; i++)
			fprintf(fileOutput, "%d ", i);

		return -1;
	}

	if ((m < 0) || (m > (*n) *((*n) + 1) / 2)) {
		fprintf(fileOutput, "%s", "bad number of edges");
		return -1;
	}

	for (i = 1; i <= m; i++) {
		fscanf(fileInput, "%d", &origin); // ������ ������ ��������� �����
		fscanf(fileInput, "%d", &destin); // ������ ���������� �����

		if ((origin == -123) || (destin == -123)) {
			fprintf(fileOutput, "%s", "bad number of lines");
			return -1;
		}

		// ����������� ����
		if (origin == destin) {
			fprintf(fileOutput, "%s", "impossible to sort"); 
			return -1;
		}

		if ((origin < 0) || (origin > *n) || (destin < 0) || (destin > *n)) {
			fprintf(fileOutput, "%s", "bad vertex");
			return -1;
		} else {
			g_adjMatrix[origin][destin] = 1; // ���������� ������
			if (origin == node) {
				for (j = origin - 1; j >= 1; j--) {
					if (g_adjMatrix[j][origin] == 1) {
						// ����������� ����
						if (g_adjMatrix[j - 1][j] == 1) {
							fprintf(fileOutput, "%s", "impossible to sort");
							return -1;
						}
					}
				}
			}
			node = destin;
		}

		if (m < *n - 1)	{ // ����� ���� ������� ����
			if (origin < destin)
				min = origin;
			else
				min = destin;

			fprintf(fileOutput, "%d ", origin);
			fprintf(fileOutput, "%d ", destin);

			for (i = min - 1; i > 0; i--)
				fprintf(fileOutput, "%d ", i);

			return -1;
		}

		origin = -123;
		destin = -123;
	}

	return 0;
}

void insertQueue(int node, int *pImpos, int *pRear, int *pFront, int *pQueue)
{
	if (*pRear == MAX_SIZE - 1)	// ����� �� ������� => ���������� ������������� ����
		*pImpos = 1;
	else {
		if (*pFront == -1)	// ���� ������� ���������� �����
			*pFront = 0;

		*pRear = *pRear + 1;
		pQueue[*pRear] = node;	// ������� ���� � ������ �������
	}
}

int deleteQueue(int *pImpos, int *pRear, int *pFront, int *pQueue)
{
	int del_item = 0;

	if (*pFront == -1 || *pFront > *pRear)
		*pImpos = 1;
	else {
		del_item = pQueue[*pFront];
		*pFront = *pFront + 1;
	}

	return del_item;
}

int inDegree(int node, int *n)
{
	int i, in_deg = 0;

	for (i = 1; i <= *n; i++)
		if (g_adjMatrix[i][node] == 1)
			in_deg++;

	return in_deg;
}

int main()
{
	FILE *inputFile;
	FILE *outputFile;
	int n = 0;	// ����� ������
	int impos = 0;	// ���������� �� ������������� ���� (0 ��� "���", 1 ��� "��")
	int front = -1, rear = -1, queue[MAX_SIZE];	// �������� ����� �������, ������ ����� ������� � ���� �������
	int i, j = 0, k;
	int topsort[MAX_SIZE], indeg[MAX_SIZE];

	inputFile = fopen("in.txt", "r");
	if (!inputFile)
		return 1;

	outputFile = fopen("out.txt", "w");
	if (!outputFile)
		return 1;

	if (createGraph(inputFile, outputFile, &n))
		return 1;

	// ����� in degree ������� ����
	for (i = 1; i <= n; i++) {
		indeg[i] = inDegree(i, &n);
		if (indeg[i] == 0)
			insertQueue(i, &impos, &rear, &front, queue);

		if (impos) {
			fprintf(outputFile, "%s", "impossible to sort");
			return 0;
		}
	}

	// � �����, ���� ������� �� �����
	while (front <= rear) {
		k = deleteQueue(&impos, &rear, &front, queue);
		if (impos) {
			fprintf(outputFile, "%s", "impossible to sort");
			return 0;
		}
		topsort[j++] = k; //���������� ���� k � ������ topsort

		// �������� ���� �����, ������ �� k-����
		for (i = 1; i <= n; i++) {
			if (g_adjMatrix[k][i] == 1) {
				g_adjMatrix[k][i] = 0;
				indeg[i] = indeg[i] - 1;
				if (indeg[i] == 0)
					insertQueue(i, &impos, &rear, &front, queue);

				if (impos) {
					fprintf(outputFile, "%s", "impossible to sort");
					return 0;
				}
			}
		}
	}

	for (i = 0; i < j; i++)
		fprintf(outputFile, "%d ", topsort[i]);

	fclose(inputFile);
	fclose(outputFile);

	return 0;
}