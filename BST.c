#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"

BSTnode *BST_create_node(char *key){
	BSTnode *p = (BSTnode*) malloc (sizeof(BSTnode));
	p->key = strdup(key);
	p->LeftChild = NULL;
	p->RightChild = NULL;

	return p;
}

BSTnode *BST_insert(BSTnode *node,char*key){
	if(node == NULL) return BST_create_node(key);

	else if(strcmp(key,node->key)>0) node->RightChild = BST_insert(node->RightChild,key);

	else if(strcmp(key,node->key)<0) node->LeftChild = BST_insert(node->LeftChild,key);

	return node;
}

int BST_search(BSTnode *node,char*key){

	if(node ==NULL) return MISSING;
	
	else if(strcmp(key,node->key)==0) return FOUND;

	else if(strcmp(key,node->key)>0) BST_search(node->RightChild,key);

	else if(strcmp(key,node->key)<0) BST_search(node->LeftChild,key);

}

void BST(int DataCnt,int QueCnt){
	FILE *Dfptr,*Sfptr;
	BSTnode *root = NULL;
	char *Key = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	char *SKey = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	struct timeval start_build;
	struct timeval end_build;
	struct timeval start_search;
	struct timeval end_search;
	int status = MISSING;
	int SucSearch = 0;
	int FailSearch = 0;

	gettimeofday(&start_build,NULL);
	Dfptr = fopen("Data.txt","r");
	for(int i = 0; i < DataCnt; i++){
		fscanf(Dfptr,"%s\n",Key);
		if(root == NULL) root = BST_create_node(Key);
		else BST_insert(root,Key);
	}
	fclose(Dfptr);
	gettimeofday(&end_build,NULL);
	
	gettimeofday(&start_search,NULL);
	Sfptr = fopen("Search.txt","r");
	for(int j = 0; j < QueCnt; j++){
		fscanf(Sfptr,"%s\n",SKey);
		status = BST_search(root,SKey);
		if(status == FOUND){
			SucSearch +=1;
			status = MISSING;
		}
		else FailSearch +=1;
	}
	fclose(Sfptr);
	gettimeofday(&end_search,NULL);

	printf("BST:\n");
	printf("Data Count: %d\tQuery Count: %d\n",DataCnt,QueCnt);
	printf("Successful Searches: %d\nFailed Searches: %d\n",SucSearch,FailSearch);
	Print_Build_Time(start_build,end_build);
	Print_Search_Time(start_search,end_search);

	free(root);
}
