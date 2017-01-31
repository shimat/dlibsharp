using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace DlibSharp
{
    // ReSharper disable InconsistentNaming

    [SuppressUnmanagedCodeSecurity]
    public static class NativeMethods
    {
        private const string Dll = "DlibExtern";


        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr dlib_set_error_redirect([MarshalAs(UnmanagedType.FunctionPtr)] ErrorCallback callback);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr dlib_get_frontal_face_detector();

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_frontal_face_detector_delete(IntPtr obj);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_frontal_face_detector_operator(
            IntPtr obj, IntPtr image, double adjust_threshold, IntPtr dst);


        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr dlib_array2d_uchar_new();

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_array2d_uchar_delete(IntPtr obj);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_load_image_array2d_uchar(IntPtr obj, string file_name);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_load_bmp_array2d_uchar(IntPtr obj, [MarshalAs(UnmanagedType.LPArray)] byte[] buffer, IntPtr buffer_length);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void dlib_pyramid_up_array2d_uchar(IntPtr obj);


        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr vector_Rect_new1();

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr vector_Rect_new2(IntPtr size);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr vector_Rect_new3(IntPtr data, IntPtr dataLength);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr vector_Rect_getSize(IntPtr vector);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr vector_Rect_getPointer(IntPtr vector);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void vector_Rect_delete(IntPtr vector);
    }
}
