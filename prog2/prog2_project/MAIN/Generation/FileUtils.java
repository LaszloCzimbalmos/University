package Generation;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import Objects.Picture;

public class FileUtils
{
    // input: a megnyitandó file neve
    // output: egy List<String> objektum, ami az egyes sorokat tartalmazza
    public static List<String> readLines(String fileName)
    {
        List<String> lines = new ArrayList<String>();

        try
        {
            String line;
            BufferedReader br = new BufferedReader(new FileReader(fileName));
            while ((line = br.readLine()) != null)
            {
                lines.add(line);
            }
            br.close();
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
            System.exit(1);
        }
        catch (IOException e)
        {
            e.printStackTrace();
            System.exit(2);
        }

        return lines;
    }

    public static String getRelativePath(File baseDirectory, File file) {
        Path basePath = baseDirectory.toPath().toAbsolutePath();
        Path filePath = file.toPath().toAbsolutePath();
        
        Path relativePath = basePath.relativize(filePath);
        
        return relativePath.toString();
    }

    public static void loopDirectories(File file, File startPage)
    {
        if (file.isDirectory())
        {
            System.out.println("Dir: " + file.getName());
            File files[] = file.listFiles();
            List<Picture> pictures = Picture.getPictures(file, file);
            Generate.createHTMLs(pictures, startPage);

            for (File f : files) 
            {
                if (f.isDirectory())
                {
                    loopDirectories(f, startPage);
                }
            }

        }
    }
}
