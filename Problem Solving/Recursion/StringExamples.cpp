#include <iostream>

using namespace std;

long GetLength(char str[])
{
  if(str[0] == '\0')
  {
    return 0;
  }

  return 1 + GetLength(str + 1);
}

void RemoveX(char str[])
{
  if(str[0] == '\0')
  {
    return;
  }

  if(str[0] != 'x')
  {
    return RemoveX(str + 1);
  }
  else
  {
    // Shift all characters one place to left.
    int i = 1;

    for(; str[i] != '\0'; ++i)
    {
      str[i - 1] = str[i];
    }

    // We also have to shift the null character at the end as well
    str[i - 1] = str[i];

    return RemoveX(str);
  }
}

void RemoveConsecutiveDuplicates(char str[], long length)
{
  if(length <= 1)
  {
    return;
  }

  if(str[0] != str[1])
  {
    RemoveConsecutiveDuplicates(str + 1, length - 1);
  }
  else
  {
    // Shift all characters one place to left.
    int i = 1;

    while(str[i] != '\0')
    {
      str[i - 1] = str[i];
      ++i;
    }

    // Shift the null character at the end as well.
    str[i - 1] = str[i];

    RemoveConsecutiveDuplicates(str, length - 1);
  }
}

int main(int argc, char const *argv[])
{
  char s1[] = "ABCD";
  long s1Length = GetLength(s1);

  cout << s1Length << endl;

  char s2[] = "xabcxabcdex";

  RemoveX(s2);

  cout << s2 << endl;

  char s3[] = "aabbbcdda";

  RemoveConsecutiveDuplicates(s3, 9);

  cout << s3 << endl;

  return 0;
}
