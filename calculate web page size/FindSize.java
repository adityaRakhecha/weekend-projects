//***********************Program to calculate the size of a web page in bytes***********************

//import necessary packages
import java.net.URL;
import java.net.URLConnection;
//import java.io.InputStream;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.MalformedURLException;

//main class
public class FindSize
{
    //method to calculate size of input webpage
    public void getWebPage(String inputWebpage)
    {

        try{

	    //Load URL
            URL url = new URL(inputWebpage);

            //construct connection
            URLConnection urlConn = url.openConnection();

            //load inputstream to bufferedStream
            BufferedInputStream buffer = new BufferedInputStream(urlConn.getInputStream());

            //to store every character from the html data(code)
            StringBuilder WPbuilder = new StringBuilder();
            
            //to store index of WPbuilder
            int WPbuilder_index;

            //traverse the buffer and check
            //if buffer is not empty, append WPbuilder
            while ((WPbuilder_index = buffer.read()) != -1)
                WPbuilder.append(WPbuilder_index);

            buffer.close();
            
            System.out.println("calculating size...");

            //calculate length of WPbuilder and print
            int WPsize = WPbuilder.length();
	    //System.out.println(WPsize);
            System.out.println("The size of input Webpage is " + WPsize + " bytes");

        }

        //When IO operation fails/distorted
        catch (IOException exception)
        {
                exception.printStackTrace();
        }

	//When input URL is distorted/corrupted
        catch (MalformedURLException exception)
        {
                exception.printStackTrace();
        }

    }

    //program execution starts from here
    public static void main(String[] args)
    {
        //calling getWebPage()
        new FindSize().getWebPage(args[0]);
    }
}

/** 
to compile :: javac FindSize.java
to execute :: java FindSize https://inputYourURL.com/
**/


