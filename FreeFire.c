#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Definição da struct que representa cada item da mochila
typedef struct {
    char nome[30];     // Nome do item
    char tipo[20];     // Tipo (arma, munição, cura, etc)
    int quantidade;    // Quantidade do item
} Item;

// Vetor que representa a mochila com até 10 itens
Item mochila[MAX_ITENS];
int totalItens = 0;  // Quantidade atual de itens na mochila

// Função para adicionar um novo item na mochila
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("A mochila está cheia. Não é possível adicionar mais itens.\n\n");
        return;
    }

    Item novo;

    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novo.nome);  // Lê até o enter (permite espaços)

    printf("Digite o tipo do item (arma, municao, cura, etc): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("Item adicionado com sucesso!\n\n");
}

// Função para remover um item da mochila pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia. Nenhum item para remover.\n\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);

    int encontrado = 0;

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // Item encontrado, removendo e deslocando os demais
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            encontrado = 1;
            printf("Item removido com sucesso.\n\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado na mochila.\n\n");
    }
}

// Função para listar todos os itens da mochila
void listarItens() {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n\n");
        return;
    }

    printf("Itens na mochila:\n");
    printf("--------------------------\n");

    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
        printf("--------------------------\n");
    }
    printf("\n");
}

// Função para buscar um item na mochila pelo nome (busca sequencial)
void buscarItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n\n");
        return;
    }

    char nomeBusca[30];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado:\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n\n");
    }
}

// Função principal com o menu de opções
int main() {
    int opcao;

    do {
        printf("=== Mochila de Loot ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("Saindo do sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n\n");
        }

    } while (opcao != 0);

    return 0;
}
