/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#ifndef __RSD_PID_H__
#define __RSD_PID_H__ 1

#include <stdio.h>      // fopen
#include <inttypes.h>   // PRIu64
#include <unistd.h>     // getpid

#include "rsd.h"
#include "rsd_errc.h"

RSD_API(int) rds_pid_to_fpath(const char * RSD_NONNULL filePath) {
    const pid_t p = getpid();
    if (p <= 0) return RSD_ERRC_getpid;
    FILE * f = fopen(filePath, "w+b");
    if (!f) return RSD_ERRC_fopen_wb;
    char buff[16];
//    PRIu64;
//    snprintf(buff, 16, "%ll");
    
//    PRIX8;
    
    fclose(f);
    return 0;
}

#endif // !__RSD_PID_H__
