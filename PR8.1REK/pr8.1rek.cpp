#include <iostream>
#include <cstring>

using namespace std;

bool SearchPair(const char* str, int i = 0)
{
    if (str[i] == '\0' || str[i + 1] == '\0')
        return false;

    if ((str[i] == 'n' && str[i + 1] == 'o') ||
        (str[i] == 'o' && str[i + 1] == 'n'))
    {
        return true;
    }

    return SearchPair(str, i + 1);
}

int ReplaceNoRecursive(const char* str, char* result, int i, int j)
{
    if (str[i] == '\0')
    {
        result[j] = '\0';
        return j;
    }

    if (str[i] == 'n' && str[i + 1] == 'o')
    {
        result[j++] = '*';
        result[j++] = '*';
        result[j++] = '*';

     
        return ReplaceNoRecursive(str, result, i + 2, j);
    }
    else
    {
     
        result[j++] = str[i];

        return ReplaceNoRecursive(str, result, i + 1, j);
    }
}

char* ReplaceNo(const char* str)
{
    int len = strlen(str);

    char* result = new char[len * 2 + 1];

    ReplaceNoRecursive(str, result, 0, 0);

    return result;
}

int main()
{
    char str[101];

    cout << "Enter string: ";
    cin.getline(str, 101);


    if (SearchPair(str))
        cout << "There is a pair 'no' or 'on'." << endl;
    else
        cout << "There is no pair 'no' or 'on'." << endl;

    char* result = ReplaceNo(str);

    cout << "Original string: " << str << endl;
    cout << "Modified string: " << result << endl;

    delete[] result;

    return 0;
}
