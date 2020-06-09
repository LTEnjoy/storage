import dictionary.*;

import java.util.ArrayList;
import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        String word = "butw";
        String[] result1 = Query.searchOfTense(word);
        System.out.println("动词时态检测");
        if(result1 !=null)
        {
            for(int i = 0;i<result1.length;i++)
            {
                System.out.println(i+1+": " + result1[i]);
            }
        }
        else
            System.out.println("无查询结果");

        System.out.println("词性及词义检测");
        ArrayList<String[]> result2 = Query.searchOfExplaination(word);
        if(result2 !=null)
        {
            for(String[] i : result2)
            {
                System.out.println(i[0] + " "+i[1]);
            }
        }
        else
            System.out.println("无查询结果");

        System.out.println("例句检测");
        ArrayList<String[]> result3 = Query.searchOfSentences(word);
        if(result3 !=null)
        {
            for(String[] i : result3)
            {
                System.out.println(i[0] + " "+i[1]);
            }
        }
        else
            System.out.println("无查询结果");
    }

}
