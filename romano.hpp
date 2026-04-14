// Copyright 2026 Davi Lopes Brito

#ifndef ROMANO_HPP_
#define ROMANO_HPP_
#include <string>
#include <vector>

int converteRomano(const std::string& numeroRomano);
bool confereErros(const std::vector<int> &vetorConvertido);
int operaVetor(const std::vector<int> &vetorConvertido);
bool confereBase5(int numero);

#endif  // ROMANO_HPP_
