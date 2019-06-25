#ifndef __LAB1_H
#define __LAB1_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

///<summary>
///Узел AVL дерева
///</summary>
typedef struct _NODE
{
	struct {
		unsigned char height;
		unsigned int key;
	} data;
	struct _NODE *left;
	struct _NODE *right;
} NODE, *PNODE;

///<summary>
/// Очистка бинарного дерева
///</summary>
///<param name="pNode">AVL дерево</param>
void freeNode(PNODE pNode);

///<summary>
/// Получение высоты узла AVL дерева
///</summary>
///<param name="pNode">Узел AVL дерева</param>
///<returns>Высота узла AVL дерева</returns>
unsigned char getNodeHeight(PNODE pNode);

///<summary>
/// Получение баланс-фактора бинарного дерева
///</summary>
///<param name="pNode">AVL дерево</param>
///<returns>Разница между высотами узлов бинарного дерева</returns>
int getNodeBalanceFactor(PNODE pNode);

///<summary>
/// Обновление высоты AVL дерева
///</summary>
///<param name="pNode">AVL дерево</param>
void fixNodeHeight(PNODE pNode);

///<summary>
/// Поворот вправо вокруг узла
///</summary>
///<param name="pNode">Узел AVL дерева</param>
///<returns>Левый узел</returns>
PNODE rightRotateNode(PNODE pNode);

///<summary>
/// Поворот влево вокруг узла
///</summary>
///<param name="pNode">Узел AVL дерева</param>
///<returns>Правый узел</returns>
PNODE leftRotateNode(PNODE pNode);

///<summary>
/// Балансировка AVL дерева
///</summary>
///<param name="pNode">AVL дерево</param>
///<returns>Балансированное бинарное дерево</returns>
PNODE balanceNode(PNODE pNode);

///<summary>
/// Вставка числа в AVL дерево
///</summary>
///<param name="pNode">AVL дерево</param>
///<returns>Полученное AVL дерево</returns>
PNODE insertKeyNode(PNODE pNode, unsigned int key);

#endif