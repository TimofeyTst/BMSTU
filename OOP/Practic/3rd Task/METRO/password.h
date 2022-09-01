#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = nullptr);
    ~Password();

private slots:
    void closeEvent(QCloseEvent *event);
    void on_pushButton_clicked();
//
signals:
    void give_access();
    void show_first();
//
private:
    Ui::Password *ui;
};

#endif // PASSWORD_H
