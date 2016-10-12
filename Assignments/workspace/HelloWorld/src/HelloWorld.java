import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class HelloWorld {
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		System.out.println("Did this thing compile?");
		
		
		
		
		
		String[] argv = null;
		//TAKE INPUT FROM COMMAND LINE:
		try {
			FileInputStream fstream = new FileInputStream(argv[0]);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
