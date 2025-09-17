#ifndef IUNIDADEMEDIDAREPOSITORY_HPP
#define IUNIDADEMEDIDAREPOSITORY_HPP

#include <vector>
#include "../entities/unidademedida.hpp"

class IUnidadeMedidaRepository {
  public:
    virtual ~IUnidadeMedidaRepository() = default;
    virtual UnidadeMedida* buscar(int id) = 0;
    virtual std::vector<UnidadeMedida> listarTodos() = 0;
};

#endif  // !IUNIDADEMEDIDAREPOSITORY_HPP
