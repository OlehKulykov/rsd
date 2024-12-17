/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#ifndef __RSD_BUFF_H__
#define __RSD_BUFF_H__ 1

#include <stddef.h>     // NULL, nullptr_t, size_t, wchar_t
#include <stdlib.h>     // malloc, realloc
#include <inttypes.h>
#include <string.h>

#include "rsd.h"
#include "rsd_errc.h"

struct rsd_buff {
#if defined(DEBUG)
    union {
        void * RSD_NULLABLE ptr;
        char * RSD_NULLABLE str;
        uint8_t * RSD_NULLABLE buf;
    };
#else
    void * RSD_NULLABLE ptr;
#endif
    uint32_t len;
    uint32_t cap;
};

RSD_API(struct rsd_buff) rsd_buff_init(const size_t cap) {
    struct rsd_buff buff;
    buff.len = 0;
    if ( (cap > 0) && (buff.ptr = malloc(cap)) ) {
        buff.cap = (uint32_t)cap;
        return buff;
    }
    buff.ptr = NULL;
    buff.cap = 0;
    return buff;
}

RSD_API(int) rsd_buff_reserve(struct rsd_buff * RSD_NONNULL buff, const size_t cap) {
    if (buff->ptr) {
        void * m = realloc(buff->ptr, cap);
        if (m) {
            buff->ptr = m;
            buff->cap = (uint32_t)cap;
            return 0;
        }
        return RSD_ERRC_realloc;
    } else if ( (buff->ptr = malloc(cap)) ) {
        buff->len = 0;
        buff->cap = (uint32_t)cap;
        return 0;
    }
    buff->cap = buff->len = 0;
    return RSD_ERRC_malloc;
}

RSD_API(void) rsd_buff_free(struct rsd_buff * RSD_NULLABLE buff) {
    if (buff) {
        if (buff->ptr) free(buff->ptr);
        buff->ptr = NULL;
        buff->cap = buff->len = 0;
    }
}

#endif // !__RSD_BUFF_H__
