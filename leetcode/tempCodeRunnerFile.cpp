int len = s1.length();
    int len_ji = len / 2;
    int len_ou = len - len_ji;
    char s1_ou[100000], s1_ji[100000], s2_ou[100000], s2_ji[100000];
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            s1_ou[i / 2] = s1[i];
            s2_ou[i / 2] = s2[i];
        }
        else
        {
            s1_ji[i / 2] = s1[i];
            s2_ji[i / 2] = s2[i];
        }
    }

    sort<char *>(s1_ou, s1_ou + len_ou);
    sort<char *>(s2_ou, s2_ou + len_ou);
    sort<char *>(s1_ji, s1_ji + len_ji);
    sort<char *>(s2_ji, s2_ji + len_ji);

    return !strcmp(s1_ou, s2_ou) && !strcmp(s1_ji, s2_ji);