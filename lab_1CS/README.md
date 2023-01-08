# Restaurant bill
Create a program that computes the restaurant bill. The program should ask the user for the meal's cost and the tip percentage.

## Goal:
* Write C++ programs
* Compile C++ programs
* Implement programs that use `std::cin` and `std::cout` correctly
* Implement mathematical expressions in C++
* Implement code that formats floating-point output correctly

Assume that the tax is 7.5% of the meal cost. Specifically, please use the value 0.075 to avoid issues with the unit test. This value should be defined as a constant in your program. And the tip is computed by multiplying the tip percentage from the user by the meal cost. Display the meal cost, tax, tip, and total amount.

Follow the sample output below as closely as possible. Note that <b>bold</b> values in the sample represent input by the user. Take note that different user input results in a different output.

<pre>
Please input meal cost: <b>34</b>
Please input tip percentage: <b>15</b>

Restaurant Bill
====================
Subtotal: $34.00
Taxes: $2.55
Tip: $5.10
====================
Total: $41.65
</pre>

# Submission checklist
1. Compiled and ran the driver (main).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (make test).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc -o main
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

We recommend pushing to github frequently to back up your work.
