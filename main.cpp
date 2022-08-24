#include <iostream>

bool is_LE_system()
{
    const uint32_t hex_number = 0x61626364;
    const uint8_t *ptr = (const uint8_t *)(&hex_number);
    
    // value of last byte from hex_number - 0x64 (hex number) equal to 'd' (char) symbol
    const char value_of_last_byte = 'd';

    return *ptr == value_of_last_byte;
}

int main()
{
    if (is_LE_system())
        std::cout << "CPU is a little endian" << std::endl;
    else
        std::cout << "CPU is a big endian" << std::endl;

    return 0;
}