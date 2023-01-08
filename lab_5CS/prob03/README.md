# Sentence Statistics

Create a program that can tell a user how many times a particular character appears in text input.
Your program will analyze the input, then prompt the user to enter characters to get stats. 
When the user types 'Q' the program will exit.

```
Enter text input to analyze: The quick brown fox jumped over the lazy dog.
What character do you want stats on? a
The character a appears 1 times.
What character do you want stats on? e
The character e appears 4 times.
What character do you want stats on? z
The character z appears 1 times.
What character do you want stats on? Q
Goodbye!
```

## Analyzing the sentence

We've provided starter code in `main.cc` to get input from the user. Now you need to analyze it. 
You can use a ``std::map`` to store information about each character and the number of times it appears in the input.

A ``std::map`` maps keys of one type to values of another type. For this problem, you'll want to map from
a letter to the number of times that letter appears. 

In C++, the ``char`` keyword is used to declare character type variables. A character variable can store only a single character.
In this case, your keys could be ``std::string`` or ``char``.  to represent a letter, and your values could be integers, to represent
the number of times that letter appears in the input. 
To declare a new map of ``char`` to ``int``, for example, you could do:

```cpp
std::map<char, int> my_map;
```
To add {key, value} pairs to the map, you can use the `insert` member function:
```cpp
// Insert the key 'c' into my_map with value 1
my_map.insert({'c', 1});
```

Then you can access elements with the `at` member function, for example:

```cpp
// Get the value for key 'c'
int value = my_map.at('c');
```

Note that if you try to access an element with `at` but that element doesn't exist in the map, the **program will crash**.
You can prevent this is by checking if a key exists in a map first. One way to do this is by using the `count` member function,
which returns how many times a given key appears in the map. If it returns 0, then it means that the given key is not in the map.
```cpp
if (my_map.count('c') == 0) {
    // The letter 'c' is not currently a key in the map.
}
```


## Responding to the user

Once you have your map of character counts, you can enter a loop that will exit only when the user types 'Q'.
We will use a loop to get characters from the user and tell them how many times each character appears in the sentence.

We've provided this loop for you, and we do so by using a `while` loop, which functions similarly to the `for` loops
you've already learned about. The syntax for a C++ while loop is:
```cpp
while (condition) {
  // code block to be executed
}
```
The code block in a while loop will be executed as long as the condition is true. In this problem,
using `while (true)` ensures that we will keep asking the user for input as many times as they want - 
and we can exit out of the loop on demand, using a special keyword called `break`, 
which is used to jump out of a loop.

## Code Evaluation

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc -o main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.
For code style, make sure you follow advice from the stylechecker using ``make stylecheck``.
For code formatting, make sure you follow advice from the formatchecker to improve code readbility using ``make formatcheck``.

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type `git add .` (period) to add all modified files.

    ```
    git add main.cc
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit -m "Your description here"
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type the `git commit -m "Your description here"` command again.    
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and personal access token when you are asked.

    ```
    git push
    ```
1. Once you push, the autograder is automatically kicked off. Check the results in the 'Actions' tab - a green check means that all tests passed.

