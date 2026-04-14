#include "romano.hpp"

int converteRomano(std::string numeroRomano) {
    int numeroDecimal = 0;
    for (const char c: numeroRomano) {
        switch (c) {
            case 'I':
                numeroDecimal++;
                break;
            case 'V':
                numeroDecimal+=5;
                break;
            case 'X':
                numeroDecimal+=10;
                break;
            case 'L':
                numeroDecimal+=50;
                break;
            case 'C':
                numeroDecimal+=100;
                break;
            case 'D':
                numeroDecimal+=500;
                break;
            case 'M':
                numeroDecimal+=1000;
                break;
            default:
                return -1;
        }
    }
    return numeroDecimal;
}

