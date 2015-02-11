using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;

namespace UdpClient
{
    class Client
    {
        static void Main(string[] args)
        {
            System.Net.Sockets.UdpClient sock = new System.Net.Sockets.UdpClient();
            IPEndPoint iep = new IPEndPoint(IPAddress.Parse("255.255.255.255"), 15000);
            byte[] data = Encoding.ASCII.GetBytes("Hola Servidor UDP!!");
            sock.Send(data, data.Length, iep);
            sock.Close();

            Console.WriteLine("Mensaje enviado.");
            Console.ReadLine();
        }
    }
}