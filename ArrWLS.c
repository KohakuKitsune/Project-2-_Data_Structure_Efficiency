#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"

void ArrWLS(int DataCnt,int QueCnt){
	FILE *Dfptr,*Sfptr;
	char **Arr = (char**) malloc (sizeof(char*)*(DataCnt+1));
	char *SKey = (char*) malloc (sizeof(char*)*(MaxStrLen+1));
	struct timeval start_build;
	struct timeval end_build;
	struct timeval start_search;
	struct timeval end_search;
	int SucSearch = 0;
	int FailSearch = 0;
	int status = MISSING;

	gettimeofday(&start_build,NULL);
	Dfptr = fopen("Data.txt","r");
	for(int i = 0; i < DataCnt; i++){
		*(Arr+i) = (char*) malloc (sizeof(char)*(MaxStrLen+1));
		fscanf(Dfptr,"%s\n",*(Arr+i));
	}
	fclose(Dfptr);
	gettimeofday(&end_build,NULL);

	gettimeofday(&start_search,NULL);
	Sfptr = fopen("Search.txt","r");
	for(int j = 0; j < QueCnt; j++){
		fscanf(Sfptr,"%s\n",SKey);
		for(int k = 0; k < DataCnt; k++){
			if(strcmp(SKey,*(Arr+k)) == 0){
				SucSearch +=1;
				status = FOUND;
				break;
			}
		}
		if(status != FOUND) FailSearch +=1;
		status = MISSING;
	}
	fclose(Sfptr);
	gettimeofday(&end_search,NULL);

	printf("ArrWLS:\n");
	printf("Data Count: %d\tQuery Count: %d\n",DataCnt,QueCnt);
	printf("Successful Searches: %d\nFailed Searches: %d\n",SucSearch,FailSearch);
	Print_Build_Time(start_build,end_build);
	Print_Search_Time(start_search,end_search);


	free(SKey);	
	for(int i =0; i < DataCnt; i++){
		free(*(Arr+i));
	}
	free(Arr);
}
