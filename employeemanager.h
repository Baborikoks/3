#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <QWidget>

class QTableWidget;
class QPushButton;

class EmployeeManager : public QWidget {
    Q_OBJECT

public:
    EmployeeManager(QWidget* parent = nullptr);

private slots:
    void showAddDialog();
    void showEditDialog();
    void deleteEmployee();

private:
    QTableWidget* table;
};

#endif // EMPLOYEEMANAGER_H
