#include <stdio.h>
#include <string.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to classify BMI and provide recommendations for Asians
void classifyAsianBMI(float height, float bmi, char *classification, float *recommendation) {
    if (bmi < 18.5) {
        strcpy(classification, "Low");
        *recommendation = (18.5 - bmi)*(height*height); // No weight change recommended for underweight Asians
    } else if (bmi < 23.0) {
        strcpy(classification, "Normal");
        *recommendation = 0.0; // No weight change recommended for Asians with normal BMI
    } else if (bmi < 27.5) {
        strcpy(classification, "Overweight");
        *recommendation = (23.0 - bmi) * (height*height); // Calculate recommended weight reduction to normal BMI for Asians
    } else {
        strcpy(classification, "Obese");
        *recommendation = (23.0 - bmi) * (height*height); // Calculate recommended weight reduction to normal BMI for Asians
    }
}

// Function to classify BMI and provide recommendations for non-Asians
void classifyNonAsianBMI(float height, float bmi, char *classification, float *recommendation) {
    if (bmi < 18.5) {
        strcpy(classification, "Low");
        *recommendation = (18.5 - bmi)*(height*height); // No weight change recommended for underweight non-Asians
    } else if (bmi < 24.9) {
        strcpy(classification, "Normal");
        *recommendation = 0.0; // No weight change recommended for non-Asians with normal BMI
    } else if (bmi < 29.9) {
        strcpy(classification, "Overweight");
        *recommendation = (24.9 - bmi) * (height*height); // Calculate recommended weight reduction to normal BMI for non-Asians
    } else {
        strcpy(classification, "Obese");
        *recommendation = (24.9 - bmi) * (height*height); // Calculate recommended weight reduction to normal BMI for non-Asians
    }
}

int main() {
    float weight, height, bmi, recommendation;
    char classification[20];
    int isAsian;

    // Input weight and height
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    if (weight <= 0 || weight > 500) {
        printf("Invalid weight entered.\n");
        return 1;
    }

    printf("Enter your height in meters: ");
    scanf("%f", &height);
    if (height <= 0 || height > 3) {
        printf("Invalid height entered.\n");
        return 1;
    }

    // Input whether the user is Asian or not
    printf("Are you Asian? (1 for Yes, 0 for No): ");
    scanf("%d", &isAsian);
    if (isAsian != 0 && isAsian != 1) {
        printf("Invalid input for Asian status.\n");
        return 1;
    }

    // Calculate BMI
    bmi = calculateBMI(weight, height);

    // Classify BMI and provide recommendations based on Asian status
    if (isAsian) {
        classifyAsianBMI(height, bmi , classification, &recommendation);
    } else {
        classifyNonAsianBMI(height, bmi, classification, &recommendation);
    }

    // Output results in a table format
    printf("\nBMI Report:\n");
    printf("+---------------------+\n");
    printf("|    Parameter        |    Value\n");
    printf("+---------------------+\n");
    printf("|    Weight           |    %.2f kg\n", weight);
    printf("|    Height           |    %.2f meters\n", height);
    printf("|    BMI              |    %.2f\n", bmi);
    printf("|    Classification   |    %s\n", classification);
    printf("|    Recommendation   |    %.2f kg\n", recommendation);
    printf("+---------------------+\n");

    return 0;
}