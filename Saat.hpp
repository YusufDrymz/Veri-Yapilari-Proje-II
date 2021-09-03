#ifndef SAAT_HPP
#define SAAT_HPP
#include <ostream>
using namespace std;
class Saat{
	int saat,dakika,saniye;
	public:
		Saat(int saat = 0, int dakika = 0, int saniye = 0);
		Saat operator+(const Saat& obj)const;
		Saat operator+(int saniye)const;
		Saat& operator+=(const Saat& obj);
		Saat& operator+=(int saniye);
		friend ostream& operator<<(ostream& out,const Saat& obj);
};

Saat::Saat(int saat, int dakika, int saniye)
 : saat(saat),dakika(dakika),saniye(saniye)
{		}
		
Saat Saat::operator+(const Saat& obj)const{
	Saat temp = *this;
	int artan = 0;
	temp.saniye += obj.saniye;
	artan = temp.saniye / 60;
	temp.saniye %= 60;
	temp.dakika += artan + obj.dakika;
	artan = temp.dakika / 60;
	temp.dakika %= 60;
	temp.saat += artan + obj.saat;
	return temp;
}
		
Saat Saat::operator+(int saniye)const{	return *this + Saat(0,0,saniye);	}
Saat& Saat::operator+=(const Saat& obj){		return *this = *this + obj;		}
Saat& Saat::operator+=(int saniye){	return *this = *this + saniye;	}

ostream& operator<<(ostream& out,const Saat& obj){
	if(obj.saat < 10)
		out << "0";
	out << obj.saat << ":";
	if(obj.dakika < 10)
		out << "0";
	out << obj.dakika << ":";
	if(obj.saniye < 10)
		out << "0";
	out << obj.saniye;
	return out;
}
#endif
