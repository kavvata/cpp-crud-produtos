#include "unidademedidarepository.hpp"

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
