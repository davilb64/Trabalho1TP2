#include <gtest/gtest.h>
#include "romano.hpp"
    TEST(RomanoTest, ConvertI) {
        EXPECT_EQ(converteRomano("I"),1);
    }

    TEST(RomanoTest, Convet2Char) {
        EXPECT_EQ(converteRomano("II"),2);
    }

