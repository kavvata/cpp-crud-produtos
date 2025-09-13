#include "oimae.h"
#include "ui_oimae.h"

OiMae::OiMae(QWidget *parent) : QDialog(parent), ui(new Ui::OiMae) { ui->setupUi(this); }

OiMae::~OiMae() { delete ui; }
