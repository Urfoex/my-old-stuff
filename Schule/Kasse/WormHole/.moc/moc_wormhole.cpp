/****************************************************************************
** WormHole meta object code from reading C++ file 'wormhole.h'
**
** Created: Mon Oct 16 19:00:39 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.6   edited Mar 8 17:43 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../.ui/wormhole.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *WormHole::className() const
{
    return "WormHole";
}

QMetaObject *WormHole::metaObj = 0;
static QMetaObjectCleanUp cleanUp_WormHole( "WormHole", &WormHole::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString WormHole::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WormHole", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString WormHole::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WormHole", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* WormHole::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "Schutz", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"Schutzschild_aktivieren", 1, param_slot_0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Schutzschild_aktivieren(bool)", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"WormHole", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_WormHole.setMetaObject( metaObj );
    return metaObj;
}

void* WormHole::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "WormHole" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool WormHole::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Schutzschild_aktivieren((bool)static_QUType_bool.get(_o+1)); break;
    case 1: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool WormHole::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool WormHole::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool WormHole::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
