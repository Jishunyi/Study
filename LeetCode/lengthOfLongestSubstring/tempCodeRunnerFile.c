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
                else if (j == max) //无重复字符
                {
                    return max;
                }
            }
        }
    }
    return max;