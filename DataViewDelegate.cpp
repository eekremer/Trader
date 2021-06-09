
#include "DataViewDelegate.h"

#include <QSpinBox>


//******************************************************************************************

DataViewDelegate::DataViewDelegate( QObject  *parent )
    :  QStyledItemDelegate( parent )
{

}

//******************************************************************************************

//

QWidget* DataViewDelegate::createEditor(            QWidget                 *parent,
                                              const QStyleOptionViewItem&   /* option */,
                                              const QModelIndex&            /* index */     ) const

{

    QSpinBox *editor = new QSpinBox( parent );

    //editor->setFrame    ( true );
    editor->setMinimum  (     0 );
    editor->setMaximum  (   100 );

    return editor;

}

//******************************************************************************************

// current data in that cell

void DataViewDelegate::setEditorData(           QWidget                 *editor,
                                          const QModelIndex             &index          ) const
{

    int value = index.model()->data( index, Qt::EditRole ).toInt();

    QSpinBox *spinBox = static_cast< QSpinBox* >( editor );

    spinBox->setValue( value );

}

//******************************************************************************************

// when you're done modifying data, this function is called to return data back in the model

void DataViewDelegate::setModelData(            QWidget                 *editor,
                                                QAbstractItemModel      *model,
                                          const QModelIndex             &index          ) const
{

    QSpinBox *spinBox = static_cast< QSpinBox* >( editor );

    spinBox->interpretText();

    int value = spinBox->value();

    model->setData( index, value, Qt::EditRole );

}

//******************************************************************************************

// it allows you to set where the obj (spinbox) will be displayed in the cell

void DataViewDelegate::updateEditorGeometry(            QWidget                  *editor,
                                                  const QStyleOptionViewItem     &option,
                                                  const QModelIndex&    /* index */         ) const

{

    editor->setGeometry( option.rect );

}

//******************************************************************************************
