#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Shifts n to the left to add 30 zeros
// GiB to GB: GB = GiB * (1024^3/1000^3) 
typedef void* void_ptr; 
#define PTR_SIZE ((u64)izeof(void_ptr))
// Since we are returning the capacity size including the size of u64 twice 
#define BASE (sizeof(Arena*)) 
// Rounding cursor to the next aligned address to ensure we add space contiguously
#define ALIGN_UP(curr, pow) (((u64)curr + (u64)pow - 1) & ~((u64)pow - 1))

typedef int8_t i8; 
typedef int16_t i16; 
typedef int32_t i32; 
typedef int64_t i64; 

typedef uint8_t u8; 
typedef uint16_t u16;
typedef uint32_t u32; 
typedef uint64_t u64; 

#define MiB(n) ((u64)n << 10)
#define KiB(n) ((u64)n << 20)
#define GiB(n) ((u64)(n) << 30)

typedef struct arena {
    u64 offset;
    u64 capacity;
} Arena; 

// Could commit or reserve space in arena using virtual address space
// Consider position alignment and fragmentation. 
Arena* create_arena(u64);
void destroy_arena(Arena*);
// namely arena_alloc. Can add as many object pointers as we can by definiting the correct sizeof into the function.Return pointer, and can be of any type by typecasting for init object structs or opther data types, as long as we allocate the right byte size, and ensure alignment to properly store size into arena. 
void* arena_alloc(Arena*, u64); 

void* arena_pop(Arena*, u64); 
void arena_clear(Arena*);


/* References:
 * > https://www.dgtlgrove.com/p/untangling-lifetimes-the-arena-allocator
 * > https://github.com/CobbCoding1/c-allocators
 * > https://andreleite.com/posts/2025/nstl/virtual-memory-arena-allocator/
 * > https://www.youtube.com/watch?v=jgiMagdjA1s
 *
 * */ 


