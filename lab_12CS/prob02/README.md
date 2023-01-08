# Implementing the Train Class
We've partially defined the `Train` class for you in "train.h" and provided the constructor, accessor (getter) functions, and member variables for you for a `Train`: `passenger_count_` representing how many passengers are in the current `Train` carriage, `seat_count_` representing the number of seats in the current `Train` carriage, and `next_carriage_` representing the next `Train` carriage, if there is one.

You are tasked with defining the recursive functions.
1. Define the recursive member function `TotalTrainPassengers`, which accepts no input, and returns an `int` representing the total number of passengers in the entire train (i.e. all the passengers in the current train carriage plus all the passengers in the remaining carriages).
2. Define the recursive member function `MaxCarriagePassengers`, which accepts no input, and returns an `int` representing the maximum number of passengers in a single carriage that is part of this train.
3. Define the recursive member function `IsTrainFull`, which accepts no input, and returns a `bool`. `IsTrainFull` should return `true` if every carriage on this train is full, i.e. the passenger count is equal to the seat count on every carriage - in other words, every seat is occupied by a passenger. If there is an available seat anywhere in the train, `IsTrainFull` should return `false`.
4. Define the recursive member function `AddCarriageToEnd`, which accepts a `std::shared_ptr<Train>` as input. This function adds the given `Train` to the very end of the train. Hint: what base case checks if the current `Train` is the last carriage in the train?

In main.cc, you will be asked to invoke each recursive function for a line of train carriages we've provided for you.

After running main, your output should be:
```
Total passengers in the train: 641
Max passengers in a carriage: 250
The train is full.
Adding a new carriage to the train!
The train now has available seats.
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
clang++ -std=c++17 main.cc train.cc -o main
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
