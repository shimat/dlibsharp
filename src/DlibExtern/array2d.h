#ifndef __DLIBEXTERN_ARRAY2D_H__
#define __DLIBEXTERN_ARRAY2D_H__

#include "DlibExtern.h"
#include <dlib/image_io.h>
#include <dlib/image_transforms/interpolation.h>

EXTERN_API dlib::array2d<uchar> *dlib_array2d_uchar_new()
{
    return new dlib::array2d<uchar>;
}

EXTERN_API void dlib_array2d_uchar_delete(dlib::array2d<uchar> *obj)
{
    delete obj;
}

EXTERN_API void dlib_load_image_array2d_uchar(dlib::array2d<uchar> *obj, const char *file_name)
{
    try 
    {
        dlib::load_image(*obj, file_name);        
    }
    catch (dlib::error &e)
    {
        if (g_ErrorCallback) g_ErrorCallback(e.what());
    }
}

EXTERN_API void dlib_pyramid_up_array2d_uchar(dlib::array2d<uchar> *obj)
{
    try
    {
        dlib::pyramid_up(*obj);
    }
    catch (dlib::error &e)
    {
        if (g_ErrorCallback) g_ErrorCallback(e.what());
    }
}

#endif
