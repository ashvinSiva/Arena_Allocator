#include "base.h" 
#include <stdio.h>


void printArena(Arena* arena); 

typedef struct person {
    u32 ID; 
    char* firstName; 
    char* lastName; 
} Student;

int main() {
    Arena* arena = create_arena(MiB(1)); 
    printArena(arena); 

    Student* Pete = (Student*)arena_alloc(arena, sizeof(Student));
    Pete->ID = 123; 
    Pete->firstName = "Pete"; 
    Pete->lastName = "Castle";
    printArena(arena); 

    Student* Charlie = (Student*)arena_alloc(arena, sizeof(Student)); 
    Charlie->ID = 456; 
    Charlie->firstName = "Charlie"; 
    Charlie->lastName = "Cox"; 
    printArena(arena); 

    Student* Karen = (Student*)arena_alloc(arena, sizeof(Student)); 
    Karen->ID = 267; 
    Karen->firstName = "Karen"; 
    Karen->lastName = "Page";
    printArena(arena); 

    Student* Foggy = (Student*)arena_alloc(arena, sizeof(Student)); 
    Foggy->ID = 219; 
    Foggy->firstName = "Foggy"; 
    Foggy->lastName = "Nelson"; 
    printArena(arena); 

    arena_pop(arena, sizeof(Student)); 

    arena_clear(arena); 

    for(int i = 0; i < 100; i++) {
        int* ptr = (int*)arena_alloc(arena, sizeof(int));
        *ptr = i; 
    }
   
    printArena(arena); 

    destroy_arena(arena); 

    return 0; 

}

void printArena(Arena* arena) {
    
    printf("offset: %llu, capacity: %llu\n", arena->offset, arena->capacity);
    
}
