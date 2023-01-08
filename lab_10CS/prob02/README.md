# Text Messages in a Social Network
For this exercise you will create a `Network` class that represents a network of `Phone`s that can send text messages (`Message` objects) to each other. 

We've provided the `Message` class for you already. A `Message` represents a text message with an associated sender.

## Phone Class
The `Phone` class represents a person's mobile phone, and contains all the messages that have been sent to that person. Create a `Phone` class with the following:

### Member Variables
Create the following private member variables:
1. `owner_` - a string representing the owner of this phone.
2. `messages_` - a vector of `std::shared_ptr<Message>`, representing all the messages that have been sent to this phone.

### Constructor
1. Create a non-default constructor that receives a `std::string` for `owner_`.

### Accessor
Create an accessor for the `owner_` called `GetOwner`. Remember to mark this function as `const`, to indicate that just getting the name of this phone's owner will not make any modification to this phone's state.

### AuthorMessage
Create a member function `AuthorMessage`, which accepts a `const` reference to a string, and returns a `std::shared_ptr<Message>`. This function creates a `Message` object whose message is set to the input string, and whose sender is set to the name of this phone's owner.

### AcceptMessage
Create a member function `AcceptMessage`, which accepts a `std::shared_ptr<Message>` and adds that message to the **end** of the `messages_` vector.

### PrintMessages
Create a member function called `PrintMessages` that returns `void` and does not take in any parameters. This function should iterate through all the messages sent to this phone, and print each message on a new line, in the format `"sender: message"`

## Network Class
The `Network` class represents a network of people that are connected to each other and are able to contact and send messages to each other through the network. Create a `Network` class with the following:

### Member Variables
A Network has just one private member variable:
1. `phonebook_` - a `std::map` which maps from a `std::string` for a person's name, to the `std::shared_ptr<Phone>` object that belongs to that person.

### Constructor
You do not need to explicitly define a constructor. The default constructor will implicitly be created for us by the compiler, initializing the `phonebook_` to an empty map.

### AddPhone
Create a function `AddPhone` that accepts a `std::shared_ptr` to a `Phone` and inserts that `Phone` to the `phonebook_`. The key is the name of that phone's owner, and the value is the shared pointer to the `Phone`.

### SendMessage
Create a function `SendMessage` that accepts a `std::shared_ptr` to a `Message` and a `const` reference to a `std::string` representing the intended recipient of this message. **You must check** if the intended recipient is in the `phonebook_`, because if an invalid recipient is provided, no message should be sent over the network. If the recipient exists in the `phonebook_`, then use the `Phone::AcceptMessage` function to send that message to the recipient's phone.

### SendMessage Overload
Create a function `SendMessage` that accepts a `std::shared_ptr` to a `Message` and a `const` reference to a vector of `std::string` representing a list of recipients in the network to send the given message to. Like above, **you must check** if the intended recipient is in the `phonebook_` before sending the message to that recipient's phone.

## Other instructions
Complete the `main` function as described. Place the `Network` class in `network.h`, and the `Phone` class in `phone.h`. Member functions that take more than ten lines or use complex constructs should have their function prototype in the respective `.h` header file and implementation in the respective `cc` implementation file.

## Sample Output:
```
Printing messages sent to Anna:
Raf: Lol
JC: Hi class!

Printing messages sent to Raf:
Anna: Sup
JC: Hi class!

Printing messages sent to JC:
Anna: Hi Prof!
Raf: help how do C++

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
The sample code below shows how you would compile code in `phone.cc`, `network.cc`, and `main.cc` and into the executable file `main`. 

```
clang++ -std=c++17 main.cc phone.cc network.cc -o main
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
