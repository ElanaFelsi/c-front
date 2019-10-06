#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*/// Box ///////////*/
void print_KpBxK(const Box *const box)
{
    printf("Box: %f x %f x %f\n",  box->length, box->width, box->height);
}

void __cBOX__pBx(Box *box)
{
    box->width = 1;
    box->length = 1;
    box->height = 1;
    print_KpBxK(box);
}

void __cBOX__pBx_d(Box *box, double dim)
{
    box->width = dim;
    box->length = dim;
    box->height = dim;
    print_KpBxK(box);
}

void __cBOX__pBx_d_d_d(Box *box, double l, double w, double h)
{
    box->length = l;
    box->width = w;
    box->height = h;
    print_KpBxK(box);
}

void __ccBOX__pBx_KpBx(Box *const box1, const Box const *box2)
{
    box1->height = box2->height;
    box1->width = box2->width;
    box1->length = box2->length;
}

void __dBOX__pBx(Box* box)
{
    printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}


void __opr_mult_equ__pBxK_d(Box *const box, double mult)
{
    box->width *= mult;
    box->height *= mult;
    box->length *= mult;
}


/*/// Shelf ///////////*/
/*void __cSHELF__pshf_(Shelf *shelf)
{
    int i=0;
    for(; i<3; ++i)
    {
        __cBOX__pBx_(&shelf->boxes[i]);
    }
}*/

void setBox_i_KpBx(Shelf *shelf, int index, Box const *dims)
{
    __ccBOX__pBx_KpBx(&shelf->boxes[index], dims);
}

double getVolume_KpShf(const Shelf *shelf)
{
    int i = 0;
    double vol = 0;
    for (; i < 3; ++i) {
        vol += shelf->boxes[i].width *shelf->boxes[i].height*shelf->boxes[i].length;
    }

    return vol;
}

void print_KpShfK(const Shelf *const shelf)
{
    printf("%s %f\n", "The total volume held on the shelf is", getVolume_KpShf(shelf));
}

