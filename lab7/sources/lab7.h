#ifndef __LAB7_H
#define __LAB7_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

///<summary>
/// ћатрица смежности графа
///</summary>
extern int g_adjMatrix[MAX_SIZE][MAX_SIZE];

///<summary>
/// —оздание графа
///</summary>
///<param name="fileInput">”казатель на input файл</param>
///<param name="fileOutput">”казатель на output файл</param>
///<param name="n">”казатель на переменную дл¤ хранени¤ количества узлов</param>
///<returns>—оздание графа и возврат размера графа</returns>
int createGraph(FILE *fileInput, FILE *fileOutput, int *n);

///<summary>
/// ƒобавление элемента в очередь
///</summary>
///<param name="node">”зел</param>
///<param name="pImpos">”казатель на impos</param>
///<param name="pRear">«адн¤¤ часть очереди</param>
///<param name="pFront">ѕередн¤¤ часть очереди</param>
///<param name="pQueue">ќчередь</param>
void insertQueue(int node, int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// ”даление элемента из очереди
///</summary>
///<param name="pImpos">”казатель на impos</param>
///<param name="pRear">«адн¤¤ часть очереди</param>
///<param name="pFront">ѕередн¤¤ часть очереди</param>
///<param name="pQueue">ќчередь</param>
int deleteQueue(int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// „исло ребер, вход¤щих в вершину
///</summary>
///<param name="node">—писок</param>
///<param name="n">”казатель на переменную дл¤ хранени¤ количества узлов</param>
///<returns>¬озвращает число ребер, вход¤щих в вершину</returns>
int inDegree(int node, int *n);

#endif
