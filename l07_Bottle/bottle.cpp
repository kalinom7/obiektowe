#include "bottle.hpp"


Bottle::Bottle(double vol){
    max = vol;
    volum = 0;
};

const double Bottle::volume(){
    return volum;
};

double Bottle::fill(double vol){
    double filled = volum + vol;
    if(filled > max)
    {
        volum = max;
        return  max - volum;
    }
    else 
    {
        volum = volum + vol;
        return vol;
    }

};

double Bottle::pour(double vol){

    
    if(volum - vol < 0)
    {
        int temp = volum ; 
        volum = 0;
        return temp; 
        
    }
    
    else{
        volum = volum - vol;
        return  vol;
    }

};
