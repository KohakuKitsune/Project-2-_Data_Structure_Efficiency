#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"

LNode *l_insert(LNode *L,char *Key){
	LNode *p = (LNode*) malloc (sizeof(LNode));
	p->key = strdup(Key);
	p->next = L;
	return p;
}

int l_search(LNode *L,char *SKey){
	LNode *p;
	p = L;

	while(p){
		if(strcmp(SKey,p->key) == 0){
			return FOUND;
		}
		p = p->next;
	}

	return MISSING;
}

void LinkedList(int DataCnt,int QueCnt){
	FILE *Dfptr,*Sfptr;
	char *SKey = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	char *Key = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	LNode *List = NULL;
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
		List = l_insert(List,Key);
	}
	fclose(Dfptr);
	gettimeofday(&end_build,NULL);

	gettimeofday(&start_search,NULL);
	Sfptr = fopen("Search.txt","r");
	for(int j = 0; j < QueCnt; j++){
		fscanf(Sfptr,"%s\n",SKey);
		status = l_search(List,SKey);
		if(status == FOUND){
			SucSearch +=1;
			status = MISSING;
		}
		else FailSearch +=1;
	}
	fclose(Sfptr);
	gettimeofday(&end_search,NULL);
	
	printf("Linked List:\n");
	printf("Data Count: %d\tQuery Count: %d\n",DataCnt,QueCnt);
	printf("Successful Searches: %d\nFailed Searches: %d\n",SucSearch,FailSearch);
	Print_Build_Time(start_build,end_build);
	Print_Search_Time(start_search,end_search);

	free(Key);
	free(SKey);
	free(List);
}
