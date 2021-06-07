#ifndef ORDERTABLEMODEL_H
#define ORDERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>



//*****************************************************************************************************


class OrderTableModel : public QAbstractTableModel
{

        Q_OBJECT

    public:

        OrderTableModel         (             int               rows    = 1,
                                              int               columns = 1,
                                              QObject           *parent = 0                     );

        int         rowCount    (       const QModelIndex       &parent = QModelIndex()         ) const;
        int         columnCount (       const QModelIndex       &parent = QModelIndex()         ) const;

        QVariant    data        (       const QModelIndex       &index,
                                              int               role                            ) const;

        QVariant    headerData  (             int               section,
                                              Qt::Orientation   orientation,
                                              int               role = Qt::DisplayRole          ) const;

        Qt::ItemFlags flags     (       const QModelIndex       &index                          ) const;

        bool        setData     (       const QModelIndex       &index,
                                        const QVariant          &value,
                                              int               role = Qt::EditRole             );

        bool        insertRows  (             int               position,
                                              int               rows,
                                        const QModelIndex       &parent = QModelIndex()         );

        bool        insertColumns(             int              position,
                                              int               columns,
                                        const QModelIndex       &parent = QModelIndex()         );

        bool        removeRows  (             int               position,
                                              int               rows,
                                        const QModelIndex       &parent = QModelIndex()         );

        bool        removeColumns(            int               position,
                                              int               columns,
                                        const QModelIndex       &parent = QModelIndex()         );

    private:

        QList< QStringList >  m_rowList;  // data container

};

//*****************************************************************************************************

#endif // ORDERTABLEMODEL_H
