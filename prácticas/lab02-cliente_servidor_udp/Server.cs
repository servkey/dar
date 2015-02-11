using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;

namespace UdpServer
{
    class Server
    {
        static void Main(string[] args)
        {
            System.Net.Sockets.UdpClient server = new System.Net.Sockets.UdpClient(15000);
            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 0);

            byte[] data = new byte[1024];
            data = server.Receive(ref sender);
            server.Close();
            string stringData = Encoding.ASCII.GetString(data, 0, data.Length);

            Console.WriteLine("Respondiendo desde " + sender.Address + Environment.NewLine + "Mensaje: " + stringData);
            Console.ReadLine();
        }
    }
}