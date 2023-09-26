/*Enunciado:Q1
FIGURAS GEOMÉTRICAS – Crie um programa que seja capaz de calcular a área de 4 figuras geométricas,
são elas, retângulo, triângulo, quadrado e círculo, todas as informações de dimensões das figuras
devem ser fornecidas pelo usuário do sistema. Após o fornecimento dos dados, o sistema deverá
realizar o cálculo das áreas de cada figura e exibir os seguintes resultados:
a) A área calculada para cada figura geométrica.
b) A figura geométrica com menor área.
c) A figura geométrica com maior área.
d) Exibir as áreas das figuras geométricas de forma crescente (da menor para a maior).
Lucas Timponi Mercdante Castro | Ra: 2304913*/
#include <stdio.h>
#include <math.h>

// Função para calcular a área do retângulo
double calcularAreaRetangulo(double comprimento, double largura) {
    return comprimento * largura;
}

// Função para calcular a área do triângulo
double calcularAreaTriangulo(double base, double altura) {
    return 0.5 * base * altura;
}

// Função para calcular a área do quadrado
double calcularAreaQuadrado(double lado) {
    return lado * lado;
}

// Função para calcular a área do círculo
double calcularAreaCirculo(double raio) {
    return M_PI * raio * raio;
}

int main() {
    double comprimento, largura, base, altura, lado, raio;
    double areaRetangulo, areaTriangulo, areaQuadrado, areaCirculo;
    double menorArea, maiorArea;

    printf("Digite o comprimento e a largura do retângulo: ");
    scanf("%lf %lf", &comprimento, &largura);

    printf("Digite a base e a altura do triângulo: ");
    scanf("%lf %lf", &base, &altura);

    printf("Digite o lado do quadrado: ");
    scanf("%lf", &lado);

    printf("Digite o raio do círculo: ");
    scanf("%lf", &raio);

    // Cálculo das áreas
    areaRetangulo = calcularAreaRetangulo(comprimento, largura);
    areaTriangulo = calcularAreaTriangulo(base, altura);
    areaQuadrado = calcularAreaQuadrado(lado);
    areaCirculo = calcularAreaCirculo(raio);

    // Inicialização das variáveis menor e maior área
    menorArea = areaRetangulo;
    maiorArea = areaRetangulo;

    // Comparação para encontrar a menor e a maior área
    if (areaTriangulo < menorArea) {
        menorArea = areaTriangulo;
    } else if (areaTriangulo > maiorArea) {
        maiorArea = areaTriangulo;
    }

    if (areaQuadrado < menorArea) {
        menorArea = areaQuadrado;
    } else if (areaQuadrado > maiorArea) {
        maiorArea = areaQuadrado;
    }

    if (areaCirculo < menorArea) {
        menorArea = areaCirculo;
    } else if (areaCirculo > maiorArea) {
        maiorArea = areaCirculo;
    }

    // Exibição das áreas calculadas
    printf("Área do Retângulo: %.2lf\n", areaRetangulo);
    printf("Área do Triângulo: %.2lf\n", areaTriangulo);
    printf("Área do Quadrado: %.2lf\n", areaQuadrado);
    printf("Área do Círculo: %.2lf\n", areaCirculo);

    // Exibição da figura com menor área
    if (menorArea == areaRetangulo) {
        printf("A figura com menor área é o Retângulo.\n");
    } else if (menorArea == areaTriangulo) {
        printf("A figura com menor área é o Triângulo.\n");
    } else if (menorArea == areaQuadrado) {
        printf("A figura com menor área é o Quadrado.\n");
    } else {
        printf("A figura com menor área é o Círculo.\n");
    }

    // Exibição da figura com maior área
    if (maiorArea == areaRetangulo) {
        printf("A figura com maior área é o Retângulo.\n");
    } else if (maiorArea == areaTriangulo) {
        printf("A figura com maior área é o Triângulo.\n");
    } else if (maiorArea == areaQuadrado) {
        printf("A figura com maior área é o Quadrado.\n");
    } else {
        printf("A figura com maior área é o Círculo.\n");
    }

    // Exibição das áreas em ordem crescente
    printf("Áreas em ordem crescente:\n");

    double areas[4] = {areaRetangulo, areaTriangulo, areaQuadrado, areaCirculo};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (areas[i] > areas[j]) {
                double temp = areas[i];
                areas[i] = areas[j];
                areas[j] = temp;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%.2lf\n", areas[i]);
    }

    return 0;
}
