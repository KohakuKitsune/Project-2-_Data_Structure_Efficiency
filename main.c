#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"



int main(int argc, char **argv){
	char *DATA_PARA = "1e4";
	char *QUEUE_PARA = "1e3";
	char **STRUC_PARA = (char**) malloc (sizeof(char*)*6);
	*(STRUC_PARA+0) = "BST";
	int DATA_SET = DEF;
	int QUEUE_SET = DEF;
	int TypeCnt = 0;
	int DataCnt,QueCnt;
	int *StrucType = (int*) malloc(sizeof(int)*6);

	for(int i=1; i < argc; i++){
		if(strcmp(*(argv+i),"-d")== 0){
			if(DATA_SET == DEF){
				DATA_PARA = strdup(*(argv+i+1));
				DATA_SET = SET;
				i++;
			}
			else {
				printf("Data Parameter has been reseted");
				exit(1);
			}
		}
		else if(strcmp(*(argv+i),"-q")== 0){
			if(QUEUE_SET == DEF){
				QUEUE_PARA = strdup(*(argv+i+1));
				QUEUE_SET = SET;
				i++;
			}
			else {
				printf("Queue Parameter has been reseted");
				exit(1);
			}
		}
		else{
			*(STRUC_PARA+TypeCnt) = strdup(*(argv+i));
			TypeCnt +=1;
		}
	}

	if(TypeCnt == 0){
		TypeCnt+=1;
	}

	DataCnt = CHECK_DATA_PARA(DATA_PARA);

	QueCnt = CHECK_QUEUE_PARA(QUEUE_PARA);
	
	for(int j = 0; j<TypeCnt; j++){
		*(StrucType+j) = CHECK_STRUCT_PARA(*(STRUC_PARA+j));
	}

	PROD_DATA(DataCnt,QueCnt);

	for(int k = 0; k<TypeCnt; k++){
		BuildNSearch(*(StrucType+k),DataCnt,QueCnt);
	}


	return 0;
}
