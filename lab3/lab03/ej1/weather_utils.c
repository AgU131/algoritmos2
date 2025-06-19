#include <stdio.h>
#include <stdlib.h>
#include "weather_utils.h"

// Soluciones del profe:
//min_temp_min
int min_hist_temp(WeatherTable table) {
   int result;
   result = table[0][0][0]._min_temp;
   for (unsigned int year = 0u; year < YEARS; ++year) {
       for (month_t month = january; month <= december; ++month) {
           for (unsigned int day = 0u; day < DAYS; ++day) {
               if (table[year][month][day]._min_temp < result) {
                   result = table[year][month][day]._min_temp;
               }
           }
       }
   }
   return result;
}

//max_temp_max
void max_hist_temp(WeatherTable table, int output[YEARS]) {
   for (unsigned int year = 0; year < YEARS; year++) {    
       // mayor temperatura del año `year`
       int max_temp_year = table[year][0][0]._max_temp;
       for (month_t month = january; month <= december; ++month) {
           for (unsigned int day = 0u; day < DAYS; ++day) {
               if (table[year][month][day]._max_temp > max_temp_year) {
                   max_temp_year = table[year][month][day]._max_temp;
               }
           }
       }
       output[year] = max_temp_year;
   }
}

//month_max_rainfall
void max_prec_per_month(WeatherTable table, month_t output[YEARS]) {
   for (unsigned int year = 0; year < YEARS; year++) {
       month_t month_max = january;
       unsigned int max_rainfall = 0;
       for (month_t month = january; month <= december; ++month) {
           // calcular suma de lluvias para el mes `month`
           unsigned int month_rainfall = 0;
           for (unsigned int day = 0u; day < DAYS; ++day) {
               month_rainfall += table[year][month][day]._rainfall;
           }
           // ver si es el máximo para este año
           if (month_rainfall > max_rainfall) {
               // guardar nuevo máximo y su mes
               max_rainfall = month_rainfall;
               month_max = month;
           }
       }
       output[year] = month_max;
   }
}



// int min_hist_temp (WeatherTable a) {
//     int min = a[0][0][0]._min_temp;
//     for (unsigned int year = 0; year < YEARS; year++) {
//         for (unsigned int month = 0; month < MONTHS; month++) {
//             for (unsigned int day = 0; day < DAYS; day++) {
//                 if(a[year][month][day]._min_temp < min) min = a[year][month][day]._min_temp;
//             }
//         }
//     }
//     return min;
// }

// void max_hist_temp (WeatherTable a, int output[YEARS]) {
//     for (unsigned int year = 0; year < YEARS; year++) {
//         int max_year = a[year][0][0]._max_temp;
//         for (unsigned int month = 0; month < MONTHS; month++) {
//             for (unsigned int day = 0; day < DAYS; day++) {
//                 output[year] = max_year < a[year][month][day]._max_temp
//                                     ? a[year][month][day]._max_temp
//                                     : max_year;
//             }
//         }
//     }
// }

// void max_prec_per_month (WeatherTable a, month_t month_with_most_rainfall[YEARS]) {
//     for (unsigned int year = 0; year < YEARS; year++) {
//         int tmp_res = 0;
//         for (month_t month = 0; month < MONTHS; month++) {
//             int rainfall_count = 0;
//             // count the amount of rainfall in this month
//             for (unsigned int day = 0; day < DAYS; day++) {
//                 rainfall_count += a[year][month][day]._rainfall;
//             }
//             if(tmp_res < rainfall_count) {
//                 month_with_most_rainfall[year] = month;
//                 tmp_res = rainfall_count;
//             }
//         }
//     }
// }