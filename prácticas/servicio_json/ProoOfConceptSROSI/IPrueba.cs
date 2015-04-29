using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace ProoOfConceptSROSI
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IPrueba" in both code and config file together.
    [ServiceContract]
    public interface IPrueba
    {

        [OperationContract]
        [WebGet(
        UriTemplate = "Sumar?x={x}&y={y}",
        ResponseFormat = WebMessageFormat.Json,
        RequestFormat = WebMessageFormat.Json
        )]

        int Sumar(int x, int y);

        [OperationContract]
        [WebGet(
            UriTemplate = "GetPerros",
            ResponseFormat = WebMessageFormat.Json,
            RequestFormat = WebMessageFormat.Json
        )]
        Perro[] Perros();

        [OperationContract]
        [WebGet(
            UriTemplate = "GetPerro?id={id}",
            ResponseFormat = WebMessageFormat.Json,
            RequestFormat = WebMessageFormat.Json
        )]
        Perro Perro(int id);    
    }
}
