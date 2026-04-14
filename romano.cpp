#include "romano.hpp"

int converteRomano(std::string numeroRomano) {
    int numeroDecimal = 0;
    for (const char c: numeroRomano) {
        if (c == 'I') {
            numeroDecimal++;
        }
    }
    return numeroDecimal;
}

