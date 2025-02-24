#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *label1 = new QLabel("Number 1", this);
    QLabel *label2 = new QLabel("Number 2", this);
    QLabel *labelResult = new QLabel("Result", this);

    num1 = new QLineEdit(this);
    num2 = new QLineEdit(this);
    result = new QLineEdit(this);
    result->setReadOnly(true);

    layout->addWidget(label1, 0, 0);
    layout->addWidget(num1, 0, 1);
    layout->addWidget(label2, 0, 2);
    layout->addWidget(num2, 0, 3);
    layout->addWidget(labelResult, 0, 4);
    layout->addWidget(result, 0, 5);


    for (int i = 0; i < 10; i++) {
        buttons[i] = new QPushButton(QString::number(i), this);
        connect(buttons[i], &QPushButton::clicked, this, &Calculator::onNumberClicked);
    }


    add = new QPushButton("+", this);
    sub = new QPushButton("-", this);
    mul = new QPushButton("*", this);
    div = new QPushButton("/", this);
    clear = new QPushButton("Clear", this);
    enter = new QPushButton("Enter", this);

    connect(add, &QPushButton::clicked, this, &Calculator::onOperationClicked);
    connect(sub, &QPushButton::clicked, this, &Calculator::onOperationClicked);
    connect(mul, &QPushButton::clicked, this, &Calculator::onOperationClicked);
    connect(div, &QPushButton::clicked, this, &Calculator::onOperationClicked);
    connect(clear, &QPushButton::clicked, this, &Calculator::onClearClicked);
    connect(enter, &QPushButton::clicked, this, &Calculator::onEnterClicked);


    int row = 1;
    int col = 0;
    for (int i = 1; i <= 9; i++) {
        layout->addWidget(buttons[i], row, col);
        col++;
        if (col > 2) {
            col = 0;
            row++;
        }
    }
    layout->addWidget(buttons[0], row, 1);
    layout->addWidget(clear, row, 0);
    layout->addWidget(enter, row, 2);


    layout->addWidget(add, 1, 3);
    layout->addWidget(sub, 2, 3);
    layout->addWidget(mul, 3, 3);
    layout->addWidget(div, 4, 3);

    setLayout(layout);
    setWindowTitle("Calculator");
}

void Calculator::onNumberClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    if (num1->hasFocus()) {
        num1->insert(button->text());
    } else if (num2->hasFocus()) {
        num2->insert(button->text());
    }
}

void Calculator::onOperationClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    operation = button->text();
}

void Calculator::onClearClicked() {
    num1->clear();
    num2->clear();
    result->clear();
}

void Calculator::onEnterClicked() {
    if (num1->text().isEmpty() || num2->text().isEmpty() || operation.isEmpty()) return;

    double val1 = num1->text().toDouble();
    double val2 = num2->text().toDouble();
    double res = 0;

    if (operation == "+") {
        res = val1 + val2;
    } else if (operation == "-") {
        res = val1 - val2;
    } else if (operation == "*") {
        res = val1 * val2;
    } else if (operation == "/") {
        if (val2 != 0) {
            res = val1 / val2;
        } else {
            result->setText("Error");
            return;
        }
    }

    result->setText(QString::number(res));
}
