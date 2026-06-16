#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *ptr_prod, float pc_desconto) {
    ptr_prod->preco -= (ptr_prod->preco * (pc_desconto / 100.0f));
}

void imprimir_produtos(Produto *ptr_estoque, int qtd_itens) {
    printf("\n================ INVENTARIO DE ESTOQUE ================\n");
    for (int i = 0; i < qtd_itens; i++) {
        // Uso obrigatório de aritmética de ponteiros para acessar os dados
        printf("Item #%d | SKU/ID: %d | Preco: R$ %.2f\n", 
               i + 1, (ptr_estoque + i)->id, (ptr_estoque + i)->preco);
    }
    printf("=======================================================\n\n");
}

int main() {
    // Inicialização do estoque comercial com 3 itens
    Produto estoque[3] = {
        {101, 100.00f},
        {102, 150.00f},
        {103, 200.00f}
    };
    
    float taxa_desc = 10.0f;

    printf(">>> Carga Inicial de Produtos <<<\n");
    imprimir_produtos(estoque, 3);

    // Aplica o desconto no primeiro item (índice 0) passando seu endereço
    aplicar_desconto(&estoque[0], taxa_desc);

    printf(">>> Estoque Atualizado apos Desconto de %.0f%% no Item 1 <<<\n", taxa_desc);
    imprimir_produtos(estoque, 3);

    return 0;
}