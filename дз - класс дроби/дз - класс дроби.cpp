#include <iostream>


class Fraction
{
public:

    // создание дроби
    Fraction(int chisl, int znam):chislitel_(chisl), znamenatel_(znam), tseloe_(0) {}

    Fraction(int tseloe, int chisl, int znam) :tseloe_(tseloe), chislitel_(chisl), znamenatel_(znam) {}

    // вывод
    void Print(Fraction& obj)
    {
        if (obj.tseloe_ != 0)
        {
            std::cout << obj.tseloe_ << " " << obj.chislitel_ << "/" << obj.znamenatel_ << "\n";
        }
        else
        {
            std::cout << obj.chislitel_ << "/" << obj.znamenatel_ << "\n";
        }

    }

    // НОК для знаменателей
    int NOK(int& a, int& b)
    {
        int max = (a > b) ? a : b;
        do
        {
            if (max % a == 0 && max % b == 0)
            {
                return max;
                break;
            }
            else
                ++max;
        } while (true);

    }
  
    // НОД для знаменателей
    int NOD(int a, int b)
    {
        a = abs(a), b = abs(b);
        if (b == 0)return a;
        else return NOD(b, a % b);
    }
    
    // перевод неправильных дробей в смешанные числа
    Fraction MixedNumber(int &chisl_res, int &znam_res)
    {
        if (chisl_res > 0)
        {
            if (chisl_res >= znam_res)
            {
                int tseloe = chisl_res / znam_res;
                int chislV2 = chisl_res - (tseloe * znam_res);
                Fraction result(tseloe, chislV2, znam_res);
                return result;
            }
            else
            {
                Fraction result(chisl_res, znam_res);
                return result;
            }
        }
        else
        {
            if (chisl_res*-1 >= znam_res)
            {
                int tseloe = chisl_res / znam_res;
                int chislV2 = (chisl_res - (tseloe * znam_res)) *-1;
                Fraction result(tseloe, chislV2, znam_res);
                return result;
            }
            else
            {
                Fraction result(chisl_res, znam_res);
                return result;
            }
        }
        
    }

    // перевод смешанных чисел в неправильные дроби
    Fraction IncorrectFr(Fraction&smeshannoe)
    {
        int chisl_res = smeshannoe.tseloe_ * smeshannoe.znamenatel_ + smeshannoe.chislitel_;
        Fraction result(chisl_res, smeshannoe.znamenatel_);
        return result;
    }

    // поиск доп множителя для числителей
    int AddMultiplier(int &max, int &a)
    {
        int dopmnozh = max / a;
        return dopmnozh;
    }

    // сложение
    Fraction Summa(Fraction&first, Fraction &second)
    {
        int chisl_res;
        int znam_res;

        if (first.znamenatel_ == second.znamenatel_)
        {
            chisl_res = first.chislitel_ + second.chislitel_;
            Fraction result(chisl_res, first.znamenatel_);
            return result;
           
        }
        else
        {
            int znam_res = first.NOK(first.znamenatel_, second.znamenatel_); 
            int dopmnozhFirst = first.AddMultiplier(znam_res, first.znamenatel_);
            int dopmnozhSecond = second.AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (first.chislitel_ * dopmnozhFirst) + (second.chislitel_ * dopmnozhSecond);

            return first.MixedNumber(chisl_res, znam_res);
      
        }
    }

    // вычитание
    Fraction Subtraction(Fraction& first, Fraction& second)
    {
        int chisl_res;
        int znam_res;
        if (first.znamenatel_ == second.znamenatel_)
        {
            chisl_res = first.chislitel_ - second.chislitel_;
            Fraction result(chisl_res, first.znamenatel_);
            return result;
        }
        else
        {
            int znam_res = first.NOK(first.znamenatel_, second.znamenatel_); 
            int dopmnozhFirst = first.AddMultiplier(znam_res, first.znamenatel_);
            int dopmnozhSecond = second.AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (first.chislitel_ * dopmnozhFirst) - (second.chislitel_ * dopmnozhSecond);

            return first.MixedNumber(chisl_res, znam_res);
        }
        
    }

    // умножение
    Fraction Multiply(Fraction& first, Fraction& second)
    {
        int ch = first.chislitel_ * second.chislitel_;
        int zn = first.znamenatel_ * second.znamenatel_;

        int nod = first.NOD(ch, zn);

        int chisl_res = ch / nod;
        int znam_res = zn / nod;

        return first.MixedNumber(chisl_res, znam_res);
    }

    // деление
    Fraction Division(Fraction& first, Fraction& second)
    {

        int chisl_tmp = second.znamenatel_;
        int znam_tmp = second.chislitel_;
        int chisl_res = first.chislitel_ * chisl_tmp;
        int znam_res = first.znamenatel_ * znam_tmp;

        return first.MixedNumber(chisl_res, znam_res);

    }


private:

    int chislitel_;
    int znamenatel_;
    int tseloe_;
    
};

int main()
{
    int chislA;
    int znamA;
    int chislB;
    int znamB;
    std::cout << "**************************************\n";
    std::cout << "Enter numerator for first fraction: ";
    std::cin >> chislA;
    std::cout << "Enter denominator for first fraction: ";
    std::cin >> znamA;
    std::cout << "Enter numerator for second fraction: ";
    std::cin >> chislB;
    std::cout << "Enter denominator for second fraction: ";
    std::cin >> znamB;

    Fraction A(chislA,znamA);
    Fraction B(chislB, znamB);
    
    std::cout << "Fractions:\n";
    A.Print(A);
    A.Print(B);
    
    std::cout << "Multiply:\n";
    Fraction res1 = A.Multiply(A, B);
    res1.Print(res1);

    std::cout << "Summa:\n";
    Fraction res2 = A.Summa(A, B);
    res2.Print(res2);
    
    std::cout << "Substraction:\n";
    Fraction res3 = A.Subtraction(A, B);
    res3.Print(res3);

    std::cout << "Division:\n";
    Fraction res4 = A.Division(A, B);
    res4.Print(res4);

}

