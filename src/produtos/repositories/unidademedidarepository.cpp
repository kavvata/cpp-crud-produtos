#include "unidademedidarepository.hpp"
#include <algorithm>

InMemoryUnidadeMedidaRepository::InMemoryUnidadeMedidaRepository()
    : unidademedidas_{}, proximoCodigo_{1} {
    // Seed common unidades de medida
    unidademedidas_.push_back(UnidadeMedida(proximoCodigo_++, "Quilo"));
    unidademedidas_.push_back(UnidadeMedida(proximoCodigo_++, "Litro"));
    unidademedidas_.push_back(UnidadeMedida(proximoCodigo_++, "Unidade"));
    unidademedidas_.push_back(UnidadeMedida(proximoCodigo_++, "Pacote"));
    unidademedidas_.push_back(UnidadeMedida(proximoCodigo_++, "Caixa"));
}

std::vector<UnidadeMedida> InMemoryUnidadeMedidaRepository::listarTodos() {
    return unidademedidas_;
}

UnidadeMedida* InMemoryUnidadeMedidaRepository::buscar(int id) {
    auto it = std::find_if(unidademedidas_.begin(), unidademedidas_.end(), [id](UnidadeMedida& p) {
        return p.codigo == id;
    });

    return it != unidademedidas_.end() ? new UnidadeMedida(*it) : nullptr;
}
