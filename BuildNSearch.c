#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void BuildNSearch(int Type,int DataCnt,int QueCnt){
	switch(Type){
		case 1:
			BST(DataCnt,QueCnt);
			break;
		case 2:
			ArrWBS(DataCnt,QueCnt);
			break;
		case 3:
			ArrWLS(DataCnt,QueCnt);
			break;
		case 4:
			LinkedList(DataCnt,QueCnt);
			break;
		case 5:
			Hash(DataCnt,QueCnt);
			break;
		default:
			printf("Unknown DataStruct Identified\n");
			break;
	}
}
