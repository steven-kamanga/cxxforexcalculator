/*
 * forexcalculator.cxx
 *
 * Copyright 2022 $teven <steven@drplxrd>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * Code to calculate the following on currencies
 * Risk, Sl and Tp
 * Lot size
 *
 */
#include <iostream>
#include <iomanip>
using namespace std;
class Risk{
    float atr;
    float price;
    float opt;
    public:
    float sl;
    float riskPerTrade(float atr, float price, float opt){

        if(opt == 1)
        {
            sl = price-2*atr;
		return sl;
        }else if(opt == 2){
            sl = price+2*atr;
        return sl;
        }
    }
};
class Lots: public Risk{
    float risk;
    float capital;
    float pipValue;
    public:
        float lotSize(float sl, float risk, float capital, float pipValue){
		float numerator = risk * capital, denominator = sl * pipValue, lots = numerator/denominator;
		return lots;
			}
};
int main(){
//Object declaration
Risk r;
Lots l;
    float atr, sl, price, capital, risk = 0.02, pipVal, opt;
	while(1){
	cout<<"Select\n1.Long\n2.Short\n";
	cin>>opt;
	if(opt == 1 || opt == 2){
	break;
	}
        }
	cout<<"Enter the atr value\t:";
	cin>>atr;
	cout<<"Enter the price\t\t:";
	cin>>price;
	cout<<"Risk is\t\t\t:"<<r.riskPerTrade(atr, price, opt);
	sl = r.riskPerTrade(atr, price, opt);
	cout<<"\n\nEnter net capital\t:";
	cin>>capital;
	cout<<"Enter pip value\t\t:";
	cin>>pipVal;
	float x = l.lotSize(sl, risk, capital, pipVal);
	cout<<"\nLot size\t\t:"<<setprecision(1)<<x;
	cout<<"\nMin lots\t\t:"<<setprecision(2)<<x*10;
	cout<<endl;
    return 0;
}


