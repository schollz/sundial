#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "sundial.h"

double mod360(double);
double acosD(double);
double asinD(double);
double cosD(double);
double sinD(double);
double goTime(double);
double julianDay(double);
double jstar(double, double);
double computeSolarAngle(double,double,double,int,time_t);
double modD(double,double);


double const PI = 3.14159265359;
double const JEPOCH = 2451545.0;
double const UEPOCH = 946728000.0;

double mod360(double x)  {
    return x - 360.0*floor(x/360.0);
}

double acosD(double x) {
    if (x >= 1.0 ) {
        return 0.0;
    }
    if( x <= -1.0) {
        return 180.0;
    }
    return acos(x) * 180.0 / PI;
}

double asinD(double x) {
    return asin(x) * 180.0 / PI;
}

double cosD(double x) {
    return cos(x * PI / 180.0);
}

double sinD(double x) {
    return sin(x * PI / 180.0);
}


double goTime(double x) {
    return UEPOCH + (x-JEPOCH)*86400.0;
}

double julianDay(double x) {
    return (x-UEPOCH)/86400.0 + JEPOCH;
}

double jstar(double longitude, double timet) {
    return 1+floor(julianDay(timet)-0.0009+longitude/360.0+0.5) + 0.0009 - longitude/360;
}

double modD (double a, double b)
{
    if(b < 0) //you can check for b == 0 separately and do what you want
        return modD(a, -b);
    double ret = (double)((int)a % (int)b);
    if(ret < 0)
        ret+=b;
    return ret;
}

double computeSolarAngle(double latitude, double longitude, double OFFSET, int isSunrise, time_t relativeTo) {
    double timet = getTime(relativeTo);
    timet = timet - modD(timet,86400)-OFFSET;
    double ma = mod360(357.5291 + 0.98560028*(jstar(longitude,timet)-JEPOCH));
    double center = 1.9148*sinD(ma) + 0.02*sinD(2.0*ma) + 0.0003*sinD(3.0*ma);
    double el = mod360(ma + 102.9372 + center + 180.0);
    double solarNoon = jstar(longitude,timet) + 0.0053*sinD(ma) - 0.0069*sinD(2.0*el);
    double declination = asinD(sinD(el) * sinD(23.45));
    double hourAngleInDays = acosD((sinD(-0.83)-sinD(latitude)*sinD(declination))/(cosD(latitude)*cosD(declination))) / 360.0;
    if (isSunrise == 1) {
        double sunriseTime = goTime(solarNoon - hourAngleInDays);
        if (sunriseTime < getTime(relativeTo)) {
            sunriseTime = sunriseTime + 24 * 3600;
        }
        return sunriseTime;
    } else {
        return goTime(solarNoon + hourAngleInDays);
    }
}

double sunrise(double latitude, double longitude, double offset, time_t relativeTo)  {
    return computeSolarAngle(latitude,longitude,offset,1,relativeTo);
}

double sunset(double latitude, double longitude, double offset, time_t relativeTo)  {
    return computeSolarAngle(latitude,longitude,offset,0,relativeTo);
}