#include <iostream> // preprocessing directive

int main() // begin main function
{
    int credit_score;                                                                                                               // variable declaration
    std::cout << "Thank you for applying for the Tuffy Credit card. Please enter your credit score: " << std::endl; // print to user
    std::cin >> credit_score;                                                                                                       // take user input
    if (credit_score < 0 || credit_score > 850)                                                                                    // if credit score is less than or equal to 0 or greater than 850
    {
        // print to user
        std::cout << "That is an invalid credit score. Please run the program again and provide a valid credit score. " << std::endl;
    }
    else if (credit_score >= 0 && credit_score <= 579) // or if credit score is equal to 0 or less than or equal to 579
    {
        // print to user
        std::cout << "Unfortunately, you are ineligible for Tuffy credit cards at the moment. " << std::endl;
        std::cout << "Please try again at a later date. " << std::endl;
    }
    else if (credit_score >= 580 && credit_score <= 669) // or if credit score is greater than or equal to 580 or less than or equal to 669
    {
        // print to user
        std::cout << "You are eligible for the Silver Tuffy Card. " << std::endl;
        std::cout << "Thank you for using our program, please come again! " << std::endl;
    }
    else if (credit_score >= 670 && credit_score <= 799) // or if credit score is greater than or equal to 670 or less than or equal to 799
    {
        // print to user
        std::cout << "You are eligible for the Gold Tuffy Card. " << std::endl;
        std::cout << "Thank you for using our program, please come again! " << std::endl;
    }
    else if (credit_score >= 800 || credit_score <= 850) // or if credit score is greater than or equal to 800 or less than or equal to 850
    {
        // print to user
        std::cout << "You are eligible for the Platinum Tuffy Card. " << std::endl;
        std::cout << "Thank you for using our program, please come again! " << std::endl;
    }

    return 0;
    // end of main function
}
