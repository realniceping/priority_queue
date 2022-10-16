using System;
using System.Runtime.InteropServices;

namespace dllimport;

public class Program{

    static void Main(string[] args){
        IntPtr queue = Connector.queue_init(10, 1);
        Connector.queue_append(queue, 9, 2);
        Connector.queue_append(queue, 8, 3);
        Connector.queue_append(queue, 7, 4);
        Connector.queue_append(queue, 6, 5);
        
        Console.WriteLine(Marshal.ReadInt32(Connector.queue_pop(queue)));
        Console.WriteLine(Marshal.ReadInt32(Connector.queue_pop(queue)));
        Console.WriteLine(Marshal.ReadInt32(Connector.queue_pop(queue)));
        Console.WriteLine(Marshal.ReadInt32(Connector.queue_pop(queue)));
        Console.WriteLine(Marshal.ReadInt32(Connector.queue_pop(queue)));
       
    }

}