#ifndef PRODUTOFORM_HPP
#define PRODUTOFORM_HPP

#include <QWidget>
#include "entities/produto.hpp"
#include "repositories/iprodutorepository.hpp"
#include "repositories/iunidademedidarepository.hpp"
#include "ui_produtoform.h"

class ProdutoForm : public QWidget {
    Q_OBJECT

  public:
    explicit ProdutoForm(QWidget* parent = nullptr, Produto* produto = nullptr);
    ~ProdutoForm();

  signals:
    void voltarListWidget();

  public slots:
    void salvar();
    void voltar();

  private:
    Ui::ProdutoForm* ui;
    IProdutoRepository* repo;
    IUnidadeMedidaRepository* unidadeMedidaRepo;
    Produto* instance = nullptr;
};

#endif  // PRODUTOFORM_HPP
