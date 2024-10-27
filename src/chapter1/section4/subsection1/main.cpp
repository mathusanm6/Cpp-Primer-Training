#include <iostream>

void consecutive_sum(int a, int b)
{
    if (b < a) {
        std::cout << b << " smaller than " << a << std::endl;
        return;
    }

    int sum = 0, val = a;

    // keep executing the while as long as val is less than or equal to b
    while (val <= b)
    {
        sum += val;
        ++val;
    }

    std::cout << "Sum of " << a << " to " << b << " inclusive is "
              << sum << std::endl;
}

void consecutive_print_desc(int r, int l)
{
    if (r < l) {
        std::cout << r << " smaller than " << l << std::endl;
        return;
    }
    
    int val = r;

    std::cout << "Listing the numbers from " << r << " to " << l
              << " in descending order :" << std::endl;
    // keep executing the while as long as val is larger or equal to l
    while (val > l)
    {
        std::cout << val << " -> ";
        --val;
    }

    std::cout << val << std::endl;
}

void consecutive_print(int l, int r)
{
    if (r < l) {
        std::cout << r << " smaller than " << l << std::endl;
        return;
    }

    int val = l;

    std::cout << "Listing the numbers from " << l << " to " << r
              << " in order :" << std::endl;
    // keep executing the while as long as val is larger or equal to l
    while (val < r)
    {
        std::cout << val << ", ";
        ++val;
    }

    std::cout << val << std::endl;
}

int main()
{
    consecutive_sum(1, 10);
    std::cout << std::endl;

    consecutive_sum(50, 100);
    std::cout << std::endl;

    consecutive_print_desc(10, 0);
    std::cout << std::endl;

    std::cout << "Enter two numbers : " << std::endl;

    int l = 0, r = 0;
    std::cin >> l >> r;

    consecutive_print(l, r);

    return 0;
}