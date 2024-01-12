package streams;
import java.io.*;
public class BufferedReaderBufferedWriterFromFile {
	

	    public static void main (String[] args) {

	       try {
	           BufferedReader br = new BufferedReader(new FileReader("a.in"));
	           BufferedWriter bw = new BufferedWriter(new FileWriter("a.out"));
	           // get line
	           String line = br.readLine();
	   
	           // while not end of file keep reading and displaying lines
	           while (line != null) {
	                 System.out.println("Read a line:");    
	                 System.out.println(line);   
	                 bw.write("copied: "+line+'\n');
	                 line = br.readLine();
	           }
	           // close stream
	           br.close();
	           bw.close();
	       } catch(FileNotFoundException fe) {
	               System.out.println("File not found");
	       } catch(IOException ioe) {
	               System.out.println("Can't read from file");
	       }
	   }
	}


