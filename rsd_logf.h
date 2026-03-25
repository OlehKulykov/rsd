/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024 - 2025.
 */

#ifndef __RSD_LOGF_H__
#define __RSD_LOGF_H__ 1

#include <stddef.h>     // NULL, nullptr_t, size_t, wchar_t
#include <fcntl.h>      // open

#include "rsd.h"
#include "rsd_errc.h"

RSD_API(int) rsd_logf_open_fpath(const char * RSD_NONNULL filePath) {
    int fd;
    if ( (fd = open(filePath, O_WRONLY)) >= 0 ) {
        if (lseek(fd, 0, SEEK_END) > 0) {
            //_empty = false;
        }
    } else if ( (fd = open(filePath, (int)(O_WRONLY | O_CREAT), (mode_t)(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) < 0 ) {
        return RSD_ERRC_open;
    }
    return 0;
}

#endif // !__RSD_LOGF_H__
