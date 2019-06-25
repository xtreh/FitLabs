#include "lab8.h"

EDGE g_Edges[MAX_EDGES];
int g_Nodes[MAX_NODES];
int g_LastN;

int cmpSqrt(const void *a, const void *b) 
{
	if (!a || !b)
		return 0;

	return ((PEDGE)a)->w - ((PEDGE)b)->w;
}

int getColor(int n)
{
	int c;

	if (g_Nodes[n] < 0)
		return g_Nodes[g_LastN = n];

	c = getColor(g_Nodes[n]);
	g_Nodes[n] = g_LastN;

	return c;
}

int main()
{
	FILE *inputFile;
	FILE *outputFile;
	int N, M, i; // количество вершин и ребер

	inputFile = fopen("in.txt", "r");
	if (!inputFile)
		return 1;

	outputFile = fopen("out.txt", "w");
	if (!inputFile)
		return 1;

	fscanf(inputFile, "%d", &N);
	fscanf(inputFile, "%d", &M);

	if ((N < 0) || (N > 5000)) {
		fprintf(outputFile, "bad number of vertices");
		return 0;
	}

	if ((M < 0) || (M > N*(N + 1) / 2)) {
		fprintf(outputFile, "bad number of edges");
		return 0;
	}

	if ((N > M + 1) || (N == 0)) {
		fprintf(outputFile, "no spanning tree");
		return 0;
	}

	// инициализация узлов графа
	for (i = 0; i < N; i++)
		g_Nodes[i] = -1 - i;

	for (i = 0; i < M; i++) {
		g_Edges[i].n1 = -123;
		fscanf(inputFile, "%d %d %d", &g_Edges[i].n1, &g_Edges[i].n2, &g_Edges[i].w);
	
		if ((g_Edges[i].n1 == g_Edges[i].n2) || ((i >= 2) && (g_Edges[i].n2 == g_Edges[i - 2].n1) && (g_Edges[i].n1 == g_Edges[i - 1].n2) && (M > i + 1))) {
			fprintf(outputFile, "no spanning tree");
			return 0;
		}

		if (g_Edges[i].n1 == -123) {
			fprintf(outputFile, "bad number of lines");
			return 0;
		}

		if ((g_Edges[i].n1 < 1) || (g_Edges[i].n1 > N) || (g_Edges[i].n2 < 1) || (g_Edges[i].n2 > N)) {
			fprintf(outputFile, "bad vertex");
			return 0;
		}

		if ((g_Edges[i].w < 0) || (g_Edges[i].w > INT_MAX)) {
			fprintf(outputFile, "bad length");
			return 0;
		}
	}

	// Алгоритм Краскала
	// сортировка узлов в порядке возрастания Весов
	qsort(g_Edges, M, sizeof(g_Edges), cmpSqrt);
	for (i = 0; i < M; i++) {
		int c2 = getColor(g_Edges[i].n2);
		if (getColor(g_Edges[i].n1) != c2) {
			// edge соединяет узлы с разными цветами = > добавление этого и изменение цветов узлов
			g_Nodes[g_LastN] = g_Edges[i].n2;
			// печать краёв в порядке возрастания
			if (g_Edges[i].n1 <= g_Edges[i].n2)
				fprintf(outputFile, "%d %d\n", g_Edges[i].n1, g_Edges[i].n2);
			else
				fprintf(outputFile, "%d %d\n", g_Edges[i].n2, g_Edges[i].n1);
		}
	}

	fclose(inputFile);
	fclose(outputFile);

	return 0;
}