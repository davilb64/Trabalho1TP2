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
        EXPECT_EQ(converteRomano("XXX"),30);
        EXPECT_EQ(converteRomano("CCC"),300);
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
        EXPECT_EQ(confereErros({1,1,1,1}),false);
        EXPECT_EQ(confereErros({5,5,5,5}),false);
        EXPECT_EQ(confereErros({10,10,10,10}),false);
        EXPECT_EQ(confereErros({50,50,50,50}),false);
        EXPECT_EQ(confereErros({100,100,100,100}),false);
        EXPECT_EQ(confereErros({500,500,500,500}),false);
        EXPECT_EQ(confereErros({1000,1000,1000,1000}),false);
    }

    TEST(RomanoTest, FalhaBaseCincoNaoRepete) {
        EXPECT_EQ(converteRomano("VV"), -1);
        EXPECT_EQ(converteRomano("LL"), -1);
        EXPECT_EQ(converteRomano("DD"), -1);
        EXPECT_EQ(converteRomano("XVV"), -1);
    }

    TEST(RomanoTest, FalhaSubtracoesInvalidas) {
        // I não pode subtrair de L, C, D, M
        EXPECT_EQ(converteRomano("IL"), -1);
        EXPECT_EQ(converteRomano("IC"), -1);
        EXPECT_EQ(converteRomano("ID"), -1);
        EXPECT_EQ(converteRomano("IM"), -1);
        // V, L, D nunca subtraem
        EXPECT_EQ(converteRomano("VX"), -1);
        EXPECT_EQ(converteRomano("LC"), -1);
        EXPECT_EQ(converteRomano("DM"), -1);
    }