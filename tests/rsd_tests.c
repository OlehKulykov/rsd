/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

#include "../rsd_pid.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    pid_t currPid;
    rds_pid_to_fpath("/tmp/rsd_tests.pid", &currPid);
    for (int i = 0; i < 10; i++) {
        fprintf(stdout, "%i ", i);
        fflush(stdout);
        usleep(100);
    }
    int res = 0;
//    std::cout << "Hello, World!\n";
    return res;
}
