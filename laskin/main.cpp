#include <QApplication>
#include "counter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Counter window;
    window.show();

    return app.exec();
}
