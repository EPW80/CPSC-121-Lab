# Military to Regular Time
Create a function called `MilitaryToRegularTime` that converts time in the military time format into the regular format.
For example, convert `2249` to `10:49 pm`. For simplicity, we will not require you to handle invalid input - but you are 
free to define how your program should respond to invalid user input.

The function should receive a single `int` parameter that represents the military time.
It should return a `std::string` that contains the regular time counterpart of the given military time.

Please see the sample output below to guide the design of your program.


## Sample output:
<pre>
Please enter the time in military time: <b>1433</b>
The equivalent regular time is: 2:33 pm
</pre>

<pre>
Please enter the time in military time: <b>0300</b>
The equivalent regular time is: 3:00 am
</pre>

Make sure that you examine the `MilitaryToRegularTime` function prototype in `time_converter.h`, implement it in `time_converter.cc`,
and call it from inside of `main.cc`. You'll find that skeleton code has already been provided and you simply need to call the function, which
can be called from inside `main.cc` because we include the header file via: `#include "time_converter.h"`

# Submission checklist
1. Examined function declaration stored in `time_converter.h` file.
1. Completed function implementation in `time_converter.cc` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Call function in the driver (`main.cc` file).
1. Compiled and ran the driver (`main.cc` file).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).


# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/root/sandbox/lab03-<YOUR_USERNAME>` and you are currently in `/root/sandbox` you can issue the following commands

```
cd lab03-<YOUR_USERNAME>
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

Use the `make build` command to compile your code and save it into an executable file called `main`. Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `time_converter.cc` and `main.cc`, and into the executable file `main`.

```
clang++ -std=c++17 main.cc time_converter.cc -o main
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
