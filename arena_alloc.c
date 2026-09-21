#include "base.h"
/*Notes:
 * Metadata: hidden feature after malloc that provides extra information about the memory space you've borrowed. Enables to track the size of each allocation, efficiently free memory, merge free chunks, and maintain internal data structures. Mainly stores prev_size, curr_size, fd & bk (only used when chunk is free)
 *
 *
 * */


//The user should know its data type's number of bytes
Arena* create_arena(u64 capacity) {
    // Can request memory space on either virtual address space (recommended) or malloc for each arena
    // Can request by multiplying capacity by 1 byte, typecast Arena* with capacity space
    Arena* arena = (Arena*)malloc(capacity); 
    
    arena->offset = 0; 
    arena->capacity = capacity;
    
    return arena;
}

void destroy_arena(Arena* arena) {
    free(arena); 
    arena = NULL;
}

void* arena_push(Arena* arena, u64 size) {

    assert(arena->offset + size < arena->capacity); 

    return NULL;
}



