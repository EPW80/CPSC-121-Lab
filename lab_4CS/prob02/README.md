# Rectangle Class
Observe the `Rectangle` class in `rectangle.h`, and you'll see it has two member variables: `length_` and `width_`.
These member variables can be modified with the "Setter functions" `SetLength` and `SetWidth` (aka mutator functions) and can be retrieved 
with the "getter functions" `GetLength` and `GetWidth` (aka accessor functions).

You will be implementing two member functions of the `Rectangle` class: `Area`, and `Perimeter`. 

Notice that if a function belongs to a class, when we define the function outside of the class, we indicate that it is a member
function of a class using the `::` operator. For example, because `Area()` belongs to the `Rectangle` class, when we define the
function in `rectangle.cc`, it is written as:

```
int Rectangle::Area() {
  ...
}
```

After implementing these two member functions, you will implement a function, `LargestRectangleByArea` that compares two input `Rectangle` objects
and returns which of the two is larger, based on its area.

1. Implement the member function `Area` that returns the area of the `Rectangle` object.
2. Implement the member function `Perimeter` that returns the perimeter of the `Rectangle` object. (Note that the perimeter is equal to the total sum of the length of all of a rectangle's sides).
3. Implement the function `LargestRectangleByArea` to find the larger of two input `Rectangle`s by area.

Complete `main.cc` according to the comments provided in the file. Note that <b>bold</b> values in the samples represent input by the user.

# Sample Output:
<pre>
====== Rectangle 1 ======
Please enter the length: 2
Please enter the width: 3
Rectangle 1 created with length 2 and width 3
The area of Rectangle 1 is: 6
The perimeter of Rectangle 1 is: 10

====== Rectangle 2 ======
Please enter the length: 4
Please enter the width: 5
Rectangle 2 created with length 4 and width 5
The area of Rectangle 2 is: 20
The perimeter of Rectangle 2 is: 18

The largest rectangle has a length of 4, a width of 5, and an area of 20.
</pre>

# Submission checklist
1. Accepted user input in the `main.cc` file.
1. Instantiated two Rectangle objects based on the user input.
1. Called the `LargestRectangleByArea` to determine which rectangle is larger.
1. Compiled and ran the driver (`main.cc` file).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/root/sandbox/lab04-<YOUR_USERNAME>` and you are currently in `/root/sandbox` you can issue the following commands

```
cd lab04-<YOUR_USERNAME>
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile `rectangle.cc` and `main.cc`, and into the executable file `main`.

```
clang++ -std=c++17 main.cc rectangle.cc -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

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
