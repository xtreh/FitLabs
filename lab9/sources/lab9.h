#ifndef __LAB9_H
#define __LAB9_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX_INT 2147483647

///<summary>
/// Очистка 2D-массива
///</summary>
///<param name="Arr">Массив</param>
///<param name="n">Размер массива</param>
void Set2DFree(int **Arr, int n);

///<summary>
/// Алгоритм Прайма
///</summary>
///<param name="n">Размер массива</param>
///<param name="G">Массив</param>
///<param name="output">Файл вывода</param>
void Prims(int n, int **G, FILE *output);

#endif