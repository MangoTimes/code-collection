import java.util.Scanner;
public class VignereEncrypt {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the plaintext or message");
        String plaintext=sc.nextLine().toUpperCase();
        System.out.println("Enter the key");
        String key=sc.nextLine().toUpperCase();
        String ciphertext="";
        for(int i=0,j=0;i<plaintext.length();i++){
              char c = plaintext.charAt(i);
              if (c < 'A' || c > 'Z') continue;
              ciphertext += (char) ((c + key.charAt(j) - 2 * 'A') % 26 + 'A');
              j = ++j % key.length();
          }System.out.println("CipherText is " + ciphertext);}}


