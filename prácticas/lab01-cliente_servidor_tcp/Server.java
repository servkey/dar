import java.net.*;
import java.io.*;
import java.lang.management.*;
public class Server{

	public static void main(String args[]){
		try {

			int puerto = 5000;

			ServerSocket s = new ServerSocket(puerto);
			String comandoSalir = "Exit";
			String entrada = "";
			System.out.println("Servidor iniciado en el puerto " + puerto + "...");
			while(true){
				Socket s1 = s.accept();        
				System.out.println("Aceptando conexion...");
				PrintWriter out = new PrintWriter(s1.getOutputStream(), true);
				BufferedReader in = new BufferedReader(new InputStreamReader(s1.getInputStream()));

				while ((entrada = in.readLine()) != null) {					
				    System.out.println(entrada);
			    	    String pathDesktop = System.getProperty("user.home") + "\\Desktop\\";
				    out.println("Hola desde el servidor!! -> " + pathDesktop);
				    out.println("");
				    if (entrada.trim().equals(comandoSalir))
				        return;
				} 
				s1.close();
				   
			}

		} catch (IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}


}