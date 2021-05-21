#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"

unsigned int hash65(char *key){
	unsigned int hv = 0;
	char *p = key;
	while(*p){
		hv = hv*65 + *p;
		p++;
	}
	return hv;
}

HNode *L_insert(HNode *L,char *key){
	HNode *p = (HNode*) malloc (sizeof(HNode));
	p->key = strdup(key);
	p->next = L;

	return p;
}


void hash_insert(HNode **HTab,int DataCnt,char *key){
	unsigned int hv;
	HNode *L;
	hv = hash65(key) % DataCnt;
	L = *(HTab+hv);
	*(HTab+hv) = L_insert(L,key);
}

int L_find(HNode *L,char *key){
	HNode *p;

	if(L == NULL) return MISSING;

	p = L;

	while(p){
		if(strcmp(key,p->key)==0) return FOUND;
		p = p->next;
	}
	
	return MISSING;
}

int hash_search(HNode **HTab,int DataCnt,char *key){
	unsigned int hv;
	HNode *Lptr;

	hv = hash65(key) % DataCnt;
	Lptr = *(HTab+hv);

	return L_find(Lptr,key);
}

void Hash(int DataCnt,int QueCnt){
	FILE *Dfptr,*Sfptr;
	HNode **HTab = (HNode**) malloc (sizeof(HNode*)*(DataCnt+1));
	char *SKey = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	char *Key = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	struct timeval start_build;
	struct timeval end_build;
	struct timeval start_search;
	struct timeval end_search;
	int status = MISSING;
	int SucSearch = 0;
	int FailSearch = 0;
	
	gettimeofday(&start_build,NULL);
	Dfptr = fopen("Data.txt","r");
	for(int i = 0; i < DataCnt+1; i++){
		*(HTab+i) = NULL;
	}
	
	for(int i = 0; i < DataCnt; i++){
		fscanf(Dfptr,"%s\n",Key);
		hash_insert(HTab,DataCnt,Key);
	}
	fclose(Dfptr);
	gettimeofday(&end_build,NULL);

	gettimeofday(&start_search,NULL);
	Sfptr = fopen("Search.txt","r");
	for(int j = 0; j < QueCnt; j++){
		fscanf(Sfptr,"%s\n",SKey);
		status =  hash_search(HTab,DataCnt,SKey);
		if(status == FOUND){
			SucSearch +=1;
			status = MISSING;
		}
		else FailSearch +=1;
	}
	fclose(Sfptr);
	gettimeofday(&end_search,NULL);

	printf("Hash:\n");
	printf("Data Count: %d\tQuery Count: %d\n",DataCnt,QueCnt);
	printf("Successful Searches: %d\nFailed Searches: %d\n",SucSearch,FailSearch);
	Print_Build_Time(start_build,end_build);
	Print_Search_Time(start_search,end_search);
}	
	
