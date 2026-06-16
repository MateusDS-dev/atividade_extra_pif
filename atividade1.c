#include <stdio.h>

int main() {
    float total_venda = 100.0f;
    float *ponteiro_total = &total_venda;

    printf("Total inicial: R$ %.2f\n", total_venda);

    // Aplica o percentual de reajuste pelo endereço
    *ponteiro_total *= 1.1;

    printf("Total com taxa: R$ %.2f\n", total_venda);

    return 0;
}