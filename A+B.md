> #### A+B Problem
##### 描述
求两个整数A+B的和
##### 输入
输入包含多组数据。每组数据包含两个整数A(1 ≤ A ≤ 100)和B(1 ≤ B ≤ 100)。
##### 输出
对于每组数据输出A+B的和
##### 样例输入
```
1 2
3 4
5 6
```
##### 样例输出
```
3
7
11
```

<table>
<thead>
<tr>
	<th>语言</th>
	<th>样例程序</th>
</tr>
</thead>
<tbody>
<tr>
<td>C</td>
<td>
<pre><code>#include &lt;stdio.h&gt;
	
int main(void) 
{
    int a, b;
    while(scanf("%d%d", &amp;a, &amp;b) != EOF) 
    {
    	printf("%d\n", a + b);
    }
    return 0;
}
</code></pre></td></tr>
<tr>
<td>C++</td>
<td>
<pre><code>#include &lt;iostream&gt;
	
using namespace std;

int main(void) 
{
    int a, b;
    while(cin &gt;&gt; a &gt;&gt; b) 
    {
    	cout &lt;&lt; a + b &lt;&lt; endl;
    }
    return 0;
}</code></pre></td></tr>
<tr>
<td>Java</td>
<td>
<pre><code>import java.util.Scanner;
	
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
        	int a = in.nextInt();
        	int b = in.nextInt();
        	System.out.println(a + b);
        }
    }
}
</code></pre></td></tr>
<tr>
<td>C#</td>
<td><pre><code>using System;

public class AplusB
{
    private static void Main()
    {
        string line;
        while((line = Console.ReadLine()) != null)
        {
            string[] tokens = line.Split(' ');
            Console.WriteLine(int.Parse(tokens[0]) + int.Parse(tokens[1]));
        }
    }
}
</code></pre></td></tr>
<tr>
	<td>Python2</td>
	<td>
<pre><code>while True:
    try:
        (x, y) = (int(x) for x in raw_input().split())
        print x + y
    except EOFError:
        break</code></pre>
<pre><code>import sys 
for line in sys.stdin: 
    (x, y) = (int(x) for x in line.split())
    print x + y</code></pre></td>
</tr>
</tbody>
</table>
