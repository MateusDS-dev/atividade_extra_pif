#include <stdio.h>

void aplicar_desconto(float *ptr_preco, float pc_desconto) {
    // Deduz o percentual informado direto no valor apontado
    *ptr_preco -= (*ptr_preco * (pc_desconto / 100.0f));
}

int main() {
    float valor_item = 100.0f;
    float taxa_desc = 15.0f;

    printf("Valor original do item: R$ %.2f\n", valor_item);

    // Chamada da rotina de desconto passando o ponteiro do valor
    aplicar_desconto(&valor_item, taxa_desc);

    printf("Valor final (com %.0f%% de desc.): R$ %.2f\n", taxa_desc, valor_item);

    return 0;
}