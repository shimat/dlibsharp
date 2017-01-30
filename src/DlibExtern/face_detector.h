#ifndef __DLIBEXTERN_FACE_DETECTOR_H__
#define __DLIBEXTERN_FACE_DETECTOR_H__

#include "DlibExtern.h"
#include <dlib/image_processing/frontal_face_detector.h>

EXTERN_API dlib::frontal_face_detector *dlib_get_frontal_face_detector()
{
    auto detector = dlib::get_frontal_face_detector();
    return new dlib::frontal_face_detector(detector);
}

EXTERN_API void dlib_frontal_face_detector_delete(dlib::frontal_face_detector *obj)
{
    delete obj;
}

EXTERN_API void dlib_frontal_face_detector_operator(
    dlib::frontal_face_detector *obj, dlib::array2d<uchar> *image, double adjust_threshold, std::vector<Rect> *dst)
{
    try
    {
        auto dets = (*obj)(*image, adjust_threshold);

        dst->resize(dets.size());
        for (size_t i = 0; i < dets.size(); ++i)
        {
            (*dst)[i] = Rect(dets[i]);
        }
    }
    catch (dlib::error &e)
    {
        if (g_ErrorCallback) g_ErrorCallback(e.what());
    }
}

#endif