#ifndef __LAB7_H
#define __LAB7_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

///<summary>
/// Матрица смежности графа
///</summary>
extern int g_adjMatrix[MAX_SIZE][MAX_SIZE];

///<summary>
/// Создание графа
///</summary>
///<param name="fileInput">Указатель на input файл</param>
///<param name="fileOutput">Указатель на output файл</param>
///<param name="n">Указатель на переменную для хранения количества узлов</param>
///<returns>Создание графа и возврат размера графа</returns>
int createGraph(FILE *fileInput, FILE *fileOutput, int *n);

///<summary>
/// Добавление элемента в очередь
///</summary>
///<param name="node">Узел</param>
///<param name="pImpos">Указатель на impos</param>
///<param name="pRear">Задняя часть очереди</param>
///<param name="pFront">Передняя часть очереди</param>
///<param name="pQueue">Очередь</param>
void insertQueue(int node, int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// Удаление элемента из очереди
///</summary>
///<param name="pImpos">Указатель на impos</param>
///<param name="pRear">Задняя часть очереди</param>
///<param name="pFront">Передняя часть очереди</param>
///<param name="pQueue">Очередь</param>
int deleteQueue(int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// Число ребер, входящих в вершину
///</summary>
///<param name="node">Список</param>
///<param name="n">Указатель на переменную для хранения количества узлов</param>
///<returns>Возвращает число ребер, входящих в вершину</returns>
int inDegree(int node, int *n);

#endif
