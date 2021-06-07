#ifndef DATAVIEWDELEGATE_H
#define DATAVIEWDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>


//******************************************************************************************

class DataViewDelegate  :  public QStyledItemDelegate
{

    //Q_OBJECT

    public:

        explicit DataViewDelegate( QObject *parent = nullptr );


        QWidget* createEditor       (           QWidget                 *parent,
                                          const QStyleOptionViewItem    &option,
                                          const QModelIndex             &index      ) const override;

        void  setEditorData         (           QWidget                 *editor,
                                          const QModelIndex             &index      ) const override;

        void  setModelData          (           QWidget                 *editor,
                                                QAbstractItemModel      *model,
                                          const QModelIndex             &index      ) const override;

        void  updateEditorGeometry  (           QWidget                 *editor,
                                          const QStyleOptionViewItem    &option,
                                          const QModelIndex             &index      ) const override;

};

//******************************************************************************************

#endif // DATAVIEWDELEGATE_H
