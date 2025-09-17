#include "produtoform.hpp"
#include <qchar.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qvariant.h>
#include <vector>
#include "entities/produto.hpp"
#include "entities/unidademedida.hpp"
#include "repositories/produtorepository.hpp"
#include "repositories/unidademedidarepository.hpp"

ProdutoForm::ProdutoForm(QWidget* parent, Produto* produto)
    : QWidget(parent), ui(new Ui::ProdutoForm) {
    ui->setupUi(this);

    unidadeMedidaRepo = new InMemoryUnidadeMedidaRepository();
    repo = &InMemoryProdutoRepository::instance();

    connect(ui->salvarPushButton_, &QPushButton::clicked, this, &ProdutoForm::salvar);
    connect(ui->voltarPushButton_, &QPushButton::clicked, this, &ProdutoForm::voltar);

    connect(ui->removerPushButton_, &QPushButton::clicked, this, &ProdutoForm::remover);

    std::vector<UnidadeMedida> unidadesMedida = this->unidadeMedidaRepo->listarTodos();

    for (const UnidadeMedida it : unidadesMedida) {
        ui->unidadeMedidacomboBox_->addItem(QString::fromStdString(it.descricao), it.codigo);
    }

    if (produto) {
        this->instance = produto;
        ui->nomeLineEdit_->setText(QString::fromStdString(instance->nome));
        ui->precoDoubleSpinBox_->setValue(instance->preco);
        ui->quantidadeSpinBox_->setValue(instance->quantidade);

        int index = ui->unidadeMedidacomboBox_->findData(instance->unidadeMedida.codigo);

        if (index != -1) {
            ui->unidadeMedidacomboBox_->setCurrentIndex(index);
        }
    } else {
        ui->removerPushButton_->hide();
    }
}

ProdutoForm::~ProdutoForm() { delete ui; }

void ProdutoForm::salvar() {
    Produto* retorno = nullptr;
    if (this->instance) {
        Produto* novo = new Produto(this->instance->codigo,
                                    ui->nomeLineEdit_->text().toStdString(),
                                    ui->precoDoubleSpinBox_->value(),
                                    ui->quantidadeSpinBox_->value(),
                                    this->instance->unidadeMedida);

        int unId = ui->unidadeMedidacomboBox_->currentData().toInt();
        novo->unidadeMedida = *this->unidadeMedidaRepo->buscar(unId);
        retorno = this->repo->editar(*novo);
    } else {
        Produto* novo = new Produto(ui->nomeLineEdit_->text().toStdString(),
                                    ui->precoDoubleSpinBox_->value(),
                                    ui->quantidadeSpinBox_->value());

        int unId = ui->unidadeMedidacomboBox_->currentData().toInt();
        novo->unidadeMedida = *this->unidadeMedidaRepo->buscar(unId);
        retorno = this->repo->cadastrar(*novo);
    }
    if (!retorno) {
        QMessageBox::warning(this, "Erro", "Erro ao salvar");
    } else {
        this->instance = retorno;
        QMessageBox::information(this, "Sucesso", "Produto salvo com sucesso!");
    }
}

void ProdutoForm::voltar() { emit voltarListWidget(); }

void ProdutoForm::remover() {
    if (!this->instance) {
        QMessageBox::critical(this, "Erro", "Erro ao remover: instância não localizada.");
        return;
    }

    this->repo->remover(*this->instance);
    QMessageBox::information(this, "Sucesso", "Produto removido com sucesso.");
    emit voltarListWidget();
}
