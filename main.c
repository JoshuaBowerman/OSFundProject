#include "globals.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "macros.h"
#include "ptable.h"
#include <stdlib.h>






int main(int argc, char **argv){
	//Process Arguments
	if(argc <= 1){ //No arguments provided
		printf("VMM Translator\n");
		printf("Usage: %s <FNAME>\n",argv[0]); //argv[0] is the name of the program executable.
		printf(" <FNAME> should point to a file containing a list of integers.\n");
		return 0;
	}
	//check if provided filename exists.
	if( access( argv[1], F_OK ) == -1 ){
		printf("ERROR: File does not exist.\n");
		return 0;
	}

	FILE *fp = fopen(argv[1],"r");

	if(fp == NULL){
		printf("Error reading addresses file.\n");
		return 0;
	}
	//check if backing store file exists.
	if( access( BACKING_STORE_LOCATION, F_OK ) == -1 ){
		printf("ERROR: Backing Store does not exist or is named wrong.\n The backing store should be named \"%s\"\n",BACKING_STORE_LOCATION);
		return 0;
	}
	backing_fp = fopen(BACKING_STORE_LOCATION,"r");
    if(backing_fp == NULL){
		printf("Error reading backing store file.\n");
		return 0;
	}

	//initialize page table
    Init_Page_Table();


	uint16_t addr;
	while(fscanf(fp,"%u",&addr) == 1){
		int8_t value = retrieve(ADDRESS(addr));
		printf("Virtual address: %u Physical address: %u Value: %d\n",addr,Physical_Address,value);
	}

	//output statistics
	double fault_rate = (double)Page_Faults / Addresses_Translated;
	printf("Number of Translated Addresses = %u\nPage Faults = %u\nPage Fault Rate = %.3f\n",Addresses_Translated,Page_Faults,fault_rate);
	return 0;
}


