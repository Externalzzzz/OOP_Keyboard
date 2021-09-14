#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QMimeData>
#include <QDrag>
#include <QString>
#include <QSettings>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "combobox.h"
#include "sorting.h"
#include "table.h"

using namespace std;

/*!
 * \brief MainWindow::MainWindow Конструктор для основного окна
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    setAcceptDrops(true);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setItemDelegateForColumn(7, new CellsComboBox7(this));
    ui->tableWidget->setItemDelegateForColumn(6, new CellsComboBox6(this));
    ui->tableWidget->setItemDelegateForColumn(5, new CellsComboBox5(this));
    ui->tableWidget->setItemDelegateForColumn(4, new CellsComboBox4(this));
    ui->tableWidget->setItemDelegateForColumn(3, new CellsComboBox3(this));
    ui->tableWidget->setItemDelegateForColumn(1, new CellsComboBox1(this));
    ui->tableWidget->horizontalHeader()->setStyleSheet("background-color:black");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: black");

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(Open()));
    connect(ui->actionAdd_string, SIGNAL(triggered()), this, SLOT(Add())); //на панели
    connect(ui->Button_Add, SIGNAL(clicked()), this, SLOT(Add()));          //справа
    connect(ui->actionDelete_string, SIGNAL(triggered()), this, SLOT(Del()));
    connect(ui->Button_Delete, SIGNAL(clicked()), this, SLOT(Del()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionClear_file, SIGNAL(triggered()), this, SLOT(Clear()));
    connect(ui->Button_Clear, SIGNAL(clicked()), this, SLOT(Clear()));
    connect(ui->Button_New, SIGNAL(clicked()), this, SLOT(newFile()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
    connect(ui->actionAbout_creator, SIGNAL(triggered()),this, SLOT(About()));
    connect(ui->actionRefresh, SIGNAL(triggered()),this, SLOT(Refresh()));
    connect(ui->Button_Refresh, SIGNAL(clicked()),this, SLOT(Refresh()));
    connect(ui->actionShowDiagKeyb, SIGNAL(triggered()),this, SLOT(showDiagramKeyboard()));
    connect(ui->Button_Search, SIGNAL(clicked()),this, SLOT(Search()));
    connect(ui->actionSorting, SIGNAL(triggered()),this, SLOT(sorting()));

    ui->Button_Add->setIcon(QIcon("images\\Add string.ico"));
    ui->Button_Add->setIconSize(QSize(20,20));
    ui->Button_Refresh->setIcon(QIcon("images\\refresh.ico"));
    ui->Button_Refresh->setIconSize(QSize(20,20));
    ui->Button_New->setIcon(QIcon("images\\add string.ico"));
    ui->Button_New->setIconSize(QSize(20,20));
    ui->Button_Clear->setIcon(QIcon("images\\clear file.ico"));
    ui->Button_Clear->setIconSize(QSize(20,20));
    ui->Button_Delete->setIcon(QIcon("images\\no.ico"));
    ui->Button_Delete->setIconSize(QSize(20,20));
    ui->Button_Search->setIcon(QIcon("images\\search.ico"));
    ui->Button_Search->setIconSize(QSize(20,20));

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu); //клик правой кнопки мыши для меню

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);



    appTranslator.load(QString("Keyboard_ru_RU.qm"));
    qApp->installTranslator(&appTranslator);
    ui->retranslateUi(this);
    qmPath = qApp->applicationDirPath() + "/translation";
}
/*!
 * \brief MainWindow::~MainWindow Деструктор главного окна
 */
MainWindow::~MainWindow()
{
    writeSettings();
    delete ui;
}
/*!
 * \brief MainWindow::Open Открытие файла
 */
