#ifndef C_UTH_CPP2C_ENCAPSULATION_DEFS_H
#define C_UTH_CPP2C_ENCAPSULATION_DEFS_H

#include <stdlib.h>
#include <stdbool.h>


const char* message;

/*------ Box -----*/

typedef struct Box
{
    double width;
    double height;
    double length;
}Box;


/*
    Box(double dim = 1);
    Box(double l, double w, double h);
    ~Box();
 */

void print_KpBxK(const Box *const box);

/* default ctor */
void __cBOX__pBx(Box *box);

/* one param ctor */
void __cBOX__pBx_d(Box *box, double dim);

/* three param ctor */
void __cBOX__pBx_d_d_d(Box *box, double l, double w, double h);

/* copy ctor */
void __ccBOX__pBx_KpBx(Box *const box1, const Box const *box2);

/* DTOR */
void __dBOX__pBx(Box* box);

/*    Box& operator*=(double mult); */
void __opr_mult_equ__pBxK_d(Box *const box, double mult);



/*----- Box Defs -----*/

/*
double getWidth() const;
double getLength() const;
double getHeight() const;
double getVolume() const;*/

/*
inline double getWidth_KpBx_(const Box *box)
{
    return box->width;
}

inline double getLength_KpBx_(const Box *box)
{
    return box->length;
}

inline double getHeight_KpBx_(const Box *box)
{
    return box->height;
}

inline double getVolume_KpBx_(const Box *box)
{
    return box->width * box->length * box->height;
}
*/

/*
inline Box operator*(const Box& box, double mult)
{
Box ret = box;
ret *= mult;
return ret;
}

inline Box operator*(double mult, const Box& box)
{
return box * mult;
}

inline bool operator==(const Box& lhs, const Box& rhs)
{
return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}

inline bool operator!=(const Box& lhs, const Box&rhs)
{
return !(lhs == rhs);
}*/


/*----- Shelf -----*/

typedef struct Shelf
{
    Box boxes[3];
}Shelf;

/* default ctor */
/*void __cSHELF__pshf_(Shelf *shelf);*/

/*void setBox(int index, const Box& dims);*/
void setBox_i_KpBx(Shelf *shelf, int index, Box const *dims);

/*double getVolume() const;*/
double getVolume_KpShf(const Shelf *shelf);

/*void print() const;*/
void print_KpShfK(const Shelf *const shelf);


/*----- Shelf Defs -----*/
/*
inline Box& Shelf::getBox(int index)
{
    return boxes[index];
}

inline int Shelf::getNumBoxes()
{
    return NUM_BOXES;
}

inline void Shelf::setMessage(const char* msg)
{
    message = msg;
}*/

#endif /*C_UTH_CPP2C_ENCAPSULATION_DEFS_H*/
