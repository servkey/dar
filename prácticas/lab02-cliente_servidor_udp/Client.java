import java.io.*;
import java.net.*;

class Client
{
   public static void main(String args[]) throws Exception
   {
      DatagramSocket clientSocket = new DatagramSocket();
      InetAddress IPAddress = InetAddress.getByName("255.255.255.255");
      byte[] data = new byte[1024];
      data = "Descubriendo servicios...".getBytes();
      DatagramPacket packet = new DatagramPacket(data, data.length, IPAddress, 1234);
      clientSocket.send(packet);
      System.out.println("Datos enviados...");
      clientSocket.close();
   }
}