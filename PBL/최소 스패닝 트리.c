#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct Edge {
	int start;
	int end;
	int weight;
} Edge;

int vcount;
int ecount;
int Parents[10002];
Edge Edges[100002];
Edge SortedEdges[100002];

// �ʱ�ȭ
void Initialize()
{
	int i;
	for (i = 1; i <= vcount; i++) {
		Parents[i] = i;
	}
}
// curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int n)
{
	if (n == Parents[n])
		return n;
	else return Parents[n] = set_find(Parents[n]);
}

// �ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
	int root1 = set_find(a);	// ��� a�� ��Ʈ�� ã�´�. 
	int root2 = set_find(b);	// ��� b�� ��Ʈ�� ã�´�.  
	Parents[root1] = root2;
}

void mergeSort()
{
	int Size, curPos, startPos, PosA, PosB;
	Size = 1;
	while (Size < ecount) {
		curPos = 1; // 1���� ����
		while (curPos <= ecount) {
			startPos = curPos;
			PosA = curPos;
			PosB = PosA + Size;
			if (PosB <= ecount) { // PosB�� �����Ҷ�
				while (1) {
					if (Edges[PosA].weight <= Edges[PosB].weight) {
						SortedEdges[curPos++] = Edges[PosA++];
					}
					else {
						SortedEdges[curPos++] = Edges[PosB++];
					}
					if (PosB > ecount || PosA == startPos + Size || PosB == startPos + Size * 2) break;
					//PosA�� PosB���߿� �ϳ��� ������ �����ϸ� Ż�� 
				}
			}
			while (PosA < startPos + Size)
			{ //PosA�� �ִ� ���� �״�� �Ű� �ش�. 
				SortedEdges[curPos++] = Edges[PosA++];
			}
			while (PosB < startPos + 2 * Size && PosB <= ecount) {
				SortedEdges[curPos++] = Edges[PosB++];
			}
		}
		curPos = 1;
		while (curPos <= ecount) {
			Edges[curPos] = SortedEdges[curPos];
			curPos++;
		}
		Size *= 2;
	}
}

void mstKruskal()
{
	int totalWeight = 0;
	int count = 0;
	int i = 1;
	int Vertex1, Vertex2, Weight;
	while (count < vcount - 1) { //Ʈ���� ���� ������ ���� ����� �� - 1
		Vertex1 = Edges[i].start;
		Vertex2 = Edges[i].end;
		Weight = Edges[i].weight;
		i++;
		if (i > ecount) break;
		if (set_find(Vertex1) == set_find(Vertex2)) continue; // Cycle�� �߻��ϸ� �Ѿ��
		set_union(Vertex1, Vertex2);
		totalWeight += Weight;
		count++;
	}
	printf("%d", totalWeight);
}

int main()
{
	int i, v1, v2, weight;
	scanf("%d %d", &vcount, &ecount);
	for (i = 1; i <= ecount; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		Edges[i].start = v1;
		Edges[i].end = v2;
		Edges[i].weight = weight;
	}
	mergeSort();
	Initialize();
	mstKruskal();
	return 0;
}
