

 vector is the type of sequence that should be used by default, list should be used when there are frequent insertions and deletions from the middle of the sequence, deque is the data structure of choice when most insertions and deletions take place at the beginning or at the end of the sequence.

 Effective STL - by Scott Meyers 2


 Contiguous-memory containers [also known as array-based containers] store their elements in one or more (dynamically allocated) chunks of memory, each chunk holding more than one container element. If a new element is inserted or an existing element is erased, other elements in the same memory chunk have to be shifted up or down to make room for the new element or to fill the space formerly occupied by the erased element. This kind of movement affects both performance (see Items 5 and 14) and exception safety (as we'll soon see). The standard contiguous-memory containers are vector, string, and deque. The nonstandard rope is also a contiguous-memory container.

 Node-based containers store only a single element per chunk of (dynamically allocated) memory. Insertion or erasure of a container element affects only pointers to nodes, not the contents of the nodes themselves, so element values need not be moved when something is inserted or erased.

 Effective STL - by Scott Meyers 2

repeated single-element insertions VS single range insertion

 when you try to insert an element into a vector whose memory is full, the vector allocates new memory with more capacity, copies its elements from the old memory to the new memory, destroys the elements in the old memory, and deallocates the old memory. Then it adds the element that is being inserted. 

 most vector implementations double their capacity each time they run out of memory,
 so inserting 1000 elements one at a time can result in 10 new allocations (including their incumbent copying of elements). In contrast (and. by now, predictably), a range insertion can figure out how much new memory it needs before it starts inserting things (assuming it is given forward iterators), so it need not reallocate a vector's underlying memory more than once. 

range insertions into associative containers may indeed be more efficient than repeated single-element insertions

 Effective STL - by Scott Meyers 16


Time to process a range of 14 elements with std::vector: 0.64286 us
Time to process a range of 14 elements with std::deque : 0.78571 us


The difference in timing between processing a range of 14 elements with std::vector and std::deque is likely due to the way these two containers store their elements in memory.

std::vector stores its elements in contiguous memory, which means that accessing elements in a std::vector is generally faster than accessing elements in a std::deque, especially for large ranges of elements. This is because accessing elements in contiguous memory involves fewer memory lookups and cache misses.

On the other hand, std::deque stores its elements in chunks of memory called "blocks", and each block is allocated separately. This means that accessing elements in a std::deque requires more memory lookups and cache misses than accessing elements in a std::vector, which can lead to slower processing times for small ranges of elements.



The difference in timing between processing a range of 14 elements with std::vector and std::deque may be due to a combination of factors, including:

Memory allocation: std::vector stores its elements in contiguous memory, which can make it faster than std::deque for accessing elements that are close together. In contrast, std::deque stores its elements in a more complex data structure that can require more memory allocations and deallocations, which can slow down performance.

Cache locality: Because std::vector stores its elements in contiguous memory, it can take advantage of CPU cache locality to access elements more quickly. In contrast, std::deque stores its elements in a more complex data structure that may not be as cache-friendly, which can slow down performance.

In general, std::vector is typically faster than std::deque for accessing elements, especially when the number of elements is large. This is because std::vector stores its elements in contiguous memory, which allows for faster access times and better cache locality.


memory allocation and cache locality.


Arrays have better cache locality that can make a pretty big difference in performance.

arrays are contiguous memory blocks, so large chunks of them will be loaded into the cache upon first access. This makes it comparatively quick to access future elements of the array. Linked lists on the other hand aren't necessarily in contiguous blocks of memory, and could lead to more cache misses, which increases the time it takes to access them.



contiguous memory blocks = cache friendly

Principle of Locality
https://youtu.be/3XmALGPW0zA

the library example
https://youtu.be/247cXLkYt2M

C++ cache locality and branch predictability
https://www.youtube.com/watch?v=EmzdmqUWq3o


14:30 data locality, nearby data is likely to be accessed soon
https://youtu.be/LzsiFYVMqi8
