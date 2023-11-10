import java.io.File;
import java.util.ArrayList;
import java.util.List;

import Generation.FileUtils;
import Objects.Picture;
import Validation.PathValidation;

public class Main
{
    public static void main(String[] args) throws Exception 
    {
        String pathString = args[0];
        if (!PathValidation.isValidPath(pathString))
        {
            System.err.println("Error: Invalid path.");
        }
        //else

        File rootDir = new File(pathString);

        File file2 = new File("C:\\Users\\lacim\\Desktop\\proba");
        File file3 = new File("C:\\Users\\lacim\\Desktop\\proba\\egy");
        File startPage = new File("C:\\Users\\lacim\\Desktop\\proba\\index.html");
        List<Picture> pictures = new ArrayList<>();
        
        //fikepathFile
        
        //String s = FileUtils.getRelativePath(file3, startPage);
        FileUtils.loopDirectories(rootDir, startPage);
        
        

    }
}
