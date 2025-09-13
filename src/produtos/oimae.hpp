#ifndef OIMAE_H
#define OIMAE_H

#include <QDialog>

#include "ui_oimae.h"

class OiMae : public QDialog {
    Q_OBJECT

  public:
    explicit OiMae(QWidget *parent = nullptr);
    ~OiMae();

  private:
    Ui::OiMae *ui;
};

#endif  // OIMAE_H
