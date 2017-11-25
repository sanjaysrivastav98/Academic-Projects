#include <stdio.h>
#include <stdlib.h>



typedef struct dnsNode
{
	char str[400];
	struct dnsNode* child;
	struct dnsNode* next;
	int isLeafNode;
}dnsNode;


dnsNode* readData(FILE *fp,int N);

void lookup(dnsNode* d,char* s);