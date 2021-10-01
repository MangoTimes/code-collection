import static java.lang.System.*;
import java.util.Scanner;

public class VIgnereDecrypt {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        out.println("Enter the ciphertext");
        String ciphertext=sc.nextLine().toUpperCase();
        out.println("Enter the key");
        String key=sc.nextLine().toUpperCase();

        String plaintext="";

        for (int i = 0, j = 0; i < ciphertext.length(); i++)
        {
            char c = ciphertext.charAt(i);
            if (c < 'A' || c > 'Z')
                continue;
            plaintext += (char) ((c - key.charAt(j) + 26) % 26 + 'A');
            j = ++j % key.length();
        }
        out.println("plaintext is:"+plaintext);
    }
}
