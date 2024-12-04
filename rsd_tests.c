/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    for (int i = 0; i < 9000; i++) {
        fprintf(stdout, "%i ", i);
        fflush(stdout);
        usleep(9000);
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
