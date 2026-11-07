#include <iostream>
#include <limits>

void printBits(unsigned int number)
{
    for (int i = std::numeric_limits<unsigned int>::digits - 1; i >= 0; --i)
    {
        std::cout << ((number >> i) & 1);
    }
    std::cout << '\n';
}

bool isEven(unsigned int number)
{
    return (number & 1) == 0;
}

unsigned int clearBit(unsigned int number, int index)
{
    return number & ~(1u << index);
}

unsigned int setBit(unsigned int number, int index)
{
    return number | (1u << index);
}

unsigned int invertBit(unsigned int number, int index)
{
    return number ^ (1u << index);
}

int countSetBits(unsigned int number)
{
    int count = 0;
    while (number != 0)
    {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool isPowerOfTwo(unsigned int number)
{
    return number != 0 && (number & (number - 1)) == 0;
}

int lowestSetBitIndex(unsigned int number)
{
    if (number == 0)
    {
        return -1;
    }

    int index = 0;
    while ((number & 1) == 0)
    {
        number >>= 1;
        ++index;
    }
    return index;
}

unsigned int clearLowestSetBit(unsigned int number)
{
    return number & (number - 1);
}

int main()
{
    unsigned int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    std::cout << "Bits: ";
    printBits(number);

    if (isEven(number))
    {
        std::cout << "The number is even\n";
    }
    else
    {
        std::cout << "The number is odd\n";
    }

    int index;
    std::cout << "Enter bit index (0-" << std::numeric_limits<unsigned int>::digits - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < std::numeric_limits<unsigned int>::digits)
    {
        std::cout << "After clearing bit: " << clearBit(number, index) << '\n';
        std::cout << "After setting bit: " << setBit(number, index) << '\n';
        std::cout << "After inverting bit: " << invertBit(number, index) << '\n';
    }
    else
    {
        std::cout << "Invalid bit index\n";
    }

    int ones = countSetBits(number);
    std::cout << "Number of 1 bits: " << ones << '\n';
    std::cout << "Number of 0 bits: " << std::numeric_limits<unsigned int>::digits - ones << '\n';

    if (isPowerOfTwo(number))
    {
        std::cout << "The number is a power of two\n";
    }
    else
    {
        std::cout << "The number is not a power of two\n";
    }

    int lowestIndex = lowestSetBitIndex(number);
    if (lowestIndex == -1)
    {
        std::cout << "There is no set bit\n";
    }
    else
    {
        std::cout << "Lowest set bit index: " << lowestIndex << '\n';
    }

    std::cout << "After clearing the lowest set bit: " << clearLowestSetBit(number) << '\n';

    return 0;
}
