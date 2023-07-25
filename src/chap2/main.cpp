#include <iostream>

namespace factorial
{
	bool IsValidFactorial(int factorial)
    {
        int result=1;
        for(int i=1;; i++)
        {
            result *= i;
            if(result == factorial)
                return true;
            else if(result > factorial)
                break;
        }
        return false;
    }

    bool IsNumber(const std::string& data)
    {
        return !data.empty() && (std::find_if(data.begin(), data.end(), [](const char& ch){
            return !std::isdigit(static_cast<int>(ch));
        }) == data.end());
    }

    void f_2_4_4()
    {
        std::cout<<"Enter factorial number(n), n>0: ";
        std::string number;
        std::cin>>number;
        assertm(IsNumber(number) && number!="0", "n is not a valid number");
        int n = std::stoi(number);
        
        if(IsValidFactorial(n))
        {
            for(int i=1;; i++)
            {
                if(n%i)
                {
                    std::cout<<"Max factorial number is " << i-1 <<std::endl;
                    break;
                }
            }
        }
        else
        {
            std::cout<<"!! Not a valid factorial number.!!"<<std::endl;
        }
    }
}

// Algorithm to compute sum of 'n' no's s=1-3+5-7+9-....., reads from standard input.
void f_2_3_8()
{
    int index=1;
    int result=1;
    int n;
    std::cout<<"Enter no of values to compute(n): ";
    std::cin >> n;
    for(int i=1; index<n; i+=2,index++)
    {
        if(index%2)
        {
            result -= i+2;
        }
        else
        {
            result += i+2;
        }
    }
    std::cout<<"result: " << result<<std::endl;
}

void f_2_2_1()
{
    float maxMarks=100.0;
    unsigned int noOfPasses=0;
    unsigned int totalMarks=0;
    std::vector < std::string > marks;
    std::ifstream file ("marks.txt");
    if (file.is_open ())
    {
        while (!file.eof())
	    {
	        std::string value;
	        std::getline(file, value);
	        marks.push_back(value);
	        auto intVal = std::stoi(value); //throws exception, need to handle.
	        if(std::stoi(value) >= 50)
	        {
	            ++noOfPasses;
	        }
	        totalMarks+=intVal;
	    }
    }
    
    //auto totalMarks =  std::accumulate(marks.begin(), marks.end());
    std::cout<<"Total marks: " << totalMarks<<std::endl;
    std::cout<<"no of pass marks: " << noOfPasses <<std::endl;
    std::cout<<"Percentage pass rate: " << std::floor(maxMarks/static_cast<float>(marks.size()) * static_cast<float>(noOfPasses)) << "%" << std::endl;
}

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

int main()
{
  f_3_1_1(64);
  return 0;
}
