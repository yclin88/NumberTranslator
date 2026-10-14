#ifndef NUMTRANSDLG_H
#define NUMTRANSDLG_H

#include <QDialog>
class QLineEdit;
class NumTransDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NumTransDlg(QWidget *parent = nullptr);
    ~NumTransDlg() override;
private:
    QLineEdit* decEdit;
    QLineEdit* hexEdit;
    QLineEdit* binEdit;
};
#endif // NUMTRANSDLG_H
