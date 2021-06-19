#ifndef DATAVIEWDELEGATE_H
#define DATAVIEWDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>

/*

    In Qt, the model behaves the same as it does for classic MVC. But instead of a controller,
    Qt uses a slightly different abstraction: the delegate.

    The delegate is used to provide fine control over how items are rendered and edited. Qt provides
    a default delegate for every type of view.

*/

//******************************************************************************************

class DataViewDelegate  :  public QStyledItemDelegate
{

    //Q_OBJECT

    public:

        explicit DataViewDelegate( QObject *parent = nullptr );


        QWidget*    createEditor            (           QWidget                 *parent,
                                                  const QStyleOptionViewItem    &option,
                                                  const QModelIndex             &index      ) const override;
/*
        void        paint                   (           QPainter                *painter,
                                                  const QStyleOptionViewItem    &option,
                                                  const QModelIndex             &index      ) const override;

*/
        void        setEditorData           (           QWidget                 *editor,
                                                  const QModelIndex             &index      ) const override;

        void        setModelData            (           QWidget                 *editor,
                                                        QAbstractItemModel      *model,
                                                  const QModelIndex             &index      ) const override;

        QSize       sizeHint                (     const QStyleOptionViewItem    &option,
                                                  const QModelIndex             &index      ) const override;
/*
        void        updateEditorGeometry    (           QWidget                 *editor,
                                                  const QStyleOptionViewItem    &option,
                                                  const QModelIndex             &index      ) const override;
*/

};

//******************************************************************************************

#endif // DATAVIEWDELEGATE_H
