/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

#include "../rsd_buff.h"
#include "../rsd_errc.h"
#include "../rsd_json.h"
#include "../rsd_logf.h"
#include "../rsd_path.h"
#include "../rsd_pid.h"
#include "../rsd_stdio.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    pid_t pid1, pid2;
    rds_pid_to_fpath("/tmp/rsd_tests.pid", &pid1);
    rds_pid_from_fpath("/tmp/rsd_tests.pid", &pid2);
    struct rsd_buff buff = rsd_buff_init(0);
    rsd_buff_reserve(&buff, 16);
    rsd_buff_reserve(&buff, 32);
    rsd_buff_free(&buff);
    for (int i = 0; i < 10; i++) {
        fprintf(stdout, "%i ", i);
        fflush(stdout);
        usleep(100);
    }
    int res = rsd_stdio_to_dev_null();
//    std::cout << "Hello, World!\n";
    return res;
}
