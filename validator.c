int isnum(char *str)
{
    int i;
    i = 0;

    if (str[i] = '-' || str[i] = '+')
        i++;
    if (str[i] = '\0')
        return (0);
    while(str[i] != '\0')
    {
        if (str[i] < '0' && str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
long	atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		++nptr;
	}
	return ((res) * (sign));
}