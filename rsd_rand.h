/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024 - 2025.
 */

#ifndef __RSD_RAND_H__
#define __RSD_RAND_H__ 1

#include <stdlib.h> // arc4random
#include <stdint.h> // uint32_t

#include "rsd.h"

RSD_API(uint32_t) rsd_rand_in_range(const uint32_t lowRange, const uint32_t upRange) {
    return ((arc4random() % (upRange - lowRange + 1)) + lowRange);
}

#endif // !__RSD_RAND_H__
