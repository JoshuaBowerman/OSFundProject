#ifndef MACROS_H
#define MACROS_H


#define BACKING_STORE_LOCATION "BACKING_STORE.bin"
#define ADDRESS_DEPTH 16
#define PAGE_DEPTH 8
	
#define ADDRESS_SPACE (0x01 << ADDRESS_DEPTH)		//The total number of bytes in the address space
#define OFFSET_DEPTH (ADDRESS_DEPTH - PAGE_DEPTH)	//number of bits used for the offset
#define PAGE_SIZE (0x01 << OFFSET_DEPTH) 			//number of bytes in each page
#define NUM_PAGES (0x01 << PAGE_DEPTH) 				//number of pages in the address space

#define PAGE_MASK ((0x01 << PAGE_DEPTH) - 1)
#define OFFSET_MASK ((0x01 << OFFSET_DEPTH) - 1)
#define ADDRESS_MASK ((0x01 << ADDRESS_DEPTH) - 1)

#define PAGE( addr ) ((( addr >> OFFSET_DEPTH ) & PAGE_MASK ))	//returns the page number for the provided address
#define OFFSET( addr ) ( addr & OFFSET_MASK )					//returns the offset for the provided address
#define ADDRESS( addr ) ( addr & ADDRESS_MASK )					//masks the provided address so that it fits in the address space

#define VI_BIT( val ) (( val & 0x0100 ) >> OFFSET_DEPTH )       //returns the valid invalid bit from a page table entry
#define FRAME( val ) ( val & 0x00ff )                           //returns the frame number from a page table entry
#define BUNDLE( frame , vi ) ((vi << PAGE_DEPTH) + frame)       //bundles a frame number and VI bit for storage in the page table



#endif