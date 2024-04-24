#ifndef SEARCH_H
#define SEARCH_H

#include "Episode.h"
#include <iostream>

using namespace std;

class Search{
    
    friend ostream& operator<<(ostream&, const Search& );
    public:

        virtual bool matches(const Episode*) = 0;
        virtual void print(ostream& ost) const = 0;

};

class H_Search: public virtual Search{

    public:
        H_Search(const string&);
        virtual bool matches(const Episode*);
        virtual void print(ostream&) const;

    private:
        string host;
};

class C_Search: public virtual Search{

    public:
        C_Search(const string&);
        virtual bool matches(const Episode*);
        virtual void print(ostream&) const;

    private:
        string category;

};

class HorC_Search: public virtual H_Search, public virtual  C_Search{
    public:
        HorC_Search(const string&, const string&);
        virtual bool matches(const Episode*);
        virtual void print(ostream&)const;

};


#endif