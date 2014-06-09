#ifndef TorrentTableModel_H
#define TorrentTableModel_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QtSql>



class TorrentTablePriv;
class WalletModel;

/**
   Qt model of the address book in the core. This allows views to access and modify the address book.
 */
class TorrentTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TorrentTableModel(WalletModel *parent = 0);
    ~TorrentTableModel();

    enum ColumnIndex {
        Title = 0,
        Address,
        Amount
    };

    enum RoleIndex {
        /** Type of transaction */
        TypeRole = Qt::UserRole,
        /** Date and time this transaction was created */
        TorrentRole
    };

    /** @name Methods overridden from QAbstractTableModel
        @{*/
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column, const QModelIndex & parent) const;

    void refreshTorrentTable();    

private:
    WalletModel *walletModel;
    TorrentTablePriv *priv;
    QStringList columns;
    QSqlDatabase db;


    
public slots:

    friend class TorrentTablePriv;
};

#endif // TorrentTableModel_H
