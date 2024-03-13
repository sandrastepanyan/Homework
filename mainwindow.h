#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void design();
    void onSerializeClicked();
    void onDeserializeClicked();

private:
    QWidget* centralWidget;
    QHBoxLayout* mainLayout;

    QWidget* formSide;
    QWidget* buttonSide;
    QVBoxLayout* formLayout;
    QVBoxLayout* buttonLayout;

    QLineEdit* name;
    QSpinBox* age;
    QLineEdit* birthDate;

    QPushButton* serializeButton;
    QPushButton* deserializeButton;
};
#endif // MAINWINDOW_H
