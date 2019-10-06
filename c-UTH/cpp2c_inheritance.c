#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

void doMaterials()
{
    printf("\n--- Start doMaterials() ---\n\n");

    Materials mat;
    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(enum Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest
    {
        Materials mat;
        Material_t mat_t;
    };
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest));

    Material_t mat1;
    Material_t mat2;
    __cMATERIAL_T__pMtrlt_EnT(&mat2, METAL);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    __cPHBOX__pPhBx_d_d_d_EnT(&pb1, 8, 6, 4, PLASTIC);
    PhysicalBox pb2;
    __cPHBOX__pPhBx_EnT(&pb2, WOOD);
    PhysicalBox pb3;
    __cPHBOX__pPhBx_d_d_d(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4;
    __ccPHBOX__pPhBx_KPhBx(&pb4, &pb1);
    __printp__KpPhBxK(&pb4);
    __printp__KpPhBxK(&pb1);

    /*printf("pb4 %s pb1\n", pb4 == pb1 ? "equals" : "does not equal");*/
    printf("pb4 %s pb1\n", pb4.box.length == pb1.box.length && pb4.box.width == pb1.box.width &&
    pb4.box.height == pb1.box.height && pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    /*pb4 = pb3;*/

    __printp__KpPhBxK(&pb4);
    __printp__KpPhBxK(&pb3);
    printf("pb4 %s pb3\n", pb4.box.length == pb1.box.length && pb4.box.width == pb1.box.width &&
                           pb4.box.height == pb1.box.height && pb4.material.material == pb1.material.material
                           ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
}

void doWeightBox()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
    __cWTBOX__pWtBx_d_d_d_d(&pw1,8, 6, 4, 25);
    WeightBox pw2;
    __cWTBOX__pWtBx_d_d_d(&pw2,1, 2, 3);
    WeightBox pw3;
    __cWTBOX__pWtBx_d_d_d_d(&pw3,10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    /*WeightBox pw4 = pw1;*/
    WeightBox pw4;
    __ccWTBOX__pWtBx_KpWtBx(&pw4, &pw1);
    __printw__KpWtBxK(&pw4);
    __printw__KpWtBxK(&pw1);

    printf("pw4 %s pw1\n", pw4.box.length == pw1.box.length && pw4.box.width == pw1.box.width &&
                           pw4.box.height == pw1.box.height && pw4.weight == pw1.weight
                           ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    /*pw4 = pw3;*/
    __assignment_opr__pWtBx_KpWtBx(&pw4, &pw3);
    __printw__KpWtBxK(&pw4);
    __printw__KpWtBxK(&pw3);
    printf("pw4 %s pw3\n", pw4.box.length == pw3.box.length && pw4.box.width == pw3.box.width &&
                           pw4.box.height == pw3.box.height && pw4.weight == pw3.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
}





int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

}