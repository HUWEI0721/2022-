/* 软件 2153393 胡峻玮 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int m = 0;
    while (str[m] != '\0')
        m += 1;
    return m; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int i = 0;
    for (i; i < len2;i++)
        s1[i + len1] = s2[i];
    s1[i + len1] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int len0, i;
    if (len2 > len)
        len0 = len;
    else
        len0 = len2;
    for (i = 0; i < len0; i++) 
        s1[i + len1] = s2[i];
    s1[i + len1] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = 0; i <= tj_strlen(s2); i++)
        s1[i] = s2[i];
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(s2);
    int j = 0;
    int len0;
    if (len <= len_h)
        len0 = len;
    else
        len0 = len_h;
    for (int i = 0; i < len0; i++)
    {
        if (s2[i] == '\0')
            i++;
        s1[j] = s2[i];
        j++;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int len0;
    if (len1 < len2)
        len0 = len1;
    else
        len0 = len2;
    for (int i = 0; i <= len0; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int len0;
    if (len1 < len2)
        len0 = len1;
    else
        len0 = len2;
    for (int i = 0; i <= len0; i++)
    {
        char a1 = s1[i];
        char a2 = s2[i];
        if (a1 >= 'A' && a1 <= 'Z')
            a1 += 32;
        if (a2 >= 'A' && a2 <= 'Z')
            a2 += 32;
        if (a1 != a2)
            return a1 - a2;
        else
            continue;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int len0;
    if (len1 < len2)
        len0 = len1;
    else
        len0 = len2;
    if (len0 < len)
        len0 = len0;
    else
        len0 = len - 1;
    for (int i = 0; i <= len0; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    int len0;
    if (len1 < len2)
        len0 = len1 + 1;
    else
        len0 = len2 + 1;
    if (len0 < len)
        len0 = len0;
    else
        len0 = len;
    for (int i = 0; i < len0; i++)
    {
        char a1 = s1[i];
        char a2 = s2[i];
        if (a1 >= 'A' && a1 <= 'Z')
            a1 += 32;
        if (a2 >= 'A' && a2 <= 'Z')
            a2 += 32;
        if (a1 != a2)
            return a1 - a2;
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(str);
    for (int i = 0; i < len_h; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(str);
    for (int i = 0; i < len_h; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(str);
    for (int i = 0; i < len_h; i++) 
    {
        if (str[i] == ch)
            return i + 1;
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int flag = -1;
    int len_str = tj_strlen(str);
    int len_substr = tj_strlen(substr);
    for (int i = 0; i < len_str; i++)
    {
        if (str[i] == substr[0])
        {
            for (int j = 0; j < len_substr; j++)
            {
                if (str[i + j] != substr[j])
                {
                    flag = 1;
                    break;
                }
                else
                    continue;
            }
            if (flag == -1)
                return i + 1;
            else
                flag = -1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(str);
    for (int i = len_h - 1; i >= 0; i--)
    {
        if (str[i] == ch)
            return i + 1;
        else
            continue;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int flag = -1;
    int len_str = tj_strlen(str);
    int len_substr = tj_strlen(substr);
    int j = 0;
    int i = len_str - len_substr;
    for (; i >= 0; i--, j++)
    {
        if (str[i] == substr[0])
        {
            for (int j = 0; j < len_substr; j++)
            {
                if (str[i + j] != substr[j])
                {
                    flag = 1;
                    break;
                }
                else
                    continue;
            }
            if (flag == -1)
                return i + 1;
            else
                flag = -1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_h = tj_strlen(str);
    int middle = (len_h + 1) / 2;
    int tmp;
    for (int i = 0; i < middle; i++)
    {
        tmp = str[i];
        str[i] = str[len_h - i - 1];
        str[tj_strlen(str) - i - 1] = tmp;
    }
    return 0; //return值可根据需要修改
}
