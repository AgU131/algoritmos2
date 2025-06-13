/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year) {
    int result = 0;
    for (month_t mes = january; mes <= december; mes++) {
      for (unsigned int dia = 0; dia < DAYS; dia++) {
        result = result + a[year][mes][dia]._rainfall;
        // Cooreccion de chatgpt al parcial que me daba error
        // result += a[year - FST_YEAR][mes][dia]._rainfall;
      }
    }

    return result;
}
