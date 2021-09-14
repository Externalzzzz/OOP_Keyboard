
#include <QApplication>
#include "mainwindow.h"

/*!
 *@mainpage Программа учёта клавиатур
 *\brief Данное ПО открывает файлы с базами данных и редактирует их, выводит диаграмму, сортирует список клавиатур, также возможен поиск конкретной модели клавиатуры.
 *\author - Борисяк М.А. ИЭУИС 2-3
 *\version - 1.0
 *\date - Июнь 2020г
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w,e;
    w.show();

    return a.exec();
}
