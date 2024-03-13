#include "mainwindow.h"
#include "user.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget)
    , mainLayout(new QHBoxLayout)
    , formSide(new QWidget)
    , buttonSide(new QWidget)
    , formLayout(new QVBoxLayout)
    , buttonLayout(new QVBoxLayout)
    , name(new QLineEdit)
    , age(new QSpinBox)
    , birthDate(new QLineEdit)
    , serializeButton(new QPushButton("Serialize"))
    , deserializeButton(new QPushButton("Deserialize"))
{
    this->setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    mainLayout->addWidget(formSide, 1);
    mainLayout->addWidget(buttonSide, 1);

    formSide->setLayout(formLayout);
    buttonSide->setLayout(buttonLayout);

    formLayout->addWidget(name);
    formLayout->addWidget(age);
    formLayout->addWidget(birthDate);

    buttonLayout->addWidget(serializeButton);
    buttonLayout->addWidget(deserializeButton);

    connect(serializeButton, &QPushButton::clicked, this, &MainWindow::onSerializeClicked);
    connect(deserializeButton, &QPushButton::clicked, this, &MainWindow::onDeserializeClicked);
    design();
}

void MainWindow::design()
{
    name->setPlaceholderText("Name");
    age->setRange(0, 120);
    birthDate->setPlaceholderText("Birthday date");
}

void MainWindow::onSerializeClicked()
{
    User user;
    user.setName(name->text());
    name->clear();
    user.setAge(age->text().toInt());
    age->clear();
    user.setBirthDate(QDate::fromString(birthDate->text(), "yyyy-MM-dd"));
    birthDate->clear();
    user.serialize();
}

void MainWindow::onDeserializeClicked()
{
    User user ;
    user.deserialize();
    name->setText(user.getName());
    age->setValue(user.getAge());
    birthDate->setText(user.getBirthDate());
}

