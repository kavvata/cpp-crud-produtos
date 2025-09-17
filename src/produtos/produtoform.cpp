#include "produtoform.hpp"
#include <qmessagebox.h>
#include <qpushbutton.h>

ProdutoForm::ProdutoForm(QWidget *parent) : QWidget(parent), ui(new Ui::ProdutoForm) {
    ui->setupUi(this);
    connect(ui->salvarPushButton_, &QPushButton::clicked, this, &ProdutoForm::salvar);
    connect(ui->voltarPushButton_, &QPushButton::clicked, this, &ProdutoForm::voltar);
}

ProdutoForm::~ProdutoForm() { delete ui; }

void ProdutoForm::salvar() { QMessageBox::warning(this, "Salvar", "TODO: Não Implementado."); }

void ProdutoForm::voltar() { emit voltarListWidget(); }
