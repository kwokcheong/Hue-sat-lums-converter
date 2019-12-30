#include <iostream>
#include <cmath>
#include <string> 

using namespace std;

struct HSL {
    int hue;
    int sat;
    int lum;
};

HSL rgb_to_hsl(int red, int green, int blue) {
    int hue=1, sat=2, lum=3;  

    double s_red = (double) red/255, s_green= (double) green/255, s_blue= (double)blue/255; 
    double max = s_red, min= s_red; 
    if (s_green > max){ 
        max = s_green;
    }
    if (s_blue > max){ 
        max = s_blue; 
    }
    if (min > s_green){ 
        min = s_green;
    }
    if (min > s_blue){ 
        min = s_blue;
    }
    double lum_double = (max + min)/2.0;
    lum = round(lum_double * 100);

    double sat_double;
    if (lum_double < 0.5) { 
        sat_double = (max-min) / (max + min);
    } else { 
        sat_double = (max-min) / (2 - max - min);
    }
    sat = round(sat_double*100); 

    double hue_double; 
    if (max == s_red){ 
        hue_double = (s_green-s_blue)/ (max - min);
    }else if (max == s_green){ 
        hue_double = 2 + ((s_blue - s_red)/(max - min));
    } else { 
        hue_double = 4 + ((s_red - s_green) / (max - min));
    }
    hue = round(hue_double*60);
    while (hue<0){ 
        hue += 360;
    }


    return (HSL){.hue=hue, .sat=sat, .lum=lum};
}

int main() {

    int red = 255;
    int green = 127;
    int blue = 0;
    
    HSL hsl = rgb_to_hsl(red, green, blue);
    printf("The result is Hue:%d, Sat:%d, Lum:%d\n", hsl.hue, hsl.sat, hsl.lum);

    return 0;
}