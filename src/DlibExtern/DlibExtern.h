#ifndef __DLIBEXTERN_H__
#define __DLIBEXTERN_H__

#include <dlib/geometry/rectangle.h>

// 以下の ifdef ブロックは DLL からのエクスポートを容易にするマクロを作成するための 
// 一般的な方法です。この DLL 内のすべてのファイルは、コマンド ラインで定義された DLIBEXTERN_EXPORTS
// シンボルを使用してコンパイルされます。このシンボルは、この DLL を使用するプロジェクトでは定義できません。
// ソースファイルがこのファイルを含んでいる他のプロジェクトは、 
// DLIBEXTERN_API 関数を DLL からインポートされたと見なすのに対し、この DLL は、このマクロで定義された
// シンボルをエクスポートされたと見なします。
#ifdef DLIBEXTERN_EXPORTS
#define EXTERN_API extern "C" __declspec(dllexport)
#else
#define EXTERN_API extern "C" __declspec(dllimport)
#endif

using uchar = char;

using ErrorCallback = void(*)(const char*);
static ErrorCallback g_ErrorCallback;

EXTERN_API ErrorCallback inline dlib_set_error_redirect(const ErrorCallback callback)
{
    auto current_callback = g_ErrorCallback;
    g_ErrorCallback = callback;
    return current_callback;
}

extern "C"
{
    struct Rect
    {
        int32_t x, y, width, height;

        Rect()
            : x(0), y(0), width(0), height(0)
        {}

        Rect(int _x, int _y, int _w, int _h) 
            : x(_x), y(_y), width(_w), height(_h)
        {}

        Rect(const dlib::rectangle &r)
            : x(r.left()), y(r.top()), width(r.width()), height(r.height())
        {}
    };
}

#endif