#include <stdio.h>
#include <string.h>
#define num_of_com 10 // Number of Comapnies
#define num_of_days 7 // Number of Days

typedef struct Stock
{
    char name[100];
    float Open;
    float High;
    float Low;
    float Close;
    int volume;
} Stock;

typedef struct OvrPerformance
{
    char names[100];
    float Op;

} OvrPerformance;

int day()
{
    int day, flag = 1;
    char ans;

    while (flag == 1)
    {
        printf("Enter the day(1-7):- \n");
        scanf("%d", &day);
        if (day > 0 && day < 8)
        {
            flag = 0;
        }
        else
        {
            printf("!!Invalid Input!!\n");
            printf("Do you want to Continue?(Y/N)\n");
            scanf("%c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
            }
        }
    }
    return (day);
}

void checkDay(int buy_day, int sell_day)
{
    int flag = 1;
    char ans, ans1;
    while (flag == 1)
    {
        if (buy_day > sell_day)
        {
            printf("!!Invalid Input!! Do you wnat to Continue(Y/N):- \n");
            scanf("%c", &ans);
            if (ans == 'Y')
            {
                printf("Do you want to change Buy Day?\n");
                scanf("%c", &ans1);
                if (ans1 == 'Y')
                {
                    printf("New Buy Day:-\n ");
                    buy_day = day();
                }
                else
                {
                    printf("Change the Selling Day\n");
                    sell_day = day();
                }
            }
            else
            {
                flag = 0;
            }
        }
        else
        {
            flag = 0;
        }
    }
}

