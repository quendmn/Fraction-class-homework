#include <iostream>

class Fraction
{
public:

    // создание дроби
    Fraction() = default;

    explicit Fraction(int chisl, int znam):chislitel_(chisl), znamenatel_(znam), tseloe_(0) {}

    explicit Fraction(int tseloe, int chisl, int znam) :tseloe_(tseloe), chislitel_(chisl), znamenatel_(znam) {}

    // вывод
    void Print()
    {
        if (this->tseloe_ != 0)
        {
            std::cout << this->tseloe_ << " " << this->chislitel_ << "/" << this->znamenatel_ << "\n";
        }
        else
        {
            std::cout << this->chislitel_ << "/" << this->znamenatel_ << "\n";
        }

    }

    // НОК для знаменателей
    static int NOK(const int& a, const int& b)
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
    static int NOD(int a, int b)
    {
        a = abs(a), b = abs(b);
        if (b == 0)return a;
        else return NOD(b, a % b);
    }
    
    // перевод неправильных дробей в смешанные числа
    static Fraction MixedNumber(int &chisl_res, int &znam_res)
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
    static int AddMultiplier(const int &max, const int &a)
    {
        int dopmnozh = max / a;
        return dopmnozh;
    }

    // сложение
    Fraction Summa(Fraction &second)
    {
        int chisl_res;
        int znam_res;

        if (this->znamenatel_ == second.znamenatel_)
        {
            chisl_res = this->chislitel_ + second.chislitel_;
            Fraction result(chisl_res, this->znamenatel_);
            return result;
           
        }
        else
        {
            int znam_res = this->NOK(this->znamenatel_, second.znamenatel_);
            int dopmnozhFirst = this->AddMultiplier(znam_res, this->znamenatel_);
            int dopmnozhSecond = second.AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (this->chislitel_ * dopmnozhFirst) + (second.chislitel_ * dopmnozhSecond);

            return this->MixedNumber(chisl_res, znam_res);
      
        }
    }

    // вычитание
    Fraction Subtraction(Fraction& second)
    {
        int chisl_res;
        int znam_res;
        if (this->znamenatel_ == second.znamenatel_)
        {
            chisl_res = this->chislitel_ - second.chislitel_;
            Fraction result(chisl_res, this->znamenatel_);
            return result;
        }
        else
        {
            int znam_res = this->NOK(this->znamenatel_, second.znamenatel_);
            int dopmnozhFirst = this->AddMultiplier(znam_res, this->znamenatel_);
            int dopmnozhSecond = second.AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (this->chislitel_ * dopmnozhFirst) - (second.chislitel_ * dopmnozhSecond);

            return this->MixedNumber(chisl_res, znam_res);
        }
        
    }

    // умножение
    Fraction Multiply(Fraction& second)
    {
        int ch = this->chislitel_ * second.chislitel_;
        int zn = this->znamenatel_ * second.znamenatel_;

        int nod = this->NOD(ch, zn);

        int chisl_res = ch / nod;
        int znam_res = zn / nod;

        return this->MixedNumber(chisl_res, znam_res);
    }

    // деление
    Fraction Division(Fraction& second)
    {

        int chisl_tmp = second.znamenatel_;
        int znam_tmp = second.chislitel_;
        int chisl_res = this->chislitel_ * chisl_tmp;
        int znam_res = this->znamenatel_ * znam_tmp;

        return this->MixedNumber(chisl_res, znam_res);

    }

    // получить числитель
    int GetChislitel()
    {
        return this->chislitel_;
    }
    // получить знаменатель
    int GetZnamenatel()
    {
        return this->znamenatel_;
    }

    // получить целую часть
    int GetInteger()
    {
        return this->tseloe_;
    }

    // получить нецелую часть
    int GetNotInteger()
    {
        GetChislitel();
        GetZnamenatel();
    }

    // получить дробь
    int GetFraction()
    {
        GetInteger();
        GetChislitel();
        GetZnamenatel();
        return GetChislitel();
    }

    // получить обратную дробь
    Fraction GetReverse()
    {
        this->chislitel_ = this->znamenatel_;
        this->znamenatel_ = this->chislitel_;

        return *this;

    }

    // унарный минус
    Fraction un_minus()
    {
        if (this->chislitel_ > 0)
        {
            this->chislitel_ = this->chislitel_ * -1;
        }
        else if (this->znamenatel_ > 0)
        {
            this->znamenatel_ = this->znamenatel_ * -1;
        }
        else if (this->tseloe_ > 0)
        {
            this->tseloe_ = this->tseloe_ * -1;
        }
        return *this;
    }

    // унарный плюс
    Fraction un_plus()
    {
        if (this->chislitel_ < 0)
        {
            this->chislitel_ = this->chislitel_ * -1;
        }
        else if (this->znamenatel_ < 0)
        {
            this->znamenatel_ = this->znamenatel_ * -1;
        }
        else if (this->tseloe_ < 0)
        {
            this->tseloe_ = this->tseloe_ * -1;
        }
        return *this;
    }

    // инкремент
    Fraction decrement()
    {
        this->chislitel_--;
        this->znamenatel_--;
        if (this->chislitel_ < 0)
        {
            this->chislitel_ = this->znamenatel_;
            this->tseloe_--;
        }
        return *this;
    }

