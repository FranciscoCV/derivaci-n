#ifndef DERIVACION_H
#define DERIVACION_H

#include <QMainWindow>

namespace Ui {
class Derivacion;
}

class Derivacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Derivacion(QWidget *parent = 0);
    ~Derivacion();

private:
    Ui::Derivacion *ui;
public slots:
    void metodo();
    void borrar();
};

#endif // DERIVACION_H