void MainWindow::Open()
{
    disconnect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(write()));

    ui->tableWidget->setSortingEnabled(true);
    int i;
    string str;
    string str1;
    int ID = 0;
    QString Brand;
    QString Model;
    int Keys = 0;
    QString Type;
    int Price = 0;
    QString Light;
    QString Connect;

    QString  fileName = QFileDialog::getOpenFileName(this,"Открытие файла", "C:\\Users\\Max\\Desktop\\OOP_Keyboard\\Keyboard","All Files(*);;Data file (*.bat *.dat);;Text file (.txt);;Database files (*.db)");



    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,
                                 tr("Application"),
                                 tr("Cannot read file %1:\n %2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        ui->statusBar->showMessage(fileName);
        // mtb_kbrd.clear();
        QTextStream database(&file);
        while(!database.atEnd())                 //прогонка по всему файлу
        {
            str1 = database.readLine().toStdString();
            stringstream line(str1);
            i = 0;
            while (getline(line, str, ';'))
            {
                QString str2 = QString::fromStdString(str);
                if (i==0) ID = str2.toInt();
                if (i==1) Brand = str2;
                if (i==2) Model = str2;
                if (i==3) Keys = str2.toInt();
                if (i==4) Type = str2;
                if (i==5) Price = str2.toInt();
                if (i==6) Light = str2;
                if (i==7) Connect = str2;
                i++;
            }
            keyboard mtb(ID, Brand, Model, Keys, Type, Price, Light,Connect);
            mtb_kbrd << mtb;

            keyboard* mtb1;
            mtb1 = new keyboard (ID, Brand, Model, Keys, Type, Price, Light,Connect);
            ptr_kbrd.append(mtb1);

        }
        file.close();


        QList<keyboard>::iterator pos;
        ui->tableWidget->setRowCount(mtb_kbrd.size());
        pos = mtb_kbrd.begin();
        QString str2;
        QTableWidgetItem * newItem = new QTableWidgetItem(); //Создаем виджет элемента таблицы
        for(int j = 0; j < mtb_kbrd.size(); j++, pos++)
        {
            newItem = new QTableWidgetItem(str2.setNum(pos->get_ID()));
            ui->tableWidget->setItem(j, 0, newItem);
            newItem = new QTableWidgetItem(pos->get_Brand());
            ui->tableWidget->setItem(j, 1, newItem);
            newItem = new QTableWidgetItem(pos->get_Model());
            ui->tableWidget->setItem(j, 2, newItem);
            newItem = new QTableWidgetItem(str2.setNum(pos->get_Keys()));
            ui->tableWidget->setItem(j, 3, newItem);
            newItem = new QTableWidgetItem(pos->get_Type());
            ui->tableWidget->setItem(j, 4, newItem);
            newItem = new QTableWidgetItem(str2.setNum(pos->get_Price()));
            ui->tableWidget->setItem(j, 5, newItem);
            newItem = new QTableWidgetItem(pos->get_Light());
            ui->tableWidget->setItem(j, 6, newItem);
            newItem = new QTableWidgetItem(pos->get_Connect());
            ui->tableWidget->setItem(j, 7, newItem);
        }
    }


    else
        QMessageBox::warning(this,
                             tr("Application"),
                             tr("No file selected."));
    write();
}
/*!
 * \brief MainWindow::saveFile Сохранение файла
 */
void MainWindow::saveFile()
{
    QFile file;
    QTextStream out(&file);
    QString str, strfile;
    int count;
    int ID;
    QString Brand;
    QString Model;
    int Keys;
    QString Type;
    int Price;
    QString Light;
    QString Connect;
    QList<keyboard>::iterator pos;


    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"),
                                                    "",
                                                    "Text file(*.txt);;Data file(*.dat);;Database files(*.db)");
    file.setFileName(filename);


    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,
                             tr("Error!"),
                             tr("File was not saved"),
                             QMessageBox::Ok);
    }


    else
    {
        count =  ui->tableWidget->rowCount();
        mtb_kbrd.clear();
        QTableWidgetItem * getItem;
        for(int i = 0; i < count; i++)
        {
            strfile = "";
            getItem = ui->tableWidget->item(i, 0);
            str = getItem->text();
            ID = str.toInt();
            getItem = ui->tableWidget->item(i, 1);
            str = getItem->text();
            Brand = str;
            getItem = ui->tableWidget->item(i, 2);
            str = getItem->text();
            Model = str;
            getItem = ui->tableWidget->item(i, 3);
            str = getItem->text();
            Keys = str.toInt();
            getItem = ui->tableWidget->item(i, 4);
            str = getItem->text();
            Type= str;
            getItem = ui->tableWidget->item(i, 5);
            str = getItem->text();
            Price = str.toInt();
            getItem = ui->tableWidget->item(i, 6);
            str = getItem->text();
            Light = str;
            getItem = ui->tableWidget->item(i, 7);
            str = getItem->text();
            Connect = str;
            keyboard mtb(ID, Brand,Model, Keys, Type, Price, Light, Connect);
            mtb_kbrd << mtb;
        }


        for(pos = mtb_kbrd.begin(); pos != mtb_kbrd.end(); pos++)
        {
            out << pos->get_ID() << ";"<<
                   pos->get_Brand() << ";"<<
                   pos->get_Model() << ";"<<
                   pos->get_Keys() << ";"<<
                   pos->get_Type()<< ";"<<
                   pos->get_Price()<< ";"<<
                   pos->get_Light()<< ";"<<
                   pos->get_Connect() <<  ";"<<endl;
        }
        file.close();
    }
}
/*!
 * \brief MainWindow::write Перезапись файла
 */
