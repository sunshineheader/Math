#pragma once

#define _USE_MATH_DEFINES 
#include <math.h>


namespace Math{

#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / M_PI))

}