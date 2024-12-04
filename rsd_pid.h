/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#ifndef __RSD_PID_H__
#define __RSD_PID_H__ 1

#include <stdio.h>      // fopen
#include <stdlib.h>     // atoull
#include <inttypes.h>   // PRIu64
#include <unistd.h>     // getpid

#include "rsd.h"
#include "rsd_errc.h"

RSD_API(int) rds_pid_to_fpath(const char * RSD_NONNULL filePath, pid_t * RSD_NULLABLE currPid) {
    const pid_t p = getpid();
    if (p <= 0) return RSD_ERRC_getpid;
    if (currPid) { *currPid = p; }
    char buff[32];
    const int len = snprintf(buff, 32, "%" PRIu64, (uint64_t)p);
    if (len <= 0) return RSD_ERRC_snprintf;
    FILE * f = fopen(filePath, "w+b");
    if (!f) return RSD_ERRC_fopen;
    int res = 0;
    if (fwrite(buff, len, 1, f) != 1) { res = RSD_ERRC_fwrite; }
    fclose(f);
    return res;
}

RSD_API(int) rds_pid_from_fpath(const char * RSD_NONNULL filePath, pid_t * RSD_NONNULL storedPid) {
    *storedPid = 0;
    FILE * f = fopen(filePath, "rb");
    if (!f) return RSD_ERRC_fopen;
    char buff[32];
    const size_t r = fread(buff, 1, 32, f);
    fclose(f);
    if (r == 0) return 0;
    if (r < 32) {
        buff[r] = 0;
        const long long pid = strtoll(buff, NULL, 10);
        if (pid >= 0) {
            *storedPid = (pid_t)pid;
            return 0;
        }
    }
    return __LINE__;
}

#endif // !__RSD_PID_H__
