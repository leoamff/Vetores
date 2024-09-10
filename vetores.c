#include <stdio.h>

void inserirOrdenado(int vetor[], int *tamanho, int valor, int capacidade) {
    if (*tamanho >= capacidade) {
        printf("Capacidade máxima atingida. Não é possível inserir mais elementos.\n");
        return;
    }

    int i;
    for (i = *tamanho - 1; (i >= 0 && vetor[i] > valor); i--) {
        vetor[i + 1] = vetor[i];
    }

    vetor[i + 1] = valor;
    (*tamanho)++;
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int posicao = buscaBinaria(vetor, *tamanho, valor);
    if (posicao == -1) {
        printf("Elemento não encontrado. Nenhuma remoção realizada.\n");
        return;
    }

    for (int i = posicao; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    (*tamanho)--;
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho, capacidade;

    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < 3 || capacidade > 50);

    tamanho = 0;
    int vetor[50];

    int valor;
    printf("Digite os valores para preencher o vetor:\n");
    while (tamanho < capacidade) {
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, valor, capacidade);
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Imprimir vetor\n");
        printf("2. Consultar elemento (busca binária)\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;

            case 2:
                printf("Digite o valor a ser consultado: ");
                scanf("%d", &valor);
                int posicao = buscaBinaria(vetor, tamanho, valor);
                if (posicao != -1)
                    printf("Elemento encontrado na posição: %d\n", posicao);
                else
                    printf("Elemento não encontrado.\n");
                break;

            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerElemento(vetor, &tamanho, valor);
                break;

            case 4:
                if (tamanho < capacidade) {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    inserirOrdenado(vetor, &tamanho, valor, capacidade);
                } else {
                    printf("Capacidade máxima atingida. Não é possível inserir mais elementos.\n");
                }
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
