#include "romano.hpp"

int converteRomano(std::string numeroRomano) {
    int numeroDecimal = 0;
    for (const char c: numeroRomano) {
        if (c == 'I') {
            numeroDecimal++;
        }
        if (c == 'V') {
            numeroDecimal+=5;
        }
        if (c == 'X') {
            numeroDecimal+=10;
        }
        if (c == 'L') {
            numeroDecimal+=50;
        }
        if (c == 'C') {
            numeroDecimal+=100;
        }
        if (c == 'D') {
            numeroDecimal+=500;
        }
        if (c == 'M') {
            numeroDecimal+=1000;
        }
    }
    return numeroDecimal;
}

