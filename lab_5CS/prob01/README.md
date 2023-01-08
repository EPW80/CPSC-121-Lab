# Finding the Minimum of a Vector

Write a function to return the index of the minimum value in a vector, or `-1` if the vector doesn't have any elements.
In this problem you will implement the `IndexOfMinimumElement` function in ``minimum.cc`` and then call that function from ``main.cc``.

You do not need to edit ``minimum.h``.

## Index of minimum value with ``std::vector``

Complete ``IndexOfMinimumElement`` in ``minimum.cc``. This function takes a ``std::vector`` containing doubles as input 
and should return the index of the smallest value in the vector, or -1 if there are no elements.


## Complete ``main.cc``

Your ``main`` function asks the user how many elements they want, construct a vector,
then prompts the user for each element and fills in the vector with values.

Your only task in ``main`` is to call the ``IndexOfMinimumElement`` function declared in ``minimum.h``, and print out the minimum element's index.
Here's an example of how this might look:

```
How many elements? 3
Element 0: 7
Element 1: -4
Element 2: 2
The minimum value in your vector is at index 1
```

## Code Evaluation

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `minimum.cc` and `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc minimum.cc -o main
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

