#include "counter.h"

Counter::Counter(QWidget *parent) : QWidget(parent), count(0) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    countButton = new QPushButton("Count", this);
    resetButton = new QPushButton("Reset", this);
    lineEdit = new QLineEdit("0", this);
    lineEdit->setReadOnly(true);

    layout->addWidget(countButton);
    layout->addWidget(resetButton);
    layout->addWidget(lineEdit);

    connect(countButton, &QPushButton::clicked, this, &Counter::increaseCount);
    connect(resetButton, &QPushButton::clicked, this, &Counter::resetCount);

    setLayout(layout);
    setWindowTitle("Counter App");
}

void Counter::increaseCount() {
    count++;
    lineEdit->setText(QString::number(count));
}

void Counter::resetCount() {
    count = 0;
    lineEdit->setText(QString::number(count));
}
