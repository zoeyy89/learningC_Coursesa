#include <stdio.h>
int normal_year_month_days[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
int leap_year_month_days[ 13 ] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
int year, JanF ;
int is_leap_year = 0 ; //0 false ; 1 true
    
int calc_JanF( int month, int day )
{
    int calc_days = 0 ;
    int i ;
    
    if( is_leap_year )
    {
        if( month > 12 || month < 1)
           return -1 ;
        
        if( day > leap_year_month_days[ month ] || day < 1)
           return -2 ;
           
        for( i = 1 ; i < month ; i ++ )
            calc_days +=  leap_year_month_days[ i ] ;
    }
    else
    {
        if( month > 12 || month < 1)
           return -1 ;
        
        if( day > normal_year_month_days[ month ] || day < 1)
           return -2 ;
           
        for( i = 1 ; i < month ; i ++ )
            calc_days +=  normal_year_month_days[ i ] ;        
    }
    
    // printf( "\n calc days = %d\n", calc_days) ;
    return (JanF + calc_days + day - 1) % 7 ;    
}

int main()
{
    int question_no ;
    int i ;
    int month, day ;
    
    scanf( "%d %d", &year, &JanF ) ;
    scanf( "%d", &question_no) ;    
    
   // printf( "%d %d %d \n",year, JanF, question_no) ;
    
    if( ((year % 4 == 0) && (year % 100 != 0)) || ( year % 400 == 0) ) 
         is_leap_year = 1 ;
    
    for( i = 0 ; i < question_no ; i++) {
       scanf( "%d %d", &month, &day ) ;
       printf( "%d ", calc_JanF( month, day ) ) ;
    }
         
    return 0;
}