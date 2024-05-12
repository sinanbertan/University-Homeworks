/**
*
* @author Sinan Bavli / sinan.bavli1@ogr.sakarya.edu.tr
* @since 01/04/2024
* <p>
* 2.Öğretim C grubu
* </p>
*/

package deneme;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // Kullanıcıdan GitHub depo URL'sini al
        String repoUrl = getUserInput("Bir GitHub Repository URL girin: ");

        // Git deposunu klonla ve sınıfları analiz et
        analyzeClasses(repoUrl);
    }

    private static String getUserInput(String prompt) {
        System.out.print(prompt);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            return reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static void analyzeClasses(String repoUrl) {
        // Git deposunu klonla
        try {
            // Klonlanmış dizini bul
            File clonedRepoDir = new File(getClonedRepoDirectoryName(repoUrl));

            // Eğer klonlanmış dizin zaten varsa, klonlama işlemine gerek yok
            if (!clonedRepoDir.exists() || !clonedRepoDir.isDirectory()) {
                // Git deposunu klonlamak için shell komutu kullanabiliriz
                Process process = Runtime.getRuntime().exec("git clone " + repoUrl);
                int exitCode = process.waitFor();
                if (exitCode == 0) {
                    System.out.println("Repository başarıyla klonlandı.");
                } else {
                    System.err.println("Repository klonlanamadı.");
                    return;
                }
            }

            // *.java dosyalarını al
            List<File> javaFiles = getJavaFiles(clonedRepoDir);

            // Her dosyayı analiz et ve çıktı ver
            for (File javaFile : javaFiles) {
                // Dosya bir interface dosyası mı kontrol et
                if (!isInterfaceFile(javaFile)) {
                    analyzeJavaFile(javaFile);
                }
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

    private static String getClonedRepoDirectoryName(String repoUrl) {
        // GitHub deposunun adını al
        String[] parts = repoUrl.split("/");
        String repoName = parts[parts.length - 1];
        // .git uzantısını kaldır
        if (repoName.endsWith(".git")) {
            repoName = repoName.substring(0, repoName.length() - 4);
        }
        // Klonlanan dizinin adını oluştur ve döndür
        return System.getProperty("user.dir") + File.separator + repoName;
    }

    private static List<File> getJavaFiles(File directory) {
        // Bir dizindeki *.java dosyalarını al
        List<File> javaFiles = new ArrayList<>();
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isFile() && file.getName().endsWith(".java")) {
                    javaFiles.add(file);
                } else if (file.isDirectory()) {
                    // Alt dizinlerde de ara
                    javaFiles.addAll(getJavaFiles(file));
                }
            }
        }
        return javaFiles;
    }

    private static boolean isInterfaceFile(File javaFile) {
        try (BufferedReader reader = new BufferedReader(new FileReader(javaFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Dosya içinde "interface" anahtar kelimesini ara
                if (line.contains("interface")) {
                    return true;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    private static void analyzeJavaFile(File javaFile) {
    	double javadocLineCount = 0;      // Javadoc yorum satırlarının sayısı
    	double otherCommentLineCount = 0; // Diğer yorum satırlarının sayısı
    	double codeLineCount = 0;         // Kod satırlarının sayısı
    	double totalLineCount = 0;        // Toplam satır sayısı
    	double functionCount = 0;         // Fonksiyonların sayısı

        try (BufferedReader reader = new BufferedReader(new FileReader(javaFile))) {
            String line; 
            boolean isInsideJavadoc = false;  // Javadoc bloğu içinde olup olmadığımızı takip eden değişken
            boolean isInsideComment = false;  // Genel yorum bloğu içinde olup olmadığımızı takip eden değişken

            while ((line = reader.readLine()) != null) { 
                totalLineCount++; // Toplam satır sayısını arttır

                line = line.trim(); // Satır başı ve sonundaki boşlukları temizle

                // Yorumların başlangıcı tespiti:
                if (line.startsWith("/*") && !isInsideComment) {
                    isInsideComment = true; 
                    if (line.startsWith("/**")) { // Javadoc bloğunun başlangıcı mı?
                        isInsideJavadoc = true;     
  
                    } else {
                        otherCommentLineCount++;
                    }
                
                } 
                // Yorumların bitişi tespiti:
                else if (line.startsWith("*/") && isInsideComment) {
                    isInsideComment = false;
                    isInsideJavadoc = false;
                } 
                // Javadoc satırının devamı:
                else if (line.startsWith("*") && isInsideJavadoc) {
                    javadocLineCount++;
                }
                // Tek satırlık yorum:
                else if (line.startsWith("//") && !isInsideComment) {
                    otherCommentLineCount++;
                }
                 
                // Kod satırı:
                else if (!isInsideComment && !line.isEmpty()) { 
                    codeLineCount++;
                 // Tek satırlık yorum:
                    if (line.contains("//")) {
                    	otherCommentLineCount++;
                    }
                } 

                // Fonksiyon tanımlama satırı:
                if (line.contains("(") && line.contains(")")  && !line.contains(";") && !isInsideComment && (line.contains("public") || line.contains("private") || line.contains("protected"))) {
                    functionCount++;
                }
                
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Sapma yüzdesini hesaplayabilmek için gerekli değişkenler
        double yg = (((double) javadocLineCount + (double) otherCommentLineCount)*0.8)/(double) functionCount;
        double yh = ((double) codeLineCount / (double) functionCount )*0.3;

        double deviationPercentage = ((yg*100)/yh)-100; 

        // Analiz sonuçlarının ekrana yazdırılması:
        System.out.println("Sınıf: " + javaFile.getName());
        System.out.println("Javadoc Satır Sayısı: " + javadocLineCount);
        System.out.println("Yorum Satır Sayısı: " + otherCommentLineCount);
        System.out.println("Kod Satır Sayısı: " + codeLineCount);
        System.out.println("LOC: " + totalLineCount);
        System.out.println("Fonksiyon Sayısı: " + functionCount);
        System.out.println("Yorum Sapma Yüzdesi: % " + deviationPercentage);
        System.out.println("-----------------------------------------");
    } 
}
