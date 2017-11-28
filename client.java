import java.io.*;
import java.net.*;

public class client{

	public static void main ( String[]args) throws IOException
	{
	Socket myclient=new Socket("192.168.79.130",1234);
	
	DataOutputStream outtoserver = new DataOutputStream(myclient.getOutputStream());
	BufferedReader infromuser= new BufferedReader(new InputStreamReader(System.in));
	
	String s = infromuser.readLine();
	outtoserver.writeBytes(s);
	myclient.close();
}
}
