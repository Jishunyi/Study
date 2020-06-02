<center><font face ="楷体" color = red size ="64">Markdown 学习笔记</font></center>

***
# 段落格式
1. **字体**
    > + *斜体*
    > + **粗体**
    > + ***斜粗体***
2. **划线**
    > - <u>下划线</u>
    > - ~~删除线~~
3. **脚注**
    > * 列表有多种方式[^1]
    > * 区块有多种方式[^2]
   
    [^1]:无序列表使用星号(+)、加号(-)或减号(*)作为列表标记
    [^2]:区块可嵌套，一个(>)符号是第一层，两个(>)符号是第二层嵌套，以此类推
4. **链接**
    > + [博客链接](https://shunyi.fun/)
    > + <https://shunyi.fun/>
***
# 代码片段
1. **行内代码**
    在一句话内的代码`printf("Hello Markdown\n");`
2. **代码块**
```C
    #include <stdio.h>
    int main(void)
    {
        printf("Hello World\n");
        return 0;
    }
```
***
# 展示图表
1. **图片**
    ![HomePage](https://shunyi.fun/wp-content/uploads/2019/06/home-page-1-e1561725613867.jpg)
2. **表格**
    | 左对齐 | 居中  | 右对齐 |
    | :----- | :---: | -----: |
    | 123    |  123  |    123 |
    | 1234   | 1234  |   1234 |
    | 12345  | 12345 |  12345 |
***
# HTML支持
1. **键盘**
   预览快捷键：<kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>V</kbd>