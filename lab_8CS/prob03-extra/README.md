# Extra Problem
This lab exercise is optional and is not graded. Use this exercise for additional practice working with classes and objects.

# Dice rolling

Create a game that lets the user roll three six-sided dice to try to get a Yahtzee, that is, a three-of-a-kind. (Rolling five dice, like the real game, will take too long!)

Here's an example of how the game will be played (from ``./main``):

```
Do you want to roll? y/n y
2 5 4     
Do you want to roll again? y
2 6 2
Do you want to roll again? y
5 5 5
Yahtzee!
Do you want to roll again? n
Goodbye!
```

## Create the ``Dice`` class

The ``Dice`` class should have two public functions, a void function ``Roll()`` and an integer function ``GetValue()``. It needs one member variable to store the current value.

When the ``Roll`` function is called, the current value should be updated using the ``rand()`` function found in ``<stdlib.h>`` [reference](http://www.cplusplus.com/reference/cstdlib/rand/). ``rand()`` returns a very large integer, so you will need to convert it to a number between 1 and 6 (inclusive).

Reference [functions review](https://github.com/ILXL-guides/function-file-organization) if you are wondering what to put in ``dice.h`` and ``dice.cc``.

## Create the ``PlayYahtzee`` function

``PlayYahtzee`` should create three dice. It may make sense to store these in a ``std::vector``.

Place the function declaration in ``dice.h`` and the definition in ``dice.cc``.

While the user hasn't entered "n", you should re-roll all three dice, print out their values (separated by a space), and then check if they are a Yahtzee (if they are all three the same value). See the sample input/output above for the expected syntax. When they are a Yahtzee, print out "Yahtzee!". Then ask the user if they want to roll again.

## Try your program

Compile with:

```
clang++ -std=c++17 main.cc dice.cc -o main
```

Try running main to play the game!

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.