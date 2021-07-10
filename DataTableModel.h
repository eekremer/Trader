#ifndef DATATABLEMODEL_H
#define DATATABLEMODEL_H

#include <QAbstractTableModel>
#include <QTextStream>



//*************************************************************************************


class DataTableModel :  public QAbstractTableModel
{

    //Q_OBJECT

    public:

        //----------------------------------------------------------------------------

        DataTableModel               (          int               rows    = 1,
                                                int               columns = 1,
                                                QObject          *parent  = 0                   );

        //----------------------------------------------------------------------------


        int             rowCount     (    const QModelIndex      &parent  = QModelIndex()       ) const;

        int             columnCount  (    const QModelIndex      &parent  = QModelIndex()       ) const;

        QVariant        data         (    const QModelIndex      &index,
                                                int               role                          ) const;

        bool            setData      (    const QModelIndex      &index,
                                          const QVariant         &value,
                                                int               role = Qt::EditRole           );

        Qt::ItemFlags   flags        (    const QModelIndex      &index                         ) const;


        QVariant        headerData   (          int               section,
                                                Qt::Orientation   orientation,
                                                int               role = Qt::DisplayRole        ) const;

        bool            insertRows   (          int               position,
                                                int               rows,
                                          const QModelIndex      &parent = QModelIndex()        );

        bool            insertColumns(          int               position,
                                                int               columns,
                                          const QModelIndex      &parent = QModelIndex()        );

        bool            removeRows   (          int               position,
                                                int               rows,
                                          const QModelIndex      &parent = QModelIndex()        );

        bool            removeColumns(          int               position,
                                                int               columns,
                                          const QModelIndex       &parent = QModelIndex()       );


        inline
        QTextStream&    qStdout() const
        {
            static QTextStream r{stdout};
            return r;
        }


    private:

        QList< QStringList >   m_rowList;

};

//*************************************************************************************

#endif // DATATABLEMODEL_H
