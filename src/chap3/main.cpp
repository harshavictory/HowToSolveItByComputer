// Square root
float f_3_1_1(float number)
{
    float g2 = number/2;
    float g1 = g2;
    const float err = 0.0001;
    
    while(std::abs(g1-g2) < err)
    {
        g1 = g2;
        g2 = (g1 + number/g1)/2.0;
    }
    return g2;
}

//Find smalled divisor of a number.
int f_3_2_1(int number)
{
    if(number%2 ==0) // if number is even, then smallest would be div'ble by 2 which is lowest divisor.
    {
        return 2;
    }
    else
    {
        const int sqRoot = f_3_1_1(number); //compute square root first.
        std::cout<<"sqRoot" << sqRoot<<std::endl;
        int divisor = 3;
        while(divisor < sqRoot)
        {
            if(number%divisor == 0)
                return divisor;
            divisor += 2;
        }
    }
    return 1; // This case occurs if the number is prime.
}
