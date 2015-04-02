import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.Arrays;

public class keywordTranspositionCypher {
	
    public static void main(String[] args) throws IOException {
        //Scanner scan = new Scanner(System.in);
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line;
        line = stdin.readLine();
        int cases = Integer.parseInt(line);
        for(int i = 0; i < cases; i++){
			String word = stdin.readLine();
			//System.out.println("Word: " + word);
			Map cyphermap = buildCypher(word);
			String phrase = stdin.readLine();
			decypher(cyphermap,phrase);
		}
    }
    
    public static void decypher(Map cyphermap, String phrase){
		String decyphered = "";
		for(int i = 0; i < phrase.length(); i++){
			decyphered += cyphermap.get(phrase.charAt(i));
		}
		System.out.println(decyphered);
	}
    
    public static Map buildCypher(String word){
		int len = word.length();
		String bareword = "";
		String preabc   = "";
		String abc      = "";
		Map<Character, Integer> chars = new HashMap<Character, Integer>();
		for(int i = 0; i < len; i++){
			if(chars.containsKey(word.charAt(i))){
				continue;
			}
			bareword += word.charAt(i);
			chars.put(word.charAt(i),1);
		}
		preabc = bareword;
		for(int i = 0; i < bareword.length(); i++){
			chars.put(bareword.charAt(i),i);
		}
		char temp;
		for(int i = 0; i < 26; i++){
			temp = (char)(i+65);
			if(chars.containsKey(temp)){
				continue;
			}
			preabc += temp;
			//chars.put(temp,1);
		}
		char[] ar = bareword.toCharArray();
		Arrays.sort(ar);
		String sorted = String.valueOf(ar);
		System.out.println("Bareword sorted: " + sorted);
		for(int i = 0; i < ar.length; i++){
			int pos = chars.get(ar[i]);
			for(int j = 0; j < 5; j++){
				abc += preabc.charAt(pos + 5*j);
			}
			if(pos == 0){
				abc += preabc.charAt(25);
			}
		}
		Map<Character, Character> cyphermap = new HashMap<Character, Character>();
		for(int i = 0; i < 26; i++){
			cyphermap.put(abc.charAt(i),(char)(i+65));
		}
		cyphermap.put(' ',' ');
		return cyphermap;
	}
}
