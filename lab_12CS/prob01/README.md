# Recursion
In this week's lab, you will practice writing recursive functions, and applying recursion to recursive structures.

## Overview of Recursive Functions

Recursion is a technique for solving a large computational problem by repeatedly applying the same function(s) to simplify it to successively smaller problems. 

A recursive function has two components: one or more base cases and a recursive call.

### Base Case
A **base case** is a predetermined solution for the simplest version of the problem: if the given problem is a base case, no further computation is necessary to get the result.

In the case of recursive objects, the "simplest" version of the problem often involves a `nullptr` check.

### Recursive Call
The recursive call is a set of rules that eventually reduces all versions of the problem to one of the base cases when applied repeatedly.

Infinite recursion occurs if there is no base case or the recursive call does not make progress towards the base case(s).

# Implementing the Customer Class
We've partially defined the `Customer` class for you in "customer.h" and provided the member variables for you for a `Customer`: `name_` representing the name of the Customer, `product_count_` representing the number of products in the Customer's shopping cart, and `next_customer_` representing the next Customer in line, if there is one.

You are tasked with defining the constructors, accessor functions, and recursive functions.
1. Create a non-default constructor which accepts 3 parameters: a const reference to a `std::string` for the customer's name, an `int` parameter for the product count, and a shared pointer to the next customer in line.
2. Create accessor functions `GetName`, `GetProductCount`, and `GetNextCustomer`, which each should return the corresponding member variable.
3. Define the recursive member function `TotalCustomersInLine`, which accepts no input, and returns an `int` representing the total number of customers waiting in line starting at the current customer and including all customers lined up behind them.
4. Define the recursive member function `TotalProductsInLine`, which accepts no input, and returns an `int` representing the total number of products held by customers waiting in line starting at the current customer and including all customers lined up behind them.
5. Define the recursive member function `FirstAlphabeticalCustomerInLine`, which accepts no input, and returns a `std::string` which is the name of the customer in line whose name comes first alphabetically, compared to all other customers lined up behind them. Hint: for this question, you can use `<` or `>` to compare strings.

In main.cc, you will be asked to invoke each recursive function for a line of customers we've provided for you, starting with Adele at the front of the line.

You are tasked with asking **the customer at the front of the line** how many customers are waiting in total, how many products are waiting to be purchased in the line, and the name of the customer in line that comes first alphabetically.

After running main, your output should be:
```
Total customers waiting: 5
Total products to be purchased: 34
First customer name alphabetically: Adele
```

# Code Evaluation

If you're using Replit, you can click the "Run" button and follow the prompts to build and test your code.

Otherwise:

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `customer.cc` and `main.cc` and into the executable file `main`. 

```
clang++ -std=c++17 main.cc customer.cc -o main
```


## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.
For code style, make sure you follow advice from the stylechecker using ``make stylecheck``.
For code formatting, make sure you follow advice from the formatchecker to improve code readbility using ``make formatcheck``.

# Submission
1. When everything runs correctly,  let's copy your code into the GitHub repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type `git add .` (period) to add all modified files.

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
