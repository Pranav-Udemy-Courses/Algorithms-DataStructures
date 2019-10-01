#include <iostream>

using namespace std;

/* Compare two Strings */
void CompareStrings(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    for (; s1[i] != '\0' && s2[j] != '\0'; ++i, ++j)
    {
        if (s1[i] != s2[j])
            break;
    }
    if (s1[i] == s2[j])
        cout << "String " << s1 << " and String " << s2 << " both are equal" << endl;
    else if (s1[i] > s2[j])
        cout << "String " << s1 << " is greater than String " << s2 << endl;
    else
        cout << "String " << s1 << " is smaller than String " << s2 << endl;
}

/* Determine if the given String is a Palindrome */
void IsPalindrome(char str[])
{
    int j = 0;
    int i = 0;
    for (; str[j] != '\0'; ++j)
    {
    }
    j--;
    bool isPalindrome = true;
    for (; i < j; ++i, --j)
    {
        if (str[i] != str[j])
        {
            cout << str << " is not a Palindrome" << endl;
            isPalindrome = false;
        }
    }

    if (isPalindrome)
        cout << str << " is a Palindrome " << endl;
}

/* Find duplicates in the given String using Hashing */
void DuplicatesUsingHashing(const char* str, bool lowerCase = true)
{
    int diff = lowerCase ? 97 : 65;

    cout << "Duplicates in the given String " << str << " are : " << endl;
    int* s = new int[26]{ 0 };
    for (int i = 0; str[i] != '\0'; ++i)
    {
        s[str[i] - diff]++;
    }

    for (int i = 0; s[i] < 26; ++i)
    {
        if (s[i] > 1)
            cout << static_cast<char>(i + diff) << " is repeated " << s[i] << " times " << endl;
    }
    delete[] s;
    s = nullptr;
}

/* Find duplicates in the given String using Bitwise Operations */
void DuplicatesUsingBitwise(const char* str, bool lowerCase = true)
{
    int diff = lowerCase ? 97 : 65;
    cout << "Duplicates in the given String " << str << " are : ";
    int temp = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        int x = 1;
        x = x << (str[i] - diff);
        if (x & temp)   // x & temp is masking
            cout << str[i] << " ";
        else
        {
            temp = x | temp; // x | temp is merging
        }
    }
    cout << endl;
}

/* Permutations of String using Auxiliary Method */
void PermuteAux(char str[], int k)
{
    static int A[10]{ 0 };
    static char res[10]{ 0 };
    int i;
    if (str[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (i = 0; str[i] != '\0'; ++i)
        {
            if (A[i] == 0)
            {
                A[i] = 1;
                res[k] = str[i];
                PermuteAux(str, k + 1);
                A[i] = 0;
            }
        }
    }
}

/* Swap two characters */
void Swap(char* c1, char* c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

/* Permutations of String using Swap Method */
void PermuteSwap(char str[], int l, int h)
{
    if (l == h)
        cout << str << endl;
    else
    {
        for (int i = l; i <= h; ++i)
        {
            Swap(&str[i], &str[l]);
            PermuteSwap(str, l + 1, h);
            Swap(&str[i], &str[l]);
        }
    }

}

int main()
{
    char a[] = "PranavShah";
    char b[] = "Pranav";
    char c[] = "Pranav";
    char d[] = "Shah";

    // Check if two strings are same
    CompareStrings(a, b);
    CompareStrings(b, c);
    CompareStrings(c, d);

    char e[] = "madam";
    char f[] = "maddeam";

    // Check if the given string is a palindrome
    IsPalindrome(e);
    IsPalindrome(f);

    // Finding Duplicates in the given String
    DuplicatesUsingHashing("finding");
    DuplicatesUsingHashing("FIINDING", false);
    DuplicatesUsingBitwise("finding");
    DuplicatesUsingBitwise("FINDING", false);

    // String Permutations
    char str[] = "abc";
    cout << "Permutations for String " << str << " using Auxiliary method are " << endl;
    PermuteAux(str, 0);
    cout << "Permutations for String " << str << " using Swap method are " << endl;
    PermuteSwap(str, 0, 2);
    system("pause");
    return 0;
}

/*
Output
String PranavShah is greater than String Pranav
String Pranav and String Pranav both are equal
String Pranav is smaller than String Shah
madam is a Palindrome
maddeam is not a Palindrome
Duplicates in the given String finding are :
i is repeated 2 times
n is repeated 2 times
Duplicates in the given String FIINDING are :
I is repeated 3 times
N is repeated 2 times
Duplicates in the given String finding are : i n
Duplicates in the given String FINDING are : I N
Permutations for String abc using Auxiliary method are
abc
acb
bac
bca
cab
cba
Permutations for String abc using Swap method are
abc
acb
bac
bca
cba
cab
*/