#pragma once
#include <stdio.h>
#include <string.h>
#include <string>

#if __linux__
#include <stdint-gcc.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <endian.h>
#endif

#if __linux__
#define ntohll		be64toh
#define htonll		htobe64
#define msleep(ms)	usleep(1000 * ms)
#define WSAGetLastError() errno
#endif

const uint32_t RECV_BUF_SIZE = 10 * 1024u;
const uint32_t SEND_BUF_SIZE = 10 * 1024u;

inline uint64_t get_timestamp_ms( )
{
	struct timeval tv;
	gettimeofday( &tv, nullptr );
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


#if WIN32
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif