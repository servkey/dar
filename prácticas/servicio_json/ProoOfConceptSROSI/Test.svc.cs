using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ProoOfConceptSROSI
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Test" in code, svc and config file together.
    public class Test : ITest
    {
        public void DoWork()
        {
        }

        public int Sumar(int x, int y)
        {
            return x + y;
        }
    }
}
