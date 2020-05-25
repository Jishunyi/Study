/*
 * @Author       : Shunyi
 * @Date         : 2020-05-22 15:05:18
 * @LastEditors  : Shunyi
 * @LastEditTime : 2020-05-25 14:29:33
 * @Blog         : https://shunyi.fun/
 * @FilePath     : \VSCode\Study\LeetCode\lengthOfLongestSubstring\lengthOfLongestSubstring.c
 */
/*
 *给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 *示例 1:
 *输入: "abcabcbb"
 *输出: 3 
 *解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

 *示例 2:
 *输入: "bbbbb"
 *输出: 1
 *解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

 *示例 3:
 *输入: "pwwkew"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
int lengthOfLongestSubstring(char *s)
{
    char *s1, *s2;                                      //理论上最长的无重复子串 由所有字符组成
    static int i, j, max;                               //s1
    s1 = (char *)calloc((strlen(s) + 1), sizeof(char)); //分配空间并全部置为0
    s2 = (char *)calloc((strlen(s) + 1), sizeof(char)); //分配空间并全部置为0

    //找出所有存在过的字符 //总数为理论上的最长无重复子串长度
    for (max = 0, j = 0; j < strlen(s); j++)
    {
        if (!(strchr(s1, s[j]))) //未收录过该字符
        {
            s1[max] = s[j];
            max++;
        }
    }
    printf("%s\n", s1);
    //按步长查找
    for (max; max > 0; max--)
    {
        for (i = 0; i < strlen(s) + 1 - max; i++)
        {
            strncpy(s2, s + i, max);
            s2[max] = '\0';
            printf("%s\n", s2);
            for (j = 0; j < strlen(s1); j++)
            {
                if (((strchr(s2, s1[j])) != strrchr(s2, s1[j]))) //该字符在片段中出现过多次
                {
                    break;
                }
                if (j == strlen(s1) - 1)
                {
                    return max;
                }
            }
        }
    }
    return max;
}

int main(void)
{
    char s[] = "hkcpmprxxxqw";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}