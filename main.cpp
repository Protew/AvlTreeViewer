#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize glut
    QApplication app( argc, argv );
    MainWindow window;
    window.show();
    window.move( 0, 0 );
    return app.exec();
}
