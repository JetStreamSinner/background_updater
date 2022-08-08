#include "../source/bytes_array.h"
#include <iostream>
#include <gtest/gtest.h>


TEST(TEST, TESTTT) {
    BytesArray png_signature_mask = {137, 80, 78, 71, 13, 10, 26, 10};
    BytesArray jpeg_signature_mask = { 0xFF, 0xD8, 0xFF };
    std::cout << png_signature_mask << std::endl;
    std::cout << jpeg_signature_mask << std::endl;
}