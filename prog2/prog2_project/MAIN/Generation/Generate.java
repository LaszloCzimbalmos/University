package Generation;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.List;

import Objects.Picture;

public class Generate 
{
    public static void createHTMLs(List<Picture> pictures, File startPage)
    {
        for (int i = 0; i < pictures.size(); i++) 
        {
            System.out.println("jkshsdjkasd");
            Picture actual = pictures.get(i);
            Picture previous = (i == 0) ? actual : pictures.get(i - 1);
            Picture next = (i == pictures.size() - 1) ? actual : pictures.get(i + 1);
            String html = pictureHTML(actual.getName(), startPage.getPath(), previous.getName() + ".html", next.getName() + ".html", actual.getFileName(), actual.getURL());
            String pathFile = String.format("%s\\%s.html", actual.getContainer(), actual.getName());
           
            writeFile(pathFile, html);
        }
    }


    public static void writeFile(String container, String output)
    {
        try 
        {
            PrintWriter writer = new PrintWriter(new FileOutputStream(container, false));
            writer.println(output);
            writer.close();
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
        
    }


    public static String pictureHTML(String title, String startPage, String elozoKep, String kovetkezoKep, String kepNeve, String kepHelye)
    {
        String htmlString = """
            <!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>%s</title>
            </head>
            <body>
                <div style="border-bottom: 2px solid; border-color: black; padding: 5px;">
                    <a href="%s" style="font-size: 25px;" >Start Page</a>
                </div>
            
                <a style="display: block; padding-top: 10px;" href="../index.html">^^</a>
                <div style="display: flex; align-items: center; padding-top: 10px;">
                
                    <a href="%s"><<</a>
                    <h4 style="margin: 0 10px;">%s</h4>
                    <a href="%s">>></a>
                
                </div>
            
                <a href="%s">
                    <img style="height: 20%%; width: 20%%; padding-top: 10px;" src="%s" alt="">
                </a>
            
            
                
            </body>
            </html>
                """;

        return String.format(htmlString, title, startPage, elozoKep, kepNeve, kovetkezoKep, kovetkezoKep, kepHelye);
    }
}
