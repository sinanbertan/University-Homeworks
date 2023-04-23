/**
*
* @author Sinan Bavli ve sinan.bavli1@ogr.sakarya.edu.tr
* @since 10.04.2023
* <p>
* Bu program Java kodlarında bulunan fonksiyonların içindeki yorumları ve yorum sayılarını bulur.
* </p>
*/


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class App {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Enter the file name:");
            System.exit(1);
        }

        String filename = args[0];
        String code = readCodeFromFile(filename);

        // fonksiyonları ve yorumları tanımlamak için Regex patternleri
        Pattern functionPattern = Pattern.compile("(?m)^\\s*(public|private|protected)?\\s*(static\\s+)?(final\\s+)?\\w+\\s+\\w+\\s*\\(.*?\\)\\s*\\{");
        Pattern singleLineCommentPattern = Pattern.compile("(?m)//.*$");
        Pattern multiLineCommentPattern = Pattern.compile("(?s)/\\*.*?\\*/");
        Pattern javadocPattern = Pattern.compile("(?s)/\\*\\*.*?\\*/");


        // Code ki fonksiyonları bul
        Matcher functionMatcher = functionPattern.matcher(code);
        while (functionMatcher.find()) {
            int functionStart = functionMatcher.start();
            int functionEnd = findMatchingBrace(code, functionStart);

            // Fonksiyonun içindeki yorumları bul
            String functionCode = code.substring(functionStart, functionEnd + 1);
            String singleLineComments = extractComments(singleLineCommentPattern, functionCode);
            String multiLineComments = extractComments(multiLineCommentPattern, functionCode);
            String javadocComments = extractComments(javadocPattern, code.substring(0, functionStart));

            // Yorum sayılarını yazdır
            System.out.println("Function: " + functionMatcher.group().trim());
            System.out.println("Single-line comments: " + countMatches(singleLineCommentPattern, functionCode));
            System.out.println("Multi-line comments: " + countMatches(multiLineCommentPattern, functionCode));
            System.out.println("Javadoc comments: " + countMatches(javadocPattern, javadocComments));
            System.out.println("----------------------------------------");
            System.out.println();

            // Yorumları dosyalara yaz
            writeCommentsToFile(singleLineComments, "teksatir.txt");
            writeCommentsToFile(multiLineComments, "coksatir.txt");
            writeCommentsToFile(javadocComments, "javadoc.txt");
        }
    }

    private static String readCodeFromFile(String filename) {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line).append('\n');
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
            System.exit(1);
        }
        return sb.toString();
    }

    private static int findMatchingBrace(String code, int start) {
        int count = 1;
        for (int i = start + 1; i < code.length(); i++) {
            char c = code.charAt(i);
            if (c == '{') {
                count++;
            } else if (c == '}') {
                count--;
                if (count == 0) {
                    return i;
                }
            }
        }
        throw new IllegalStateException("No matching brace found for function starting at index " + start);
    }

    private static String extractComments(Pattern pattern, String code) {
        StringBuilder sb = new StringBuilder();
        Matcher matcher = pattern.matcher(code);
        while (matcher.find()) {
            sb.append(matcher.group()).append('\n');
        }
        return sb.toString();
    }
    
    private static int countMatches(Pattern pattern, String code) {
        Matcher matcher = pattern.matcher(code);
        int count = 0;
        while (matcher.find()) {
            count++;
        }
        return count;
    }
    
    private static void writeCommentsToFile(String comments, String filename) {
        try (FileWriter fw = new FileWriter(filename, true)) {
            fw.write(comments);
        } catch (IOException e) {
            System.out.println("Error writing to file " + filename + ": " + e.getMessage());
            System.exit(1);
        }
    }
}
    

