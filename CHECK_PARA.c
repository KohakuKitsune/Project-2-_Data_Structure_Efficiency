#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"



int CHECK_DATA_PARA(char*para){
	int Cnt;
	int MulCnt;
	if(*(para+1) == 'e'){
		Cnt = atoi(para);
		MulCnt = atoi(para+2);
	}
	else{
		printf("Input format error for Data parameter");
		exit(1);
	}
	
	for(int i=0; i<MulCnt; i++){
		Cnt = Cnt*10;
	}
	return Cnt;
}


int CHECK_QUEUE_PARA(char* para){
	int Cnt;
	int MulCnt;
	if(*(para+1) == 'e'){
		Cnt = atoi(para);
		MulCnt = atoi(para+2);
	}
	else{
		printf("Input format error for Queue parameter");
		exit(1);
	}

	for(int i=0; i<MulCnt; i++){
		Cnt = Cnt*10;
	}

	return Cnt;
}

int CHECK_STRUCT_PARA(char* para){
	int Type;	
	if(*(para+0) =='-'){
		if(strcmp(para,"-bst")==0) Type = 1 ;
		
		else if(strcmp(para,"-bs")==0) Type = 2 ;
		
		else if(strcmp(para,"-arr")==0) Type = 3 ;

		else if(strcmp(para,"-ll")==0) Type = 4 ;
		
		else if(strcmp(para,"-hash")==0) Type = 5;
		
		else{
			printf("Input format error for DataStruct parameter");
			exit(1);
		}	
	}
	else{
		printf("Input format error for DataStruct parameter");
		exit(1);
	}

	return Type;
}
