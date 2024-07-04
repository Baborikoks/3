   #include "employeemanager.h"

#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

EmployeeManager::EmployeeManager(QWidget* parent) : QWidget(parent) {
    // Создание таблицы
    table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Имя", "Фамилия", "Должность", "Зарплата"});

    // Создание кнопок
    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* editButton = new QPushButton("Редактировать");
    QPushButton* deleteButton = new QPushButton("Удалить");

    // Компоновка элементов
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(table);
    layout->addWidget(addButton);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);

    // Подключение сигналов
    connect(addButton, &QPushButton::clicked, this, &EmployeeManager::showAddDialog);
    connect(editButton, &QPushButton::clicked, this, &EmployeeManager::showEditDialog);
    connect(deleteButton, &QPushButton::clicked, this, &EmployeeManager::deleteEmployee);
}

void EmployeeManager::showAddDialog() {
    QDialog dialog(this);
    dialog.setWindowTitle("Добавить сотрудника");

    QLineEdit* nameEdit = new QLineEdit(&dialog);
    QLineEdit* surnameEdit = new QLineEdit(&dialog);
    QLineEdit* positionEdit = new QLineEdit(&dialog);
    QLineEdit* salaryEdit = new QLineEdit(&dialog);

    QPushButton* okButton = new QPushButton("OK", &dialog);
    QPushButton* cancelButton = new QPushButton("Отмена", &dialog);

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->addWidget(new QLabel("Имя:"));
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("Фамилия:"));
    layout->addWidget(surnameEdit);
    layout->addWidget(new QLabel("Должность:"));
    layout->addWidget(positionEdit);
    layout->addWidget(new QLabel("Зарплата:"));
    layout->addWidget(salaryEdit);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        // Добавление новой строки в таблицу
        int rowCount = table->rowCount();
        table->insertRow(rowCount);
        table->setItem(rowCount, 0, new QTableWidgetItem(nameEdit->text()));
        table->setItem(rowCount, 1, new QTableWidgetItem(surnameEdit->text()));
        table->setItem(rowCount, 2, new QTableWidgetItem(positionEdit->text()));
        table->setItem(rowCount, 3, new QTableWidgetItem(salaryEdit->text()));
    }
}

void EmployeeManager::showEditDialog() {
    // Реализация диалогового окна для редактирования сотрудника
    // Получение выбранной строки
    int currentRow = table->currentRow();
    if (currentRow == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите сотрудника для редактирования.");
        return;
    }

    // Диалоговое окно для редактирования сотрудника
    QDialog dialog(this);
    dialog.setWindowTitle("Редактировать сотрудника");

    QLineEdit* nameEdit = new QLineEdit(&dialog);
    QLineEdit* surnameEdit = new QLineEdit(&dialog);
    QLineEdit* positionEdit = new QLineEdit(&dialog);
    QLineEdit* salaryEdit = new QLineEdit(&dialog);

    // Заполнение полей текущими данными
    nameEdit->setText(table->item(currentRow, 0)->text());
    surnameEdit->setText(table->item(currentRow, 1)->text());
    positionEdit->setText(table->item(currentRow, 2)->text());
    salaryEdit->setText(table->item(currentRow, 3)->text());

    QPushButton* okButton = new QPushButton("OK", &dialog);
    QPushButton* cancelButton = new QPushButton("Отмена", &dialog);

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->addWidget(new QLabel("Имя:"));
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("Фамилия:"));
    layout->addWidget(surnameEdit);
    layout->addWidget(new QLabel("Должность:"));
    layout->addWidget(positionEdit);
    layout->addWidget(new QLabel("Зарплата:"));
    layout->addWidget(salaryEdit);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);


    if (dialog.exec() == QDialog::Accepted) {
        // Обновление данных в таблице
        table->setItem(currentRow, 0, new QTableWidgetItem(nameEdit->text()));
        table->setItem(currentRow, 1, new QTableWidgetItem(surnameEdit->text()));
        table->setItem(currentRow, 2, new QTableWidgetItem(positionEdit->text()));
        table->setItem(currentRow, 3, new QTableWidgetItem(salaryEdit->text()));
    }
}

void EmployeeManager::deleteEmployee() {
    // Реализация удаления сотрудника
    // Получение выбранной строки
    int currentRow = table->currentRow();
    if (currentRow == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите сотрудника для удаления.");
        return;
    }

    // Удаление выбранной строки
    table->removeRow(currentRow);
}
