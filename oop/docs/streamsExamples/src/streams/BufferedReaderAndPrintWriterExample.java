package streams;
import java.io.*;
public class BufferedReaderAndPrintWriterExample {
	public static void main (String[] args) {

		try {
			//example showing how to use BR, PW
			//br reads from console, pw writes to console (yes, the same as System.out.println), pwFile writes to file
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			// second parameter of type boolean - autoflush
			PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out),true);
			PrintWriter pwFile = new PrintWriter(new FileWriter("a.out"));
			// get line
			String line = br.readLine();

			// while not end of file, keep reading and displaying lines
			while (!line.equals("q")) {
				pw.println("Read a line:");    
				pw.println(line);   
				pwFile.println(line);
				line = br.readLine();
			}
			// close stream
			br.close();
			pw.close();
			pwFile.close();
		} catch(IOException ioe) {
			System.out.println("Can't read!");
		}
	}
}
