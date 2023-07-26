// Square root
int f_3_1_1(int number)
{
    if(number < 2)
        return number;
  
    int result = -1;
    int g2 = number/2;
    int g1 = g2;
    
    while((g2*g2) >= number)
    {
        g1 = g2;
        g2 = (g1 + number/g1)/2;
        if(g2*g2 == number)
        {
            result = g2;
            break;
        }
    }
    return result;
}

int f_3_1_1()
{
    if(number < 2)
        return number;
}
