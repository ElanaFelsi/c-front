#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
vt TF_vptr = {__dTEXTFORMATOR__pTF};
vt DTF_vptr = {__dDEFAULTEXTFORMATOR__pDTF, __pvPrint__KDTFK_Kcp};
vt PPF_vptr = {__dPPF__pPPF, __pvPrint__KPPFK_Kcp, __pvPrint__KPPFK_Kl_Kc, __getDefaultSymbolPPF__};
vt PPDF_vptr = {__dPPDF__pPPDF, __pvPrint__KPPFK_Kcp, __print__KpPPDFK_Kl_Kc, __getDefaultSymbolPPDF__};

void __dTEXTFORMATOR__pTF(TextFormatter *this) {}

/* DefaultTextFormatter Defs */

/*int DefaultTextFormatter::Ider::next_id = 0;*/

/*
DefaultTextFormatter::DefaultTextFormatter()
:   id(Ider::getId())
{
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", id);
}*/
void __dcDEFAULTEXTFORMATOR__pDTF(DefaultTextFormatter *this)
{
    this->textFormatter.TF_vptr = TF_vptr;
    this->textFormatter.TF_vptr = DTF_vptr;
    this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
/*
DefaultTextFormatter::~DefaultTextFormatter()
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", id);
}
*/
void __dDEFAULTEXTFORMATOR__pDTF(DefaultTextFormatter *this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
    this->textFormatter.TF_vptr = TF_vptr;
    __dTEXTFORMATOR__pTF(&this->textFormatter);
}

/*
DefaultTextFormatter::DefaultTextFormatter(const DefaultTextFormatter& other)
:   id(Ider::getId())
{
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other.id, id);
}
*/
void __ccDEFAULTEXTFORMATOR__pDTF_KpDTF(DefaultTextFormatter *const this, const DefaultTextFormatter const *other)
{
    /* inline cctor tf */ this->textFormatter.TF_vptr = other->textFormatter.TF_vptr;

    this->id = next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

/*
DefaultTextFormatter& DefaultTextFormatter::operator=(const DefaultTextFormatter& other)
{
printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other.id, id);
return *this;
}
*/
void __assignment_opr__pDTF_KpDTF(DefaultTextFormatter *const this, const DefaultTextFormatter const *other)
{
    /* inline cctor tf */ this->textFormatter.TF_vptr = other->textFormatter.TF_vptr;

    this->id = next_id++;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
}

/*
void DefaultTextFormatter::print(const char* text) const
{
printFunc("[DefaultTextFormatter::print(const char*)]");
printf("%s\n", text);
} */

void __pvPrint__KDTFK_Kcp(const DefaultTextFormatter *const this, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}


DefaultTextFormatter* __generateFormatterArray__()
{
    DefaultTextFormatter *DTF = malloc(sizeof(DefaultTextFormatter)*3);
    return DTF;
}


/* PrePostFixer Defs */

/*
PrePostFixer::PrePostFixer(const char* prefix, const char* postfix)
:   pre(prefix)
,   post(postfix)
{
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
}
 */
void __cPPF__pPPF_Kcp_Kcp(PrePostFixer *this, const char* prefix, const char* postfix)
{
    __dcDEFAULTEXTFORMATOR__pDTF(&this->defaultTextFormatter);
    this->defaultTextFormatter.textFormatter.TF_vptr = PPF_vptr;
    this->pre = prefix;
    this->post = postfix;
}

void __ccPPF__pPPF_KpPPFp(PrePostFixer *this, const PrePostFixer *other)
{
    __ccDEFAULTEXTFORMATOR__pDTF_KpDTF(&this->defaultTextFormatter, &other->defaultTextFormatter);
    this->pre = other->pre;
    this->post = other->post;
}


/*
PrePostFixer::~PrePostFixer()
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre, post);
}
 */
void __dPPF__pPPF(PrePostFixer *this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
    this->defaultTextFormatter.textFormatter.TF_vptr = DTF_vptr;
    __dDEFAULTEXTFORMATOR__pDTF(&this->defaultTextFormatter);
}

/*
void PrePostFixer::print(const char* text) const
{
printFunc("[PrePostFixer::print(const char*)]");
printf("%s%s%s\n", pre, text, post);
}
 */
void __pvPrint__KPPFK_Kcp(const PrePostFixer *const this, const char* text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}

void __pvPrint__KPPFK_Kl_Kc(const PrePostFixer *const this, const long num, const char symbol /*= '\0'*/)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol) {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}

char __getDefaultSymbolPPF__()
{
    return '\0';
}

/* PrePostDollarFixer Defs */

/*PrePostDollarFixer::PrePostDollarFixer(const char* prefix, const char* postfix)
:   PrePostFixer(prefix, postfix)
{
printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}
*/
void __cPPDF__pPPDF_Kc_Kc(PrePostDollarFixer *this, const char* prefix, const char* postfix)
{
    __cPPF__pPPF_Kcp_Kcp(&this->prePostFixer, prefix, postfix);
    this->prePostFixer.defaultTextFormatter.textFormatter.TF_vptr = PPDF_vptr;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
}

/*
PrePostDollarFixer::PrePostDollarFixer(const PrePostDollarFixer& other)
:   PrePostFixer(other)
        {
                printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
        }
*/
void __ccPPDF__pPPDF_KPPDF(PrePostDollarFixer *this, const PrePostDollarFixer *other)
{
    __ccPPF__pPPF_KpPPFp(&this->prePostFixer, &other->prePostFixer);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, other->prePostFixer.post);

}

