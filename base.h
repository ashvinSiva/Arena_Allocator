#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define KiB(bytes)(bytes << 10)
#define MiB(bytes)(bytes << 20) 
#define GiB(bytes)(bytes << 30)

typedef int8_t i8; 
typedef int16_t i16; 
typedef int32_t i32; 
typedef int64_t i64; 

typedef uint8_t u8; 
typedef uint16_t u16;
typedef uint32_t u32; 
typedef uint64_t u64; 

typedef struct arena {
    u64 capacity;

} Arena; 

// Could commit or reserve space in arena
void* arena_alloc();
void free_arena(Arena*);

void arena_push(Arena*); 
void* arena_remove(Arena*); 
void arena_clear(Arena*);

/* References:
 * > https://www.dgtlgrove.com/p/untangling-lifetimes-the-arena-allocator
 *
 *
 *
 * */ 