void MainWindow::write()
{

    QString str, strfile;
    int count;
    int ID;
    QString Brand;
    QString Model;
    int Keys;
    QString Type;
    int Price;
    QString Light;
    QString Connect;


    count =  ui->tableWidget->rowCount();
    mtb_kbrd.clear();
    QTableWidgetItem * getItem;
    for(int i = 0; i < count; i++)
    {
        strfile = "";
        getItem = ui->tableWidget->item(i, 0);
        str = getItem->text();
        ID = str.toInt();
        getItem = ui->tableWidget->item(i, 1);
        str = getItem->text();
        Brand = str;
        getItem = ui->tableWidget->item(i, 2);
        str = getItem->text();
        Model = str;
        getItem = ui->tableWidget->item(i, 3);
        str = getItem->text();
        Keys = str.toInt();
        getItem = ui->tableWidget->item(i, 4);
        str = getItem->text();
        Type = str;
        getItem = ui->tableWidget->item(i, 5);
        str = getItem->text();
        Price = str.toInt();
        getItem = ui->tableWidget->item(i, 6);
        str = getItem->text();
        Light = str;
        getItem = ui->tableWidget->item(i, 7);
        str = getItem->text();
        Connect = str;
        keyboard mtb(ID, Brand, Model, Keys, Type, Price, Light,Connect);
        mtb_kbrd << mtb;
    }

}
/*!
 * \brief MainWindow::closeEvent Событие закрытия программы
 * \param event Указатель на событие
 */
void MainWindow::closeEvent(QCloseEvent *event)
{

    QMessageBox messageBox(QMessageBox::Question,
                           tr("Exit"),
                           tr("Do you want to exit?"),
                           QMessageBox::Yes | QMessageBox::No,
                           this);
    messageBox.setButtonText(QMessageBox::Yes, tr("Yes"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));

    int quest=  messageBox.exec();
    if (quest == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();

}
/*!
 * \brief MainWindow::Clear Очищение таблицы
 */
void MainWindow::Clear()
{

    int k = ui->tableWidget->rowCount();
    if (k == 0)
    {
        QMessageBox::warning(this,
                             tr("Delete"),
                             tr("List is empty"),
                             QMessageBox::Ok);
    }
    else
    {
        int i = ui->tableWidget->rowCount();
        while(0 != i + 1)
        {
            ui->tableWidget->removeRow(i--);
        }
    }
}
/*!
 * \brief MainWindow::Add Добавление строчки
 */
void MainWindow::Add()
{
    int amountRow = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(amountRow + 1);
}
/*!
 * \brief MainWindow::Del Удаление выбранной строки
 */
void MainWindow::Del()
{
    int k = ui->tableWidget->rowCount();
    if (k == 0)
    {
        QMessageBox::warning(this,
                             tr("Delete"),
                             tr("List is empty"),
                             QMessageBox::Ok);
    }
    else
    {
        int num = ui->tableWidget->currentRow();    //текущая строка
        ui->tableWidget->removeRow(num);            //удалить
    }
}
/*!
 * \brief MainWindow::newFile Создание нового окна
 */
void MainWindow::newFile()
{

    MainWindow *e = new MainWindow;
    e->show();
}
/*!
 * \brief MainWindow::writeSettings Запись настроек окна
 */
void MainWindow::writeSettings()
{
    QSettings qsettings( "Company", "Keyboards" );

    qsettings.beginGroup( "mainwindow" );

    qsettings.setValue( "geometry", saveGeometry() );
   // qsettings.setValue( "savestate", saveState() );
    qsettings.setValue( "maximized", isMaximized() );
//    if ( !isMaximized() ) {
//        qsettings.setValue( "pos", pos() );
//        qsettings.setValue( "size", size() );
//    }

    qsettings.endGroup();


    //    QSettings settings("Company", "Keyboards");
    //    settings.beginGroup("MainWindow");
    //    settings.setValue("size", size());
    //    settings.setValue("Position", pos());
    //    settings.endGroup();
}
/*!
 * \brief MainWindow::readSettings Чтение настроек окна
 */
void MainWindow::readSettings()
{
    QSettings qsettings( "Company", "Keyboards" );

    qsettings.beginGroup( "mainwindow" );

    restoreGeometry(qsettings.value( "geometry", saveGeometry() ).toByteArray());
   // restoreState(qsettings.value( "savestate", saveState() ).toByteArray());
    move(qsettings.value( "pos", pos() ).toPoint());
    resize(qsettings.value( "size", size() ).toSize());
//    if ( qsettings.value( "maximized", isMaximized() ).toBool() )
//        showMaximized();

    qsettings.endGroup();
    //    QSettings settings("Company", "Keyboards");
    //    settings.beginGroup("MainWindow");
    //    resize(settings.value("size", QSize(0, 0)).toSize());
    //    move(settings.value("position", QPoint(0,0)).toPoint());
    //    settings.endGroup();
}
/*!
 * \brief MainWindow::slotCustomMenuRequested Соединение клавиш верхнего меню с кнопками на главном окне
 * \param pos Строка
 */
void MainWindow::slotCustomMenuRequested(QPoint pos)
{
    QMenu * menu = new QMenu(this);
    QAction * AddString = new QAction(tr("Add string"), this);
    QAction * deleteString = new QAction(tr("Delete string"), this);
    QAction * RefreshT = new QAction(tr("Refresh"), this);
    connect(AddString, SIGNAL(triggered()), this, SLOT(Add()));
    connect(deleteString, SIGNAL(triggered()), this, SLOT(Del()));
    connect(RefreshT, SIGNAL(triggered()), this, SLOT(Refresh()));
    menu->addAction(AddString);
    menu->addAction(deleteString);
    menu->addAction(RefreshT);
    menu->popup(ui->tableWidget->viewport()->mapToGlobal(pos));
}



/*!
 * \brief MainWindow::connects Соединение сигналов и слотов
 */
void MainWindow::connects()
{
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(write()));
}
/*!
 * \brief MainWindow::showDiagram Вывод диаграммы
 */
