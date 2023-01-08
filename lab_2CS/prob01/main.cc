#include <iostream> // preprocessing directive

// begin main function
int main()
{
  int height; // initialize variable as int type
  std::cout << "You must be as least 55 inches to safely ride the TuffyTwister. "
            << "\n";                                   // print to user
  std::cout << "Please enter your height in inches: "; // output to user
  std::cin >> height;                                  // take input
  if (height < 55)
  { // if user is less than 55 inches deny entry
    std::cout << "Safety is our first priority. Unfortunately, we can't let you ride yet. "
              << "\n";
  }
  else
  { // otherwise allow user to ride
    std::cout << "Congratulations! You are tall enough to ride! "
              << "\n";
  }

  return 0;
  // end of main function
}
