#ifndef __LAB8_H
#define __LAB8_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5005
#define MAX_EDGES 12500000

///<summary>
///Край графа
///</summary>
typedef struct _EDGE 
{
	int n1;
	int n2;
	int w;
} EDGE, *PEDGE;

extern EDGE g_Edges[MAX_EDGES];
extern int g_Nodes[MAX_NODES];
extern int g_LastN;

///<summary>
///Функция сравнения для qsort
///</summary>
///<param name="a">Первый край</param>
///<param name="b">Второй край</param>
///<returns>Возвращает разницу между весом краёв</returns>
int cmpSqrt(const void *a, const void *b);

///<summary>
///Функция получает цвет узла
///</summary>
///<param name="n">Первый край</param>
///<returns>
/// g_Nodes[n] < 0 => узел n имеет цветные g_Nodes[n]
/// g_Nodes[n] >= 0 => узел n имеет тот же цвет, что и узел g_Nodes[n]
///</returns>
int getColor(int n);

#endif