char checkType()
{
    int flag = 1;
    char type_price[10], ans[20];
    while (flag == 1)
    {

        printf("Enter type of price (Open , High , Low , Close):-\t");
        scanf("%s", &type_price);
        if (strcmp(type_price, "Open") == 0 || strcmp(type_price, "Close") == 0 || strcmp(type_price, "High") == 0 || strcmp(type_price, "Low") == 0)
        {
            flag = 0;
        }
        else
        {
            printf("!! Invalid Input !! Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "Yes") == 0)
            {
                // continue
            }
            else if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else
            {
                printf("!!Invalid Input!!\n");
            }
        }
    }
    return type_price[0];
}

void input(Stock S[num_of_com][num_of_days])
{

    int flag = 1;
    char ans[20];
    int no;
    while (flag == 1)
    {
        printf("Enter the Question Number:- \n");
        scanf("%d", &no);
        if (no == 1)
        {

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
        else if (no == 2)
        {

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
        else if (no == 3)
        {
            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
        else if (no == 4)
        {
            int buy = day();
            // char buy_type = checkType();
            int sell = day();
            checkDay(buy, sell);
            // char sell_type = checkType();

            Question4(S, buy, "Open", sell, "Close");

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
        else if (no == 5)
        {

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
        }
        else if (no == 6)
        {

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
        else if (no == 7)
        {

            printf("Do you want to continue?(Yes/No)\t");
            scanf("%s", &ans);
            if (strcmp(ans, "No") == 0)
            {
                flag = 0;
            }
            else if (strcmp(ans, "Yes") != 0 || strcmp(ans, "No") != 0)
            {
                printf("!!Invalid Input!!\n");
            }
        }
    }
}

void Question1(Stock S[num_of_com][num_of_days], int start_date, int end_date, char type_startPrice[], char type_endPrice[], int num)
{
    int check = 0;
    if (start_date > end_date)
    {
        printf("!! Invalid Inputs: 'starting date should not be greater than ending date' !!");
    }
    else if (start_date > 7 || start_date < 1 || end_date > 7 || end_date < 1)
    {
        printf("!! Invalid Inputs: 'starting date or ending date should not exceed range i.e [1,7]' !!");
    }
    else
    {
        float diff, change;
        int com = num - 1;
        int dateEnd = end_date - 1;
        int dateStart = start_date - 1;

        if (strcmp(type_startPrice, "Open") == 0)
        {
            diff = S[num - 1][end_date - 1].Open - S[num - 1][start_date - 1].Open;
            change = (diff / S[num - 1][end_date - 1].Open) * 100;
        }
        else if (strcmp(type_startPrice, "High") == 0)
        {
            diff = S[num - 1][end_date - 1].High - S[num - 1][start_date - 1].High;
            change = (diff / S[num - 1][end_date - 1].High) * 100;
        }
        else if (strcmp(type_startPrice, "Low") == 0)
        {
            diff = S[num - 1][end_date - 1].Low - S[num - 1][start_date - 1].Low;
            change = (diff / S[num - 1][end_date - 1].Low) * 100;
        }
        else if (strcmp(type_startPrice, "Close") == 0)
        {
            diff = S[num - 1][end_date - 1].Close - S[num - 1][start_date - 1].Close;
            change = (diff / S[num - 1][end_date - 1].Close) * 100;
        }
        else
        {
            check = 1;
            printf("!! No such price type exists !!");
        }

        if (check == 0)
        {
            if (start_date != end_date)
            {
                printf("Percentage change in price from day %d to day %d are:\n", start_date, end_date);
                printf("%s  ->  %f %% \n", S[num - 1][start_date - 1].name, change);
            }
            else
            {
                printf("Percentage change in prices from day %d to day %d are:\n", start_date, end_date);
                diff = S[num - 1][end_date - 1].Close - S[num - 1][start_date - 1].Open;
                change = (diff / S[num - 1][end_date - 1].Close) * 100;
                printf("%s  ->  %f %% \n", S[num - 1][start_date - 1].name, change);
            }
        }
        else
        {
            printf("Invalid Inputs:");
        }
    }
}

void Question2(Stock S[num_of_com][num_of_days], int day)
{
    int i, j, flag = 1;
    for (i = 0; i < 10 && flag == 1; i++)
    {
        flag = 0;
        for (j = 0; j < num_of_com - 1; j++)
        {
            if (S[j][day].volume > S[j + 1][day].volume)
            {
                Stock temp = S[j][day];
                S[j][day] = S[j + 1][day];
                S[j + 1][day] = temp;

                flag = 1;
            }
            else if (S[j][day].volume == S[j + 1][day].volume)
            {
                if (S[j][day].Close > S[j + 1][day].Close)
                {
                    Stock temp = S[j][day];
                    S[j][day] = S[j + 1][day];
                    S[j + 1][day] = temp;
                }
                flag = 1;
            }
        }
    }
    for (int i = 0; i < num_of_com; i++)
    {
        printf("%s --> %d \t %f\n", S[i][0].name, S[i][day].volume, S[i][day].Close);
    }
}

void Question3(Stock S[num_of_com][num_of_days], int buy_date, int sell_date, char buytype[], char selltype[], int NumStocks, int Chosen[])
{
    for (int i = 0; i < NumStocks; i++)
    {
        float buy_price, sell_price;
        int dateFinal = sell_date - 1;
        int dateInitial = buy_date - 1;
        int num = Chosen[i] - 1;
        if (strcmp(buytype, "Open") == 0)
        {
            buy_price = S[num][dateInitial].Open;
        }
        else if (strcmp(buytype, "High") == 0)
        {
            buy_price = S[num][dateInitial].High;
        }
        else if (strcmp(buytype, "Low") == 0)
        {
            buy_price = S[num][dateInitial].Low;
        }
        else
        {
            buy_price = S[num][dateInitial].Close;
        }

        if (strcmp(selltype, "Open") == 0)
        {
            sell_price = S[num][dateFinal].Open;
        }
        else if (strcmp(selltype, "High") == 0)
        {
            sell_price = S[num][dateFinal].High;
        }
        else if (strcmp(selltype, "Low") == 0)
        {
            sell_price = S[num][dateFinal].Low;
        }
        else
        {
            sell_price = S[num][dateFinal].Close;
        }
        float change = sell_price - buy_price;
        if (change < 0)
        {
            change *= (-1);
            printf("%s\t --> %0.3f Rs Loss\n", S[num][buy_date].name, change);
        }
        else
        {
            printf("%s\t --> %0.3f Rs Profit\n", S[num][buy_date].name, change);
        }
    }
}

void Question4(Stock S[num_of_com][num_of_days], int buy_day, char buy_type[20], int sell_day, char sell_type[20])
{
    int j;
    int check = 1;
    float buy, sell;
    float performance, high_performance = 0;
    printf("The Highest Preforming Stock is :- \n");
    for (int i = 0; i < 10; i++)
    {

        if (strcmp(buy_type, "Open") == 0)
        {
            buy = S[i][buy_day].Open;
        }
        else if (strcmp(buy_type, "Close") == 0)
        {
            buy = S[i][buy_day].Close;
        }
        else if (strcmp(buy_type, "High") == 0)
        {
            buy = S[i][buy_day].High;
        }
        else if (strcmp(buy_type, "Low") == 0)
        {
            buy = S[i][buy_day].Low;
        }
        if (strcmp(sell_type, "Open") == 0)
        {
            sell = S[i][sell_day].Open;
        }
        if (strcmp(sell_type, "Close") == 0)
        {
            sell = S[i][sell_day].Close;
        }
        if (strcmp(sell_type, "High") == 0)
        {
            sell = S[i][sell_day].High;
        }
        if (strcmp(sell_type, "Low") == 0)
        {
            sell = S[i][sell_day].Low;
        }

        performance = 100 * (sell - buy) / buy;
        if (performance > high_performance)
        {
            high_performance = performance;
            j = i;
        }
    }
    printf(" %s \t\t\t %f  ", S[j][0].name, high_performance);
}

void Question5(Stock S[num_of_com][num_of_days], int buy_day, char buy_type[20], int sell_day, char sell_type[20])
{
    int j;
    int check = 1;
    float buy, sell;
    float performance, low_performance = 0;
    printf("The Lowest Preforming Stock is :- \n");
    for (int i = 0; i < 10; i++)
    {

        if (strcmp(buy_type, "Open") == 0)
        {
            buy = S[i][buy_day].Open;
        }
        else if (strcmp(buy_type, "Close") == 0)
        {
            buy = S[i][buy_day].Close;
        }
        else if (strcmp(buy_type, "High") == 0)
        {
            buy = S[i][buy_day].High;
        }
        else if (strcmp(buy_type, "Low") == 0)
        {
            buy = S[i][buy_day].Low;
        }
        if (strcmp(sell_type, "Open") == 0)
        {
            sell = S[i][sell_day].Open;
        }
        else if (strcmp(sell_type, "Close") == 0)
        {
            sell = S[i][sell_day].Close;
        }
        else if (strcmp(sell_type, "High") == 0)
        {
            sell = S[i][sell_day].High;
        }
        else if (strcmp(sell_type, "Low") == 0)
        {
            sell = S[i][sell_day].Low;
        }

        performance = 100 * (sell - buy) / buy;
        if (performance < low_performance)
        {
            low_performance = performance;
            j = i;
        }
    }
    printf(" %s \t\t\t %f", S[j][0].name, low_performance);
}

void Question6(Stock S[num_of_com][num_of_days], int starting_date, int ending_date)
{
    OvrPerformance P[num_of_com];
    for (int i = 0; i < num_of_com; i++)
    {
        float ovr_per = 0;
        for (int j = starting_date - 1; j <= ending_date - 1; j++)
        {
            float change = 0;
            change = S[i][j].Close - S[i][j].Open;
            change = (change / S[i][j].Open) * S[i][j].volume;
            ovr_per += change;
        }
        strcpy(P[i].names, S[i][0].name);
        P[i].Op = ovr_per;
    }
    int flag = 1;
    for (int i = 0; i < num_of_com - 1 && flag == 1; i++)
    {
        flag = 0;
        for (int j = 0; j < num_of_com - i - 1; j++)
        {
            if (P[j].Op > P[j + 1].Op)
            {
                OvrPerformance temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < num_of_com; i++)
    {
        printf("%s --> %0.2f\n", P[i].names, P[i].Op);
    }
}

void Question7(Stock S[num_of_com][num_of_days], int date, int start_date, int end_date)
{
    float avg_val;
    for (int i = 0; i < num_of_com; i++)
    {
        avg_val = (S[i][date - 1].Open + S[i][date - 1].Close) / 2;
        printf("%s -> %0.3f\n", S[i][0].name, avg_val);
    }
    printf("\n");
    float avg_avg_val;
    for (int i = 0; i < num_of_com; i++)
    {
        float weighted_Sum = 0, Vol_Sum = 0;
        for (int j = start_date; j <= end_date; j++)
        {
            avg_val = (S[i][j - 1].Open + S[i][j - 1].Close) / 2;
            weighted_Sum += avg_val * S[i][j - 1].volume;
            Vol_Sum += S[i][j - 1].volume;
        }
        avg_avg_val = weighted_Sum / Vol_Sum;
        printf("%s -> %0.3f \n", S[i][0].name, avg_avg_val);
    }
}

int main()
{

    Stock Company[num_of_com][num_of_days];

    for (int i = 0; i < num_of_days; i++)
    {
        strcpy(Company[0][i].name, "TATASTEEL");
        strcpy(Company[1][i].name, "COALINDIA");
        strcpy(Company[2][i].name, "ICICIBANK");
        strcpy(Company[3][i].name, "ADANIENT ");
        strcpy(Company[4][i].name, "BAJAJFIN ");
        strcpy(Company[5][i].name, "ONGC     ");
        strcpy(Company[6][i].name, "WIPRO    ");
        strcpy(Company[7][i].name, "RELIANCE ");
        strcpy(Company[8][i].name, "ITC      ");
        strcpy(Company[9][i].name, "BPCL     ");
    }

    { // TATASTEEL

        Company[0][6].Open = 127.85;
        Company[0][5].Open = 127.9;
        Company[0][4].Open = 125.1;
        Company[0][3].Open = 125;
        Company[0][2].Open = 125.35;
        Company[0][1].Open = 126;
        Company[0][0].Open = 124.7;

        Company[0][6].High = 128.7;
        Company[0][5].High = 128.55;
        Company[0][4].High = 127.25;
        Company[0][3].High = 125.75;
        Company[0][2].High = 126.9;
        Company[0][1].High = 126.3;
        Company[0][0].High = 125.9;

        Company[0][6].Low = 126.6;
        Company[0][5].Low = 127;
        Company[0][4].Low = 124.95;
        Company[0][3].Low = 124;
        Company[0][2].Low = 125.1;
        Company[0][1].Low = 124.7;
        Company[0][0].Low = 123.75;

        Company[0][6].Close = 127.1;
        Company[0][5].Close = 127.4;
        Company[0][4].Close = 127;
        Company[0][3].Close = 125.05;
        Company[0][2].Close = 125.9;
        Company[0][1].Close = 124.95;
        Company[0][0].Close = 125.3;

        Company[0][6].volume = 20926079;
        Company[0][5].volume = 24241710;
        Company[0][4].volume = 23868700;
        Company[0][3].volume = 26912800;
        Company[0][2].volume = 19361688;
        Company[0][1].volume = 24455932;
        Company[0][0].volume = 28745957;

        // COALINDIA

        Company[1][6].Open = 317.35;
        Company[1][5].Open = 313;
        Company[1][4].Open = 307.85;
        Company[1][3].Open = 305;
        Company[1][2].Open = 302.55;
        Company[1][1].Open = 304.55;
        Company[1][0].Open = 288.25;

        Company[1][6].High = 319.75;
        Company[1][5].High = 318.35;
        Company[1][4].High = 313.65;
        Company[1][3].High = 310.85;
        Company[1][2].High = 309.1;
        Company[1][1].High = 305;
        Company[1][0].High = 303.9;

        Company[1][6].Low = 315.25;
        Company[1][5].Low = 312.1;
        Company[1][4].Low = 306.55;
        Company[1][3].Low = 304.45;
        Company[1][2].Low = 301.9;
        Company[1][1].Low = 299.45;
        Company[1][0].Low = 287.8;

        Company[1][6].Close = 316.95;
        Company[1][5].Close = 317.4;
        Company[1][4].Close = 312;
        Company[1][3].Close = 307.95;
        Company[1][2].Close = 307.2;
        Company[1][1].Close = 301.85;
        Company[1][0].Close = 303.25;

        Company[1][6].volume = 9662837;
        Company[1][5].volume = 7760527;
        Company[1][4].volume = 10535107;
        Company[1][3].volume = 9516879;
        Company[1][2].volume = 15375295;
        Company[1][1].volume = 12321154;
        Company[1][0].volume = 28745957;

        // ICICIBANK

        Company[2][6].Open = 949.2;
        Company[2][5].Open = 955.4;
        Company[2][4].Open = 948.5;
        Company[2][3].Open = 949.95;
        Company[2][2].Open = 952.85;
        Company[2][1].Open = 954.9;
        Company[2][0].Open = 940.4;

        Company[2][6].High = 950.65;
        Company[2][5].High = 960.95;
        Company[2][4].High = 954.85;
        Company[2][3].High = 957.4;
        Company[2][2].High = 960.1;
        Company[2][1].High = 962.05;
        Company[2][0].High = 957.5;

        Company[2][6].Low = 939.1;
        Company[2][5].Low = 951.5;
        Company[2][4].Low = 946.15;
        Company[2][3].Low = 944.55;
        Company[2][2].Low = 948.4;
        Company[2][1].Low = 950.75;
        Company[2][0].Low = 940.35;

        Company[2][6].Close = 943.75;
        Company[2][5].Close = 953.9;
        Company[2][4].Close = 951.4;
        Company[2][3].Close = 951.3;
        Company[2][2].Close = 954.25;
        Company[2][1].Close = 953.1;
        Company[2][0].Close = 951.2;

        Company[2][6].volume = 12000153;
        Company[2][5].volume = 7747527;
        Company[2][4].volume = 5763024;
        Company[2][3].volume = 6650442;
        Company[2][2].volume = 7836818;
        Company[2][1].volume = 12321154;
        Company[2][0].volume = 11452715;

        // ADANIENT

        Company[3][6].Open = 2440;
        Company[3][5].Open = 2459.95;
        Company[3][4].Open = 2454.55;
        Company[3][3].Open = 2488;
        Company[3][2].Open = 2499;
        Company[3][1].Open = 2533;
        Company[3][0].Open = 2443;

        Company[3][6].High = 2441.75;
        Company[3][5].High = 2462;
        Company[3][4].High = 2464.70;
        Company[3][3].High = 2495;
        Company[3][2].High = 2521.75;
        Company[3][1].High = 2538;
        Company[3][0].High = 2515.95;

        Company[3][6].Low = 2401.05;
        Company[3][5].Low = 2423.50;
        Company[3][4].Low = 2421.85;
        Company[3][3].Low = 2422.35;
        Company[3][2].Low = 2490.65;
        Company[3][1].Low = 2482.5;
        Company[3][0].Low = 2443;

        Company[3][6].Close = 2406.35;
        Company[3][5].Close = 2428.40;
        Company[3][4].Close = 2429.35;
        Company[3][3].Close = 2454.55;
        Company[3][2].Close = 2506.35;
        Company[3][1].Close = 2488.6;
        Company[3][0].Close = 2498.3;

        Company[3][6].volume = 776977;
        Company[3][5].volume = 707543;
        Company[3][4].volume = 803856;
        Company[3][3].volume = 2278682;
        Company[3][2].volume = 1804818;
        Company[3][1].volume = 1627836;
        Company[3][0].volume = 1771910;

        // BAJAJFINANCE

        Company[4][6].Open = 8050;
        Company[4][5].Open = 8080;
        Company[4][4].Open = 8044.30;
        Company[4][3].Open = 7999.55;
        Company[4][2].Open = 8125;
        Company[4][1].Open = 8139.80;
        Company[4][0].Open = 8055;

        Company[4][6].High = 8084.60;
        Company[4][5].High = 8159;
        Company[4][4].High = 8069;
        Company[4][3].High = 8082.90;
        Company[4][2].High = 8127;
        Company[4][1].High = 8173;
        Company[4][0].High = 8135;

        Company[4][6].Low = 7850;
        Company[4][5].Low = 8057.55;
        Company[4][4].Low = 7982.65;
        Company[4][3].Low = 7956.05;
        Company[4][2].Low = 8003;
        Company[4][1].Low = 8095.45;
        Company[4][0].Low = 8021;

        Company[4][6].Close = 7866.55;
        Company[4][5].Close = 8093;
        Company[4][4].Close = 8036;
        Company[4][3].Close = 8051.65;
        Company[4][2].Close = 8014.30;
        Company[4][1].Close = 8101.95;
        Company[4][0].Close = 8083.60;

        Company[4][6].volume = 12000153;
        Company[4][5].volume = 838283;
        Company[4][4].volume = 438246;
        Company[4][3].volume = 662282;
        Company[4][2].volume = 764092;
        Company[4][1].volume = 712372;
        Company[4][0].volume = 965024;

        // ONGC

        Company[5][6].Open = 188;
        Company[5][5].Open = 187;
        Company[5][4].Open = 187.95;
        Company[5][3].Open = 184.5;
        Company[5][2].Open = 183.2;
        Company[5][1].Open = 184.4;
        Company[5][0].Open = 182.3;

        Company[5][6].High = 188.05;
        Company[5][5].High = 187.05;
        Company[5][4].High = 188.2;
        Company[5][3].High = 186.25;
        Company[5][2].High = 184.85;
        Company[5][1].High = 184.7;
        Company[5][0].High = 184.5;

        Company[5][6].Low = 186.05;
        Company[5][5].Low = 185.55;
        Company[5][4].Low = 186.25;
        Company[5][3].Low = 184.05;
        Company[5][2].Low = 183;
        Company[5][1].Low = 182.75;
        Company[5][0].Low = 182.05;

        Company[5][6].Close = 186.95;
        Company[5][5].Close = 186.25;
        Company[5][4].Close = 186.55;
        Company[5][3].Close = 184.9;
        Company[5][2].Close = 184.45;
        Company[5][1].Close = 183.25;
        Company[5][0].Close = 183.5;

        Company[5][6].volume = 10181113;
        Company[5][5].volume = 4381065;
        Company[5][4].volume = 12376549;
        Company[5][3].volume = 7435899;
        Company[5][2].volume = 8677885;
        Company[5][1].volume = 8499601;
        Company[5][0].volume = 11819690;

        // WIPRO

        Company[6][6].Open = 409;
        Company[6][5].Open = 411.7;
        Company[6][4].Open = 411;
        Company[6][3].Open = 411.9;
        Company[6][2].Open = 421.75;
        Company[6][1].Open = 409;
        Company[6][0].Open = 406.4;

        Company[6][6].High = 413.65;
        Company[6][5].High = 413.85;
        Company[6][4].High = 411.9;
        Company[6][3].High = 414.4;
        Company[6][2].High = 421.9;
        Company[6][1].High = 423.95;
        Company[6][0].High = 408.75;

        Company[6][6].Low = 407;
        Company[6][5].Low = 411.05;
        Company[6][4].Low = 408.15;
        Company[6][3].Low = 409.05;
        Company[6][2].Low = 414.7;
        Company[6][1].Low = 409;
        Company[6][0].Low = 406.2;

        Company[6][6].Close = 407.45;
        Company[6][5].Close = 411.4;
        Company[6][4].Close = 410.2;
        Company[6][3].Close = 411.05;
        Company[6][2].Close = 417.1;
        Company[6][1].Close = 421.15;
        Company[6][0].Close = 407.75;

        Company[6][6].volume = 2440533;
        Company[6][5].volume = 2989694;
        Company[6][4].volume = 2638826;
        Company[6][3].volume = 5457027;
        Company[6][2].volume = 1804818;
        Company[6][1].volume = 9546114;
        Company[6][0].volume = 2564007;

        // 8. RELIANCE

        Company[7][6].Open = 2355.25;
        Company[7][5].Open = 2356;
        Company[7][4].Open = 2340;
        Company[7][3].Open = 2340;
        Company[7][2].Open = 2343.85;
        Company[7][1].Open = 2314.45;
        Company[7][0].Open = 2306.55;

        Company[7][6].High = 2367;
        Company[7][5].High = 2359.70;
        Company[7][4].High = 2354.55;
        Company[7][3].High = 2357.50;
        Company[7][2].High = 2359.35;
        Company[7][1].High = 2349.70;
        Company[7][0].High = 2317.90;

        Company[7][6].Low = 2321;
        Company[7][5].Low = 2341.30;
        Company[7][4].Low = 2336;
        Company[7][3].Low = 2329.15;
        Company[7][2].Low = 2338.15;
        Company[7][1].Low = 2313;
        Company[7][0].Low = 2303.75;

        Company[7][6].Close = 2324;
        Company[7][5].Close = 2355.25;
        Company[7][4].Close = 2344.05;
        Company[7][3].Close = 2349.30;
        Company[7][2].Close = 2349.40;
        Company[7][1].Close = 2345.05;
        Company[7][0].Close = 2308.40;

        Company[7][6].volume = 4459160;
        Company[7][5].volume = 3964090;
        Company[7][4].volume = 12376549;
        Company[7][3].volume = 5075158;
        Company[7][2].volume = 1804818;
        Company[7][1].volume = 4907059;
        Company[7][0].volume = 5118016;

        // 9. ITC

        Company[8][6].Open = 454.25;
        Company[8][5].Open = 449.8;
        Company[8][4].Open = 448;
        Company[8][3].Open = 449.85;
        Company[8][2].Open = 449.65;
        Company[8][1].Open = 447.2;
        Company[8][0].Open = 440.45;

        Company[8][6].High = 458.2;
        Company[8][5].High = 454.5;
        Company[8][4].High = 451;
        Company[8][3].High = 451.8;
        Company[8][2].High = 452.5;
        Company[8][1].High = 449.45;
        Company[8][0].High = 444.85;

        Company[8][6].Low = 451;
        Company[8][5].Low = 449;
        Company[8][4].Low = 446.2;
        Company[8][3].Low = 447;
        Company[8][2].Low = 446.15;
        Company[8][1].Low = 444.8;
        Company[8][0].Low = 440.45;

        Company[8][6].Close = 451.65;
        Company[8][5].Close = 453.45;
        Company[8][4].Close = 448.95;
        Company[8][3].Close = 448.35;
        Company[8][2].Close = 450.7;
        Company[8][1].Close = 448.25;
        Company[8][0].Close = 444.4;

        Company[8][6].volume = 6894947;
        Company[8][5].volume = 6936218;
        Company[8][4].volume = 4214958;
        Company[8][3].volume = 7632483;
        Company[8][2].volume = 11774487;
        Company[8][1].volume = 7651513;
        Company[8][0].volume = 5014758;

        // BPCL

        Company[9][6].Open = 355;
        Company[9][5].Open = 348.90;
        Company[9][4].Open = 345;
        Company[9][3].Open = 347.10;
        Company[9][2].Open = 344.90;
        Company[9][1].Open = 342.20;
        Company[9][0].Open = 340.05;

        Company[9][6].High = 356.50;
        Company[9][5].High = 357.70;
        Company[9][4].High = 348.45;
        Company[9][3].High = 350.60;
        Company[9][2].High = 350.35;
        Company[9][1].High = 345.30;
        Company[9][0].High = 342.60;

        Company[9][6].Low = 348.85;
        Company[9][5].Low = 346.70;
        Company[9][4].Low = 342;
        Company[9][3].Low = 347.05;
        Company[9][2].Low = 344.05;
        Company[9][1].Low = 341.50;
        Company[9][0].Low = 339.20;

        Company[9][6].Close = 350.20;
        Company[9][5].Close = 354.70;
        Company[9][4].Close = 347.25;
        Company[9][3].Close = 347.70;
        Company[9][2].Close = 348.70;
        Company[9][1].Close = 342.55;
        Company[9][0].Close = 340.40;

        Company[9][6].volume = 4581114;
        Company[9][5].volume = 6936218;
        Company[9][4].volume = 1631235;
        Company[9][3].volume = 1990902;
        Company[9][2].volume = 3851901;
        Company[9][1].volume = 2399756;
        Company[9][0].volume = 1786489;
    }

    input(Company);

    return 0;
}