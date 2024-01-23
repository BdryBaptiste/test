#include "GUIDisplay.h"
#include <iostream>

GUIDisplay::GUIDisplay(QWidget *parent) : ui(new Ui::MainWindow), mainWindow(new QMainWindow(parent)) {
    ui->setupUi(mainWindow);
}

void GUIDisplay::displayBoard(const Board& board) {
    int rows = board.getRows();
    int cols = board.getCols();

    if(ui->Board->columnCount() != cols){
        ui->Board->setColumnCount(cols);
        if(ui->Board->rowCount() != rows){
            ui->Board->setRowCount(rows);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Symbol cellSymbol = board.getCell(i, j);
            QString cellChar = QString::fromStdString(symbolToString(cellSymbol));
            QTableWidgetItem *newItem = new QTableWidgetItem();
            newItem->setText(cellChar);
            ui->Board->setItem(i, j, newItem);

        }
    }

    ui->Board->update();

    QApplication::processEvents();

}


void GUIDisplay::displayPositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) {

}


void GUIDisplay::showMessage(const std::string& message) {
    qDebug() << "Debug " << QString::fromStdString(message);
    ui->Label->setText(QString::fromStdString(message));
    QApplication::processEvents();
}

void GUIDisplay::displayInstructions(){

}
