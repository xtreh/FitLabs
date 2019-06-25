#include "lab9.h"

void Set2DFree(int **Arr, int n)
{
	for (int i = 0; i < n; i++)
		free(Arr[i]);
	
	free(Arr);
}

void Prims(int n, int **G, FILE *output)
{
	int* distance = (int*)malloc(sizeof(int)*n);
	int* from = (int*)malloc(sizeof(int)*n);
	int* visited = (int*)malloc(sizeof(int)*n);
	int u, v = 0, min_distance;
	int no_of_edges, i, j;

	// изменение исходной матрицы
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (G[i][j] == 0)
				G[i][j] = INFINITY;
		}
	}

	// инициализация visited [], distance[] & from[]
	distance[0] = 0;
	visited[0] = 1;

	for (i = 1; i < n; i++) {
		distance[i] = G[0][i];
		from[i] = 0;
		visited[i] = 0;
	}

	no_of_edges = n - 1; //нет ребер, которые будут добавлены

	while (no_of_edges > 0) {
		// нахождение вершины на минимальном расстоянии от дерева
		min_distance = INFINITY;

		for (i = 1; i < n; i++) {
			if (visited[i] == 0 && distance[i] < min_distance) { // если не посетил & расстояние меньше, чем предыдущий мин
				v = i;	// я новый кандидат для добавления
				min_distance = distance[i];	// новые расстояния минимальное расстояние
			}
		}

		u = from[v];

		// вставка ребра в связующее дерево = сразу печать в выходной файл (для сохранения памяти)
		fprintf(output, "%d %d\n", u + 1, v + 1);

		no_of_edges--;	// одним меньше край чтобы добавить
		visited[v] = 1;	// визитеры посетили

		// обновление массива distance[] 
		for (i = 1; i < n; i++) {
			if (visited[i] == 0 && G[i][v] < distance[i]) {
				distance[i] = G[i][v];
				from[i] = v;
			}
		}
	}

	free(distance);
	free(from);
	free(visited);
}

int main()
{
	FILE *fileInput;
	FILE *fileOutput;

	int n, m, n1, n2, w, i, j;	// числа вершин и ребер, узлов, веса ребер и Вар циклов
	int noNeed = 0, check = 0;	// чеки-Варс

	fileInput = fopen("in.txt", "r");
	if (!fileInput)
		return 1;

	fileOutput = fopen("out.txt", "w");
	if (!fileOutput)
		return 1;

	fscanf(fileInput, "%d", &n);
	fscanf(fileInput, "%d", &m);


	if ((n == 1) && (m == 0))
		return 1;

	if (m == 2)
		noNeed = 1;

	if ((n < 0) || (n > 5000)) {
		fprintf(fileOutput, "bad number of vertices");
		return 0;
	}

	if ((m < 0) || (m > n*(n + 1) / 2)) {
		fprintf(fileOutput, "bad number of edges");
		return 0;
	}

	if ((n > m + 1) || ((n == 0) && (m == 0))) {
		fprintf(fileOutput, "no spanning tree");
		return 0;
	}

	// создание динамического 2D-массива для нашего графа
	int **G = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
		G[i] = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			G[i][j] = 0;
	}

	for (i = 1; i <= m; i++) {
		n1 = -123;
		fscanf(fileInput, "%d %d %d", &n1, &n2, &w);

		if (n1 == -123) {
			fprintf(fileOutput, "bad number of lines");
			return 0;
		}

		if (n1 == n2) {
			fprintf(fileOutput, "no spanning tree");
			return 0;
		}

		if ((n1 < 1) || (n1 > n) || (n2 < 1) || (n2 > n)) {
			fprintf(fileOutput, "bad vertex");
			return 0;
		}

		if ((w < 0) || (w > INT_MAX)) {
			fprintf(fileOutput, "bad length");
			return 0;
		}

		if (w == MAX_INT)
			w = INFINITY - 1;

		G[n1 - 1][n2 - 1] = w;
		G[n2 - 1][n1 - 1] = w;
	}

	for (i = 0; i < n; i++) {
		if (G[n - 1][i] != 0)
			check = 1;	// проверка узлов без соединений
	}

	// есть (есть) узел (ы) с соединениями
	if (check == 0) {
		fprintf(fileOutput, "no spanning tree");
		return 0;
	}

	// нет необходимости использовать ALG Прима = > просто печать ребер нашего графика
	if (noNeed == 1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if ((G[i][j] != 0) && (i < j))
					fprintf(fileOutput, "%d %d\n", i + 1, j + 1);
			}
		}
		return 0;
	}

	Prims(n, G, fileOutput);

	Set2DFree(G, n);
	fclose(fileInput);
	fclose(fileOutput);

	return 0;
}