#include <iostream>

void consecutive_sum(int a, int b)
{
    int sum = 0;

    // sum values from a through b inclusive
    for (int val = a; val <= b; ++val)
    {
        sum += val; // equivalent to sum = sum + val
    }

    std::cout << "Sum of " << a << " to " << b << " inclusive is "
              << sum << std::endl;
}

int main()
{
    consecutive_sum(1, 10);
    return 0;
}
