# Arena Allocator
Imagine you are creating a large and complex low-level C project where you have to dynamically allocate hundreds or thousands of memory blocks in the heap. This is where each malloc() pointers live in a huge space of random memory addresses like a large Walmart warehouse. Unlike any warehouse, the memory space is borrowed at random locations, which leaves unused and wasted space in the virtual memory. In the end, you'll have to make sure you free hundreds or thousands of pointers to ensure you are not leaving any memory leaks in the heap. Notice that for every malloc you do, you'd have to free each malloc every time. This is known as symmetry, and it is catastrophic. 

What if we can store every objects in a large chunk of memory? Anytime we add objects next to each other equally spaced in the chunk of memory, we would not waste any memory space anywhere! If ever the chunk reached its limit, we can create a new memory set by expanding the capacity. In the end, we can only destroy or free the chunk of memory only ONCE for every chunk of memory created. At this point, the concept behaves similarly to garbage collection, like in Java! This concept is known as an arena allocator, also called a linear allocator. In this repo, the goal is to improve C syntax and memory management by creating my own custom arena allocator. 

## References
- https://www.dgtlgrove.com/p/untangling-lifetimes-the-arena-allocator
- https://andreleite.com/posts/2025/nstl/virtual-memory-arena-allocator/
- https://www.submillisecond.com/glossary/systems/memory-alignment#worked-example---struct-layout
- https://github.com/CobbCoding1/c-allocators
- https://medium.com/@mrajagopalaswamy/malloc-and-its-hidden-metadata-de77aa212090
  
