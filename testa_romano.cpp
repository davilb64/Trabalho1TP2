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

    TEST(RomanoTest, Convert3Char) {
        EXPECT_EQ(converteRomano("III"),3);
        EXPECT_EQ(converteRomano("VVV"),15);
        EXPECT_EQ(converteRomano("XXX"),30);
        EXPECT_EQ(converteRomano("LLL"),150);
        EXPECT_EQ(converteRomano("CCC"),300);
        EXPECT_EQ(converteRomano("DDD"),1500);
        EXPECT_EQ(converteRomano("MMM"),3000);
    }

    TEST(RomanoTest, ConvertSubs) {
        EXPECT_EQ(converteRomano("IV"),4);
        EXPECT_EQ(converteRomano("IX"),9);
        EXPECT_EQ(converteRomano("XLIX"),49);
        EXPECT_EQ(converteRomano("CDXCIX"),499);
        EXPECT_EQ(converteRomano("CMXCIX"),999);
    }

    TEST(RomanoTest, FalhasIniciais) {
        EXPECT_EQ(converteRomano("IIII"),-1);
        EXPECT_EQ(converteRomano("VVVV"),-1);
        EXPECT_EQ(converteRomano("IIIX"),-1);
        EXPECT_EQ(converteRomano("XXXX"),-1);
        EXPECT_EQ(converteRomano("MMMM"),-1);
    }

