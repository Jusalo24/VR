#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onNumberClicked();
    void onOperationClicked();
    void onClearClicked();
    void onEnterClicked();

private:
    QLineEdit *num1;
    QLineEdit *num2;
    QLineEdit *result;
    QPushButton *buttons[10];
    QPushButton *add, *sub, *mul, *div, *clear, *enter;
    QString operation;
};

#endif
