#pragma once

#ifndef CPU
#define CPU 1
#endif

#ifndef GPU
#define GPU 0
#endif

#ifndef OPENCV
#define OPENCV 0
#endif

#ifndef TRUST
#define TRUST 0
#endif

#ifndef CUDNN
#define CUDNN 0
#endif

#ifdef _MSC_VER
#include "bw_msposix.h"
#else
#define _NOEXCEPT noexcept
#endif

