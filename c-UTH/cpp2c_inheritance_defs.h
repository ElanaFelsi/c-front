#ifndef C_UTH_CPP2C_INHERITANCE_DEFS_H
#define C_UTH_CPP2C_INHERITANCE_DEFS_H

/*#include <cstdio>*/
#include <stdio.h>

#include "cpp2c_encapsulation_defs.h"

/*  Materials  */

typedef struct Materials
{
    enum  Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    } Types;

    /*
    static const char* getName(Types type)
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[type];
    }*/
}Materials;

static const char* __s_getName__EnT(enum Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}


typedef struct Material_t/*: public Materials*/
{
    Materials materials;

    /*Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }*/

    /*const char* name() const { return getName(material); }*/

    enum Types material;
}Material_t;

void __cMATERIAL_T__pMtrlt(Material_t *this);
void __cMATERIAL_T__pMtrlt_EnT(Material_t *this, enum Types mat);

const char* __name__pMtrlt(Material_t *this);


/* PhysicalBox */

/*
class PhysicalBox: public Box
{
public:
    PhysicalBox(double l, double w, double h);
    PhysicalBox(double l, double w, double h, Materials::Types t);
    PhysicalBox(Materials::Types t);
    ~PhysicalBox();

    Materials::Types getMaterial() const;
    void printp() const;

private:
    Material_t material;
};
*/

typedef struct PhysicalBox
{
    Box box;
    Material_t material;

}PhysicalBox;

void __cPHBOX__pPhBx_d_d_d(PhysicalBox *this, double l, double w, double h);
void __cPHBOX__pPhBx_d_d_d_EnT(PhysicalBox *this, double l, double w, double h, enum Types t);
void __cPHBOX__pPhBx_EnT(PhysicalBox *this, enum Types t);

void __dPHBOX__pPhBx(PhysicalBox *this);

void __printp__KpPhBxK(const PhysicalBox *const this);



/*bool operator==(const PhysicalBox&, const PhysicalBox&);
bool operator!=(const PhysicalBox&, const PhysicalBox&);*/

/* PhysicalBox Defs inlines */

/*
inline Materials::Types PhysicalBox::getMaterial() const
{
return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
return !(lhs == rhs);
}*/

/* WeightBox */

/*
class WeightBox: public Box
{
public:
    WeightBox(double l, double w, double h, double wgt = 0.0);
    WeightBox(const WeightBox& other);
    ~WeightBox();

    WeightBox& operator=(const WeightBox& other);

    double getWeight() const;
    void printw() const;

private:
    double weight;
};
*/

typedef struct WeightBox
{
    Box box;
    double weight;

}WeightBox;

void __cWTBOX__pWtBx_d_d_d(WeightBox *this, double l, double w, double h);
void __cWTBOX__pWtBx_d_d_d_d(WeightBox *this, double l, double w, double h, double wgt);
void __ccWTBOX__pWtBx_KpWtBx(WeightBox *const this, const WeightBox const *other);

void __dWTBOX__pWtBx(WeightBox *this);

void __assignment_opr__pWtBx_KpWtBx(WeightBox *const this, const WeightBox const *other);

void __printw__KpWtBxK(const WeightBox *const this);



/*bool operator==(const WeightBox&, const WeightBox&);
bool operator!=(const WeightBox&, const WeightBox&);*/

/* WeightBox Defs inlines */

/*
inline double WeightBox::getWeight() const
{
return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
return !(lhs == rhs);
}
 */




#endif /*C_UTH_CPP2C_INHERITANCE_DEFS_H*/
