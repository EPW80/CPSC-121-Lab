# Insecure Bank Accounts
For this exercise you will create a `Bank` class that represents a bank that doesn't care about privacy. This bank allows anyone to create an account, delete an account, and view all the accounts registered with the bank and their associated balances.

We've provided the `Account` class for you already. An `Account` represents an individual's bank account - which stores the name of the account holder and the current balance in US dollars.

## Bank Class
The `Bank` class stores all the accounts that have been created with this bank. It allows people to create and delete accounts with the bank, get the total accounts that the bank currently has, and display every account holder's total balance in US Dollars.

### Member Variables
Create the following private member variables:
1. `bank_name_` - a string representing the name of this bank.
2. `accounts_` - a map whose key is an int representing the account ID, and whose value is the `Account` object representing the account associated with that ID.

### Constructor
Create one non-default constructor, which accepts a const reference to a string, which specifies the name of this bank. 

### Accessor Functions
Create two accessor functions for the two member variables. Please use these names for your accessors: `GetBankName()` and `GetAccounts()`. Use const references where appropriate (i.e. to avoid expensive copies when returning large objects!)

### CreateAccount
Create a member function `CreateAccount`, which accepts a const string reference representing the name of the account holder, and a double for the initial balance of the account. `CreateAccount` should use these inputs to create a new `Account` object. Use the provided `GenerateAccountId()` function to create a random ID between [1000, 9999] and use that as the new account's ID, and store the mapping from that ID to the `Account` object into the `accounts_` map. This function should return an `int` - the randomly generated account ID.

### TotalAccounts
Create a member function `TotalAccounts`, which accepts no input and returns the total number of accounts in the map.

### DisplayBalances
Create a member function `DisplayBalances`, which accepts no input and returns nothing. This function should use an iterator object (please use `.begin()` and `.end()`) to iterate through all **key, value pairs** in `accounts_`, and print the details of each account to the console - the account holder's name and the current balance in the following format:
```
Alice: $100.21
Bob: $2250.62
Carl: $50.25
```

### DeactivateAccount
Create a member function `DeactivateAccount`, which accepts an int representing the ID of the account to be deactivated. This function should remove the account from the map, if that account ID exists. You can use the `std::map` function `find`, which takes in a key and returns an iterator pointing to that key if that key exists in the map, e.g.:
```cpp
std::map<std::string, int> grades {{"JC", 98}, {"Paul", 97}, {"Carl", 78}};
grades.find("JC"); // returns an iterator pointing to {"JC", 98}
grades.find("Bob"); // returns grades.end(), since "Bob" is not in the map.
```
You can use the `erase` function we learned in lecture last week. The `erase` function for vectors works the same way as it does for a map:
```cpp
// Removes the element pointed to by the iterator pos from the map
iterator std::map::erase(iterator pos);
```
For example,
```cpp
std::map<std::string, int>::iterator it = grades.find("JC");
grades.erase(it);
```

## Other instructions
Complete the `main` function as described. Place the `Bank` class in `bank.h`. Member functions that take more than ten lines or use complex constructs should have their function prototype in the respective `.h` header file and implementation in the respective `.cc` implementation file.

## Sample Output:
```
Frank: $1234.56
Oreo: $140.12
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
The sample code below shows how you would compile code in `bank.cc` and `main.cc` and into the executable file `main`. 

```
clang++ -std=c++17 main.cc bank.cc -o main
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
