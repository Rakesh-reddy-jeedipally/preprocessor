#include "header.h"
void *commentremove(char *str)
{
        char *ptr = NULL;
        ptr = str;

        char *first = NULL, *last = NULL;
        char sub1[] = "//";
        char sub2[] = "\n";
        int n;
        char s1[] = "/*";
        char s2[] = "*/";
        int in_string = 0;
        int in_char = 0;
        //remove single comment
        while ((ptr = strstr(ptr, sub1)) != NULL)
        {
                in_string = 0;
                in_char = 0;
                char *temp = str;
                while (temp < ptr)
                {
                        if (*temp == '"' && (temp == str || *(temp - 1) != '\\'))
                                in_string = !in_string;
                        if (*temp == '\'' && (temp == str || *(temp - 1) != '\\'))
                                in_char = !in_char;
                        temp++;
                }
                if (in_string || in_char)
                {
                        ptr = ptr + 2;
                        continue;
                }
                first = ptr;

                while ((ptr = strstr(ptr, sub2)) != NULL)
                {
                        last = ptr;
                        break;
                }
                ptr = first;
                memmove(first, last, strlen(last) + 1);
        }
        ptr = str;
        while ((ptr = strstr(ptr, s1)) != NULL)
        {
                in_string = 0;
                in_char = 0;
                char *temp = str;
                while (temp < ptr)
                {
                        if (*temp == '"' && (temp == str || *(temp - 1) != '\\'))
                                in_string = !in_string;

                        if (*temp == '\'' && (temp == str || *(temp - 1) != '\\'))
                                in_char = !in_char;
                        temp++;
                }
                if (in_string || in_char)
                {
                        ptr = ptr + 2;
                        continue;
                }
                first = ptr;
                while ((ptr = strstr(ptr, s2)) != NULL)
                {
                        last = ptr;
                        break;
                }
                if (*(last + 2) == '\n')
                {
                        n = 3 + last - first;
                }
                else
                {
                        n = 2 + last - first;
                }
                ptr = first;
                memmove(ptr, ptr + n, strlen(ptr + n) + 1);
        }
        return str;
}
