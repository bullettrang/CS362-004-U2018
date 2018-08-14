import java.util.ArrayList;

import junit.framework.TestCase;
import java.util.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



// <scheme> <host> <port> <path> <query>

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("MANUAL TESTING....");
	   
	   //PERFORMING TESTS ON URL FORMATS
	   
	   System.out.println(urlVal.isValid("http://www.google.com:65535"));//NEEDS TO BE PASS
	   System.out.println(urlVal.isValid("http://www.google.com:6553"));//NEEDS TO BE PASS
	   System.out.println(urlVal.isValid("http://www.google.com:655"));//NEEDS TO BE PASS
	   System.out.println(urlVal.isValid("http://www.google.com:80"));//NEEDS TO BE PASS
	   
	   
	   //System.out.println(urlVal.isValid("http://7.7.7.895"));//NEEDS TO BE FAIL
	   //System.out.println(urlVal.isValid("http://1.1.9.255"));//NEEDS TO BE PASS
	   System.out.println(urlVal.isValid("http://2.8.8.256"));//NEEDS TO BE FAIL
	   System.out.println(urlVal.isValid("http://www.google.com?x=1"));
   }
   
   
   public void testYourFirstPartition()
   {
	   
	 //You can use this function to implement your First Partition testing
	   UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("TESTING FIRST PARTITION via scheme");
	   System.out.println(urlVal.isValid("://www.google.com"));
	   System.out.println(urlVal.isValid("https://www.google.com"));
	   System.out.println(urlVal.isValid("//www.google.com"));
	   System.out.println(urlVal.isValid("httpz://www.google.com")); 
	   System.out.println(urlVal.isValid("qwert://www.google.com")); 
	   System.out.println(urlVal.isValid("http;//www.google.com"));
	   System.out.println(urlVal.isValid("http??//www.google.com"));
	   System.out.println(urlVal.isValid("www.google.com"));
	   
	   System.out.println("TESTING SECOND PARTITION via delimiters");
	   System.out.println(urlVal.isValid("http://////www.google.com"));
	   System.out.println(urlVal.isValid("http:;www.google.com"));
	   System.out.println(urlVal.isValid("http:!!www.google.com"));
	   System.out.println(urlVal.isValid("http:\\www.google.com"));
	   System.out.println(urlVal.isValid("http:://www.google.com"));
	   System.out.println(urlVal.isValid("http:/www.google.com"));

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

	   UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("TESTING SECOND PARTITION via host");

	   System.out.println(urlVal.isValid("http://ww.google.com"));
	   System.out.println(urlVal.isValid("http://w.wwgooglecom"));
	   System.out.println(urlVal.isValid("http://wwwgoo.glecom"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.co"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.com"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.COM"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.CoM"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.edu"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.us"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.cn"));  
	   System.out.println(urlVal.isValid("http://wwwgoogle.au"));   
	   System.out.println(urlVal.isValid("http://wwwgoogle.ca"));
	   System.out.println(urlVal.isValid("http://wwwg.oo.glecom"));
	   System.out.println(urlVal.isValid("http://wwwag.ooglecom"));
	   System.out.println(urlVal.isValid("http://wwwgooglecom.o"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.c0m"));
	   System.out.println(urlVal.isValid("http://wwwgoogle.c"));

	   System.out.println("TESTING SECOND PARTITION via paths");
	   System.out.println(urlVal.isValid("http://www.google.com/"));
	   System.out.println(urlVal.isValid("http://www.google.com/about"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/$"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/?"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/^"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/#"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/%"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/&"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/()"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones/dfasdf.czd"));
	   System.out.println(urlVal.isValid("https://store.google.com/category/phones:80"));
	   
	   System.out.println("TESTING SECOND PARTITION via query");
	   System.out.println(urlVal.isValid("https://support.google.com/optimize/answer/6283424?hl=en"));
	   System.out.println(urlVal.isValid("https://support.google.com/optimize/answer/6283424?hl="));
	   System.out.println(urlVal.isValid("https://support.google.com:80/optimize/answer/6283424?action=view"));
	   
	   
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	// You can use this function for programming-based testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("PERMUTATION PROGRAMMING-BASED TESTING....");
	   
	   // create arrays to sort results
	   ArrayList<String> valid = new ArrayList<String>();
	   ArrayList<String> invalid = new ArrayList<String>();
	   
	   boolean result = false;
	   do {
	          StringBuilder testBuffer = new StringBuilder();
	          
	          // percolate up the URL as each group finishes
        	  //if (testPartsIndex[4] == testUrlQuery.length)
	          if (testPartsIndex[4] == 2)
        	  {
        		  testPartsIndex[3]++;
        		  testPartsIndex[4] = 0;
        	  }
        	  
        	  //if (testPartsIndex[3] == testUrlPathOptions.length)
	          if (testPartsIndex[3] == 2)
        	  {
        		  testPartsIndex[2]++;
        		  testPartsIndex[3] = 0;
        	  }
        	  
        	  //if (testPartsIndex[2] == testUrlPort.length)
	          if (testPartsIndex[2] == 2)
        	  {
        		  testPartsIndex[1]++;
        		  testPartsIndex[2] = 0;
        	  }
        	  
        	  //if (testPartsIndex[1] == testUrlAuthority.length)
	          if (testPartsIndex[1] == 2)
        	  {
        		  testPartsIndex[0]++;
        		  testPartsIndex[1] = 0;
        	  }
	          
	          // build a URL
	          for (int i = 0; i < testPartsIndex.length; i++)
	          {
	        	  testBuffer.append(testUrlPartsOptions[i][testPartsIndex[i]]);
	          }
	          
	          // test the URL
	          result = urlVal.isValid(testBuffer.toString());
	          
	          // Save the result to the proper ArrayList
	          if (result)
	          {
	        	  valid.add(testBuffer.toString());
	          }
	          else
	          {
	        	  invalid.add(testBuffer.toString());
	          }
	          
	          
	   } while (testPartsIndex[0] < testUrlScheme.length);
	   
	   // Print out valid/invalid addresses
	   System.out.println("Valid URL's\n");
	   for(int i = 0; i < valid.size(); i++)
	   {
		   System.out.println(valid.get(i) + "\n");
	   }
	   
	   System.out.println("Invalid URL's\n");
	   for(int i = 0; i < invalid.size(); i++)
	   {
		   System.out.println(invalid.get(i) + "\n");
	   }
	   

   }
   
   public static void main(String[] argv) {

	      UrlValidatorTest fct = new UrlValidatorTest("url test");
	      //fct.setUp();
	      //fct.testIsValid();
	      //fct.testManualTest();
	      //fct.testIsValid();
	      fct.testYourFirstPartition();
	   }
   
   //-------------------- Test data for creating a composite URL
   /**
    * The data given below approximates the 4 parts of a URL
    * <scheme>://<authority><path>?<query> except that the port number
    * is broken out of authority to increase the number of permutations.
    * A complete URL is composed of a scheme+authority+port+path+query,
    * all of which must be individually valid for the entire URL to be considered
    * valid.
    */
   /** Note: This code below was originally written by the Apache Software Foundation
    *      and has been modified for re-use in this program.  Please refer to
    *       to the URLValidatorCorrect project under the same class name for the
    *       original implementation.
    */
   String[] testUrlScheme = {"http://", 
		                     "ftp://", 
		                     "h3t://", 
		                     "3ht://", 
		                     "http:/", 
		                     "http:", 
		                     "http/", 
		                     "://", 
		                     ""
                            };

   String[] testUrlAuthority = {"www.google.com",
                                "go.com", 
                                "go.au", 
                                "0.0.0.0", 
                                "255.255.255.255", 
                                "256.256.256.256", 
                                "255.com", 
                                "1.2.3.4.5", 
                                "1.2.3.4.", 
                                "1.2.3", 
                                ".1.2.3.4", 
                                "go.a", 
                                "go.a1a", 
                                "go.1aa", 
                                "aaa.", 
                                ".aaa",
                                "aaa",
                                 ""
                               };
   
   String[] testUrlPort = {":80",
		                   ":65535",
                           ":0",
                           ":-1",
                           ":65636",
                           ":65a",
                           ""
                          };
   
   String[] testUrlPathOptions = {"/test1",
                                  "/t123",
                                  "/$23",
                                  "/..",
                                  "/../", 
                                  "/test1/",
                                  "/#",
                                  "/test1/file",
                                  "/t123/file",
                                  "/$23/file", 
                                  "/../file",
                                  "/..//file",
                                  "/test1//file",
                                  "/#/file",
                                   ""
                                 };

   String[] testUrlQuery = {"?action=view",
                            "?action=edit&mode=up",
                            ""
                           };

   String[][] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
   int[] testPartsIndex = {0, 0, 0, 0, 0};
   


}





