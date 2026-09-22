#include "base.h"
/*Notes:
 * Metadata: hidden feature after malloc that provides extra information about the memory space you've borrowed. Enables to track the size of each allocation, efficiently free memory, merge free chunks, and maintain internal data structures. Mainly stores prev_size, curr_size, fd & bk (only used when chunk is free)
 *
 *
 * Contiguous memorry allocation: storing a consistent, non-broken memory sequence in a process, leaving the other contiguous memory in the same place. It can be easily divided by equally partitions of the same, fixed size.
 *
 * */


//The user should know its data type's number of bytes
Arena* create_arena(u64 capacity) {
    // Can request memory space on either virtual address space (recommended) or malloc for each arena
    // Can request by multiplying capacity by 1 byte, typecast Arena* with capacity space
    Arena* arena = (Arena*)malloc(capacity); 

    assert(arena);
    
    arena->offset = BASE;   
    arena->capacity = capacity;
    
    return arena;
}

void destroy_arena(Arena* arena) {
    free(arena); 
    arena = NULL;
}

// size takes the sizeof() from a data or reference type 
void* arena_alloc(Arena* arena, u64 size) {
    
    u64 align_pos = ALIGN_UP(arena->offset, PTR_SIZE); // Make sure the position is in alignmenot, otherwise we would access values in fragmented space
    // Make sure we add by alignment along with correct padding to avoid fragmentation and non-contiguous uneven space
    assert(align_pos + size < arena->capacity); 
    arena->offset = align_pos + size; 
    
    u8* out = (u8*)arena + align_pos; // increment by 1 byte, why?
   
    return out;
}

void* arena_pop(Arena* arena, u64 prev_size) {

    assert(prev_size < arena->capacity && prev_size < arena->offset); 
    
    arena->offset -= prev_size; 
    
    return arena; 
}

void arena_clear(Arena* arena)  {
    arena->offset = BASE; 
}