void MainWindow::showDiagramKeyboard()
{
    Diagram diag;
    diag.showDiagram();
    diag.exec();

}

/*!
 * \brief MainWindow::About О программе
 */
void MainWindow::About()
{
    QMessageBox::about(this,
                       tr("About that programm"),
                       tr("This programm was made by Maxim Borisyak IEUIS 2-3 2020 y. \n Keyboard variant"));
}
/*!
 * \brief MainWindow::Refresh Обновление таблицы
 */
void MainWindow::Refresh()
{

    disconnect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(write()));

    if (mtb_kbrd.isEmpty()){
        QMessageBox::warning(this,
                             tr("Refresh"),
                             tr("File is not open"));
    }
    QList<keyboard>::iterator pos;
    ui->tableWidget->setRowCount(mtb_kbrd.size());
    pos = mtb_kbrd.begin();
    QString str2;
    QTableWidgetItem * newItem = new QTableWidgetItem();
    for(int j = 0; j < mtb_kbrd.size(); j++, pos++)
    {
        newItem = new QTableWidgetItem(str2.setNum(pos->get_ID()));
        ui->tableWidget->setItem(j, 0, newItem);
        newItem = new QTableWidgetItem(pos->get_Brand());
        ui->tableWidget->setItem(j, 1, newItem);
        newItem = new QTableWidgetItem(pos->get_Model());
        ui->tableWidget->setItem(j, 2, newItem);
        newItem = new QTableWidgetItem(str2.setNum(pos->get_Keys()));
        ui->tableWidget->setItem(j, 3, newItem);
        newItem = new QTableWidgetItem(pos->get_Type());
        ui->tableWidget->setItem(j, 4, newItem);
        newItem = new QTableWidgetItem(str2.setNum(pos->get_Price()));
        ui->tableWidget->setItem(j, 5, newItem);
        newItem = new QTableWidgetItem(pos->get_Light());
        ui->tableWidget->setItem(j, 6, newItem);
        newItem = new QTableWidgetItem(pos->get_Connect());
        ui->tableWidget->setItem(j, 7, newItem);
    }
    connects();
}
/*!
 * \brief MainWindow::Search Поиск позиции набранной клавиватуры
 */
void MainWindow::Search()
{

    ui->tableWidget->clearSelection();


    QString strsearch;
    strsearch = ui->lineEdit->text();
    qDebug()<<strsearch;
    Refresh();
    for(int i = 0; i < mtb_kbrd.count(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(ui->tableWidget->item(i,j)->text()==strsearch)
            {
                ui->tableWidget->setRangeSelected(QTableWidgetSelectionRange(i,0,i,7),true);    //выделяет нужную ячейку
            }
        }
    }

}
/*!
 * \brief MainWindow::sorting Сортировка таблицы по заданным критериям
 */
