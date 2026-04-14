#include <gtest/gtest.h>
#include "romano.hpp"
    TEST(RomanoTest, ConvertI) {
        EXPECT_EQ(converteRomano("I"),1);
    }

    TEST(RomanoTest, Convert2Char) {
        EXPECT_EQ(converteRomano("II"),2);
    }

    TEST(RomanoTest, ConvertCharDiferentesDeI) {
        EXPECT_EQ(converteRomano("V"),5);
        EXPECT_EQ(converteRomano("X"),10);
        EXPECT_EQ(converteRomano("L"),50);
        EXPECT_EQ(converteRomano("C"),100);
        EXPECT_EQ(converteRomano("D"),500);
        EXPECT_EQ(converteRomano("M"),1000);
    }

    TEST(RomanoTest, 3char) {
        EXPECT_EQ(converteRomano("III"),3);
        EXPECT_EQ(converteRomano("VVV"),15);
        EXPECT_EQ(converteRomano("XXX"),30);
        EXPECT_EQ(converteRomano("LLL"),150);
        EXPECT_EQ(converteRomano("CCC"),300);
        EXPECT_EQ(converteRomano("DDD"),1500);
        EXPECT_EQ(converteRomano("MMM"),3000);
    }

