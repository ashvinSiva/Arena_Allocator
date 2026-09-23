#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

/*
  Used for one of the agruments in ALIGN_UP to maintain contiguous sequence of objects in memory.
  The size of the void pointer is always 8 bytes.
*/
#define ALIGN (sizeof(void*))
/*
 Since we are returning the capacity size including the size of u64 twice, 
 which stores the value of offset and capacity in the memory space
*/
#define BASE (sizeof(Arena))  
/* 
 This function macro rounds the cursor to the next aligned address to ensure the
 memory space is contiguous. 'o' is the current offset, while 'p' stand for the power of 2 (1,2,4,8,etc). 
*/
#define ALIGN_UP(o, p) (((u64)o + (u64)p - 1) & ~((u64)p - 1))

// typedef macros to type faster and easier (shoutout to MacigcalBat!)
typedef int8_t i8; 
typedef int16_t i16; 
typedef int32_t i32; 
typedef int64_t i64; 
typedef uint8_t u8; 
typedef uint16_t u16;
typedef uint32_t u32; 
typedef uint64_t u64; 

// Some defined macros that convert from bytes to larger metric bytes
#define MiB(n) ((u64)n << 10)
#define KiB(n) ((u64)n << 20)
#define GiB(n) ((u64)n << 30)

/* 
 An arena requires an offset to track the position or displacement. 
 It also requires a capacity to maintain the size of the arena consistently 
*/
typedef struct arena {
    u64 offset;
    u64 capacity;
} Arena; 

// Creates an arena allocator by accepting a size, which is the capacity of the chunk of memory
Arena* create_arena(u64);
/*
 Destroys the arena simply by freeing it. It only takes the 
 Arena* type, which is simply the arena that was created.
*/
void destroy_arena(Arena*);

/* 
 Adds as many object pointers as I can by definiting the correct sizeof into the function.
 Returns pointer, and can be of any type by typecasting for object structs or other 
 data types, as long as we allocate the right byte size, and ensure alignment 
 to properly store size into arena. 
*/
void* arena_alloc(Arena*, u64); 
// Pops an object in the arena from the top, acting like a stack. It needs to know its previous size of data/reference type.
void* arena_pop(Arena*, u64); 
// Completely clears the specified arena.
void arena_clear(Arena*);

