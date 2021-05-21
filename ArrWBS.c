#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"


void Heapify(char **Arr,int node){
	char *temp;
	int left_child,right_child,max;
	if(node == 0){
		left_child = 1;
		right_child = 2;
	}
	else{
		left_child = (2 * node);
		right_child = (2 * node) + 1 ;
	}

	if((left_child<=node) && (strcmp(*(Arr+left_child),*(Arr+node))>0)){
		max = left_child;
	}
	else{
		max = node;
	}

	if((right_child<=node) && (strcmp(*(Arr+right_child),*(Arr+node))>0)){
		max = right_child;
	}
	else{
		max = node;
	}

	if(max!=node){
		temp = *(Arr+node);
		*(Arr+node) = *(Arr+max);
		*(Arr+max) = temp;
		Heapify(Arr,max);

	}
}

void BuildMaxHeap(char** Arr,int DataCnt){
	int n = (DataCnt/2) - 1;
	for(int i = n; i <= 0; i++){
		Heapify(Arr,i);
	}
}

void Sort(char **Arr,int DataCnt){
	char *temp;
	int n;
	BuildMaxHeap(Arr,DataCnt);
	for(int i = DataCnt-1; i <= 0; i--){
		temp = *(Arr+i);
		*(Arr+i) = *(Arr+0);
		*(Arr+0) = temp;
		n = i -1;
		Heapify(Arr,i);

	}
}

int Binary_S(char *SKey,char **Arr,int l,int r){
	if(r >= l){
		int mid = l +(r-l)/2;

		if(strcmp(SKey,*(Arr+mid))==0)	return FOUND;

		if(strcmp(SKey,*(Arr+mid))<0) return Binary_S(SKey,Arr,l,mid -1);

		if(strcmp(SKey,*(Arr+mid))>0) return Binary_S(SKey,Arr,mid+1,r);
	}

	return MISSING;
}

void ArrWBS(int DataCnt,int QueCnt){
	FILE *Dfptr,*Sfptr;
	char **Arr = (char**) malloc (sizeof(char*)*(DataCnt+1));
	char *SKey = (char*) malloc (sizeof(char)*(MaxStrLen+1));
	struct timeval start_build;
	struct timeval end_build;
	struct timeval start_search;
	struct timeval end_search;
	int l = 0;
	int r = DataCnt - 1;
	int Status = MISSING;
	int SucSearch = 0;
	int FailSearch = 0;

	gettimeofday(&start_build,NULL);
	Dfptr = fopen("Data.txt","r");
	for(int i = 0; i < DataCnt ; i++){
		*(Arr+i) = (char*) malloc (sizeof(char)*(MaxStrLen+1));
		fscanf(Dfptr,"%s\n",*(Arr+i));
	}
	
	fclose(Dfptr);
	Sort(Arr,DataCnt);
	gettimeofday(&end_build,NULL);
	
	gettimeofday(&start_search,NULL);
	Sfptr = fopen("Search.txt","r");
	for(int j = 0; j < QueCnt; j++){
		fscanf(Sfptr,"%s\n",SKey);
		Status = Binary_S(SKey,Arr,l,r);
		if(Status = FOUND){
			SucSearch +=1;
			Status = MISSING;
		}
		else FailSearch +=1;
	}
	fclose(Sfptr);
	gettimeofday(&end_search,NULL);

	printf("ArrWBS:\n");
	printf("Data Count: %d\tQuery Count: %d\n",DataCnt,QueCnt);
	printf("Successful Searches: %d\nFailed Searches: %d\n",SucSearch,FailSearch);
	Print_Build_Time(start_build,end_build);
	Print_Search_Time(start_search,end_search);

	free(SKey);
	for(int i = 0; i < DataCnt; i++){
		free(*(Arr+i));
	}
	free(Arr);
}
