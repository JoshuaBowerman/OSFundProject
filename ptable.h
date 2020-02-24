#ifndef PTABLE_H
#define PTABLE_H
#include "macros.h"
#include <stdint.h>
#include <stdlib.h>
#include "globals.h"



struct Page_Table_s {
	uint16_t entries[NUM_PAGES];
} Page_Table;

void Init_Page_Table(){
	for(int i = 0; i < NUM_PAGES; i++){
		Page_Table.entries[i] = 0;
	}
}
//returns the frame number
uint8_t page_in(uint8_t page){
	//Seek to the location in the backing store.
	fseek(backing_fp,page*PAGE_SIZE,SEEK_SET);
	//read the data in
	if(fread(Memory + (PAGE_SIZE * (Page_Faults)),1,PAGE_SIZE,backing_fp) != PAGE_SIZE){
		printf("Error reading backing store.\n");
		exit(1);
	}
	return Page_Faults++;
}

int8_t retrieve(uint16_t addr){
    Addresses_Translated++;
	//Check page table
	if(!VI_BIT(Page_Table.entries[PAGE(addr)])){
		//Page Fault
		Page_Table.entries[PAGE(addr)] = BUNDLE(page_in(PAGE(addr)),1); //Update the page table and mark the entry valid

	}
	//Retrieve the data
	Physical_Address = (FRAME(Page_Table.entries[PAGE(addr)]) << PAGE_DEPTH) + OFFSET(addr);
	return Memory[(FRAME(Page_Table.entries[PAGE(addr)]) << PAGE_DEPTH) + OFFSET(addr)];
}
	
#endif