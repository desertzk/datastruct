#define _CRT_SECURE_NO_WARNINGS
#include"adjacencymatrix.h"
#include<stdlib.h>
#include<stdio.h>

MGraph CreateMGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertMEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildMGraph(int vertexnum)
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	//scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateMGraph(vertexnum); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	scanf("%d", &(Graph->Ne));   /* ������� */
	if (Graph->Ne != 0) { /* ����б� */
		E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
		/* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
			InsertMEdge(Graph, E);
		}
	}

	/* ������������ݵĻ����������� */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
}

