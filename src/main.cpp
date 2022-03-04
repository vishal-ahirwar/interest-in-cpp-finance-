#include<iostream>
inline void MonthlyInterest(double &invest,const double &rate,const std::string &ctype)
{
    std::cerr<<"Enter number of months invested : ";
    unsigned short int nmonths{};
    std::cin>>nmonths;
    for(short nm=0;nm<nmonths;++nm)
    {
        invest+=(invest*rate/(100*12));
    };
    std::cerr<<"The investment after "<<nmonths<<" months is ==> "<<ctype<<" : "<<invest<<"\n";

};
inline void DayInterest(double &invest,const double &rate,const std::string &ctype)
{
    std::cerr<<"Enter number of days invested : ";
    unsigned short int ndays{};
    std::cin>>ndays;
    for(short nd=0;nd<ndays;++nd)
    {
        invest+=(invest*rate/(100*365));
    };
    std::cerr<<"The investment after "<<ndays<<" days is ==> "<<ctype<<" : "<<invest<<"\n";

};

inline void yearlyInterest(double &invest,const double &rate,const std::string &ctype)
{
    std::cerr<<"Enter number of years invested : ";
    unsigned short int nyears{};
    std::cin>>nyears;
    for(short ny=0;ny<nyears;++ny)
    {
        invest+=(invest*rate/(100));
    };
    std::cerr<<"The investment after "<<nyears<<" years is ==> "<<ctype<<" : "<<invest<<"\n";

};
int main(void)
{
    double invest{},rate{};
    enum CompoundingTypes{daily,monthly,yearly,unknown} compounding;
    std::cerr<<"Enter Currency Type{rupee,doller,pound etc.\n";
    std::string ctype{};
    std::getline(std::cin,ctype);


    std::cerr<<"Enter Amount Invested  "<<ctype<<" :";
    std::cin>>invest;
    std::cin.clear();
    if(invest<0)
    {
        std::cerr<<R"(***[ERROR]***
        Negetive amount invested ! Please Invest more than $0
        [MESSAGE] : System Exited!)";
        return -1;

    };
    std::cerr<<"Enter invest rate : {%/year}";
    std::cin>>rate;
    std::cin.clear();
    compounding=CompoundingTypes::unknown;
    while(compounding==CompoundingTypes::unknown)
    {
        std::cerr<<"Enter Compounding period {m for monthly d for day y for year}";
        unsigned char choice{};
        std::cin>>choice;
        switch(choice)
        {
            case 'm':
            {
                compounding=CompoundingTypes::monthly;
                break;
            };
            case 'd':
            {
                compounding=CompoundingTypes::daily;
                break;
            };
            case 'y':
            {
                compounding=CompoundingTypes::yearly;
                break;
            };
            default:
            {
                compounding=CompoundingTypes::unknown;
                std::cerr<<"\n[ERROR]unknown componding period entered!\n";
                break;
            };
        };
    };

    switch(compounding)
    {
        case CompoundingTypes::monthly:
        {
            MonthlyInterest(invest,rate,ctype);
            break;
        };
        case CompoundingTypes::daily:
        {
            DayInterest(invest,rate,ctype);
            break;
        };
        case CompoundingTypes::yearly:
        {
            yearlyInterest(invest,rate,ctype);
            break;
        };
    };

    std::cerr<<R"(
                  ------------------------------
                  [SYSTEM MESSAGE] : Quiting ...
                  ------------------------------
    )";

    return 0;
}