#include <iostream>
#include <QtGui/QApplication>
#include <mdi.h>

int main(int argc, char *argv[]) {
  std::cout << "Hello World\n";
  QApplication app(argc, argv);
   Mdi mainWindow;
   mainWindow.show();

   return app.exec();
  return 0;
}
