#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

static cFlag = true;
static dFlag = false;

static Box largeBox;


void thisFunc()
{
    static Box box99;

    if(dFlag)
    {
        __dBOX__pBx_(&box99);
        return;
    }

    printf("\n--- thisFunc() ---\n\n");
    if(cFlag)
    {
        __cBOX__pBx_d_d_d(&box99, 90, 90, 90);
        cFlag = false;
    }

    __opr__mult_equ__pBxK_d(&box99, 10);

}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");
    static Box box88 = {88, 88, 88};
    __opr__mult_equ__pBxK_d(&box88, 10);
}


void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
    __cBOX__pBx_d(&b1,3);
    Box b2;
    __cBOX__pBx_d_d_d(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    __opr__mult_equ__pBxK_d(&b1, 1.5);
    __opr__mult_equ__pBxK_d(&b2, 0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    Box b3;
    __ccBOX__pBx_pBx(&b3, &b2);
    Box b4;
    b4.width = b2.width *3;
    b4.length = b2.length *3;
    b4.height = b2.height *3;
    printf("b3 %s b4\n", (b3.width == b4.width && b3.length == b4.length && b3.height == b4.height) ? "equals" : "does not equal");

    __opr__mult_equ__pBxK_d(&b3, 1.5);
    __opr__mult_equ__pBxK_d(&b4, 0.5);
    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.length == b4.length && b3.height == b4.height) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    __dBOX__pBx_(&b4);
    __dBOX__pBx_(&b3);
    __dBOX__pBx_(&b2);
    __dBOX__pBx_(&b1);
}


void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    __cBOX__pBx_d(&aBox, 5);

    Shelf aShelf;

    print_KpShfK(&aShelf);
    //Box my_largeBox;
    //__cBOX__pBx_d_d_d(&my_largeBox, 10, 20, 30);
    setBox_i_KpBx(&aShelf, 1, &largeBox);
    setBox_i_KpBx(&aShelf, 0, &aBox);
    print_KpShfK(&aShelf);

    /* TODO: const message and inline */
    /*
    aShelf.setMessage("This is the total volume on the shelf:");
    print_KpShfK(&aShelf);
    Shelf::setMessage("Shelf's volume:");
    print_KpShfK(&aShelf);*/

    Box b5;
    __cBOX__pBx_d_d_d(&b5, 2, 4, 6);
    setBox_i_KpBx(&aShelf, 1, &b5);
    __dBOX__pBx_(&b5);

    Box b6;
    __cBOX__pBx_d(&b6, 2);
    setBox_i_KpBx(&aShelf, 2, &b6);
    __dBOX__pBx_(&b6);
    print_KpShfK(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    __dBOX__pBx_(&aShelf.boxes[2]);
    __dBOX__pBx_(&aShelf.boxes[1]);
    __dBOX__pBx_(&aShelf.boxes[0]);
    __dBOX__pBx_(&aBox);
}

int main()
{
    __cBOX__pBx_d_d_d(&largeBox, 10, 20, 30);
    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");
    dFlag = true;
    thisFunc();
    __dBOX__pBx_(&largeBox);

    return 0;
}