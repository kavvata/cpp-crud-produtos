#include "produtorepository.hpp"
#include <algorithm>

InMemoryProdutoRepository::InMemoryProdutoRepository() : produtos_{}, proximoCodigo_{1} {
    UnidadeMedida kg(1, "Quilo");
    UnidadeMedida litro(2, "Litro");
    UnidadeMedida unidade(3, "Unidade");
    UnidadeMedida pacote(4, "Pacote");
    UnidadeMedida caixa(5, "Caixa");

    cadastrar(Produto(Produto::SEM_CODIGO, "Arroz", 5.50, 10, kg));
    cadastrar(Produto(Produto::SEM_CODIGO, "Feijão", 8.20, 5, kg));
    cadastrar(Produto(Produto::SEM_CODIGO, "Leite", 4.30, 12, litro));
    cadastrar(Produto(Produto::SEM_CODIGO, "Macarrão", 3.10, 20, pacote));
    cadastrar(Produto(Produto::SEM_CODIGO, "Açúcar", 6.00, 7, kg));
    cadastrar(Produto(Produto::SEM_CODIGO, "Cerveja", 4.90, 24, caixa));
    cadastrar(Produto(Produto::SEM_CODIGO, "Ovos", 14.00, 30, unidade));
}

std::vector<Produto> InMemoryProdutoRepository::listarTodos() { return produtos_; }

std::vector<Produto> InMemoryProdutoRepository::cadastrar(Produto novoProduto) {
    if (novoProduto.codigo == Produto::SEM_CODIGO) {
        novoProduto.codigo = proximoCodigo_++;
    }
    produtos_.push_back(novoProduto);
    return produtos_;
}

std::vector<Produto> InMemoryProdutoRepository::editar(Produto produto) {
    auto it = std::find_if(produtos_.begin(), produtos_.end(), [&](const Produto& p) {
        return p.codigo == produto.codigo;
    });

    if (it != produtos_.end()) {
        *it = produto;
    }
    return produtos_;
}

std::vector<Produto> InMemoryProdutoRepository::remover(Produto produto) {
    produtos_.erase(std::remove_if(produtos_.begin(),
                                   produtos_.end(),
                                   [&](const Produto& p) { return p.codigo == produto.codigo; }),
                    produtos_.end());
    return produtos_;
}
