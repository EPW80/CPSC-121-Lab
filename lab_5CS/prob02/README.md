# Class Average GPA
Create a program that dynamically creates a vector whose size depends on the user's preference. 
Pass the vector to a `CalculateAverage` function that is responsible for computing the average GPA of the given vector of GPAs.

### CalculateAverage
Implement a function called `CalculateAverage` in ``calculate_avg.cc`` that calculates the average of a `double` vector and returns that average.

`CalculateAverage()` will have one parameter, a `std::vector<double>&` referring to the vector.

When the vector size is greater than 0, the function should calculate the average GPA from the given vector of grades.

However, when the size of the vector is 0, then the function should return 0.

### main
The `main` function has mostly been built for you. It is your task to:
1. Construct a `double` vector based on the inputted class size.
2. Store each student's GPAs into the vector.
3. Pass the vector as input to `CalculateAverage` to compute the average GPA of the class. 
4. Display the students' average GPA. 
Read the instructions in `main.cc` for more details.

If the user happens to provide a class size of `0`, then the program should output `"You have no students!"` and then end the execution of the program without attempting to calculate the average.

Place the `CalculateAverage`'s function's' implementation in `calculate_avg.cc`. We have provided the prototype in `calculate_avg.h`.

# Sample Output
<pre>
How many students are in your class? <b>5</b>
Enter the GPA for the students in your class (0.0 - 4.0)
Enter the GPA for student #1: <b>3.8</b>
Enter the GPA for student #2: <b>2.5</b>
Enter the GPA for student #3: <b>4.0</b>
Enter the GPA for student #4: <b>1.9</b>
Enter the GPA for student #5: <b>3.6</b>
Class average: 3.16
</pre>

<pre>
How many students are in your class? <b>0</b>
You have no students!
</pre>

## Code Evaluation

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `calculate_avg.cc` and `main.cc`, and into the executable file `main`. 
You need to include ``calculate_avg.cc`` when compiling so that clang can find the implementation of `CalculateAverage`:

```
clang++ -std=c++17 main.cc calculate_avg.cc -o main
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

