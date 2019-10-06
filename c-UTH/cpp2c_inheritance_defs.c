#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

/*  Materials  */

void __cMATERIAL_T__pMtrlt(Material_t *this)
{
    this->material = this->materials.OTHER;
    printf("Material created, set to %s\n", __name__pMtrlt(this));
}
void __cMATERIAL_T__pMtrlt_EnT(Material_t *this, enum Types mat)
{
    this->material = mat;
    printf("Material created, set to %s\n", __name__pMtrlt(this));
}

const char* __name__pMtrlt(Material_t *this)
{
    return __s_getName__EnT(this->material);
}



/* PhysicalBox Defs */

PhysicalBox::PhysicalBox(double l, double w, double h)
:   Box(l, w, h)
{
printp();
}

PhysicalBox::PhysicalBox(double l, double w, double h, Materials::Types t)
:   Box(l, w, h)
,   material(t)
        {
                printp();
        }

PhysicalBox::PhysicalBox(Materials::Types t)
:   material(t)
        {
                printp();
        }

PhysicalBox::~PhysicalBox()
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(), getWidth(), getHeight(), material.name());
}

void PhysicalBox::printp() const
{
printf("PhysicalBox, made of %s; ", material.name());
print();
}


/// WeightBox Defs ////////////

WeightBox::WeightBox(double l, double w, double h, double wgt)
:   Box(l, w, h)
,   weight(wgt)
        {
                printw();
        }

WeightBox::WeightBox(const WeightBox& other)
:   weight(other.weight)
{
printw();
}

WeightBox::~WeightBox()
{
    printf("Destructing WeightBox; ");
    printw();
}

WeightBox& WeightBox::operator=(const WeightBox& other)
{
weight = other.weight;
return *this;
}

void WeightBox::printw() const
{
printf("WeightBox, weight: %f; ", weight);
print();
}

