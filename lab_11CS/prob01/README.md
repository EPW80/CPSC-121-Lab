# Iterators
In this week's lab, you will practice creating and using iterators. We’ll review what they are, and common use cases for them.

## Overview of Iterators

### What is an iterator?
Iterators in C++ are objects that allow you to access each element of a container (e.g., std::vector, std::map). No matter the underlying implementation of the container, we can use the same iterator operations. This idea of using iterators to hide away (aka "abstract away") the underlying structure of a container and the specific implementation details needed to iterate over its elements is called _abstraction_, and is one of the core pillars of object-oriented programming.

### Obtaining Iterators
Iterators are effectively pointers to specific elements of a container. Containers in the C++ standard library often have the following functions defined to obtain an iterator for that container:
1. `begin()`, which returns an iterator pointing to the first element of a container, and
2. `end()`, which returns an iterator pointing to the element after the last element of a container.

Say we define a vector of strings:
```cpp
std::vector<std::string> lyrics
  {"I", "got", "my", "peaches", "out", "in", "Georgia"};
```
We can obtain an iterator that points to the first element, the string "I":
```cpp
std::vector<std::string>::iterator it = lyrics.begin();
```
To move the iterator along to other elements in the vector, we can apply iterator operators.

### Iterator Operators
1. operator++: the `++` operator, or increment, moves the iterator to point to the next element.
```cpp
it++;
std::cout << *it; // Prints "got"
```
Similarly, we can use the `+` operator to move the iterator by a specified amount of elements.
```cpp
it += 5; // Moves iterator forward by 5 elements.
std::cout << *it; // Prints "Georgia"
```

2. operator==: the `==` operator, or equality operator, is applied on two iterators to check if they are "equal". Two iterators are "equal" if they are pointing to the same element in the container.

We most frequently use an equality check as a condition in a for loop:
```cpp
for (std::vector<std::string>::iterator
        it = lyrics.begin();
        it != lyrics.end();
        it++) {
  ...
}
```
Let's break down each part of this for loop.
The initialization
```cpp
std::vector<std::string>::iterator it = lyrics.begin();
```
declares `it`, and sets `it` to point to the first element initially.

The condition `it != lyrics.end()` stops the for loop when the iterator has moved past the last element in the vector;

Finally, the update `it++` moves the iterator forward by 1 element at every iteration.

3. operator*: the `*` operator, or the deference operator, dereferences (i.e. accesses) the element that the iterator is currently pointing to.

What is returned when you dereference an iterator depends on what type of element is stored in that container. In the case of our `lyrics` vector above, dereferencing its iterator would give us a string, as each element is a `std::string`. We can complete the for loop below:

```cpp
for (std::vector<std::string>::iterator
        it = lyrics.begin();
        it != lyrics.end();
        it++) {
  std::cout << *it << " ";
}
```
Which, after all iterations are run, prints out "I got my peaches out in Georgia".

# Implementing the Plane Class
We've partially defined the `Plane` class for you in "plane.h" and provided the accessor and mutator functions for you, for each of the member variables in `Plane`: seat count, passenger count, and destination.

Define two constructors:
1. A default constructor which sets the default values of each of the member variables. `seat_count_`, and `passenger_count_` should be initialized to default values 121, and `destination_` set to "Fullerton"
2. A non-default constructor overload which accepts 3 parameters: an `int` for the seat count, `int` for the passenger count, and a const reference to a `std::string` for the destination.

In main.cc, you will be asked to create a fleet of `Plane` objects and iterate over that fleet. As you iterate over each `Plane` in the fleet, you must print out the flights and their destinations, **only if** that flight is fully booked. A flight is fully booked if every seat in the Plane is occupied (i.e. the passenger count is equal to the seat count). Assume that the passenger count is always less than or equal to the seat count. See expected output below:
```
121 passengers flying to Fullerton
220 passengers flying to Atlanta
75 passengers flying to Guatemala City
```
