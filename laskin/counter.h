#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class Counter : public QWidget {
    Q_OBJECT

public:
    Counter(QWidget *parent = nullptr);

private slots:
    void increaseCount();
    void resetCount();

private:
    int count;
    QLineEdit *lineEdit;
    QPushButton *countButton;
    QPushButton *resetButton;
};

#endif
