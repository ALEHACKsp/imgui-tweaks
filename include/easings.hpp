#pragma once

#ifndef EASINGS_IMGUITWEAKER
#define EASINGS_IMGUITWEAKER

#ifndef PI
#define PI 3.1415926545
#endif

#include <algorithm>

namespace ImEasings {
    float InSine(float t) {
        return sin(1.5707963 * t);
    }

    float OutSine(float t) {
        return 1 + sin(1.5707963 * (--t));
    }

    float InOutSine(float t) {
        return 0.5 * (1 + sin(3.1415926 * (t - 0.5)));
    }

    float InQuad(float t) {
        return t * t;
    }

    float OutQuad(float t) {
        return t * (2 - t);
    }

    float InOutQuad(float t) {
        return t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1;
    }

    float InCubic(float t) {
        return t * t * t;
    }

    float OutCubic(float t) {
        return 1 + (--t) * t * t;
    }

    float InOutCubic(float t) {
        return t < 0.5 ? 4 * t * t * t : 1 + (--t) * (2 * (--t)) * (2 * t);
    }

    float InQuart(float t) {
        t *= t;
        return t * t;
    }

    float OutQuart(float t) {
        t = (--t) * t;
        return 1 - t * t;
    }

    float InOutQuart(float t) {
        if (t < 0.5) {
            t *= t;
            return 8 * t * t;
        }
        else {
            t = (--t) * t;
            return 1 - 8 * t * t;
        }
    }

    float InQuint(float t) {
        float t2 = t * t;
        return t * t2 * t2;
    }

    float OutQuint(float t) {
        float t2 = (--t) * t;
        return 1 + t * t2 * t2;
    }

    float InOutQuint(float t) {
        float t2;
        if (t < 0.5) {
            t2 = t * t;
            return 16 * t * t2 * t2;
        }
        else {
            t2 = (--t) * t;
            return 1 + 16 * t * t2 * t2;
        }
    }

    float InExpo(float t) {
        return (pow(2, 8 * t) - 1) / 255;
    }

    float OutExpo(float t) {
        return 1 - pow(2, -8 * t);
    }

    float InOutExpo(float t) {
        if (t < 0.5) {
            return (pow(2, 16 * t) - 1) / 510;
        }
        else {
            return 1 - 0.5 * pow(2, -16 * (t - 0.5));
        }
    }

    float InCirc(float t) {
        return 1 - sqrt(1 - t);
    }

    float OutCirc(float t) {
        return sqrt(t);
    }

    float InOutCirc(float t) {
        if (t < 0.5) {
            return (1 - sqrt(1 - 2 * t)) * 0.5;
        }
        else {
            return (1 + sqrt(2 * t - 1)) * 0.5;
        }
    }

    float InBack(float t) {
        return t * t * (2.70158 * t - 1.70158);
    }

    float OutBack(float t) {
        return 1 + (--t) * t * (2.70158 * t + 1.70158);
    }

    float InOutBack(float t) {
        if (t < 0.5) {
            return t * t * (7 * t - 2.5) * 2;
        }
        else {
            return 1 + (--t) * t * 2 * (7 * t + 2.5);
        }
    }

    float InElastic(float t) {
        float t2 = t * t;
        return t2 * t2 * sin(t * PI * 4.5);
    }

    float OutElastic(float t) {
        float t2 = (t - 1) * (t - 1);
        return 1 - t2 * t2 * cos(t * PI * 4.5);
    }

    float InOutElastic(float t) {
        float t2;
        if (t < 0.45) {
            t2 = t * t;
            return 8 * t2 * t2 * sin(t * PI * 9);
        }
        else if (t < 0.55) {
            return 0.5 + 0.75 * sin(t * PI * 4);
        }
        else {
            t2 = (t - 1) * (t - 1);
            return 1 - 8 * t2 * t2 * sin(t * PI * 9);
        }
    }

    float InBounce(float t) {
        return pow(2, 6 * (t - 1)) * abs(sin(t * PI * 3.5));
    }

    float OutBounce(float t) {
        return 1 - pow(2, -6 * t) * abs(cos(t * PI * 3.5));
    }

    float InOutBounce(float t) {
        if (t < 0.5) {
            return 8 * pow(2, 8 * (t - 1)) * abs(sin(t * PI * 7));
        }
        else {
            return 1 - 8 * pow(2, -8 * t) * abs(sin(t * PI * 7));
        }
    }
}

#endif