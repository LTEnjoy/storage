jar包中提供了Query查询类，其中有三个静态方法供用户调用来查词。

分别是：
	Query.searchOfTense	获得一个词汇的各种变形：过去式、过去分词、进行时及复数形式
	
	Query.searchOfExplaination	获得一个单词的多种词性及词义

	Query.searchOfSentences		提供单词的例句查询

详细解释：
	Query.searchOfTense方法的输入参数是一个关于查询单词的字符串。
	返回值是一个String[4]。数组中的值依次是：过去式、过去分词、进行时及复数形式。若相应位置查询无结果则相应位置返回“”。

	Query.searchOfExplaination方法的输入参数是一个关于查询单词的字符串。
	返回值是一个Arraylist<String[]>。
	其中每一个String[]都有两个元素，第一个元素为词性，第二个元素为中文释义。若相应位置查询无结果则相应位置返回“”。

	Query.searchOfSentences方法的输入参数是一个关于查询单词的字符串。
	返回值是一个Arraylist<String[]>。
	其中每一个String[]都有两个元素，第一个元素为英文例句，第二个元素为中文翻译。若相应位置查询无结果则相应位置返回“”。


样例展示（可复制粘贴）：
 	
	String word = "butw";
        String[] result1 = Query.searchOfTense(word);
        System.out.println("变形检测");
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

输出结果为：

变形检测
1: 
2: 
3: 
4: apples
词性及词义检测
n 苹果
例句检测
An apple is a kind of fruit. 苹果是一种水果。
The apple trees are blossoming. 苹果树正在开花。

