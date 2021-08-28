#include "BracketTableModel.h"

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include <QFont>
#include <QBrush>
#include <QDebug>



//******************************************************************************************

BracketTableModel::BracketTableModel(       int          rows,
                                            int          columns,
                                            QObject     *parent                   )

    :   QAbstractTableModel( parent )

{

    QStringList list;

    for ( int column = 0; column < qMax( 1, columns ); ++column )
    {
        list.append( "NA" );
    }

    for ( int row = 0; row < qMax( 1, rows ); ++row )
    {
        m_rowList.append( list );
    }

}

//******************************************************************************************

/*!
    Returns the number of items in the row list as the number of rows
    in the model.
*/

int  BracketTableModel::rowCount(  const QModelIndex&  /*parent*/ ) const
{

    return 2; //m_rowList.size();

}

//******************************************************************************************

/*!
    Returns the number of items in the first list item as the number of
    columns in the model. All rows should have the same number of columns.
*/

int  BracketTableModel::columnCount(  const QModelIndex&  /*parent*/ ) const
{

    return m_rowList[ 0 ].size();

}

//******************************************************************************************

/*!
    QVariant QAbstractItemModel::data(      const QModelIndex&  index,
                                                  int           role = Qt::DisplayRole    ) const

    Returns the data stored under the given role for the item referred to by the index.
    Note: If you do not have a value to return, return an invalid QVariant instead of returning 0.
*/

QVariant  BracketTableModel::data(        const QModelIndex     &index,
                                                int              role       ) const
{

    // in addition to controlling what text the view displays,
    // the model also controls the text's appearance


    int row = index.row();
    int col = index.column();

    // generate a log message when this method gets called
    qDebug() << QString( "row %1, col%2, role %3" ).arg( row ).arg( col ).arg( role );


    if ( !index.isValid() )
        return QVariant();


    switch ( role )         // see this page:  https://doc.qt.io/qt-5/qt.html
    {

        //-----------------------------------------------

        case Qt::DisplayRole:

            //return (   m_rowList[ index.row() ][ index.column() ].toInt()   );

            if ( index.row() == 0 && index.column() == 0 )
            {

                qInfo(          "within ...DataTableModel::data() \n"              );

                qStdout() <<  m_rowList[ index.row() ][ index.column() ] << Qt::endl;

            }

            return (     m_rowList[ index.row() ][ index.column() ]     );

        //-----------------------------------------------

        case Qt::FontRole:

            if ( row == 0 )
            {

                QFont boldFont;

                boldFont.setBold( false );

                return boldFont;
            }

        break;

        //-----------------------------------------------

        case Qt::BackgroundRole:

            if ( ( row == 0 || row == 1 ) && ( col == 0 || col == 1 || col == 2 ) )     // change background only for cell( 0, 1 )
            {

                return QBrush( Qt::black );


            }

            if ( row == 0 && ( col == 3 ||  col == 4 ) )     // change background only for cell( 0, 1 )
            {

                return QBrush( Qt::red );

                // here goes RED or GREEN depending on its previous closing

            }

        break;

        //-----------------------------------------------

        case Qt::ForegroundRole:

            if ( row == 0 && ( col == 0 ||  col == 1 || col == 2 ) )     // change background only for cell( 0, 1 )
            {

                return QBrush(  Qt::white  );

            }

        break;

        //-----------------------------------------------

        // Qt::SizeHintRole

        case Qt::TextAlignmentRole:

            if ( row == 0 )     // change text alignment only for cell( 0, 1 )
            {

                return int( Qt::AlignRight | Qt::AlignVCenter  );

            }

        break;

        //-----------------------------------------------
/*
        case Qt::CheckStateRole:

            if ( row == 0 && col == 0 )     // add a checkbox to cell( 0, 0 )
            {

                return Qt::Checked;

            }

        break;
*/
        //-----------------------------------------------

    }

    return QVariant();

}

//******************************************************************************************

/*!
    Returns the appropriate header string depending on the orientation of
    the header and the section. If anything other than the display role is
    requested, we return an invalid variant.
*/