void MainWindow::sorting()
{

    bool Choose = 0;
    Choose_ptr_kbrd.clear();

    Sorting sort;
    if(sort.exec()) //ок
    {

        foreach (keyboard *ptrkeyboard, ptr_kbrd)
        {
            if(sort.checkOK(ptrkeyboard))
            {

                Choose_ptr_kbrd << ptrkeyboard;
                Choose = 1;
            }
        }
        if (Choose)
        {
            ui->tableWidget->setRowCount(Choose_ptr_kbrd.length());

            foreach (keyboard *ptrkeyboard, Choose_ptr_kbrd) {

                QString str2;
                QTableWidgetItem *newItem = new QTableWidgetItem();

                int j = Choose_ptr_kbrd.indexOf(ptrkeyboard);

                newItem = new QTableWidgetItem(str2.setNum(ptrkeyboard->get_ID()));
                ui->tableWidget->setItem(j, 0, newItem);
                newItem = new QTableWidgetItem(ptrkeyboard->get_Brand());
                ui->tableWidget->setItem(j, 1, newItem);
                newItem = new QTableWidgetItem(ptrkeyboard->get_Model());
                ui->tableWidget->setItem(j, 2, newItem);
                newItem = new QTableWidgetItem(str2.setNum(ptrkeyboard->get_Keys()));
                ui->tableWidget->setItem(j, 3, newItem);
                newItem = new QTableWidgetItem(ptrkeyboard->get_Type());
                ui->tableWidget->setItem(j, 4, newItem);
                newItem = new QTableWidgetItem(str2.setNum(ptrkeyboard->get_Price()));
                ui->tableWidget->setItem(j, 5, newItem);
                newItem = new QTableWidgetItem(ptrkeyboard->get_Light());
                ui->tableWidget->setItem(j, 6, newItem);
                newItem = new QTableWidgetItem(ptrkeyboard->get_Connect());
                ui->tableWidget->setItem(j, 7, newItem);


            }
        }
        else QMessageBox::warning(this,
                                  tr("Sorting"),
                                  tr("No keyboard with such criterials!"));
    }
}
/*!
 * \brief MainWindow::dragEnterEvent Событие взятия строки
 * \param Указатель на элемент
 */
void MainWindow::dragEnterEvent(QDragEnterEvent * e)
{
    e->setAccepted(true);
}
/*!
 * \brief MainWindow::dragLeaveEvent Событие покидания поля
 * \param e Указатель на элемент
 */
void MainWindow::dragLeaveEvent(QDragLeaveEvent * e)
{
    e->setAccepted(true);
}
/*!
 * \brief MainWindow::dragMoveEvent Событие переноса элемента
 * \param e Указатель на элемент
 */
void MainWindow::dragMoveEvent(QDragMoveEvent * e)
{
    e->setAccepted(true);
}
/*!
 * \brief MainWindow::dropEvent Событие отпускания клавиши
 * \param e Указатель на элемент
 */
void MainWindow::dropEvent(QDropEvent * e)
{

    QStringList strListkeyboard = e->mimeData()->text().split(";");
    keyboard  newkeyboard(strListkeyboard.at(0).toInt(),
                          strListkeyboard.at(1),
                          strListkeyboard.at(2),
                          strListkeyboard.at(3).toInt(),
                          strListkeyboard.at(4),
                          strListkeyboard.at(5).toInt(),
                          strListkeyboard.at(6),
                          strListkeyboard.at(7));
    mtb_kbrd << newkeyboard;
    Refresh();
}
/*!
 * \brief MainWindow::on_actionSwitch_triggered Перевод на английский
 */
void MainWindow::on_actionSwitch_triggered()
{
    appTranslator.load(QString("Keyboard_en_US.qm"));
    qApp->installTranslator(&appTranslator);
    ui->retranslateUi(this);

}
/*!
 * \brief MainWindow::on_actionSwitch2_triggered Перевод на русский
 */
void MainWindow::on_actionSwitch2_triggered()
{
    appTranslator.load(QString("Keyboard_ru_RU.qm"));
    qApp->installTranslator(&appTranslator);
    ui->retranslateUi(this);
}

/*!
 * \brief MainWindow::on_actionSwith3_triggered - Перевод на испанский
 */
void MainWindow::on_actionSwith3_triggered()
{
    appTranslator.load(QString("Keyboard_es_ES.qm"));
    qApp->installTranslator(&appTranslator);
    ui->retranslateUi(this);
}

/*!
 * \brief MainWindow::on_lineEdit_textChanged - Очистка таблицы после поиска
 * \param arg1
 */
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if (ui->lineEdit->text()==nullptr)
        ui->tableWidget->clearSelection();
    (void)arg1;
}
