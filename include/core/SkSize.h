

#ifndef SkSize_DEFINED
#define SkSize_DEFINED

template <typename T> struct SkTSize {
    T fWidth;
    T fHeight;

    void set(T w, T h) {
        fWidth = w;
        fHeight = h;
    }

    /** Returns true iff fWidth == 0 && fHeight == 0
     */
    bool isZero() const {
        return 0 == fWidth && 0 == fHeight;
    }

    /** Returns true if either widht or height are <= 0 */
    bool isEmpty() const {
        return fWidth <= 0 || fHeight <= 0;
    }
    
    /** Set the width and height to 0 */
    void setEmpty() {
        fWidth = fHeight = 0;
    }
    
    /** If width or height is < 0, it is set to 0 */
    void clampNegToZero() {
        if (fWidth < 0) {
            fWidth = 0;
        }
        if (fHeight < 0) {
            fHeight = 0;
        }
    }
};

template <typename T>
static inline bool operator==(const SkTSize<T>& a, const SkTSize<T>& b) {
    return a.fWidth == b.fWidth && a.fHeight == b.fHeight;
}

template <typename T>
static inline bool operator!=(const SkTSize<T>& a, const SkTSize<T>& b) {
    return !(a == b);
}

///////////////////////////////////////////////////////////////////////////////

struct SkISize : public SkTSize<int32_t> {};

#include "SkScalar.h"

struct SkSize : public SkTSize<SkScalar> {
    SkSize& operator=(const SkISize& src) {
        this->set(SkIntToScalar(src.fWidth), SkIntToScalar(src.fHeight));
        return *this;
    }

    SkISize round() const {
        SkISize s;
        s.set(SkScalarRound(fWidth), SkScalarRound(fHeight));
        return s;
    }
    
    SkISize ceil() const {
        SkISize s;
        s.set(SkScalarCeil(fWidth), SkScalarCeil(fHeight));
        return s;
    }

    SkISize floor() const {
        SkISize s;
        s.set(SkScalarFloor(fWidth), SkScalarFloor(fHeight));
        return s;
    }
};

#endif