# Car Class Composition
Create a class called `Car` that will utilize other objects.

## Car

### Car member variables
Create two data members that are: (1) an instance of the `VehicleId` class called `id_` and (2) an instance of the `Date` class called `release_date_`.

*NOTE*: `VehicleId` and `Date` are classes that have been provided to you. You **DO NOT** need to create them.

### Default Constructor
The default constructor will be **EMPTY**, so you do not have to initialize anything. `VehicleId` and `Date`'s respective constructors will initialize their default values.

### Non-Default Constructors
1. Create a non-default constructor that takes in a `VehicleId` object. This will assign the parameter to the `id_` member variable.
2. Create a non-default constructor that takes in a `Date` object. This will assign the parameter to the `release_date_` member variable.
3. Create a non-default constructor that takes in a `VehicleId` and a `Date` object (in this order). This will assign the parameters to the `id_` and `release_date_` parameters correspondingly.

### Accessors and Mutators
Create accessors and mutators for `id_` and `release_date_`, following the naming conventions covered in class. e.g. for id_, name the accessor `Id`, and the mutator `SetId`.

### Other Member Functions
Create a `void` member function called `Print` that takes in no parameters. `Print` should print the model, vehicle id (VIN), license plate, and release date of the car. The release date should follow the format **mm/dd/yyyy**. See the output below as a reference.

## Other instructions
Complete the `main` function as described. Place your class in `car.h`. Member functions that take more than ten lines or use complex constructs should have their function prototype in `car.h` and implementation in `car.cc`.

Your program does not need to account for the correct dates or license plates. For example: 13/41/1 will be acceptable for your program, even though it is not an acceptable date, and "1111111111111111" will be acceptable in your program, even though it is not a valid license plate number.

## Sample output
```
The model of the car is: Tesla
The VIN of the car is: 121
The license plate of the car is: TUFFY121L
The release date of the car is: 1/1/2022

The model of the car is: Honda
The VIN of the car is: 3
The license plate of the car is: 7B319X4
The release date of the car is: 1/1/2022

The model of the car is: Ford
The VIN of the car is: 1
The license plate of the car is: 123456
The release date of the car is: 11/4/2018

The model of the car is: Honda
The VIN of the car is: 3
The license plate of the car is: 7B319X4
The release date of the car is: 11/4/2018

The model of the car is: Tesla
The VIN of the car is: 121
The license plate of the car is: TUFFY121L
The release date of the car is: 1/1/2022
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
The sample code below shows how you would compile code in `car.cc` and `main.cc` into the executable file `main`. 

```
clang++ -std=c++17 main.cc car.cc -o main
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
