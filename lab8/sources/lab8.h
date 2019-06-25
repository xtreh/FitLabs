#ifndef __LAB8_H
#define __LAB8_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5005
#define MAX_EDGES 12500000

///<summary>
///���� �����
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
///������� ��������� ��� qsort
///</summary>
///<param name="a">������ ����</param>
///<param name="b">������ ����</param>
///<returns>���������� ������� ����� ����� ����</returns>
int cmpSqrt(const void *a, const void *b);

///<summary>
///������� �������� ���� ����
///</summary>
///<param name="n">������ ����</param>
///<returns>
/// g_Nodes[n] < 0 => ���� n ����� ������� g_Nodes[n]
/// g_Nodes[n] >= 0 => ���� n ����� ��� �� ����, ��� � ���� g_Nodes[n]
///</returns>
int getColor(int n);

#endif
