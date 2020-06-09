package dictionary;
import jxl.*;
import java.util.ArrayList;

/**
 * @author:LTEnjoy
 * @className : Query
 * @packageName : dictionary
 * @description: 查询类，提供外部程序调用来查询单词
 * @date: 2020/5/31 15:54
 **/

public class Query
{
    private static Workbook workbook;
    private static Sheet sheet;
    private static int length;

    /**
     * 静态代码块，在加载该类时便执行对上述静态变量进行赋值。
     */
    static
    {
        try
        {
            workbook = Workbook.getWorkbook(Query.class.getResourceAsStream("words.xls"));
            sheet = workbook.getSheet(0);
            length = sheet.getRows();
        } catch (Exception e)
        {
            ;
        }
    }

    /**
     *@date: 2020/6/6 20:02
     *@methodName: searchOfTense
     *@description: 获得一个词汇的各种变形：过去式、过去分词、进行时及复数形式
     *@author: LTEnjoy
     *@param: [word]
     *@return: java.lang.String[]
     *@throws:
     */
    public static String[] searchOfTense(String word)
    {
        String[] result = new String[4];
        int row = searchWord(word); //如果没找到单词直接返回
        if(row == 0)
            return null;
        for(int i = 0; i<4;i++)
            result[i] = sheet.getCell(i+2,row).getContents();
        return result;
    }

    /**
     *@date: 2020/6/6 20:14
     *@methodName: searchOfExplaination
     *@description: 获得一个单词的多种词性及词义
     *@author: LTEnjoy
     *@param: [word]
     *@return: java.util.ArrayList<java.lang.String[]>
     *@throws:
     */
    public static ArrayList<String[]> searchOfExplaination(String word)
    {
        ArrayList<String[]> result = new ArrayList<>();
        int row = searchWord(word); //如果没找到单词直接返回
        if(row == 0)
            return null;
        for(String j:sheet.getCell(6,row).getContents().split("\n"))
        {
            String[] temp = j.split("\\.",2);
            for(int i = 0;i<temp.length;i++)    //对读取的字符串进行规范化处理
            {
                temp[i] = temp[i].trim();
                temp[i] = temp[i].replace("<br>","");
            }
            if(temp.length == 2)
                result.add(temp);
        }
        return result;
    }

    /**
     *@date: 2020/6/7 10:17
     *@methodName: searchOfSentences
     *@description: 提供单词的例句查询
     *@author: LTEnjoy
     *@param: [word]
     *@return: java.util.ArrayList<java.lang.String[]>
     *@throws:
     */
    public static ArrayList<String[]> searchOfSentences(String word)
    {
        ArrayList<String[]> result = new ArrayList<>();
        int row = searchWord(word); //如果没找到单词直接返回
        if(row == 0)
            return null;
        if(sheet.getCell(7,row).getContents() == "")    //如果没有例句
            return null;
        for(String j:sheet.getCell(7,row).getContents().split("\n"))
        {
            String[] temp = j.split("/r/n",3);
            for(int i = 0;i<temp.length;i++)    //对读取的字符串进行规范化处理
                temp[i] = temp[i].trim();
            if(temp.length == 3)
                result.add(new String[]{temp[0],temp[1]});
        }
        return result;
    }

    /**
     *@date: 2020/6/7 9:56
     *@methodName: searchWord
     *@description: private方法查询单词，供接口方法进行调用
     *@author: LTEnjoy
     *@param: [word]
     *@return: int
     *@throws:
     */
    private static int searchWord(String word)
    {
        for(int i = 0; i < length; i++)
            if (sheet.getCell(1, i).getContents().equals(word))
                return i;
        return 0;
    }
}
