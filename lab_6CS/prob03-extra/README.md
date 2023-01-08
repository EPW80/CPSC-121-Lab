# Extra Problem
This lab exercise is optional and is not graded. Use this exercise for additional practice working with classes.

# Player
Create a `Player` class with the following data members to represent a game character: 
`xpos_` that is an `int` representing their x position, 
`ypos_` that is an `int` representing their y position, 
`name_` that is a `std::string` representing the player's name, 
and `health_`, `strength_`, and `defense_` which are all of type `int` representing the character's attributes.

### Default Constructor
Create a default constructor that initializes the following values to your data members:
`0` for the x position, `0` for the y position, `Ash` for the name, `10` for the health, `5` for the strength and `2` for the defense.

### Non-Default Constructor
Create a non-default constructor that takes in 6 values in this order: the name, the health, the strength, the defense, the x position, and the y position respectively. These should be used to initialize the corresponding data members.

### Accessors & Mutators
Create accessors and mutators for all data members. Follow the format `Get` or `Set` followed by the name of the variable in upper camel case.
For example, `GetXpos`, `SetXpos`, `GetYpos`, `SetYpos`, `GetStrength`, `GetDefense`, etc.

### Member functions

#### DisplayStat
Create a member function called `DisplayStat` that takes in no parameters and does not return anything. This member function should display the name of the player, the player's health, the player's strength, the player's defense, and the player's coordinates (x and y position). Look at the output provided below for an example.

#### PlayerMove
Create a member function called `PlayerMove` that takes in no parameters and does not return anything. This member function should increment the x position and the y position by a value of 1.

#### IsPlayerDead
Create a member function called `IsPlayerDead` that takes in no parameters and returns a `bool` value. This member function should check the player's health. If the player's health is equal to 0, then return `true`, otherwise return `false`.

#### TakeDamage
Create a member function called `TakeDamage` that takes in an `int` value for the damage taken and returns nothing. This member function should display a statement saying that the player took damage, and decrease the player's health based on the damage taken.

If the damage taken is greater than the player's current health, set the player's health to 0 (the player cannot have negative health). This member function should  call the `IsPlayerDead` function to check whether the player survives the attack. If the player is dead, display a statement saying that the player is dead. Look at the output provided below for an example.

## Other instructions
Place the `Player` class inside `player.h` and implementatiion in `player.cc`.

The `main` function is already provided for you. Do not edit the `main.cc` file.

## Sample output
```
Player: Ash
Health: 10
Strength: 5
Defense: 2
At position: (10, 10)

Player: Les
Health: 20
Strength: 10
Defense: 6
At position: (0, 0)

Ash took 25 damage
Ash is dead

Player: Ash
Health: 0
Strength: 5
Defense: 2
At position: (10, 10)
```

## Code Evaluation

Use the `make build` command to compile your code and save it into an executable file called `main`.
Then you can use the `./` command to run it. Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
make build
./main
```

Alternatively, you can use the `clang++` command to compile your code and the `./` command to run it. 
The sample code below shows how you would compile code in `player.cc` and `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc player.cc -o main
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

