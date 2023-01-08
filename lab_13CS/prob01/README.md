# Stars

This lab exercise will practice creating objects with constructors and destructors and demonstrate when constructors and destructors are called.

## Star Class

Create a class, ``Star``. A `Star` object has two member variables: its name, and a [solar radius](https://en.wikipedia.org/wiki/Solar_radius). This class should have a constructor which takes a std::string, the name of the star, and a double, the solar radius of the star.

In the constructor, the ``Star`` class should print to the terminal that the star was born. For example, if you create a ``Star`` as follows:

```cpp
Star my_star("Saiph", 22.2);
```

Then the constructor should print:

```
The star Saiph was born.
```

In the destructor, the ``Star`` class should print to the terminal that the star was destroyed, along with the number of times the volume of the sun that that star was, formatted to two decimal places. Hint: use the following line to set the precision to 2 decimal places:
```cpp
std::cout << std::fixed << std::setprecision(2);
```
For example, when ``my_star`` above has its destructor called, we would see something like:

```
The star Saiph has gone supernova. It was 492.84 times the volume of our sun.
```

The ``Star`` class will need member variables to store the information passed in the constructor.

Additionally, the ``Star`` class needs a getter, ``GetName()``, to return the name string.

### Calculating volume

A [solar radius](https://en.wikipedia.org/wiki/Solar_radius) is the number of times bigger a star's radius is than our sun's radius. You can use it to determine the relative volume between a star and our sun:

The equation for volume of a sphere is ``4 / 3 * pi * r ^ 2``.

Since ``4 / 3 * pi`` is constant, and the solar radius ``r`` of the sun is by definition 1, you need only calculate the solar radius of your star squared.

So if the solar radius of the star is 2, the star is 2 * 2 = 4 times larger than the sun by volume.

## Main program

Your main program should ask the user for how many stars they want to create, and then for each of those stars it should ask for the star name and solar radius to create a ``Star`` object. After creation, your ``main`` program should print "Created star <name>" for the user's given star name.

For example:

```
How many stars? 2
Enter star 0's name: Mintaka
What is the solar radius? 16.5     
The star Mintaka was born  
Created star Mintaka
The star Mintaka has gone supernova. It was 272.25 times the volume of our sun.      
Enter star 1's name: Alnilam
What is the solar radius? 32.4     
The star Alnilam was born
Created star Alnilam
The star Alnilam has gone supernova. It was 1049.76 times the volume of our sun.
```

*Note: Because your ``Star`` objects are created within a loop, their destructors are automatically called at the end of each pass through the loop!*


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
clang++ -std=c++17 main.cc star.cc -o main
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
