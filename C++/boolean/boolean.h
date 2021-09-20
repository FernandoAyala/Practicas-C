#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

class Boolean
{

private:
    int _valor;

public:
    Boolean();
    Boolean(int );
    int getValue() const;
    int _and(Boolean &) const;
    int _or(Boolean &) const;
    int _not() const;
    Boolean operator*(const Boolean &) const;
    Boolean operator+(const Boolean &) const;
};

#endif // BOOLEAN_H_INCLUDED