    // инкремент
    Fraction increment()
    {
        this->chislitel_++;
        this->znamenatel_++;
        if (this->chislitel_ > this->znamenatel_)
        {
            this->chislitel_ = 0;
            this->tseloe_++;
        }
        return *this;
    }

    // is неправильная
    bool IsIncorrect()
    {
        if (chislitel_ > znamenatel_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // is правильная
    bool IsCorrect()
    {
        if (chislitel_ <= znamenatel_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // оператор +
    friend Fraction operator +(const Fraction& first, const Fraction& second)
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
            int znam_res = NOK(first.znamenatel_, second.znamenatel_);
            int dopmnozhFirst = AddMultiplier(znam_res, first.znamenatel_);
            int dopmnozhSecond = AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (first.chislitel_ * dopmnozhFirst) + (second.chislitel_ * dopmnozhSecond);

            return MixedNumber(chisl_res, znam_res);

        }
    }

    // оператор -
    friend Fraction operator -(const Fraction& first, const Fraction& second)
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
            int znam_res = NOK(first.znamenatel_, second.znamenatel_);
            int dopmnozhFirst = AddMultiplier(znam_res, first.znamenatel_);
            int dopmnozhSecond = second.AddMultiplier(znam_res, second.znamenatel_);
            int chisl_res = (first.chislitel_ * dopmnozhFirst) - (second.chislitel_ * dopmnozhSecond);

            return MixedNumber(chisl_res, znam_res);
        }
    }

    // оператор *
    friend Fraction operator*(const Fraction& first, const Fraction& second)
    {
        int ch = first.chislitel_ * second.chislitel_;
        int zn = first.znamenatel_ * second.znamenatel_;

        int nod = NOD(ch, zn);

        int chisl_res = ch / nod;
        int znam_res = zn / nod;

        return MixedNumber(chisl_res, znam_res);
    }

    // оператор /
    friend Fraction operator/(const Fraction& first, const Fraction& second)
    {
        int chisl_tmp = second.znamenatel_;
        int znam_tmp = second.chislitel_;
        int chisl_res = first.chislitel_ * chisl_tmp;
        int znam_res = first.znamenatel_ * znam_tmp;

        return MixedNumber(chisl_res, znam_res);
    }

    // оператор ++
    friend Fraction operator ++(Fraction& first)
    {
        first.chislitel_++;
        first.znamenatel_++;
        if (first.chislitel_ > first.znamenatel_)
        {
            first.chislitel_ = 0;
            first.tseloe_++;
        }
        return first;
    }

    // оператор --
    friend Fraction operator --(Fraction& first)
    {
        first.chislitel_--;
        first.znamenatel_--;
        if (first.chislitel_ > first.znamenatel_)
        {
            first.chislitel_ = 0;
            first.tseloe_++;
        }
        return first;
    }

    // оператор унарный +
    friend Fraction operator +(Fraction& first)
    {
        if (first.chislitel_ < 0)
        {
            first.chislitel_ = first.chislitel_ * -1;
        }
        else if (first.znamenatel_ < 0)
        {
            first.znamenatel_ = first.znamenatel_ * -1;
        }
        else if (first.tseloe_ < 0)
        {
            first.tseloe_ = first.tseloe_ * -1;
        }
        return first;
    }
   
    // оператор унарный -
    friend Fraction operator -(Fraction& first)
    {
        if (first.chislitel_ > 0)
        {
            first.chislitel_ = first.chislitel_ * -1;
        }
        else if (first.znamenatel_ > 0)
        {
            first.znamenatel_ = first.znamenatel_ * -1;
        }
        else if (first.tseloe_ > 0)
        {
            first.tseloe_ = first.tseloe_ * -1;
        }
        return first;
    }

    // оператор <<
    friend std::ostream& operator << (std::ostream& out, Fraction& obj)
    {
        if (obj.GetInteger() > 0)
        {
            out << obj.GetInteger() << " " << obj.GetChislitel() << "/" << obj.GetZnamenatel();
            return out;
        }
        else if (obj.GetInteger() <= 0)
        {
            out << obj.GetChislitel() << "/" << obj.GetZnamenatel();
            return out;
        }
    }

    // оператор >>
    friend std::istream& operator >> (std::istream& cin, Fraction& obj)
    {
        cin >> obj.chislitel_ >> obj.znamenatel_;
        return cin;
    }

private:

    int chislitel_;
    int znamenatel_;
    int tseloe_;
    
};


int main()
{
    Fraction A;
    Fraction B;

    std::cout << "**************************************\n";
    std::cout << "Enter numerator and denominator for first fraction:\n";
    std::cin >> A;

    std::cout << "Enter numerator and denominator for second fraction:\n";
    std::cin >> B;

    std::cout << "Fractions:\n";
    std::cout << A << "\n";
    std::cout << B << "\n";

    std::cout << "Multiply:\n";
    Fraction res1 = A * B;
    std::cout << res1 << "\n";

    std::cout << "Summa:\n";
    Fraction res2 = A + B;
    std::cout << res2 << "\n";
    
    std::cout << "Substraction:\n";
    Fraction res3 = A - B;
    std::cout << res3 << "\n";

    std::cout << "Division:\n";
    Fraction res4 = A / B;
    std::cout << res4 << "\n";
    
}

