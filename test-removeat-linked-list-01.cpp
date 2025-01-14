#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1;

    // Adicionando elementos à lista
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }

    // Início do cálculo de tempo
    auto beg = std::chrono::high_resolution_clock::now();
    
    unsigned int m;
    std::cin >> m;
    unsigned int removed = 0, not_removed = 0;

    // Tentando remover os elementos pelos índices informados
    for (unsigned int i = 0; i < m; ++i) {
        unsigned int index;
        std::cin >> index;
        if (l1.remove_at(index))
            removed++;
        else
            not_removed++;
    }

    // Finalizando o cálculo de tempo
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - beg); // Correção no cálculo do tempo

    // Exibindo as informações de depuração
    std::cerr << "[DEBUG] Tried to remove " << m << " element(s)\n";
    std::cerr << "[DEBUG] Removed " << removed << " element(s)\n";
    std::cerr << "[DEBUG] Not removed " << not_removed << " element(s)\n";

    // Verificando se a quantidade de elementos restantes está correta
    if (l1.size() != n - removed || (not_removed + removed != m)) {
        std::cerr << "[ERROR] check remove_at method!\n";
        exit(1);
    }

    // Exibindo o tempo de execução
    std::cerr << "[INFO] Elapsed time for " << removed << " remove_at success: " << elapsed.count() << " ms" << std::endl;
    
    return 0;
}
