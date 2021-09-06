
#include "OrderTableModel.h"


//********************************************************************************

/*!
    Constructs a table model with at least one row and one column.
*/

OrderTableModel::OrderTableModel(       int         rows,
                                        int         columns,
                                        QObject    *parent         )

    :  QAbstractTableModel( parent )

{

    QStringList newList;

    for ( int column = 0; column < qMax( 1, columns ); ++column )
    {
        newList.append( "" );
    }

    for ( int row = 0; row < qMax( 1, rows ); ++row )
    {
        m_rowList.append( newList );
    }

}

//********************************************************************************

/*!
    Returns the number of items in the row list as the number of rows
    in the model.
*/

int OrderTableModel::rowCount(  const QModelIndex&  /*parent*/ ) const
{

    return m_rowList.size();

}

//********************************************************************************

/*!
    Returns the number of items in the first list item as the number of
    columns in the model. All rows should have the same number of columns.
*/

int OrderTableModel::columnCount(  const QModelIndex&  /*parent*/ ) const
{

    return m_rowList[ 0 ].size();

}

//********************************************************************************

/*!
    QVariant QAbstractItemModel::data(      const QModelIndex&  index,
                                                  int           role = Qt::DisplayRole    ) const

    Returns the data stored under the given role for the item referred to by the index.
    Note: If you do not have a value to return, return an invalid QVariant instead of returning 0.
*/

QVariant OrderTableModel::data(      const QModelIndex&     index,
                                           int              role       ) const
{

    if ( !index.isValid() )
        return QVariant();

    if ( role == Qt::DisplayRole )
        return m_rowList[ index.row() ][ index.column() ];
    else
        return QVariant();

}

//********************************************************************************

/*!
    Returns the appropriate header string depending on the orientation of
    the header and the section. If anything other than the display role is
    requested, we return an invalid variant.
*/

QVariant OrderTableModel::headerData(       int                 section,
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
                return "Id";
            case 1:
                return "Timestamp";
            case 2:
                return "Symbol/Exchange";  // Ticker/Exchange. For instance IBM|SMART
            case 3:
                return "Action";    // order action: Buy or Sell
            case 4:
                return "Type";      // order type: LMT, MKT, MTL...
            case 5:
                return "Details";   // if LMT, limit price will be displayed
            case 6:
                return "Quantity";
            case 7:
                return "Status";
            case 8:
                return "Fill Px";   // the price an order is filled or completed at
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

//********************************************************************************

/*!
    Returns an appropriate value for the item's flags. Valid items are
    enabled, selectable, and editable.
*/

Qt::ItemFlags OrderTableModel::flags(  const QModelIndex  &index  ) const
{

    if ( !index.isValid() )
        return Qt::ItemIsEnabled;

    return Qt::NoItemFlags;  //Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;

}

//********************************************************************************

/*!
    Changes an item in the model, but only if the following conditions
    are met:

    * The index supplied is valid.
    * The role associated with editing text is specified.

    The dataChanged() signal is emitted if the item is changed.
*/

bool OrderTableModel::setData(        const QModelIndex   &index,
                                      const QVariant      &value,
                                            int           role            )
{

    if ( !index.isValid() || role != Qt::EditRole )
        return false;

    m_rowList[ index.row() ][ index.column() ] = value.toString();

    // signal for its connected views to update their displays
    emit dataChanged( index, index );

    return true;

}

//********************************************************************************

/*!
    Inserts a number of rows into the model at the specified position.
*/

bool OrderTableModel::insertRows(            int             position,
                                        int             rows,
                                  const QModelIndex     &parent         )
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

//********************************************************************************

/*!
    Inserts a number of columns into the model at the specified position.
    Each entry in the list is extended in turn with the required number of
    empty strings.
*/

bool OrderTableModel::insertColumns(             int             position,
                                            int             columns,
                                      const QModelIndex     &parent         )
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

//********************************************************************************

/*!
    Removes a number of rows from the model at the specified position.
*/

bool OrderTableModel::removeRows(            int             position,
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

//********************************************************************************

/*!
    Removes a number of columns from the model at the specified position.
    Each row is shortened by the number of columns specified.
*/

bool OrderTableModel::removeColumns(            int             position,
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

//********************************************************************************
