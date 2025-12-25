#include <stdio.h>
#include "minunit.h"             // Inclui a biblioteca de teste
#include "calculadora_preco.h"   // Inclui nossa função a ser testada

int tests_run = 0;


// --- NOSSOS TESTES ---

// MUDANÇA 1: As funções de teste agora retornam 'void' em vez de 'char*'
static void test_preco_crianca() {
    mu_assert("Erro: preco para crianca (10 anos) deveria ser 10.0", calcular_preco_por_idade(10) == 10.0);
    // MUDANÇA 2: O 'return 0;' foi REMOVIDO daqui.
}

static void test_preco_adulto() {
    mu_assert("Erro: preco para adulto (30 anos) deveria ser 30.0", calcular_preco_por_idade(30) == 30.0);
}

static void test_preco_idoso() {
    mu_assert("Erro: preco para idoso (70 anos) deveria ser 15.0", calcular_preco_por_idade(70) == 15.0);
}

// --- FIM DOS TESTES ---

static void all_tests() {
    printf("-> Executando teste: 'test_preco_crianca'... ");
    test_preco_crianca();
    // A mensagem de OK só aparece se o teste não falhar,
    // pois a falha interrompe a função.
    printf("OK\n");
    tests_run++;

    printf("-> Executando teste: 'test_preco_adulto'... ");
    test_preco_adulto();
    printf("OK\n");
    tests_run++;

    printf("-> Executando teste: 'test_preco_idoso'... ");
    test_preco_idoso();
    printf("OK\n");
    tests_run++;
}

// MUDANÇA 4: A função main foi ajustada para este modelo do minunit
int main(int argc, char **argv) {
    printf("--- INICIANDO TESTES ---\n");
    all_tests(); // Apenas chama a função que roda os testes

    if (minunit_status == 0) {
        printf("\nTODOS OS TESTES PASSARAM\n");
    } else {
        // A mensagem de erro já é impressa pela macro mu_assert nesta versão
        printf("\nUM OU MAIS TESTES FALHARAM\n");
    }
    printf("Testes executados: %d\n", tests_run);

    return minunit_status;
}
