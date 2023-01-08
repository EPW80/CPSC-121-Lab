# Digicup
This program simulates interactions with a `Cup` object for getting a drink, refilling a drink, emptying a drink, and drinking from it.

## Output
All of the output statements (`std::cout`) should be in `main` and are mostly provided for you. 
You will only need to complete missing logic to construct a `Cup` object and call the appropriate member functions
in the `Cup` class.

The `Cup` object will be used to ask the user for the type of drink they prefer and the amount they want to drink. 

The menu options are shown below for your reference:

```
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
```

## The `Cup` class
### State (member variables)
Create a class called `Cup` with the following member variables:

1. `drink_type_` which is an `std::string` that will be the name of the drink.
1. `fluid_oz_` which is a `double` that will be the amount of fluid in the cup.

### Constructors
#### Default constructor
The default constructor should initialize `drink_type_` to `"Water"` and initialize `fluid_oz_` to `16.0`

#### Non-default constructor
The non-default constructor should take in an `std::string` parameter that will be the name of the drink type and a 
`double` parameter that will be the amount of drink in the cup in fluid ounces. It should set the passed parameter values
to the corresponding data members.

### Member functions
#### Drink
Create a function called `Drink` which accepts one `double` as a parameter.
Drinking reduces the amount of liquid in the `Cup` based on a given `double` that is passed as input. 
Take note that `fluid_oz_` should never be negative, so if you drink an amount that is greater than
`fluid_oz_`, then `fluid_oz_` should be set to `0`.

##### Refill
Create a function called `Refill` which accepts one `double` as a parameter.
Refilling the cup increases the amount of liquid in the `Cup` based on the given input. Assume the cup is bottomless.

##### NewDrink
Create a function called `NewDrink` which accepts two parameters. The first is the name of the new drink type
and the second is the amount of the new drink type.
`NewDrink` should throw out your current drink and replace it with a new drink. Make sure to replace the 
value of the member variables in this function.

##### Empty
*Empties out* the contents of the cup in its entirety. `fluid_oz_` should be set to 0, and `_drink_type` should be set to `"nothing"`.

##### Accessors
Create the accessor for `fluid_oz_`, and name it `GetFluidOz`.
Create the accessor for `drink_type_`, and name it `GetDrinkType`. 

## Other information
Declare the `Cup` class in `cup.h`, implement the member functions in `cup.cc`, and complete the code in `main.cc`.

## Sample Output
<pre>
What kind of drink can I get you?: <b>Kool Aid</b>
How much do you want?: <b>32</b>
Your cup currently has 32 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>16</b>
Your cup currently has 16 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>6</b>
Your cup currently has 10 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>R</b>
How much do you want to refill your cup?: <b>2</b>
Your cup currently has 12 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>E</b>
Emptying your cup
Your cup currently has 0 oz. of nothing
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>N</b>
What is the new drink you want?: <b>Coke</b>
What is the amount you want?: <b>16</b>
Your cup currently has 16 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>8</b>
Your cup currently has 8 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>X</b>
Thank you for using Digicup!
</pre>

## Code Evaluation

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `cup.cc` and `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc cup.cc -o main
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

