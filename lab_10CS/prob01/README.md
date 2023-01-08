# Shared Pointers
Today you and your lab partner will practice creating and using shared pointers. We’ll review what they are, how to use them, and the motivation behind using them over raw pointers.

## Overview of std::shared_ptr

### Creating shared_ptr
A pointer, like a variable, is a container. Variables can hold values (e.g. `int`, `double`, `bool`, `std::string`), and so can pointers - but there's one main difference. While variables you've seen so far hold some type of data, a pointer doesn't contain the data we typically use.  Instead, a pointer’s data is an address in memory - it "points" to data.

We must tell C++ what data will be stored in the address the pointer points to, using the following syntax:

```cpp
std::shared_ptr<DATA_TYPE> pointer_name;
```

The code snippet above creates a *null pointer*. No object was created, so there's no memory address for the pointer to store. If we want to create an object in memory for our pointer to point to, we use the `make_shared` function:
```cpp
std::shared_ptr<DATA_TYPE> pointer_name = std::make_shared<DATA_TYPE>();
```

### Null pointers
If we are creating a shared pointer by just declaring (instead of defining it with `std::make_shared`), then it is a "null pointer", which is represented in C++ by the keyword `nullptr`. When handling and passing around pointers, it is very important to check for the case when your function receives a nullptr as input, as a nullptr can’t be dereferenced, e.g.:
```cpp
if (pointer_name != nullptr) {
  // It's safe to dereference pointer_name here.
}
```

### Why Use Shared Pointers?
Each C++ program you write gets allocated a certain amount of memory for your program to store local variables and function arguments - in a place called the Stack. The size of the stack is limited, and it varies depending on several factors (e.g. your operating system, compiler version, etc). The stack is often only 1-10 MB in size.

Since the stack is limited in space, when you start wanting to create bigger objects and data structures in your programs, you may find it is quite easy to run out of space on the stack - an issue called a **"Stack
Overflow"**. 

To avoid this, we can define pointer on the stack, which takes up a small amount of space (e.g. 4 bytes). The pointer may point to a place in memory called the Heap, a much larger (virtually unlimited) area of memory on your computer that is not already allocated to your program. Defining a `std::shared_ptr` on your stack does not take up much memory, but the object it points to may take up a lot of memory. This is why it is important to have that object be dynamically allocated in the heap, and just access that data through pointers.

A `std::shared_ptr` is a smart pointer, meaning that it is smart enough to handle memory management for us. The allocation of memory on the Heap for our objects is done under the hood whenever we use `make_shared`, and it automatically deallocates that memory when it's not used anymore (in other words, we don't need to explicitly `delete` the object it holds!). 

### use_count
A `std::shared_ptr` tracks how many `std::shared_ptr`s point to the same object by tracking the `use_count`. A std::shared_ptr's use_count decreases by one when it is assigned a nullptr or when it goes out of scope. A variable goes out of scope when a function containing it exits or a code block containing the variable exits (e.g., loop body, if statement body). When there are no  more `std::shared_ptr` pointing to the object in the heap, it is automatically deleted, and that space in memory is freed up.

This feature is what makes smart pointers like `shared_ptr` so powerful - it reduces the risk of **memory leaks** - which happens when the programmer forgets to free up allocated space in memory.

Please print the following secret key to the bottom of the main function in `main.cc` to pass the unit test: 
```cpp
std::cout << "TUFFY121L" << std::endl;
```
Now give yourself a pat on the back for reading this far! :)
