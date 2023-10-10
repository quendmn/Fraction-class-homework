#pragma once
#ifndef _FRACTION HPP_
#define _FRACTION HPP_

#include <iostream>
class Fraction
{
public:

    // �������� �����
    Fraction() = default;

    explicit Fraction(int chisl, int znam) :chislitel_(chisl), znamenatel_(znam), tseloe_(0) {}

    explicit Fraction(int tseloe, int chisl, int znam) :tseloe_(tseloe), chislitel_(chisl), znamenatel_(znam) {}

    explicit Fraction(float tmp)
    {
        this->chislitel_ = (int)tmp;
        this->znamenatel_ = tmp - this->chislitel_;
    }

    // �����
    void Print();

    // ��� ��� ������������
    static int NOK(const int& a, const int& b);

    // ��� ��� ������������
    static int NOD(int a, int b);

    // ������� ������������ ������ � ��������� �����
    static Fraction MixedNumber(int& chisl_res, int& znam_res);

    // ������� ��������� ����� � ������������ �����
    Fraction IncorrectFr(Fraction& smeshannoe);

    // ����� ��� ��������� ��� ����������
    static int AddMultiplier(const int& max, const int& a);

    // ��������
    Fraction Summa(Fraction& second);

    // ���������
    Fraction Subtraction(Fraction& second);

    // ���������
    Fraction Multiply(Fraction& second);

    // �������
    Fraction Division(Fraction& second);

    // �������� ���������
    int GetChislitel()
    {
        return this->chislitel_;
    }

    // �������� �����������
    int GetZnamenatel()
    {
        return this->znamenatel_;
    }

    // �������� ����� �����
    int GetInteger()
    {
        return this->tseloe_;
    }

    // �������� ������� �����
    int GetNotInteger()
    {
        GetChislitel();
        GetZnamenatel();
    }


    // �������� �������� �����
    Fraction GetReverse()
    {
        this->chislitel_ = this->znamenatel_;
        this->znamenatel_ = this->chislitel_;

        return *this;

    }

    // ������� �����
    Fraction un_minus();

    // ������� ����
    Fraction un_plus();

    // ���������
    Fraction decrement();

    // ���������
    Fraction increment();

    // is ������������
    bool IsIncorrect();

    // is ����������
    bool IsCorrect();

    // �������� +
    friend Fraction operator +(const Fraction& first, const Fraction& second);

    // �������� -
    friend Fraction operator -(const Fraction& first, const Fraction& second);

    // �������� *
    friend Fraction operator*(const Fraction& first, const Fraction& second);

    // �������� /
    friend Fraction operator/(const Fraction& first, const Fraction& second);

    // �������� ++
    friend Fraction operator ++(Fraction& first);

    // �������� --
    friend Fraction operator --(Fraction& first);

    // �������� ������� +
    friend Fraction operator +(Fraction& first);

    // �������� ������� -
    friend Fraction operator -(Fraction& first);

    // �������� <<
    friend std::ostream& operator << (std::ostream& out, Fraction& obj);

    // �������� >>
    friend std::istream& operator >> (std::istream& cin, Fraction& obj);

private:

    int chislitel_;
    int znamenatel_;
    int tseloe_;

};

#endif