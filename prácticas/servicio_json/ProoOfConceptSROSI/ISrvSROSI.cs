using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.ServiceModel.Web;
namespace ProoOfConceptSROSI
{
    [ServiceContract]
    public interface ISrvSROSI
    {
        [OperationContract]
        string Saludos();

        [OperationContract]
        [WebGet(
            UriTemplate = "GetEstudiante?idEstudiante={idEstudiante}&dos={dos}",
            ResponseFormat = WebMessageFormat.Json,
            RequestFormat = WebMessageFormat.Json
        )]
        Estudiante GetEstudiante(String idEstudiante, int dos);

        [OperationContract]
        [WebGet(
            UriTemplate = "GetEstudiantes",
            ResponseFormat = WebMessageFormat.Json,
            RequestFormat = WebMessageFormat.Json
        )]
        Estudiante[] GetEstudiantes();       
    }
}
