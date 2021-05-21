#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"header.h"

void Print_Build_Time(struct timeval start,struct timeval end){
	unsigned long diff;
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("Building Time: %ld us (equal to %f sec)\n",diff,diff/1000000.0);
}

void Print_Search_Time(struct timeval start,struct timeval end){
	unsigned long diff;
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("Query Time: %ld us (equal to %f sec)\n\n",diff,diff/1000000.0);
}