#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include <QTranslator>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QSettings>
#include <QFontDialog>
#include <QColorDialog>
#include <QPoint>
#include <QApplication>
#include <QActionGroup>
#include <QLibraryInfo>
#include <QErrorMessage>
#include <QCloseEvent>
#include <QDrag>
#include <QTableWidget>
#include <QStandardItemModel>

#include "keyboard.h"
#include "diagram.h"

/*!
 *\brief namespace Ui{class MainWindow;} - Пространствро имен UI
 */
namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class - Класс основного рабочего окна
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief writeSettings - Запись настроек окна
     */
    void writeSettings();

    /*!
     * \brief readSettings - Чтение настроек окна
     */
    void readSettings();

protected:

    virtual void dragEnterEvent (QDragEnterEvent * e);  /*! virtual void dragEnterEvent (QDragEnterEvent * e); функции DragAndDrop*/

    virtual void dragLeaveEvent (QDragLeaveEvent * e);  /*!  virtual void dragLeaveEvent (QDragLeaveEvent * e);  функции DragAndDrop*/

    virtual void dragMoveEvent(QDragMoveEvent * e);     /*! virtual void dragMoveEvent(QDragMoveEvent * e); функции DragAndDrop*/

    virtual void dropEvent      (QDropEvent * e);       /*!  virtual void dropEvent      (QDropEvent * e); функции DragAndDrop*/

private slots:
    void Open();    /*! void Open(); - Открытие файла*/

    void Add(); /*! void Add(); - Добавить строку*/

    void Del();     /*! void Del(); - Удалить строку*/

    void newFile();     /*! void newFile(); - Открытие нового окна*/

    void saveFile();    /*! void saveFile(); - Сохранение файла*/

    void write();   /*! void write(); - Перезапись файла*/

    void closeEvent(QCloseEvent *event);    /*! void closeEvent(QCloseEvent *event); - Закрытие окна*/

    void Clear();       /*! void Clear(); - Очистить*/

    void About();     /*! void About(); - О программе*/

    void Refresh();      /*! void Clear(); - Обновить*/

    void Search();         /*! void Search(); - Поиск */

    void sorting();      /*!    void sorting(); - Фильтр*/

    void showDiagramKeyboard();        /*! void showDiagramKeyboard(); - Показ диаграммыь*/
    /*!
     * \brief slotCustomMenuRequested - связывание кнопок на окне с кнопками на верхней панели
     */
    void slotCustomMenuRequested(QPoint);


    void on_actionSwitch_triggered();  /*!   void on_actionSwitch_triggered(); - Английский язык*/

    void on_actionSwitch2_triggered();  /*! void on_actionSwitch2_triggered(); - Русский язык*/


    void on_actionSwith3_triggered(); /*! void on_actionSwith3_triggered(); - Испанский язык*/
    /*!
     * \brief on_lineEdit_textChanged - обнуление выделений в таблице, после очищения поля поиска
     * \param arg1
     */
    void on_lineEdit_textChanged(const QString &arg1);

private:
    /*!
     * \brief ui - основное окно
     */
    Ui::MainWindow      *ui;
    /*!
     * \brief appTranslator - Перевод для окон
     */
    QTranslator         appTranslator;
    /*!
     * \brief qmPath - Путь файлов  переводами
     */
    QString             qmPath;
    /*!
     * \brief mtb_kbrd - Список клавиатур
     */
    QList<keyboard>      mtb_kbrd;
    /*!
     * \brief Choose_ptr_kbrd - Список клавиатур
     */
    QList<keyboard*>     Choose_ptr_kbrd;
    /*!
     * \brief ptr_kbrd - Список указателей на клавиатуры
     */
    QList<keyboard*>     ptr_kbrd;
    /*!
     * \brief connects - метод соединения сигнаолов и слотов
     */
    void connects();
};

#endif // MAINWINDOW_H
