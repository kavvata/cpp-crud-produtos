#ifndef UNIDADEMEDIDA_HPP
#define UNIDADEMEDIDA_HPP

#include <string>
struct UnidadeMedida {
    int codigo;
    std::string descricao;
    UnidadeMedida() : codigo{}, descricao{} {}
    UnidadeMedida(int c, std::string desc) : codigo{c}, descricao{desc} {}
};

#endif  // !UNIDADEMEDIDA_HPP
