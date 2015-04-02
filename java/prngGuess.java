import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class prngGuess {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int cases = scan.nextInt();
        for(int i = 0; i < cases; i++){
			long start = scan.nextLong();
			long end = scan.nextLong();
			int[] seq = new int[10];
			for (int j = 0; j < 10; j++){
				seq[j] = scan.nextInt();
			}
			while(start <= end){
				Random rnd = new Random(start);
				boolean good = true;
				int nextVal;
				int rNum;
				for(int j = 0; j < 10; j++){
					rNum = rnd.nextInt(1000);
					if(seq[j] != rNum){
						good = false;
						break;
					}
				}
				if(good){
					String str = Long.toString(start);
					for(int j = 0; j < 10; j++){
						rNum = rnd.nextInt(1000);
						str += " ";
						str += Integer.toString(rNum);
					}
					System.out.println(str);
					break;
				}
				start++;
			}
		}
    }
}
