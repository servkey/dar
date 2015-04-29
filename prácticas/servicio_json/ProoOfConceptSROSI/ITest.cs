using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ProoOfConceptSROSI
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "ITest" in both code and config file together.
    [ServiceContract]
    public interface ITest
    {
        [OperationContract]
        void DoWork();

        [OperationContract]
        int Sumar(int x, int y);
    }
}
