#include <QDebug>

#include "sorting.h"
#include "ui_sorting.h"


/*!
 * \brief Sorting::checkOK Сортировка по параметрам
 * \param ptrkeyboard элемент класса клавиатуры
 * \return Логический ответ подходит ли строка или нет
 */
bool Sorting::checkOK(keyboard *ptrkeyboard)
{
    BrandOK= 0;
    LightOK =0;
    ConnectOK = 0;
    OK = 0;

    switch (Brand){     //проверка на подходящий бренд
    case 0:
        BrandOK =1;
        break;
    case 1:
        if(ptrkeyboard->get_Brand() == "Logitech") BrandOK =1;
        break;
    case 2:
        if(ptrkeyboard->get_Brand() == "Tesoro") BrandOK =1;
        break;
    case 3:
        if(ptrkeyboard->get_Brand() == "HyperX") BrandOK =1;
        break;
    case 4:
        if(ptrkeyboard->get_Brand() == "Corsair") BrandOK =1;
        break;
    case 5:
        if(ptrkeyboard->get_Brand() == "QCyber") BrandOK =1;
        break;
    case 6:
        if(ptrkeyboard->get_Brand() == "HARPER") BrandOK =1;
        break;
    case 7:
        if(ptrkeyboard->get_Brand() == "OKLICK") BrandOK =1;
        break;
    case 8:
        if(ptrkeyboard->get_Brand() == "Cooler Master") BrandOK =1;
        break;
    case 9:
        if(ptrkeyboard->get_Brand() == "SteelSeries") BrandOK =1;
        break;
    case 10:
        if(ptrkeyboard->get_Brand() == "Defender") BrandOK =1;
        break;
    case 11:
        if(ptrkeyboard->get_Brand() == "Razer") BrandOK = 1;
        break;
    case 12:
        if(ptrkeyboard->get_Brand() == "Apple") BrandOK =1;
        break;
    case 13:
        if(ptrkeyboard->get_Brand() == "A4Tech") BrandOK = 1;
        break;

    }

    switch (Light) {      //проверка на подходящий тип подсветки клавиатуры
    case 0:
        LightOK =1;
        break;
    case 1:
        if(ptrkeyboard->get_Light() == "RGB") LightOK =1;
        break;
    case 2:
        if(ptrkeyboard->get_Light() == "Null") LightOK =1;
        break;
    case 3:
        if(ptrkeyboard->get_Light() == "Mono") LightOK =1;
        break;
    }

    switch (Connect) {        //проверка на подходящий тип подключения
    case 0:
        ConnectOK = 1;
        break;
    case 1:
        if(ptrkeyboard->get_Connect() == "USB") ConnectOK =1;
        break;
    case 2:
        if(ptrkeyboard->get_Connect() == "BT") ConnectOK =1;
        break;
    }

    if (BrandOK && LightOK && ConnectOK)
        OK = 1;
    return OK;
}

/*!
 * \brief Sorting::Sorting Конструктор сортировки
 * \param parent указатель на родительский класс
 */
Sorting::Sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sorting)
{

    ui->setupUi(this);

    OK = 0;
    ui->pushButton->setIcon(QIcon("images\\sorting.ico"));
    ui->pushButton->setIconSize(QSize(60,60));

}
/*!
 * \brief Sorting::~Sorting Деструктор сортировки
 */
Sorting::~Sorting()
{
    delete ui;
}
/*!
 * \brief Sorting::on_buttonBox_accepted Выбор нужных параметров
 */
void Sorting::on_buttonBox_accepted()
{
    Brand = ui->comboBox_Brand->currentIndex();
    Light = ui->comboBox_Light->currentIndex();
    Connect = ui->comboBox_Connect->currentIndex();
}