QVariant  BracketTableModel::headerData(        int                 section,
                                                Qt::Orientation     orientation,
                                                int                 role            ) const
{

    if ( role != Qt::DisplayRole )
        return QVariant();

    if ( orientation == Qt::Horizontal )
    {

        switch ( section )
        {

            case 0:
                return "USD/stock";
            case 1:
                return "%";                 // Ticker/Exchange. For instance IBM|SMART
            case 2:
                return "increm. P&L";       // order action: Buy or Sell
            default:
                return QString( "" );

        }

    }
    else if ( orientation == Qt::Vertical )
    {

        switch ( section )
        {

            case 0:
                return "Take a profit";
            case 1:
                return "Stop loss";
            default:
                return QString( "" );

        }

    }
    else
    {
        //return QString( "Row %1"    ).arg( section );
        return "";
    }

}

//******************************************************************************************

/*!
    Returning Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled is enough
    to show an editor that a cell can be selected
*/

Qt::ItemFlags  BracketTableModel::flags(  const QModelIndex  &index  ) const
{

    if ( !index.isValid() )
        return Qt::ItemIsEnabled;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;

}

//******************************************************************************************

/*!
    Changes an item in the model, but only if the following conditions
    are met:

    * The index supplied is valid.
    * The role associated with editing text is specified.

    The dataChanged() signal is emitted if the item is changed.
*/

bool BracketTableModel::setData(        const QModelIndex  &index,
                                        const QVariant     &value,
                                              int           role            )
{

    if ( !index.isValid() || role != Qt::EditRole )
        return false;

    m_rowList[ index.row() ][ index.column() ] = value.toString();

    qInfo(      "within ...DataTableModel::setData() \n"        );

    qStdout() <<  m_rowList[ index.row() ][ index.column() ] << Qt::endl;

    // signal for its connected views to update their displays
    emit dataChanged( index, index );

    return true;

}

//******************************************************************************************

/*!
    Inserts a number of rows into the model at the specified position.
*/

bool  BracketTableModel::insertRows(        int             position,
                                            int             rows,
                                      const QModelIndex    &parent         )
{

    int columns = columnCount();

    beginInsertRows(            parent,
                                position,
                                position + rows - 1         );

    for ( int row = 0; row < rows; ++row )
    {

        QStringList items;

        for ( int column = 0; column < columns; ++column )
            items.append( "" );

        m_rowList.insert( position, items );

    }

    endInsertRows();

    return true;

}

//******************************************************************************************

/*!
    Inserts a number of columns into the model at the specified position.
    Each entry in the list is extended in turn with the required number of
    empty strings.
*/

bool  BracketTableModel::insertColumns(         int             position,
                                                int             columns,
                                          const QModelIndex    &parent         )
{


    int rows = rowCount();

    beginInsertColumns(             parent,
                                    position,
                                    position + columns - 1          );

    for ( int row = 0; row < rows; ++row )
    {

        for ( int column = position; column < columns; ++column )
        {

            m_rowList[ row ].insert( position, "" );

        }

    }

    endInsertColumns();

    return true;

}

//******************************************************************************************

/*!
    Removes a number of rows from the model at the specified position.
*/

bool  BracketTableModel::removeRows(        int             position,
                                            int             rows,
                                      const QModelIndex     &parent         )
{

    beginRemoveRows(            parent,
                                position,
                                position + rows - 1             );

    for ( int row = 0; row < rows; ++row )
    {

        m_rowList.removeAt( position );

    }

    endRemoveRows();

    return true;

}

//******************************************************************************************

/*!
    Removes a number of columns from the model at the specified position.
    Each row is shortened by the number of columns specified.
*/

bool  BracketTableModel::removeColumns(         int             position,
                                                int             columns,
                                          const QModelIndex&    parent         )
{

    int rows = rowCount();

    beginRemoveColumns(             parent,
                                    position,
                                    position + columns - 1          );

    for ( int row = 0; row < rows; ++row )
    {

        for ( int column = 0; column < columns; ++column )
        {

            m_rowList[ row ].removeAt( position );

        }

    }

    endRemoveColumns();

    return true;

}

//******************************************************************************************
