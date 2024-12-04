/*
 * Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
 */

#ifndef __RSD_H__
#define __RSD_H__ 1

#if !defined(DEBUG) && defined(_DEBUG)
#  define DEBUG 1
#endif

#if defined(DEBUG) && defined(NDEBUG)
#  undef DEBUG
#endif

#define RSD_API(RETURN_TYPE) static inline RETURN_TYPE

#if defined(__clang__)
#  define RSD_NULLABLE _Nullable
#  define RSD_NONNULL _Nonnull
#else
#  define RSD_NULLABLE
#  define RSD_NONNULL
#endif

#endif // !__RSD_H__
