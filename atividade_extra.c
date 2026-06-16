#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float preco;
} Produto;

void imprimir_produtos(Produto *ptr_estoque, int qtd_itens) {
    printf("\n================ INVENTARIO DE ESTOQUE ================\n");
    for (int i = 0; i < qtd_itens; i++) {
        printf("Item #%d | SKU/ID: %d | Preco: R$ %.2f\n", 
               i + 1, (ptr_estoque + i)->id, (ptr_estoque + i)->preco);
    }
    printf("=======================================================\n\n");
}

int main() {
    int qtd_cadastro;

    printf("Módulo de Entrada - Digite a quantidade de itens do lote: ");
    if (scanf("%d", &qtd_cadastro) != 1 || qtd_cadastro <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    // Alocação dinâmica de memória conforme a demanda informada
    Produto *lote_produtos = (Produto *) malloc(qtd_cadastro * sizeof(Produto));

    // Validação de segurança do ponteiro de alocação
    if (lote_produtos == NULL) {
        printf("Erro Crítico: Memória insuficiente para o lote informado.\n");
        return 1;
    }

    printf("\n>>> INICIANDO ENTRADA DE DADOS <<<\n");
    for (int i = 0; i < qtd_cadastro; i++) {
        printf("\n[Item #%d de %d]\n", i + 1, qtd_cadastro);
        
        printf("  Defina o SKU/ID: ");
        scanf("%d", &(lote_produtos + i)->id);

        printf("  Defina o Preco (R$): ");
        scanf("%f", &(lote_produtos + i)->preco);
    }

    // Exibe o relatório consolidado usando a função de listagem
    imprimir_produtos(lote_produtos, qtd_cadastro);

    // Liberação obrigatória do bloco de memória alocado na Heap
    free(lote_produtos);
    lote_produtos = NULL; // Boa prática corporativa: limpa o ponteiro órfão

    return 0;
}