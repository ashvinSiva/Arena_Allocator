#include "base.h"
/*
Notes:
 > Metadata: hidden feature after malloc that provides extra information about the memory space you've borrowed. 
  Enables to track the size of each allocation, efficiently free memory, merge free chunks, and maintain 
  internal data structures. Mainly stores prev_size, curr_size, fd & bk (only used when chunk is free)
 > Contiguous memorry allocation: storing a consistent, non-broken memory sequence in a process, leaving the other 
  oontiguous memory in the same place. It can be easily divided by equally partitions of the same, fixed size.
*/


// capacity: as the name suggests, the function takes a 8-byte capacity size to borrow memory space in the virtual memory (VM)
Arena* create_arena(u64 capacity) {

    Arena* arena = (Arena*)malloc(capacity); 
    assert(arena);
    
    /* 
     offset has to start at the arena's BASE value because 
     the memory space malloced has to reserve the size of Arena type
     included.
    */
    arena->offset = BASE;   
    arena->capacity = capacity;
    
    return arena;
}
// takes the arena to free the memory space
void destroy_arena(Arena* arena) {
    free(arena); 
    arena = NULL;
}

// size: takes the sizeof() from a data type or reference type 
void* arena_alloc(Arena* arena, u64 size) {
    /* 
      > Make sure the position is in alignment, otherwise we would access values in fragmented space
      > Make sure we add by alignment along with correct padding to avoid fragmentation and
        non-contiguous uneven space
     */
    u64 align_pos = ALIGN_UP(arena->offset, ALIGN);  //get aligned position     
    assert(align_pos + size < arena->capacity); //make sure the new position (align_pos + size) is not greater than the capacity 
    arena->offset = align_pos + size; // set new postion to offset
    u8* out = (u8*)arena + align_pos; // increment by 1 byte, why?
   
    return out;
}

// takes the specific arena to pop the top object by taking its size of object type (prev_size)
void* arena_pop(Arena* arena, u64 prev_size) {
   
    assert(prev_size < arena->capacity && prev_size < arena->offset); 
    u64 align_pos = ALIGN_UP(prev_size, ALIGN); //alignment in memory space is very necessary to ensure contiguous sequence 
    arena->offset -= align_pos;

    
    return arena; 
}

// takes the specific arena to clear all objects 
void arena_clear(Arena* arena)  {
    arena->offset = BASE; 
}
