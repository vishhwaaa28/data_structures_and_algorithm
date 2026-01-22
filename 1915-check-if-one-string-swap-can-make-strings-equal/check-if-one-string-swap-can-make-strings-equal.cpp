class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        char diffChar1, diffChar2;
        int diff = 0;

        for (int i = 0; i < s1.length(); i++)
        {

            if (s1[i] != s2[i])
            {
                diff++;
                if (diff == 1)
                {
                    diffChar1 = s1[i];
                    diffChar2 = s2[i];
                }
                else if (diff == 2)
                {
                    if (s1[i] != diffChar2 || s2[i] != diffChar1)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return (diff == 0 || diff == 2);
    }
};