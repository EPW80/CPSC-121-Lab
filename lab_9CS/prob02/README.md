# Pets
## Breed Class
Create a `Breed` class with the following:

### Member Variables
Create the following private member variables, all of type `std::string`: 
1. `species_`
2. `breed_name_`
3. `color_`

### Constructors
1. Create a default constructor for `Breed` that sets its `species_` to `"Dog"`, `breed_name_` to `"Chihuahua"`, and `color_` to `"Fawn"`.
2. Create a non-default constructor that receives a `std::string` for `species_`, `breed_name_`, and `color_`; in that order. The values from the constructor should appropriately assign the member variables.

### Accessors and Mutators
Create accessors and mutators for all member variables, following the naming conventions covered in class. e.g. for species_, name the accessor `Species`, and the mutator `SetSpecies`.

## Pet Class
Create a `Pet` class with the following:

### Member Variables
Create the following private member variables:
1. `std::string name_`
2. `Breed breed_` 
3. `double weight_`

### Constructors
1. Create a default constructor for `Pet` that sets its name to `"Cookie"` and weight to `15.6`. The `Breed` object will automatically be created using its default constructor.
2. Create a non-default constructor that receives a `std::string` for `name_`, `Breed` for `breed_`, and a `double` for `weight_` in that order. The values from the constructor should appropriately assign the member variables.
3. Create another non-default constructor that receives a `std::string` for Pet's name stored in `name_`, `std::string` for the `Breed` species, `std::string` for the `Breed` name, and `std::string` for the `Breed` color, and `double` for `weight_`. The values accepted for the `Breed` species, `Breed` name, and `Breed` color should all be passed into the `Breed` constructor to create an object to assign to the `breed_` member variable (hint: you can initialize an object member variable within a member initializer list by invoking its constructor, see [this slide](https://docs.google.com/presentation/d/1zIAC4kj9FZ2GVZN2aMCJYm8qK_GFIKwfg55bW6b_s2M/edit#slide=id.g1636e2659d3_0_117)). The other values from the constructor should appropriately assign the member variables.

### Accessors and Mutators
Create accessors and mutators for `name_`, `breed_`, and `weight_`. Please name the accessor for `breed_` as `GetBreed`, to avoid conflicting with the constructor for the `Breed` class.

### SetBreed overload
Create a function overload for `SetBreed` that accepts a `species`, `breed_name`, and `color`, all of type `std::string`, that will internally create a `Breed` object using the values provided and then assign it to the `breed_` member variable.

### Print
Create a member function called `Print` that returns `void` and does not take in any parameters. Using the member variables, this function should print out the name and weight of the `Pet`. It should also utilize accessors of the `Breed` class to get the species, breed name, and color. 

## Other instructions
Complete the `main` function as described. Place the `Pet` class in `pet.h`, and the `Breed` class in `breed.h`. Member functions that take more than ten lines or use complex constructs should have their function prototype in the respective `.h` header file and implementation in the respective `.cc` implementation file.

## Sample Output:
```
Please enter the pet's name (q to quit): Bitzy
Please enter the pet's type: Dog
Please enter the pet's breed: Chihuahua
Please enter the pet's color: Tan
Please enter the pet's weight (lbs): 11.5
Please enter the pet's name (q to quit): Cookie
Please enter the pet's type: Dog
Please enter the pet's breed: Long Chihuahua
Please enter the pet's color: Brown & White
Please enter the pet's weight (lbs): 6.2
Please enter the pet's name (q to quit): q
Printing Pets:
Pet 1
Name: Bitzy
Species: Dog
Breed: Chihuahua
Color: Tan
Weight: 11.5 lbs
Pet 2
Name: Cookie
Species: Dog
Breed: Long Chihuahua
Color: Brown & White
Weight: 6.2 lbs
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
The sample code below shows how you would compile code in `pet.cc` and `main.cc` and into the executable file `main`. 

```
clang++ -std=c++17 main.cc pet.cc -o main
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
