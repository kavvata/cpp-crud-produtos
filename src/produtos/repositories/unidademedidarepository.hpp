#ifndef INMEMORYUNIDADEMEDIDAREPOSITORY_HPP
#define INMEMORYUNIDADEMEDIDAREPOSITORY_HPP

#include <vector>
#include "iunidademedidarepository.hpp"
class InMemoryUnidadeMedidaRepository : public IUnidadeMedidaRepository {
  public:
    InMemoryUnidadeMedidaRepository();
    std::vector<UnidadeMedida> listarTodos();

  private:
    std::vector<UnidadeMedida> unidademedidas_;
    int proximoCodigo_;
};

#endif  // !INMEMORYUNIDADEMEDIDAREPOSITORY_HPP
