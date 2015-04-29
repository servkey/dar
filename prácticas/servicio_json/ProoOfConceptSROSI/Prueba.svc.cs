using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ProoOfConceptSROSI
{
    public class Perro{
        public string Name{get;set;}
        public string Raza { get; set; }
        public int Edad { get; set; } 
    }
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Prueba" in code, svc and config file together.
    public class Prueba : IPrueba
    {

        public Perro[] Perros()
        {
            List<Perro> perros = new List<Perro>();
            perros.Add(new Perro
            {
                Edad = 10,
                Name = "Rocky",
                Raza = "Pastor"
            });
            perros.Add(new Perro
            {
                Edad = 10,
                Name = "Ponchis",
                Raza = "Pastor"
            });

            return perros.ToArray();
        }


        public Perro Perro(int id)
        {
            return new Perro
              {
                  Edad = 10,
                  Name = "Huesos",
                  Raza = "Pastor"
              };
        }

        public int Sumar(int x, int y)
        {
            return x + y;
        }

    }
}