/*
PrePostDollarFixer::~PrePostDollarFixer()
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}
*/
void __dPPDF__pPPDF(PrePostDollarFixer *this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
    this->prePostFixer.defaultTextFormatter.textFormatter.TF_vptr = PPF_vptr;
    __dPPF__pPPF(&this->prePostFixer);
}

/*
void PrePostDollarFixer::print(int num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(int, char)]");
printf("-->\n");

print(long(num), symbol);
}
*/
void __print__KpPPDFK_Ki_Kc(const PrePostDollarFixer *const this, const int num, const char symbol /*= DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    __print__KpPPDFK_Kl_Kc(this, (long)num, symbol);
}

/*
void PrePostDollarFixer::print(long num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(long, char)]");
printf("-->\n");

PrePostFixer::print(num, symbol);
}
*/
void __print__KpPPDFK_Kl_Kc(const PrePostDollarFixer *const this, const long num, const char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    __pvPrint__KPPFK_Kl_Kc(&this->prePostFixer, num, symbol);
}

/*
void PrePostDollarFixer::print(double num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(double, char)]");
printf("%s%c%f%s\n", getPrefix(), symbol, num, getPostfix());
}
*/
void __print__KpPPDFK_Kd_Kc(const PrePostDollarFixer *const this, const double num, const char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->prePostFixer.pre, symbol, num, this->prePostFixer.post);
}

char __getDefaultSymbolPPDF__()
{
    return '$';
}


/* PrePostHashFixer Defs */
/*
PrePostHashFixer::PrePostHashFixer(int prc)
:   PrePostDollarFixer("===> ", " <===")
,   precision(prc)
        {
                printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", getPrefix(), getPostfix(), precision);

        print(9999.9999);
        }

PrePostHashFixer::~PrePostHashFixer()
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostHashFixer::print(int num, char symbol) const
{
printFunc("[PrePostHashFixer::print(int, char)]");
printf("-->\n");

print(double(num), symbol);
}

void PrePostHashFixer::print(long num, char symbol) const
{
printFunc("[PrePostHashFixer::print(long, char)]");
printf("-->\n");

print(double(num), symbol);
}


//// PrePostFloatDollarFixer Defs ////////////

PrePostFloatDollarFixer::PrePostFloatDollarFixer(const char* prefix, const char* postfix)
:   PrePostDollarFixer(prefix, postfix)
{
printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostFloatDollarFixer::~PrePostFloatDollarFixer()
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostFloatDollarFixer::print(float num) const
{
printFunc("[PrePostFloatDollarFixer::print(float)]");
printf("-->\n");

print(num, DEFAULT_SYMBOL);
}

void PrePostFloatDollarFixer::print(float num, char symbol) const
{
printFunc("[PrePostFloatDollarFixer::print(float, char)]");

printf("%s%c%.2f%s\n", getPrefix(), symbol, num, getPostfix());
}

//// PrePostChecker Defs ////////////

PrePostChecker::PrePostChecker()
:   PrePostFloatDollarFixer("[[[[ ", " ]]]]")
{
printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostChecker::~PrePostChecker()
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostChecker::printThisSymbolUsingFunc() const
{
printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

printf("Default symbol is %c\n", this->getDefaultSymbol());
}

void PrePostChecker::printThisSymbolDirectly() const
{
printFunc("[PrePostChecker::printThisSymbolDirectly()]");

printf("Default symbol is %c\n", this->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByCastUsingFunc() const
{
printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByScopeUsingFunc() const
{
printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByCastDirectly() const
{
printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByScopeDirectly() const
{
printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
}


//// Multiplier Defs ////////////

void Multiplier::print(const char* text) const
{
printFunc("[Multiplier::print(const char*)]");

for (int i = 0; i < times; ++i)
printf("%s", text);
printf("\n");
}

 */

