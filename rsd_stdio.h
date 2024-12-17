/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#ifndef __RSD_STDIO_H__
#define __RSD_STDIO_H__ 1

#include <stdio.h>  // freopen
#include <unistd.h> // close

#include "rsd.h"
#include "rsd_errc.h"

RSD_API(int) rsd_stdio_to_dev_null(void) {
    if ((close(STDIN_FILENO) != 0) ||
        (close(STDOUT_FILENO) != 0) ||
        (close(STDERR_FILENO) != 0)) return RSD_ERRC_close;
    const char * dnPath = "/dev/null";
    if (!freopen(dnPath, "r", stdin) ||
        !freopen(dnPath, "w", stdout) ||
        !freopen(dnPath, "w", stderr)) return RSD_ERRC_freopen;
    return 0;
}

#endif // !__RSD_STDIO_H__
