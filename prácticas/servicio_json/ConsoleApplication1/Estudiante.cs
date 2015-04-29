using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;

using System.Text;

namespace ConsoleApplication1
{  
    public class Estudiante
    {
        public String id { get; set; }
        public String nombre { get; set; }
        public String apellidopaterno { get; set; }
        public String apellidomaterno { get; set; }
        public int edad { get; set; }

    }
}