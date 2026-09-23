#include "base.h" 
#include <stdio.h>


void printArena(Arena* arena); 

typedef struct person {
    u32 ID; 
    char* firstName; 
    char* lastName; 
} Student;

typedef struct pt {
    i32 x;
    i32 y;
} Point;

int main() {
    Arena* arena = create_arena(MiB(1)); 
    printArena(arena); 

    Student* Pete = (Student*)arena_alloc(arena, sizeof(Student));
    Pete->ID = 1; 
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

    
    Point* p1 = (Point*)arena_alloc(arena, sizeof(Point)); 
    p1->x = 0; 
    p1->y = 0;

    Point* p2 = (Point*)arena_alloc(arena, sizeof(Point));
    p2->x = 1;
    p2->y = 1;
    
    Point* p3 = (Point*)arena_alloc(arena, sizeof(Point)); 
    p3->x = 2;
    p3->y = 2;

    printArena(arena);

    //arena_clear(arena); 

    for(i32 i = 0; i < 100; i++) {
        int* ptr = (int*)arena_alloc(arena, 4);
        *ptr = i; 
    }

    arena_pop(arena, sizeof(int));
   
    printArena(arena); 

    destroy_arena(arena); 

    return 0; 

}

void printArena(Arena* arena) {
    
    printf("offset: %llu, capacity: %llu\n", arena->offset, arena->capacity);
    
}
