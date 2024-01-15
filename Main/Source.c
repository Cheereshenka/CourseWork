#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void step_stairs_output();
int step_stairs_calc(int numStairs, int numPlate);

void flight_stairs_output();
double flight_stairs_calc(int numFlight, int numPlate);

void save_to_file(char* filename);
void load_from_file(char filename[100]);

typedef struct {
    double plateLength;
    double plateWidth;
} plate;

typedef struct {
    double stepHeight;
    double stepWidth;
    double stepLength;
    int stepAmount;
} stairs;

typedef struct {
    double flightHeight;
    double flightWidth;
    double flightLength;
} flight;

plate objectsPlate[100];
int numPlate = 0;

stairs objectsStairs[100];
int numStairs = 0;

flight objectsFlight[100];
int numFlight = 0;

int main()
{
    setlocale(LC_CTYPE, "RUS");

    char filename[100];
    char loadfile[100];

    int choice;

    printf("Программа для расчёта количества плиток для облицовки ступенек или площадки.\n\n");

    do
    {
        printf("\nМеню:\n");
        printf("1. Создать ступени\n");
        printf("2. Создать площадки\n");
        printf("3. Созданные лестницы\n");
        printf("4. Созданные площадки\n");
        printf("5. Сохранить данные в файл\n");
        printf("0. Выйти\n");
        printf("Выберите действие: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            step_stairs_output();
            break;

        case 2:
            flight_stairs_output();
            break;

        case 3:
            if (numStairs == 0) printf("Нет лестниц.\n");
            else
            {
                printf("\nИнформация о лестницах:\n");
                for (int i = 0; i < numStairs; i++)
                {
                    printf("Лестница %d\n", i + 1);
                    printf("Высота ступеньки: %d м.\n", objectsStairs[i].stepHeight);
                    printf("Ширина ступеньки: %d м.\n", objectsStairs[i].stepWidth);
                    printf("Длина ступеньки: %d м.\n", objectsStairs[i].stepLength);
                    printf("Количество ступенек: %d\n", objectsStairs[i].stepAmount);
                    printf("\n");
                }
            }
            break;

        case 4:
            if (numFlight == 0) printf("Нет площадок.\n");
            else
            {
                printf("\nИнформация о площадках:\n");
                for (int i = 0; i < numFlight; i++)
                {
                    printf("Площадка %d\n", i + 1);
                    printf("Высота площадки: %g м.\n", objectsFlight[i].flightHeight);
                    printf("Ширина площадки: %g м.\n", objectsFlight[i].flightWidth);
                    printf("Длина площадки: %g м.\n", objectsFlight[i].flightLength);
                    printf("\n");
                }
            }
            break;

        case 5:
            printf("Введите название сохраняемого файла: ");
            scanf("%s", filename);
            save_to_file(filename);
            break;

        case 0:
            break;

        default:printf("Некорректный ввод. Попробуйте ещё раз.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}


void step_stairs_output()
{
    int result;
    printf("Введите длину одной плитки (в метрах): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("Введите ширину одной плитки (в метрах): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("Введите высоту ступеньки (в метрах): ");
    scanf("%lf", &objectsStairs[numStairs].stepHeight);
    printf("Введите ширину ступеньки (в метрах): ");
    scanf("%lf", &objectsStairs[numStairs].stepWidth);
    printf("Введите длину ступеньки (в метрах): ");
    scanf("%lf", &objectsStairs[numStairs].stepLength);
    printf("Введите количество ступенек: ");
    scanf("%d", &objectsStairs[numStairs].stepAmount);

    printf("Вы ввели следующие данные:\n");
    printf("Длина одной плитки: %g м.\n", objectsPlate[numPlate].plateLength);
    printf("Ширина одной плитки: %g м.\n", objectsPlate[numPlate].plateWidth);
    printf("Высота ступеньки: %g м.\n", objectsStairs[numStairs].stepHeight);
    printf("Ширина ступеньки: %g м.\n", objectsStairs[numStairs].stepWidth);
    printf("Длина ступеньки: %g м.\n", objectsStairs[numStairs].stepLength);
    printf("Количество ступенек: %d\n", objectsStairs[numStairs].stepAmount);

    result = step_stairs_calc(numStairs, numPlate);

    printf("Для облицовки ступенек вам необходимо: %d плиток\n", result);

    numStairs++;

}

int step_stairs_calc(int numStairs, int numPlate)
{
    double step_width = objectsStairs[numStairs].stepWidth;
    double step_length = objectsStairs[numStairs].stepLength;
    double step_height = objectsStairs[numStairs].stepHeight;
    int step_amount = objectsStairs[numStairs].stepAmount;
    double plate_width = objectsPlate[numPlate].plateWidth;
    double plate_length = objectsPlate[numPlate].plateLength;

    double hor_square, ver_square, plate_square;
    int result;

    plate_square = plate_width * plate_length;
    hor_square = step_width * step_length;
    ver_square = step_length * step_height;
    result = ((ceil(hor_square / plate_square) + ceil(ver_square / plate_square)) * step_amount);
    return result;
}

void flight_stairs_output()
{
    int result;
    printf("Введите длину одной плитки (в метрах): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("Введите ширину одной плитки (в метрах): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("Введите высоту площадки (в метрах): ");
    scanf("%lf", &objectsFlight[numFlight].flightHeight);
    printf("Введите ширину площадки (в метрах): ");
    scanf("%lf", &objectsFlight[numFlight].flightWidth);
    printf("Введите длину площадки (в метрах): ");
    scanf("%lf", &objectsFlight[numFlight].flightLength);

    printf("Вы ввели следующие данные:\n");
    printf("Длина одной плитки: %g м.\n", objectsPlate[numPlate].plateLength);
    printf("Ширина одной плитки: %g м.\n", objectsPlate[numPlate].plateWidth);
    printf("Высота площадки: %g м.\n", objectsFlight[numFlight].flightHeight);
    printf("Ширина площадки: %g м.\n", objectsFlight[numFlight].flightWidth);
    printf("Длина ступеньки: %g м.\n", objectsFlight[numFlight].flightLength);

    result = flight_stairs_calc(numFlight, numPlate);

    printf("Для облицовки площадки вам необходимо: %d плиток.", result);

    numFlight++;

}

double flight_stairs_calc(int numFlight, int numPlate)
{
    double flight_width = objectsFlight[numFlight].flightWidth;
    double flight_length = objectsFlight[numFlight].flightLength;
    double flight_height = objectsFlight[numFlight].flightHeight;
    double plate_width = objectsPlate[numPlate].plateWidth;
    double plate_length = objectsPlate[numPlate].plateLength;

    double hor_square, ver_square, plate_square;
    int result;

    plate_square = plate_width * plate_length;
    hor_square = flight_width * flight_length;
    ver_square = flight_length * flight_height;
    result = (ceil(hor_square / plate_square) + ceil(ver_square / plate_square));
    return result;
}

void save_to_file(char* filename) {

    if (numStairs == 0 && numFlight == 0) {
        printf("Нет объектов для сохранения.\n");
        return;
    }

    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    fprintf(file, "Лестницы:\n");
    for (int i = 0; i < numStairs; i++) {
        fprintf(file, "Лестница %d\n", i + 1);
        fprintf(file, "Высота ступеньки: %g м.\n", objectsStairs[i].stepHeight);
        fprintf(file, "Ширина ступеньки: %g м.\n", objectsStairs[i].stepWidth);
        fprintf(file, "Длина ступеньки: %g м.\n", objectsStairs[i].stepLength);
        fprintf(file, "Количество ступенек: %d\n", objectsStairs[i].stepAmount);
        fprintf(file, "\n");
    }

    fprintf(file, "Площадки:\n");
    for (int i = 0; i < numFlight; i++) {
        fprintf(file, "Площадка %d\n", i + 1);
        fprintf(file, "Высота площадки: %g м.\n", objectsFlight[i].flightHeight);
        fprintf(file, "Ширина площадки: %g м.\n", objectsFlight[i].flightWidth);
        fprintf(file, "Длина площадки: %g м.\n", objectsFlight[i].flightLength);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Данные успешно сохранены в файл '%s'.\n", filename);
}
