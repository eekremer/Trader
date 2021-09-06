#ifndef DIFFTABLEMODEL_H
#define DIFFTABLEMODEL_H

#include <QAbstractTableModel>
#include <QTextStream>




//*************************************************************************************


class DiffTableModel    :   public  QAbstractTableModel
{

    //Q_OBJECT

    public:

        //----------------------------------------------------------------------------

        DiffTableModel               (          int               rows    = 1,
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

#endif // DIFFTABLEMODEL_H
