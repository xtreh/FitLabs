#ifndef __LAB7_H
#define __LAB7_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

///<summary>
/// ������� ��������� �����
///</summary>
extern int g_adjMatrix[MAX_SIZE][MAX_SIZE];

///<summary>
/// �������� �����
///</summary>
///<param name="fileInput">��������� �� input ����</param>
///<param name="fileOutput">��������� �� output ����</param>
///<param name="n">��������� �� ���������� ��� �������� ���������� �����</param>
///<returns>�������� ����� � ������� ������� �����</returns>
int createGraph(FILE *fileInput, FILE *fileOutput, int *n);

///<summary>
/// ���������� �������� � �������
///</summary>
///<param name="node">����</param>
///<param name="pImpos">��������� �� impos</param>
///<param name="pRear">������ ����� �������</param>
///<param name="pFront">�������� ����� �������</param>
///<param name="pQueue">�������</param>
void insertQueue(int node, int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// �������� �������� �� �������
///</summary>
///<param name="pImpos">��������� �� impos</param>
///<param name="pRear">������ ����� �������</param>
///<param name="pFront">�������� ����� �������</param>
///<param name="pQueue">�������</param>
int deleteQueue(int *pImpos, int *pRear, int *pFront, int *pQueue);

///<summary>
/// ����� �����, �������� � �������
///</summary>
///<param name="node">������</param>
///<param name="n">��������� �� ���������� ��� �������� ���������� �����</param>
///<returns>���������� ����� �����, �������� � �������</returns>
int inDegree(int node, int *n);

#endif
