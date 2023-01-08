# Optional Inheritance Practice
This problem is ungraded and not mandatory. Please use this as an opportunity to practice applying inheritance.

This program uses three classes: `Utensil`, `Spoon`, and `Food`.

## Food class
Create a `Food` class with two member variables, an `std::string` `name_` and `double` `mass_` (in grams).

Create a default constructor for `Food` that sets the name to ``"Apple Pie"`` and mass to `1000`.

Create a constructor that receives an `std::string` name and `double` mass.

Create accessor and mutator functions for both member variables, `name_` and `mass_`, `Name`, `SetName`, `Mass`, and `SetMass`.

Create a function `Eat` that receives a `double` and subtracts it from `mass_` if there is enough left. Otherwise, set the mass to 0 (can't have a negative mass of an object).

Create a function `Print` that prints the food's name and mass.

## Utensil class
Create a `Utensil` class with two member variables: `double` `size_`, and `std::string` `color_`.

Create a default constructor for `Utensil` that sets the size to `8.5` and its color to `"silver"`.

Create a constructor that receives a `double` size and `std::string` color that sets `size_` and `color_` accordingly.

Create accessor and mutator functions for both member variables,  `Size`, `SetSize`, `Color` and `SetColor`.

Create a function `Use` that receives a reference to a `Food` object, but does nothing to it (i.e., the member function's body is empty).

## Spoon class
`Spoon` inherits from `Utensil` and has an additional member variable, a `double` `bite_size_`.

Create a default constructor for `Spoon` that sets the size to 6, color to silver and `bite_size_` to 25.

Create a nondefault constructor that receives a `double` size, a `std::string` color, and a `double` bite_size then assigns the values to the member variables accordingly.

Create an accessor and mutator function for the member variable `bite_size_`, `BiteSize` and `SetBiteSize`.

Create a function `Use` that receives a reference to a `Food` object and removes *`bite_size_` grams* of mass from the object (i.e., eating the food). You will need to call that object's `Eat` member function and provide the appropriate arguments.

## Other instructions
Complete the `main` function as described. Place your member function declarations in `utensils.h`, and implement them in `utensils.cc`.

## Sample Output:
```
Please enter the name of a food item: Pumpkin Pie
Please enter the mass of the food item: 1250
Please enter the size of the spoon: 5
Please enter the color of the spoon: gold
Please enter your bite size using the spoon: 20
Food before being eaten:
Pumpkin Pie 1250g
Food after spoon used:
Pumpkin Pie 1230g
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
The sample code below shows how you would compile code in `star.cc` and `main.cc` and into the executable file `main`. 

```
clang++ -std=c++17 main.cc utensils.cc -o main
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
