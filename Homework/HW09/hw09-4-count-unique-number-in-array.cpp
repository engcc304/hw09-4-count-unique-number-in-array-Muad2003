/*
    ผู้ใช้กรอกจำนวนอาเรย์ที่ต้องการกรอก จากนั้นผู้ใช้ทำการกรอกข้อมูลลงไปในอาเรย์จนครบ และให้คุณแสดงจำนวนชุดตัวเลขที่ซ้ำกันจากที่ผู้ใช้กรอก
    
    Test case:
        Input N :
            4
        Element[0] :
            3
        Element[1] :
            3
        Element[2] :
            2
        Element[3] :
            5
    Output:
        2 -> 1 value.
        3 -> 2 values.
        5 -> 1 value.


    Test case:
        Input N :
            9
        Element[0] :
            6
        Element[1] :
            6
        Element[2] :
            5
        Element[3] :
            9
        Element[4] :
            1
        Element[5] :
            9
        Element[6] :
            7
        Element[7] :
            6
        Element[8] :
            2
    Output:
        1 -> 1 value.
        2 -> 1 value.
        5 -> 1 value.
        6 -> 3 values.
        7 -> 1 value.
        9 -> 2 values.
*/

#include <stdio.h>

int main() {
    
    int n ;
    int temp = 0 ;
    printf ( "Input N :\n" ) ;
    scanf ( "%d", &n ) ;
    int array[ n ] ;
    int count[ n ] = {  } ;

    // รับค่า ตามจำนวน n
    for ( int i = 0 ; i < n ; i++ ) {
        printf ( "Element[%d] :\n", i ) ;
        scanf ( "%d", &array[ i ]  ) ;
    } // end for

    // เรียงค่าจากเลขน้อยไปหามาก
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = i + 1 ; k < n ; k++ ) {
            if ( array[ i ] > array[ k ] ) {
                temp = array[ i ] ;
                array[ i ] = array[ k ] ;
                array[ k ] = temp ;
            } // end if
        } // end for
    } // end for

    // ถ้าเปรียบเทียบแล้วได้ค่าซ้ำจะให้ ยอดรวมเพิ่ม
    for ( int i = 0 ; i <= n ; i++ ) {
        for ( int k = i + 1 ; k < n ; k++ ) {
            if ( array[ i ] == array[ k ] ) {
                count[ i ]++ ;
            } // end if
        } // end for
    } // end for
    
    // แสดงค่า
    for ( int i = 0 ; i < n ; i++ ) {
        if ( array[ i ] != array [ i - 1 ] ) {
            printf ( "%d -> %d values.\n", array[ i ] , count[ i ] + 1 ) ;
        } // end if   
    } // end for
    
    return 0;
} // end main