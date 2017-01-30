#ifndef __DLIBEXTERN_STD_VECTOR__
#define __DLIBEXTERN_STD_VECTOR__

#include "DlibExtern.h"
#include <vector>

#pragma region Rect

EXTERN_API std::vector<Rect> *vector_Rect_new1()
{
    return new std::vector<Rect>;
}
EXTERN_API std::vector<Rect> *vector_Rect_new2(size_t size)
{
    return new std::vector<Rect>(size);
}
EXTERN_API std::vector<Rect> *vector_Rect_new3(Rect *data, size_t dataLength)
{
    return new std::vector<Rect>(data, data + dataLength);
}
EXTERN_API size_t vector_Rect_getSize(std::vector<Rect> *vector)
{
    return vector->size();
}
EXTERN_API Rect *vector_Rect_getPointer(std::vector<Rect> *vector)
{
    return &(vector->at(0));
}
EXTERN_API void vector_Rect_delete(std::vector<Rect> *vector)
{
    delete vector;
}

#pragma endregion

#endif