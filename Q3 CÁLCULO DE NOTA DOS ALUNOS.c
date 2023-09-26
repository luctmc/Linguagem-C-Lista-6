/*Enunciado:Q3
CÁLCULO DE NOTA DOS ALUNOS – Crie um programa que deverá solicitar RA, NOTA1, NOTA2 e
NOTAPLURI para 3 alunos diferentes. Em posse das informações, o sistema deverá realizar as seguintes
ações:
a) Calcular a média para cada um dos alunos, aplicando os seguintes pesos 30% para nota1, 40%
para nota2 e 30% para notapluri.
b) Deverá apresentar o RA e MÉDIA de cada um dos alunos.
c) Deverá apresentar a média geral das notas dos alunos (some as médias calculas e divida por
três).
d) Deverá apresentar o RA e a mensagem APROVADO (media >= 7.0) ou REPROVADO (media < 7).
e) Deverá exibir uma mensagem informando quantos alunos foram aprovados e quantos foram
reprovados.
f) Deverá exibir o RA e MEDIA ordenados do menor para o maior, para realizar a ordenação
considere as médias calculadas.
Lucas Timponi Mercdante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações de cada aluno
struct Aluno {
    char RA[20];
    double NOTA1;
    double NOTA2;
    double NOTAPLURI;
    double media;
};

int main() {
    struct Aluno alunos[3];
    double mediaGeral = 0.0;
    int aprovados = 0, reprovados = 0;

    // Solicitar informações de cada aluno
    for (int i = 0; i < 3; i++) {
        printf("Informe o RA do aluno %d: ", i + 1);
        scanf("%s", alunos[i].RA);
        printf("Informe a NOTA1 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTA1);
        printf("Informe a NOTA2 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTA2);
        printf("Informe a NOTAPLURI do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTAPLURI);

        // Calcular a média ponderada
        alunos[i].media = (0.30 * alunos[i].NOTA1) + (0.40 * alunos[i].NOTA2) + (0.30 * alunos[i].NOTAPLURI);

        // Atualizar a média geral
        mediaGeral += alunos[i].media;

        // Verificar aprovação ou reprovação
        if (alunos[i].media >= 7.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    // Exibir RA e MÉDIA de cada aluno
    printf("RA e MÉDIA de cada aluno:\n");
    for (int i = 0; i < 3; i++) {
        printf("RA: %s, MÉDIA: %.2lf\n", alunos[i].RA, alunos[i].media);
    }

    // Exibir média geral das notas
    printf("Média geral das notas dos alunos: %.2lf\n", mediaGeral / 3);

    // Exibir RA e situação (APROVADO ou REPROVADO) de cada aluno
    printf("Situação de cada aluno:\n");
    for (int i = 0; i < 3; i++) {
        if (alunos[i].media >= 7.0) {
            printf("RA: %s, Situação: APROVADO\n", alunos[i].RA);
        } else {
            printf("RA: %s, Situação: REPROVADO\n", alunos[i].RA);
        }
    }

    // Exibir quantidade de alunos aprovados e reprovados
    printf("Quantidade de alunos APROVADOS: %d\n", aprovados);
    printf("Quantidade de alunos REPROVADOS: %d\n", reprovados);

    // Ordenar alunos por média (do menor para o maior)
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (alunos[i].media > alunos[j].media) {
                struct Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    // Exibir RA e MÉDIA ordenados
    printf("RA e MÉDIA ordenados (do menor para o maior):\n");
    for (int i = 0; i < 3; i++) {
        printf("RA: %s, MÉDIA: %.2lf\n", alunos[i].RA, alunos[i].media);
    }

    return 0;
}
