/*Enunciado:Q2
CÁLCULO DINHEIRO PARA VIAGEM – Crie um programa para calcular várias informações financeiras
de um grupo de 4 amigos brasileiros que deseja viajar para um intercambio, o programa deverá
solicitar: a) Cotação diária das seguintes moedas, Dólar, Euro e Libra Esterlina;
b) O primeiro Nome (estude como armazenar nomes na linguagem C) e quantidade de Reais que cada
um dos 4 amigos deseja levar.
Após informar todos os dados, o programa deverá exibir os seguintes resultados:
a) Deverá exibir a soma total juntando todos os valores em reais dos amigos.
b) Deverá exibir o nome e valor do amigo que contiver a maior quantidade de reais.
c) Deverá exibir o nome e valor do amigo que contiver a menor quantidade de reais.
d) Deverá exibir o nome de cada um dos amigos e também a quantidade de dinheiro que cada um
terá para gastar na viagem já convertida em cada das moedas (aplique o valor das cotações), a
mensagem deverá ser algo como “Joao tem X reais, convertidos terá Y dólares, Z euros e W
libras.”
e) Deverá exibir também os valores ordenados em reais do menor para o maior.
Lucas Timponi Mercdante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>

#define NUM_AMIGOS 4

// Estrutura para armazenar informações de cada amigo
struct Amigo {
    char nome[50];
    double quantidadeReais;
    double quantidadeDolar;
    double quantidadeEuro;
    double quantidadeLibra;
};

int main() {
    double cotacaoDolar, cotacaoEuro, cotacaoLibra;
    struct Amigo amigos[NUM_AMIGOS];
    double somaReais = 0;
    int amigoMaiorReais = 0, amigoMenorReais = 0;

    // Solicitar cotações
    printf("Informe a cotação diária do Dólar: ");
    scanf("%lf", &cotacaoDolar);
    printf("Informe a cotação diária do Euro: ");
    scanf("%lf", &cotacaoEuro);
    printf("Informe a cotação diária da Libra Esterlina: ");
    scanf("%lf", &cotacaoLibra);

    // Solicitar informações de cada amigo
    for (int i = 0; i < NUM_AMIGOS; i++) {
        printf("Informe o nome do amigo %d: ", i + 1);
        scanf("%s", amigos[i].nome);
        printf("Informe a quantidade de Reais que %s deseja levar: ", amigos[i].nome);
        scanf("%lf", &amigos[i].quantidadeReais);

        // Converter para outras moedas
        amigos[i].quantidadeDolar = amigos[i].quantidadeReais / cotacaoDolar;
        amigos[i].quantidadeEuro = amigos[i].quantidadeReais / cotacaoEuro;
        amigos[i].quantidadeLibra = amigos[i].quantidadeReais / cotacaoLibra;

        // Atualizar soma total de Reais
        somaReais += amigos[i].quantidadeReais;

        // Encontrar amigo com maior e menor quantidade de Reais
        if (amigos[i].quantidadeReais > amigos[amigoMaiorReais].quantidadeReais) {
            amigoMaiorReais = i;
        }
        if (amigos[i].quantidadeReais < amigos[amigoMenorReais].quantidadeReais) {
            amigoMenorReais = i;
        }
    }

    // Exibir soma total em Reais
    printf("Soma total em Reais: %.2lf\n", somaReais);

    // Exibir amigo com maior quantidade de Reais
    printf("Amigo com a maior quantidade de Reais: %s (%.2lf Reais)\n", amigos[amigoMaiorReais].nome, amigos[amigoMaiorReais].quantidadeReais);

    // Exibir amigo com menor quantidade de Reais
    printf("Amigo com a menor quantidade de Reais: %s (%.2lf Reais)\n", amigos[amigoMenorReais].nome, amigos[amigoMenorReais].quantidadeReais);

    // Exibir quantidade de dinheiro convertida para cada amigo
    printf("Quantidade de dinheiro convertida para cada amigo:\n");
    for (int i = 0; i < NUM_AMIGOS; i++) {
        printf("%s tem %.2lf Reais, convertidos terá %.2lf dólares, %.2lf euros e %.2lf libras.\n", amigos[i].nome, amigos[i].quantidadeReais, amigos[i].quantidadeDolar, amigos[i].quantidadeEuro, amigos[i].quantidadeLibra);
    }

    // Ordenar amigos por quantidade de Reais (do menor para o maior)
    for (int i = 0; i < NUM_AMIGOS - 1; i++) {
        for (int j = i + 1; j < NUM_AMIGOS; j++) {
            if (amigos[i].quantidadeReais > amigos[j].quantidadeReais) {
                struct Amigo temp = amigos[i];
                amigos[i] = amigos[j];
                amigos[j] = temp;
            }
        }
    }

    // Exibir valores ordenados em Reais
    printf("Valores ordenados em Reais (do menor para o maior):\n");
    for (int i = 0; i < NUM_AMIGOS; i++) {
        printf("%s tem %.2lf Reais\n", amigos[i].nome, amigos[i].quantidadeReais);
    }

    return 0;
}

