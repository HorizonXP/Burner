#include "Burner.h"
#include <QApplication>
#include <QWidget>

int main(int argv, char **args)
{
    QCoreApplication::addLibraryPath("app/native/lib");
    QApplication app(argv, args);

    Burner window;
    window.resize(1024, 600);
    window.show();

    return app.exec();
}

