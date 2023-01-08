# Chirper: A lonely social network

Create a social network, Chirper, that lets the user add new Chirps and like existing Chirps. It's lonely because only one person can add and like messages -- so there's really not much "social" about it. At least you can practice using objects, references, and function overloading in C++!

Here's an example of how this program will run (from ``./main``):

```
You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? chirp
What's your message? This is my first chirp!
Chirper has 1 chirps:
1. This is my first chirp! (0 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? like
Which index do you want to like? 1
Chirper has 1 chirps:
1. This is my first chirp! (1 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? chirp
What's your message? Second chirp is the best chirp.
Chirper has 2 chirps:
1. This is my first chirp! (1 likes)
2. Second chirp is the best chirp (0 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? exit
Goodbye!
```

## Create the ``Chirp`` class

``Chirp`` objects need two member variables:
1. one to track the message, and
2. one to track the number of likes.

For the ``Chirp`` class constructors, use member initializer notation to initialize the member variables. You should define the following constructors:
1. A default constructor, which initializes the message to the empty string "", and initializes the number of likes to 0.
2. A non-default constructor, which accepts a message as input and initializes the message to that input.
3. A non-default constructor, which accepts a message as input and initializes the message to that input, and also accepts a like count as input, and initializes the like count to that.

The ``Chirp`` class should have the following member functions:
1. ``SetMessage`` which takes a ``std::string``,
2. ``GetMessage`` which returns a ``std::string``,
3. ``GetLikes`` which returns an integer,
4. ``AddLike`` which takes in no input increments the number of likes by 1, and
5. ``AddLike`` which takes in an integer input to increment the number of likes by. Notice that the function names are the same, but accept different parameters. This is the power of function overloading!


Put the ``Chirp`` function declarations in ``chirp.h`` and the ``Chirp`` function definitions in ``chirp.cc``. Reference [functions review](https://github.com/ILXL-guides/function-file-organization).

## Create ``main.cc``

``main.cc`` will implement the not-so-social network, Chirper. We've provided some input and output code, but haven't yet created any ``Chirp`` objects. You need to:

1. Create a ``std::vector`` into which you can store ``Chirp`` objects.

2. Create new ``Chirp`` objects when the user wants to add a new message.

3. Add likes to ``Chirp``s based on user input.

4. Complete the functionality to print the full list of chirps to the console. You should print the total number of chirps, and then you should have one line for each chirp, starting with the (1-based) index of the chirp, the message, and then the number of likes, for example:

```
Chirper has 2 chirps:
1. This is my first chirp! (1 likes)
2. 2021 can't come soon enough (3 likes)
```

*Notes: we aren't checking for grammar (1 chirps vs 1 chirp). You can assume that the user will not enter invalid input.*

Ensure you include ``chirp.h`` in ``main.cc`` so the compiler can find the function declarations.

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
The sample code below shows how you would compile code in `chirp.cc` and `main.cc`, and into the executable file `main`. 

```
clang++ -std=c++17 main.cc chirp.cc -o main
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
