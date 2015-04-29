using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ProoOfConceptSROSI
{
    public class SrvSROSI : ISrvSROSI
    {
        public string Saludos()
        {
            return "Hola";
        }

        public Estudiante[] GetEstudiantes()        
        {
            Estudiante e = new Estudiante();
            e.Id = "S10390";
            e.Nombre = "Luis";
            e.ApellidoPaterno = "Montané";
            e.ApellidoMaterno = "Jiménez";
            e.Edad = 27;


            Estudiante e1 = new Estudiante();
            e1.Id = "S10391";
            e1.Nombre = "Hugo";
            e1.ApellidoPaterno = "Montané";
            e1.ApellidoMaterno = "Jiménez";
            e1.Edad = 27;


            List<Estudiante> estudiantes = new List<Estudiante>();
            estudiantes.Add(e);
            estudiantes.Add(e1);
            return estudiantes.ToArray<Estudiante>();
        }

        public Estudiante GetEstudiante(String idEstudiante, int dos)
        {
            Estudiante e = new Estudiante();
            e.Id = "S10390";
            e.Nombre = "Luis";
            e.ApellidoPaterno = "Montané";
            e.ApellidoMaterno = "Jiménez";
            e.Edad = 27;
            return e;
        }

    }
}
