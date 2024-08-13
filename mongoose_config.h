#ifndef MONGOOSE_CONFIG_H_
#define MONGOOSE_CONFIG_H_

/******************************************************************************
 * (c) Copyright 2024 Chris Woods
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#define MG_ARCH_WASM_WAMR 15    // WebAssembly WAMR Runtime

#if defined(__wasm__) && defined(WAMR)
#define MG_ARCH MG_ARCH_WASM_WAMR
#endif

#if MG_ARCH == MG_ARCH_WASM_WAMR

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MG_ENABLE_POLL 1

#if defined(MG_ENABLE_EPOLL) && MG_ENABLE_EPOLL
#include <sys/epoll.h>
#elif defined(MG_ENABLE_POLL) && MG_ENABLE_POLL
#include <poll.h>
#else
#include <sys/select.h>
#endif

#include <wasi_socket_ext.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef MG_ENABLE_DIRLIST
#define MG_ENABLE_DIRLIST 1
#endif

#ifndef MG_PATH_MAX
#define MG_PATH_MAX FILENAME_MAX
#endif

#endif // MG_ARCH_WASM

#ifdef __cplusplus
}
#endif

#endif// MONGOOSE_CONFIG_H_

