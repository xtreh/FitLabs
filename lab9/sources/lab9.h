#ifndef __LAB9_H
#define __LAB9_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX_INT 2147483647

///<summary>
/// ������� 2D-�������
///</summary>
///<param name="Arr">������</param>
///<param name="n">������ �������</param>
void Set2DFree(int **Arr, int n);

///<summary>
/// �������� ������
///</summary>
///<param name="n">������ �������</param>
///<param name="G">������</param>
///<param name="output">���� ������</param>
void Prims(int n, int **G, FILE *output);

#endif