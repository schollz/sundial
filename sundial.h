// public API for sundial
#ifndef SUNDIAL_H
#define SUNDIAL_H

double sunrise(double latitude,double longitude, double tzOffset, time_t relativeTo);
double sunset(double latitude,double longitude, double tzOffset, time_t relativeTo);
// double getTime( time_t relative);
#define getTime(x) ((double)(x))

#endif // SUNDIAL_H