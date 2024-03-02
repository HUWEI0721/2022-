/* 2153393 胡峻玮 软件 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    if (str == NULL)
        return 0;
    while (*str != '\0')
    {
        str++;
        count++;
    }
    return count;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL || s2 == NULL)
        return p;
    while (*s1 != '\0')
        s1++;
    while (*s2 != '\0')
    {
        *s1 = *s2; 
        s1++;
        s2++;
    }
    *s1 = *s2;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    int i = len;
    if (s1 == NULL || s2 == NULL)
        return p;
    while (*s1 != '\0')
        s1++;
    while (i && *s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
        i--;
    }
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return p;
    }
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = 0;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    char* p = s1;
    int i = len;
    if (s1 == NULL || s2 == NULL)
        return p;
    while (i && *s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
        i--;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    while (*s1 != 0 && *s2 != 0) 
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    if (*s1 != 0 || *s2 != 0)
        return *s1 - *s2;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char ch1, ch2;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    while (1)
    {
        if (*s1 != 0 && *s2 != 0)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                ch1 = *s1 + 32;
            else
                ch1 = *s1;
            if (*s2 >= 'A' && *s2 <= 'Z')
                ch2 = *s2 + 32;
            else
                ch2 = *s2;
            if (ch1 != ch2)
                return ch1 - ch2;
            s1++;
            s2++;
        }
        else
            break;
    }
    if (*s1 != 0 || *s2 != 0)
        return *s1 - *s2;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    
    while (1)
    {
        if (*s1 != 0 && *s2 != 0 && s1 - p < len)
        {
            if (*s1 != *s2)
                return *s1 - *s2;
            s1++;
            s2++;
        }
        else
            break;
    }
    if (s1 - p != len)
        return *s1 - *s2;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    char ch1 = *s1;
    char ch2 = *s2;
    const char* p = s1;
    while (1)
    {
        if (*s1 != 0 && *s2 != 0 && s1 - p < len)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                ch1 = *s1 + 32;
            else
                ch1 = *s1;
            if (*s2 >= 'A' && *s2 <= 'Z')
                ch2 = *s2 + 32;
            else
                ch2 = *s2;
            if (ch1 != ch2)
                return ch1 - ch2;
            s1++;
            s2++;
        }
        else
            break;
    }
    if (s1 - p != len) 
    {
        if (*s1 >= 'A' && *s1 <= 'Z')
            ch1 = *s1 + 32;
        else
            ch1 = *s1;
        if (*s2 >= 'A' && *s2 <= 'Z')
            ch2 = *s2 + 32;
        else
            ch2 = *s2;
        return ch1 - ch2;
    }
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        str++;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    for (int i = 1; *str != '\0';i++)
    {
        if (*str == ch)
            return i;
        str++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int flag = 0;
    int i = 1, j = 0;
    if (str == NULL || substr == NULL||(tj_strlen(substr) > tj_strlen(str)))
        return 0;
    while (1)
    {
        if (*str != '\0' && *substr != '\0')
        {
            if (*str == *substr)
            {
                while (*str != '\0' && *substr != '\0')
                {
                    if (*str != *substr)
                    {
                        substr -= j;
                        str -= j;
                        flag = 1;
                        break;
                    }
                    j++;
                    substr++;
                    str++;
                }
                if (flag == 0)
                    return i;
                else
                    flag = 0;
            }
            str++, i++;
        }
        else
            break;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    int len = tj_strlen(str);
    str = str + tj_strlen(str) - 1;
    for (int i = len; i >= 0; i--)
    {
        if (*str == ch)
            return i;
        str--;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int flag = 0;
    if (str == NULL || substr == NULL || (tj_strlen(substr) > tj_strlen(str)))
        return 0;
    int len = tj_strlen(str);
    str = str + tj_strlen(str) - 1;
    int i = len, j = 0;
    while (1)
    {
        if (*str != '\0' && *substr != '\0')
        {
            if (*str == *substr)
            {
                while (*str != '\0' && *substr != '\0')
                {
                    if (*str != *substr)
                    {
                        substr -= j;
                        str -= j;
                        flag = 1;
                        break;
                    }
                    j++;
                    substr++;
                    str++;
                }
                if (flag == 0)
                    return i;
                else
                    flag = 0;
            }
            str--;
            i--;
        }
        else
            break;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str,* q = str;
    q += tj_strlen(str) - 1;
    char temp;
    for (; p < q; p++, q--)
    {
        temp = *p;
        *p = *q;
        *q = temp;
    }
    return str;
}
