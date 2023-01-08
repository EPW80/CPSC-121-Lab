# Double Bubble
For this exercise you need to create a `Bubble` class and construct two instances of the `Bubble` object. You will then take the two `Bubble` objects and combine them to create a new, larger combined `Bubble` object. This will be done using functions that take in these `Bubble` objects as parameters.

The `Bubble` class contains one data member, `radius_`, and the corresponding accessor and mutator methods for `radius_`, ``GetRadius`` and ``SetRadius``. Create a member function called `CalculateVolume` that computes for the [volume of a bubble (sphere)](https://en.wikipedia.org/wiki/Sphere#Enclosed_volume). Use the value 3.1415 for `PI`.

Your `main` function has some skeleton code that asks the user for the radius of two bubbles. You will use this to create the two `Bubble` objects. You will create a `CombineBubbles` function that receives two **references** (two `Bubble` objects) and returns a `Bubble` object. Combining bubbles simply means creating a new `Bubble` object whose radius is the sum of the two `Bubble` objects' radii. Take note that the `CombineBubbles function is not part  of the `Bubble` class.

Place the `Bubble` class and the `CombineBubbles` function declaration in `bubble.h`. Implement `CombineBubbles` in `bubble.cc`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.

Please see the sample output below to guide the design of your program.

## Sample Output
```
Please enter the radius of the first bubble: 4.5
Please enter the radius of the second bubble: 2.3
The bubbles have now combined and created a bubble with the volume of: 1317.05
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
The sample code below shows how you would compile code in `bubble.cc` and `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc bubble.cc -o main
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
