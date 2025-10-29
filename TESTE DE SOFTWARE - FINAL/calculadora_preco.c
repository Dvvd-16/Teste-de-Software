#include "calculadora_preco.h"

// Implementação da função que calcula o preço
float calcular_preco_por_idade(int idade) {
    if (idade <= 12) {
        return 10.0; // Criança
    } else if (idade >= 13 && idade <= 59) {
        return 30.0; // Adulto
    } else {
        return 15.0; // Idoso
    }
}
