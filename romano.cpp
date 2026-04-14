// Copyright 2026 Davi Lopes Brito

#include "./romano.hpp"
#include <vector>

int converteRomano(const std::string& numeroRomano) {
    std::vector<int> vetorConvertido;
    for (const char c : numeroRomano) {
        switch (c) {
            case 'I':
                vetorConvertido.push_back(1);
                break;
            case 'V':
                vetorConvertido.push_back(5);
                break;
            case 'X':
                vetorConvertido.push_back(10);
                break;
            case 'L':
                vetorConvertido.push_back(50);
                break;
            case 'C':
                vetorConvertido.push_back(100);
                break;
            case 'D':
                vetorConvertido.push_back(500);
                break;
            case 'M':
                vetorConvertido.push_back(1000);
                break;
            default:
                return -1;
        }
    }
    if (confereErros(vetorConvertido)) {
        return operaVetor(vetorConvertido);
    }
    return -1;
}

bool confereErros(const std::vector<int> &vetorConvertido) {
    int contadorV = 0;
    int contadorL = 0;
    int contadorD = 0;

    for (size_t i = 0; i < vetorConvertido.size(); i++) {
        if (i + 3 < vetorConvertido.size()
            && vetorConvertido[i] == vetorConvertido[i + 1]
            && vetorConvertido[i] == vetorConvertido[i + 2]
            && vetorConvertido[i] == vetorConvertido[i + 3]) {
            return false;
            }

        if (vetorConvertido[i] == 5) contadorV++;
        else if (vetorConvertido[i] == 50) contadorL++;
        else if (vetorConvertido[i] == 500) contadorD++;

        if (contadorV > 1 || contadorL > 1 || contadorD > 1) {
            return false;
        }

        // 1 não subtrai de >= 50
        if (i + 1 < vetorConvertido.size()
            && vetorConvertido[i] == 1
            && (vetorConvertido[i + 1] == 50
                || vetorConvertido[i + 1] == 100
                || vetorConvertido[i + 1] == 500
                || vetorConvertido[i + 1] == 1000)) {
            return false;
                }

        // 5, 50, 500 não subtraem
        if (i + 1 < vetorConvertido.size()
            && confereBase5(vetorConvertido[i])
            && vetorConvertido[i + 1] > vetorConvertido[i]) {
            return false;
            }

        //trata mais de uma subtracao
        if (i + 1 < vetorConvertido.size()
            && vetorConvertido[i + 2] > vetorConvertido[i]
            && vetorConvertido[i] == vetorConvertido[i + 1]) {
            return false;
        }
    }
    return true;
}

bool confereBase5(const int numero) {
    if (numero == 5 || numero == 50 || numero == 500) {
        return true;
    }
    return false;
}

int operaVetor(const std::vector<int> &vetorConvertido) {
    int numeroDecimal = 0;
    for (size_t i = 0; i < vetorConvertido.size(); i++) {
        if (i + 1 < vetorConvertido.size()
            && vetorConvertido[i] < vetorConvertido[i + 1]) {
            numeroDecimal -= vetorConvertido[i];
        } else {
            numeroDecimal += vetorConvertido[i];
        }
    }
    return numeroDecimal;
}
