#include <iostream>
#include "Sales_item.h"

Sales_item init_new_item()
{
    Sales_item book;

    // read ISBN, number of copies sold, and sales price
    std::cin >> book;

    // write ISBN, number of copies sold, total revenue, and average
    std::cout << book << std::endl;

    return book;
}

Sales_item add_two_items()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2; // read a pair of transactions
    Sales_item item_res = item1 + item2;
    std::cout << item_res << std::endl; // print their sum
    return item_res;
}

void read_and_output()
{
    Sales_item item;
    while (std::cin >> item)
    {
        std::cout << item << std::endl;
    }
}

Sales_item read_and_add_two_items()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2; // read a pair of transactions

    if (item1.isbn() != item2.isbn())
    {
        std::cerr << "Error: ISBNs do not match." << std::endl;
        return Sales_item(); // return a default Sales_item in case of error
    }

    Sales_item item_res = item1 + item2;
    std::cout << item_res << std::endl; // print their sum
    return item_res;
}

void read_and_add_same_isbn()
{
    Sales_item prev, curr, sum;
    if (std::cin >> prev)
    {
        sum = prev;
        while (std::cin >> curr)
        {
            if (prev.isbn() == curr.isbn())
            {
                sum += curr;
            }
            else
            {
                prev = curr;
                std::cout << sum << std::endl;
                sum = prev;
            }
        }
        std::cout << sum << std::endl;
    }
}

void read_and_count_same_isbn()
{
    Sales_item prev, curr;
    int count = 0;
    if (
        std::cin >> prev)
    {
        count = 1;
        while (std::cin >> curr)
        {
            if (prev.isbn() == curr.isbn())
            {
                ++count;
            }
            else
            {
                std::cout << "ISBN: " << prev.isbn() << " has " << count << " transactions." << std::endl;
                prev = curr;
                count = 1;
            }
        }
        std::cout << "ISBN: " << prev.isbn() << " has " << count << " transactions." << std::endl;
    }
}

int main()
{
    read_and_count_same_isbn();
    return 0;
}