#ifndef PRODUTOFORM_HPP
#define PRODUTOFORM_HPP

#include <QWidget>
#include "ui_produtoform.h"

class ProdutoForm : public QWidget {
    Q_OBJECT

  public:
    explicit ProdutoForm(QWidget *parent = nullptr);
    ~ProdutoForm();

  public slots:
    void salvar();
    void voltar();

  private:
    Ui::ProdutoForm *ui;
};

#endif  // PRODUTOFORM_HPP
