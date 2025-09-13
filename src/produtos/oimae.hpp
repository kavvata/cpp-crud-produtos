#ifndef OIMAE_H
#define OIMAE_H

#include <QDialog>

namespace Ui {
    class OiMae;
}

class OiMae : public QDialog {
    Q_OBJECT

  public:
    explicit OiMae(QWidget *parent = nullptr);
    ~OiMae();

  private:
    Ui::OiMae *ui;
};

#endif  // OIMAE_H
