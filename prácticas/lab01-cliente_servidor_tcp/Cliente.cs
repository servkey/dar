using System;
using System.Text;
using System.Net;
using System.Net.Sockets;

class Program 
{                
        private static string Cliente(IPAddress servidor, int puerto)
        {
            try
            {
                string request = "<DIR>";
                Byte[] bytesSent = Encoding.ASCII.GetBytes(request);
                Byte[] bytesReceived = new Byte[256];

                // Crear socket ip, puerto
                IPEndPoint ipe = new IPEndPoint(servidor, puerto);
                Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                s.Connect(ipe);

                if (s == null) return "Connexion falló!";
                                
                s.Send(bytesSent, bytesSent.Length, 0);

                try
                {
                    byte[] data = new byte[1024];
                    int receivedDataLength = s.Receive(data);
                    string stringData = Encoding.ASCII.GetString(data, 0, receivedDataLength);
                    Console.WriteLine(stringData);

                    s.Shutdown(SocketShutdown.Both);
                    s.Close();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }
            }
            catch (Exception se)
            {
                Console.WriteLine("Error en conexión" + se.StackTrace);
            }
            return "";
        }


        static void Main(string[] args)
        {           
            int port = 8000;            
            try
	    {
		if (args.Length > 0){
	                string result = Cliente(IPAddress.Parse(args[0]), port);
	                Console.WriteLine(result);
		}else 
			Console.WriteLine("Argumentos inválidos!!");
            }
            catch (Exception e) {
                Console.WriteLine(e.Message);
            }
        }
}