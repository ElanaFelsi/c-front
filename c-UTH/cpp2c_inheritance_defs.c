#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

/*  Materials  */

void __cMATERIAL_T__pMtrlt(Material_t *this)
{
    this->material = this->materials.Types = OTHER;
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

/*
PhysicalBox::PhysicalBox(double l, double w, double h)
:   Box(l, w, h)
{
printp();
}*/
void __cPHBOX__pPhBx_d_d_d(PhysicalBox *this, double l, double w, double h)
{
    __cBOX__pBx_d_d_d(&this->box, l, w, h);

    __printp__KpPhBxK(this);
}

/*
PhysicalBox::PhysicalBox(double l, double w, double h, Materials::Types t)
:   Box(l, w, h)
,   material(t)
        {
                printp();
        }
*/
void __cPHBOX__pPhBx_d_d_d_EnT(PhysicalBox *this, double l, double w, double h, enum Types t)
{
    __cBOX__pBx_d_d_d(&this->box, l, w, h);
    this->material.material = t;
    __printp__KpPhBxK(this);
}

/*
PhysicalBox::PhysicalBox(Materials::Types t)
:   material(t)
        {
                printp();
        }*/
void __cPHBOX__pPhBx_EnT(PhysicalBox *this, enum Types t)
{
    this->material.material = t;
    __printp__KpPhBxK(this);
}

void __ccPHBOX__pPhBx_KPhBx(PhysicalBox *const this, const PhysicalBox const *other)
{
    __ccBOX__pBx_KpBx(&this->box, &other->box);
    this->material = other->material;
    __printw__KpWtBxK(this);
}

/*
PhysicalBox::~PhysicalBox()
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(), getWidth(), getHeight(), material.name());
}*/
void __dPHBOX__pPhBx(PhysicalBox *this)
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width, this->box.height, __name__pMtrlt(&this->material));
}

/*
void PhysicalBox::printp() const
{
printf("PhysicalBox, made of %s; ", material.name());
print();
}
 */
void __printp__KpPhBxK(const PhysicalBox *const this)
{
    printf("PhysicalBox, made of %s; ", __name__pMtrlt(&this->material));
    print_KpShfK(&this->box);
}


/* WeightBox Defs */

/*
WeightBox::WeightBox(double l, double w, double h, double wgt)
:   Box(l, w, h)
,   weight(wgt)
        {
                printw();
        }
*/
void __cWTBOX__pWtBx_d_d_d(WeightBox *this, double l, double w, double h)
{
    __cBOX__pBx_d_d_d(&this->box, l, w, h);
    this->weight = 0.0;
    __printw__KpWtBxK(this);
}
void __cWTBOX__pWtBx_d_d_d_d(WeightBox *this, double l, double w, double h, double wgt)
{
    __cBOX__pBx_d_d_d(&this->box, l, w, h);
    this->weight = wgt;
    __printw__KpWtBxK(this);
}

/*
WeightBox::WeightBox(const WeightBox& other)
:   weight(other.weight)
{
printw();
}*/
void __ccWTBOX__pWtBx_KpWtBx(WeightBox *const this, const WeightBox const *other)
{
    __ccBOX__pBx_KpBx(&this->box, &this->box);
    this->weight = other->weight;
    __printw__KpWtBxK(this);
}

/*
WeightBox::~WeightBox()
{
    printf("Destructing WeightBox; ");
    printw();
}
 */
void __dWTBOX__pWtBx(WeightBox *this)
{
    printf("Destructing WeightBox; ");
    __printw__KpWtBxK(this);
}

/*
WeightBox& WeightBox::operator=(const WeightBox& other)
{
weight = other.weight;
return *this;
}
*/
void __assignment_opr__pWtBx_KpWtBx(WeightBox *const this, const WeightBox const *other)
{
    this->weight = other->weight;
}

/*
void WeightBox::printw() const
{
printf("WeightBox, weight: %f; ", weight);
print();
}
*/
void __printw__KpWtBxK(const WeightBox *const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    print_KpBxK(&this->box);
}

