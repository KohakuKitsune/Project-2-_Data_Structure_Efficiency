#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void PROD_DATA_LIST(FILE *fptr,int Cnt){
	srand(1);
	char c;
	
	fprintf(fptr,"ZZZZZZZZZZ\n");

	for(int i = 0; i < Cnt-1; i++){
		for(int j = 0; j < MaxStrLen; j++){
			c = 65 + (32 * (rand()%2)) + rand()%23;
			fprintf(fptr,"%c",c);
		}
		fprintf(fptr,"\n");
	}
}

void PROD_SEARCH_LIST(FILE *dest,int QueCnt,int DataCnt){
	FILE *src = fopen("Data.txt","r");
	char **list = (char**) malloc (sizeof(char*) *(DataCnt+1));
	
	int idx;
	srand(1);

	for(int i = 0; i < DataCnt; i++){
		*(list+i) = (char*) malloc (sizeof(char) * MaxStrLen+1);
		fscanf(src,"%s",*(list+i));
	}

	for(int j = 0; j < QueCnt; j++){
		idx = rand()%DataCnt;
		fprintf(dest,"%s\n",*(list+idx));
	}

	for(int k = 0; k < DataCnt; k++){
		free(*(list+k));
	}
	free(list);
}

void PROD_DATA(int DataCnt,int QueCnt){
	FILE *fptr1, *fptr2;
	
	fptr1 = fopen("Data.txt","w");
	fptr2 = fopen("Search.txt","w");

	PROD_DATA_LIST(fptr1,DataCnt);

	fclose(fptr1);

	PROD_SEARCH_LIST(fptr2,QueCnt,DataCnt);

	fclose(fptr2);
}

