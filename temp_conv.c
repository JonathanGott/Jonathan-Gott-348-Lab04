#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a Coat.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and cool off.\n");
    }
}

int main() {
    float temp, converted_temp;
    int current_scale, target_scale;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    if (current_scale == 1) {  // Celsius
        if (target_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temp);
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else if (target_scale == 3) {
            converted_temp = celsius_to_kelvin(temp);
            printf("Converted temperature: %.2fK\n", converted_temp);
        } else {
            converted_temp = temp;
            printf("Converted temperature: %.2f°C\n", converted_temp);
        }
    } else if (current_scale == 2) {  // Fahrenheit
        if (target_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temp);
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (target_scale == 3) {
            converted_temp = celsius_to_kelvin(fahrenheit_to_celsius(temp));
            printf("Converted temperature: %.2fK\n", converted_temp);
        } else {
            converted_temp = temp;
            printf("Converted temperature: %.2f°F\n", converted_temp);
        }
    } else if (current_scale == 3) {  // Kelvin
        if (target_scale == 1) {
            converted_temp = kelvin_to_celsius(temp);
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (target_scale == 2) {
            converted_temp = celsius_to_fahrenheit(kelvin_to_celsius(temp));
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else {
            converted_temp = temp;
            printf("Converted temperature: %.2fK\n", converted_temp);
        }
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    // Categorize based on Celsius value
    if (current_scale == 2) {  // Fahrenheit
        categorize_temperature(fahrenheit_to_celsius(temp));
    } else if (current_scale == 3) {  // Kelvin
        categorize_temperature(kelvin_to_celsius(temp));
    } else {
        categorize_temperature(temp);
    }

    return 0;
}
