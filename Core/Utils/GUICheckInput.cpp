#include "GUICheckInput.h"
#include <QDebug>


GUICheckInputs::GUICheckInputs(Display& display, QWidget *parent) : CheckInputs(display), ui(new Ui::MainWindow), mainWindow(new QMainWindow(parent)) {
    ui->setupUi(this);
    connect(ui->Board, &QTableWidget::cellClicked, this, &GUICheckInputs::on_Board_cellClicked);
}

int GUICheckInputs::getIntegerInput() {
    waitingForInput = true;

    while (waitingForInput) {
        QApplication::processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return position.second;
}

std::pair<int, int> GUICheckInputs::getTwoIntsInput() {
    waitingForInput = true;

    while (waitingForInput) {
        QApplication::processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return position;
}

void GUICheckInputs::on_Board_cellClicked(int row, int column){
    position.first = row;
    position.second = column;
    waitingForInput = false;
}
