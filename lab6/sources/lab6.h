#ifndef __LAB1_H
#define __LAB1_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

///<summary>
///���� AVL ������
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
/// ������� ��������� ������
///</summary>
///<param name="pNode">AVL ������</param>
void freeNode(PNODE pNode);

///<summary>
/// ��������� ������ ���� AVL ������
///</summary>
///<param name="pNode">���� AVL ������</param>
///<returns>������ ���� AVL ������</returns>
unsigned char getNodeHeight(PNODE pNode);

///<summary>
/// ��������� ������-������� ��������� ������
///</summary>
///<param name="pNode">AVL ������</param>
///<returns>������� ����� �������� ����� ��������� ������</returns>
int getNodeBalanceFactor(PNODE pNode);

///<summary>
/// ���������� ������ AVL ������
///</summary>
///<param name="pNode">AVL ������</param>
void fixNodeHeight(PNODE pNode);

///<summary>
/// ������� ������ ������ ����
///</summary>
///<param name="pNode">���� AVL ������</param>
///<returns>����� ����</returns>
PNODE rightRotateNode(PNODE pNode);

///<summary>
/// ������� ����� ������ ����
///</summary>
///<param name="pNode">���� AVL ������</param>
///<returns>������ ����</returns>
PNODE leftRotateNode(PNODE pNode);

///<summary>
/// ������������ AVL ������
///</summary>
///<param name="pNode">AVL ������</param>
///<returns>��������������� �������� ������</returns>
PNODE balanceNode(PNODE pNode);

///<summary>
/// ������� ����� � AVL ������
///</summary>
///<param name="pNode">AVL ������</param>
///<returns>���������� AVL ������</returns>
PNODE insertKeyNode(PNODE pNode, unsigned int key);

#endif