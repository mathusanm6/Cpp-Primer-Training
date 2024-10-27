#include <iostream>

void sum()
{
    int sum = 0, value = 0;

    // read until end-of-file, calculating a running total of all values read
    while (std::cin >> value)
    {
        sum += value; // equivalent to sum = sum + value
    }

    // BEGIN (A)
    if (std::cin.fail() && !std::cin.eof())
    {
        // clear the error flag and resets std::cin to a good state (without this subsequent reads would fail)
        std::cin.clear();
        // ignore the invalid input by removing it from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input ignored. \n";
    }
    // END (A)

    std::cout << "Sum is: " << sum << std::endl;
}

int main()
{
    sum();

    // Uncomment this line after commenting (A) Block
    // Giving an invalid input on the first sum might cause issues!
    // sum();
    
    // return 0
} // implicitly returns 0 (assumption from the compiler)