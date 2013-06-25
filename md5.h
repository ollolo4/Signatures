#ifndef MD5_H
#define MD5_H

#include <QFile>
#include <iostream>
#include <QByteArray>
#include <QtEndian>
#include <QTemporaryFile>

#define SIZE_OF_BLOCK 64

using namespace std;

QString md5( char *name );

#endif // MD5_H
