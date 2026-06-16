#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *ptr_prod, float pc_desconto) {
    // Acessa o campo preço via operador seta e deduz o desconto
    ptr_prod->preco -= (ptr_prod->preco * (pc_desconto / 100.0f));
}

int main() {
    Produto prod1;
    prod1.id = 101;
    prod1.preco = 100.0f;

    float taxa_desc = 15.0f;

    printf("--- Registro de Entrada ---\n");
    printf("SKU/ID: %d | Preco Base: R$ %.2f\n\n", prod1.id, prod1.preco);

    // Passa o endereço da struct para a função
    aplicar_desconto(&prod1, taxa_desc);

    printf("--- Cupom Gerado ---\n");
    printf("SKU/ID: %d | Preco Liquido: R$ %.2f (Desconto de %.0f%%)\n", prod1.id, prod1.preco, taxa_desc);

    return 0;
}