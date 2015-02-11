using System;
using System.Text;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Web.Script.Serialization; 

class Program
{
        static void Main()
        {

            Console.WriteLine("Esperando para conexión...!!");
                       
            IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 8000);
            Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            sock.Bind(localEndPoint);
            sock.Listen(10);
            Socket handler = sock.Accept();
            Console.WriteLine("Conexión recibida de " + ((IPEndPoint)handler.RemoteEndPoint).Address.ToString());	  
            String data = null;

            byte[] bytes;

	    string[] directorios = Directory.GetFiles(@"c:\");
	    JavaScriptSerializer oSerializer = new JavaScriptSerializer();
            string dirJSON = oSerializer.Serialize(directorios);


            while (true)
            {
                bytes = new byte[1024];
                int bytesRec = handler.Receive(bytes);
                data += Encoding.ASCII.GetString(bytes, 0, bytesRec);
                Console.WriteLine(data);
                
                if (data.IndexOf("<DIR>") > -1)
                {
			Console.WriteLine("Texto recibido: {0}", data);
	                byte[] msg = Encoding.ASCII.GetBytes(dirJSON);
		        handler.Send(msg);
			handler.Shutdown(SocketShutdown.Both);
			handler.Close();   
			break;
                }
                
                                
             }
	}
}
