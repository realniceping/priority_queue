using System;
using System.Runtime.InteropServices;

namespace dllimport;

public class Connector{
    
    [DllImport("./Dll1.dll", CharSet = CharSet.Unicode)]
    public static extern IntPtr queue_init(int v, int p);

    [DllImport("./Dll1.dll", CharSet = CharSet.Unicode)]
    public static extern IntPtr queue_take_last(IntPtr first);

    [DllImport("./Dll1.dll", CharSet = CharSet.Unicode)]
    public static extern void queue_append(IntPtr first, int v, int p);
    
    [DllImport("./Dll1.dll", CharSet = CharSet.Unicode)]
    public static extern int queue_get_higest_priority(IntPtr first);

    [DllImport("./Dll1.dll", CharSet = CharSet.Unicode)]
    public static extern IntPtr queue_pop(IntPtr firstptr);
}