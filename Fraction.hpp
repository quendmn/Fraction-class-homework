#pragma once
#ifndef _FRACTION HPP_
#define _FRACTION HPP_

#include <iostream>
class Fraction
{
public:

    // создание дроби
    Fraction() = default;

    explicit Fraction(int chisl, int znam) :chislitel_(chisl), znamenatel_(znam), tseloe_(0) {}

    explicit Fraction(int tseloe, int chisl, int znam) :tseloe_(tseloe), chislitel_(chisl), znamenatel_(znam) {}

    explicit Fraction(float tmp)
    {
        this->chislitel_ = (int)tmp;
        this->znamenatel_ = tmp - this->chislitel_;
    }

    // вывод
    void Print();

    // НОК для знаменателей
    static int NOK(const int& a, const int& b);

    // НОД для знаменателей
    static int NOD(int a, int b);

    // перевод неправильных дробей в смешанные числа
    static Fraction MixedNumber(int& chisl_res, int& znam_res);

    // перевод смешанных чисел в неправильные дроби
    Fraction IncorrectFr(Fraction& smeshannoe);

    // поиск доп множителя для числителей
    static int AddMultiplier(const int& max, const int& a);

    // сложение
    Fraction Summa(Fraction& second);

    // вычитание
    Fraction Subtraction(Fraction& second);

    // умножение
    Fraction Multiply(Fraction& second);

    // деление
    Fraction Division(Fraction& second);

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


    // получить обратную дробь
    Fraction GetReverse()
    {
        this->chislitel_ = this->znamenatel_;
        this->znamenatel_ = this->chislitel_;

        return *this;

    }

    // унарный минус
    Fraction un_minus();

    // унарный плюс
    Fraction un_plus();

    // декремент
    Fraction decrement();

    // инкремент
    Fraction increment();

    // is неправильная
    bool IsIncorrect();

    // is правильная
    bool IsCorrect();

    // оператор +
    friend Fraction operator +(const Fraction& first, const Fraction& second);

    // оператор -
    friend Fraction operator -(const Fraction& first, const Fraction& second);

    // оператор *
    friend Fraction operator*(const Fraction& first, const Fraction& second);

    // оператор /
    friend Fraction operator/(const Fraction& first, const Fraction& second);

    // оператор ++
    friend Fraction operator ++(Fraction& first);

    // оператор --
    friend Fraction operator --(Fraction& first);

    // оператор унарный +
    friend Fraction operator +(Fraction& first);

    // оператор унарный -
    friend Fraction operator -(Fraction& first);

    // оператор <<
    friend std::ostream& operator << (std::ostream& out, Fraction& obj);

    // оператор >>
    friend std::istream& operator >> (std::istream& cin, Fraction& obj);

private:

    int chislitel_;
    int znamenatel_;
    int tseloe_;

};

#endif