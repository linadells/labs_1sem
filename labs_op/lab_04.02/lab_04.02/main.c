#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define size 256

int main()
{
    FILE* log, * flin, * flout;
    double x, y, res;
    char inputfilename[size], outputfilename[size];
    int format, resreading, reswritting;
    char* timearr;

    log = fopen("log.txt", "a");
    time_t realTime;

    time(&realTime);
    timearr = ctime(&realTime);
    *(strchr(timearr, '\n')) = '\0';

    fprintf(log, "[%s] Program started.\n", timearr);

    printf("Input file name: ");
    scanf("%s", inputfilename);


    flin = fopen(inputfilename, "r");
    if (!flin)
    {
        time(&realTime);
        timearr = ctime(&realTime);
        *(strchr(timearr, '\n')) = '\0';

        fprintf(log, "[%s] Error opening file. Message: %s\n", timearr, strerror(errno));
        return -1;
    }

    resreading = 0;
    resreading += fread(&x, sizeof(double), 1, flin);
    resreading += fread(&y, sizeof(double), 1, flin);

     if (resreading != 2)
     {
         time(&realTime);
         timearr = ctime(&realTime);
         *(strchr(timearr, '\n')) = '\0';

         fprintf(log, "[%s] Error reading y. Message: %s\n", timearr, strerror(errno));
         return -1;
     }

    fclose(flin);

    time(&realTime);
    timearr = ctime(&realTime);
    *(strchr(timearr, '\n')) = '\0';

    fprintf(log, "[%s] Parameters file %s opened.x = %lf, y = %lf\n", timearr, inputfilename, x, y);



    res = pow(2, -x) * sqrt((1 / x) * (1 / x) * (1 / x) * (1 / x) + sqrt(fabs(y)));

    time(&realTime);
    timearr = ctime(&realTime);
    *(strchr(timearr, '\n')) = '\0';

    fprintf(log, "[%s] Expression calculated. Res = %lf\n", timearr, res);

  
    printf("Enter the format of the file. Press 0 for bin file or 1 for txt file: ");
    scanf("%i", &format);


    printf("Enter output file name: ");
    scanf("%s", outputfilename);


    reswritting = 0;
    if (format == 0)
    {
        if (strstr(outputfilename, ".txt") != NULL)
        {
            fprintf(log, "[%s] Incorrect output file format.\n", timearr);
            return -1;
        }

        flout = fopen(outputfilename, "wb");

        reswritting += fwrite(&res, sizeof(double), 1, flout);

        time(&realTime);
        timearr = ctime(&realTime);
        *(strchr(timearr, '\n')) = '\0';

        if (reswritting != 1)
        {
            fprintf(log, "[%s] Error writting results. Message: %s\n", timearr, strerror(errno));
            return -1;
        }

        fclose(flout);

        fprintf(log, "[%s] Output file \"%s\"  saved.\n", timearr, outputfilename);
    }

    else if (format == 1)
    {
        if (strstr(outputfilename, ".bin") != NULL)
        {
            fprintf(log, "[%s] Incorrect output file format.\n", timearr);
            return -1;
        }

        flout = fopen(outputfilename, "w");

        reswritting += fprintf(flout, "%lf", res);

        time(&realTime);
        timearr = ctime(&realTime);
        *(strchr(timearr, '\n')) = '\0';

        if (reswritting != 8)
        {
            fprintf(log, "[%s] Error writting results. Message: %s\n", timearr, strerror(errno));
            return -1;
        }

        fclose(flout);

        fprintf(log, "[%s] Output file \"%s\" saved.\n", timearr, outputfilename);
    }

    else
    {
        fprintf(log, "[%s] Incorrect format value.\n", timearr);
        return -1;
    }


    time(&realTime);
    timearr = ctime(&realTime);
    *(strchr(timearr, '\n')) = '\0';

    fprintf(log, "[%s] Program ended.\n\n", timearr);

    fclose(log);
    return 0;
}