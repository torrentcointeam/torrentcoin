#ifndef TorrentPage_H
#define TorrentPage_H

#include <QDialog>
#include <QtSql>
#include <QThread>

namespace Ui {
    class TorrentPage;
}
class TorrentTableModel;
class ClientModel;

QT_BEGIN_NAMESPACE
class QTableView;
class QItemSelection;
class QSortFilterProxyModel;
class QMenu;
class QModelIndex;
QT_END_NAMESPACE

/** Widget that shows a list of sending or receiving addresses.
  */
class TorrentPage : public QDialog
{
    Q_OBJECT

public:

    explicit TorrentPage(QWidget *parent = 0);
    ~TorrentPage();

    void setModel(TorrentTableModel *model);
    void setClientModel(ClientModel *model);

    const QString &getReturnValue() const { return returnValue; }
    void startExecutor();

public slots:
    void refreshTorrentTable();
private:
    Ui::TorrentPage *ui;
    TorrentTableModel *model;
    ClientModel *clientModel;
    QString returnValue;
    QSortFilterProxyModel *proxyModel;
    QMenu *contextMenu;
    QAction *deleteAction;
    QString newAddressToSelect;
    


signals:
    void doubleClicked(const QModelIndex&);
    void updateRequest();
    void stopExecutor();

private slots:
    void searchButtonClicked();
    void showDetails();
private:
    

};

#endif // TorrentPage_H
