#include <QApplication>

#include "gui/mainwindow.hpp"

auto main(int argc, char* argv[]) -> int {
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}
