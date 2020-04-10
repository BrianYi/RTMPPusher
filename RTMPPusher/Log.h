/*
 *  Copyright (C) 2008-2009 Andrej Stepanchuk
 *  Copyright (C) 2009-2010 Howard Chu
 *
 *  This file is part of librtmp.
 *
 *  librtmp is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation; either version 2.1,
 *  or (at your option) any later version.
 *
 *  librtmp is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with librtmp see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 *  http://www.gnu.org/copyleft/lgpl.html
 */
 /*
  * Copyright (C) 2020 BrianYi, All rights reserved
  */

#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#if WIN32
#include <winsock2.h>
#endif

#ifdef _DEBUG
#define _NOHEXSTR
#endif

typedef enum
{
	RTMP_LOGCRIT = 0, RTMP_LOGERROR, RTMP_LOGWARNING, RTMP_LOGINFO,
	RTMP_LOGDEBUG, RTMP_LOGDEBUG2, RTMP_LOGALL
} RTMP_LogLevel;
struct LOG
{
	uint32_t dataSize;
	char *data;
};
extern RTMP_LogLevel RTMP_debuglevel;

typedef void ( RTMP_LogCallback )( int level, const char *fmt, va_list, int isPrint );
void RTMP_LogSetCallback( RTMP_LogCallback *cb );
void RTMP_LogSetOutput( FILE *file );
void RTMP_LogThreadStart( );
void RTMP_LogThreadStop( );
#ifdef __GNUC__
void RTMP_LogPrintf( const char *format, ... ) __attribute__( ( __format__( __printf__, 1, 2 ) ) );
void RTMP_LogStatus( const char *format, ... ) __attribute__( ( __format__( __printf__, 1, 2 ) ) );
void RTMP_Log( int level, const char *format, ... ) __attribute__( ( __format__( __printf__, 2, 3 ) ) );
void RTMP_LogAndPrintf( int level, const char *format, ... );
#else
void RTMP_LogPrintf( const char *format, ... );
void RTMP_LogStatus( const char *format, ... );
void RTMP_Log( int level, const char *format, ... );
void RTMP_LogAndPrintf( int level, const char *format, ... );
#endif
void RTMP_LogHex( int level, const uint8_t *data, unsigned long len );
void RTMP_LogHexStr( int level, const uint8_t *data, unsigned long len );
void RTMP_LogSetLevel( RTMP_LogLevel lvl );
RTMP_LogLevel RTMP_LogGetLevel( void );

