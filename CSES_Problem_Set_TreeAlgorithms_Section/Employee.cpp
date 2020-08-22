int Em char for (int i = 0; i < log_count; i++)
{
    char *row = (log + i);
    char starttime[100], endtime[100];
    int s = 0, e = 0;
    int comma = 0;
    for (int j = 0; j < strlen(row); j++)
    {
        if (row[j] == ',')
        {
            comma++;
        }
        else if (comma >= 1)
        {
            starttime[s++] = row[j];
        }
        else if (comma >= 2)
        {
            endtime[e++] = row[j];
        }
    }
}