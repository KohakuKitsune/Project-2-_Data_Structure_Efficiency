#ifndef HEADER_H
#define HEADER_H

#define SET 1
#define DEF 0

#define FOUND 1
#define MISSING 0

#define MaxStrLen 10

typedef struct bstnode{
	char *key;
	struct bstnode *LeftChild;
	struct bstnode *RightChild;
}BSTnode;

typedef struct LLnode{
	char *key;
	struct LLnode *next;
}LNode;

typedef struct Hashnode{
	char *key;
	struct Hashnode *next;
}HNode;


int CHECK_DATA_PARA(char* para);

int CHECK_QUEUE_PARA(char* para);

int CHECK_STRUCT_PARA(char* para);

void PROD_DATA_LIST(FILE *fptr,int Cnt);

void PROD_SEARCH_LIST(FILE *dest,int QueCnt,int DataCnt);

void PROD_DATA(int DataCnt,int QueCnt);

void Print_Build_Time(struct timeval start,struct timeval end);

void Print_Search_Time(struct timeval start,struct timeval end);

BSTnode *BST_create_node(char *key);

BSTnode *BST_insert(BSTnode *node,char*key);

int BST_search(BSTnode *node,char*key);

void BST(int DataCnt,int QueCnt);

void Heapify(char **Arr,int node);

void BuildMaxHeap(char** Arr,int DataCnt);

void Sort(char **Arr,int DataCnt);

int Binary_S(char *SKey,char **Arr,int l,int r);

void ArrWBS(int DataCnt,int QueCnt);

void ArrWLS(int DataCnt,int QueCnt);

LNode *l_insert(LNode *L,char *Key);

int l_search(LNode *L,char *SKey);

void LinkedList(int DataCnt,int QueCnt);

unsigned int hash65(char *key);

HNode *L_insert(HNode *L,char *key);

void hash_insert(HNode **HTab,int DataCnt,char *key);

int L_find(HNode *L,char *key);

int hash_search(HNode **HTab,int DataCnt,char *key);

void Hash(int DataCnt,int QueCnt);

void BuildNSearch(int Type,int DataCnt,int QueCnt);

#endif
