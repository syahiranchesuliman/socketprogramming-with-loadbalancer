import java.io.*;
import java.net.*;

public class loadbalancer{

	public static void main( String []args) throws IOException{
	ServerSocket s1 = new ServerSocket (1234);
	while (true)
	{
	
	Socket connectionsocket = s1.accept();
	BufferedReader messagefromclient = new BufferedReader( new InputStreamReader (connectionsocket.getInputStream()));
	String cs = messagefromclient.readLine();
	
	if(cs.contains("enemy"))
	{
		
		Socket server = new Socket("192.168.223.128",2345);
		DataOutputStream outtoserver = new DataOutputStream( server.getOutputStream());
		outtoserver.writeBytes(cs + "\n");
		server.close();
	}
		
	else if(cs.contains("friend"))
	{

		Socket server = new Socket("192.168.223.131",2346);
		DataOutputStream outtoserver = new DataOutputStream( server.getOutputStream());
		outtoserver.writeBytes(cs + "\n");
		server.close();
	}

	else
		
		System.out.println("Error");
	}
}
}	
