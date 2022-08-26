#include <iostream>
#include "../include/LE_system.hpp"


int main()
{
    if (is_LE_system())
        std::cout << "CPU is a little endian" << std::endl;
    else
        std::cout << "CPU is a big endian" << std::endl;

    uint32_t hex_number = 0x61626364;
    std::cout << std::hex;
    std::cout << "hex number is " << hex_number << std::endl;

    swap_LE_BE_by_pointer(hex_number);
    std::cout << "hex number is " << hex_number << std::endl;

    swap_LE_BE_by_bitwise(hex_number);
    std::cout << "hex number is " << hex_number << std::endl;

    return 0;
}