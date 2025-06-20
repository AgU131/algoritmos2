/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    // min_temp_min();
    // max_temp_max();
    // month_max_rainfall();

// Usar funciones de weather_utils.h
    int min_temp = min_hist_temp(table);
    printf("Lowest historical minimum temperature: %d°C\n", min_temp);

    int max_temp_per_year[YEARS];
    max_hist_temp(table, max_temp_per_year);
    printf("Max temperatures per year:\n");
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("  %u: %d°C\n", FST_YEAR + year, max_temp_per_year[year]);
    }

    month_t rainiest_months[YEARS];
    max_prec_per_month(table, rainiest_months);
    const char* month_names[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("Rainiest month per year:\n");
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("  %u: %s\n", FST_YEAR + year, month_names[rainiest_months[year]]);
    }

    /* show the table in the screen */ //Lo ocultamos por ahora para que no me oculte lo que queria ver antes por la cantidad de datos
    // table_dump(table);
    return EXIT_SUCCESS;
}
