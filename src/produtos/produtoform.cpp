#include "produtoform.hpp"
#include <qchar.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include "entities/produto.hpp"

ProdutoForm::ProdutoForm(QWidget *parent, Produto *produto)
    : QWidget(parent), ui(new Ui::ProdutoForm) {
    ui->setupUi(this);

    connect(ui->salvarPushButton_, &QPushButton::clicked, this, &ProdutoForm::salvar);
    connect(ui->voltarPushButton_, &QPushButton::clicked, this, &ProdutoForm::voltar);

    if (produto) {
        ui->nomeLineEdit_->setText(QString::fromStdString(produto->nome));
        ui->precoDoubleSpinBox_->setValue(produto->preco);
        ui->quantidadeSpinBox_->setValue(produto->quantidade);
    }
}

ProdutoForm::~ProdutoForm() { delete ui; }

void ProdutoForm::salvar() { QMessageBox::warning(this, "Salvar", "TODO: Não Implementado."); }

void ProdutoForm::voltar() { emit voltarListWidget(); }
