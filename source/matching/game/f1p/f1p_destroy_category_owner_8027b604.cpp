// Inferred category-owner fields and dynamic shared-string arrays.
struct F1pCategoryIface{void**table;};struct F1pCategoryHeld{F1pCategoryIface*p;~F1pCategoryHeld(){if(p)((void(*)(F1pCategoryIface*))p->table[4])(p);}};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_802134fc(void*);
struct F1pCategoryText{char*text;~F1pCategoryText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pCategoryNames{F1pCategoryText*begin,*end,*capacity;int unknown;~F1pCategoryNames(){F1pCategoryText*last=end;for(F1pCategoryText*p=begin;p!=last;++p)p->~F1pCategoryText();if(begin)fn_802134fc(begin);}};
struct F1pCategoryBase_801628ec{void**table;char unknown[24];~F1pCategoryBase_801628ec();};
struct F1pCategoryOwner:F1pCategoryBase_801628ec{F1pCategoryNames campaign,challenge,tutorial,other5,other6;int state108,state112,state116;F1pCategoryHeld held120;F1pCategoryHeld held124;F1pCategoryHeld held128;F1pCategoryHeld held132;F1pCategoryHeld held136;F1pCategoryHeld held140;F1pCategoryHeld held144;F1pCategoryHeld held148;F1pCategoryHeld held152;F1pCategoryHeld held156;~F1pCategoryOwner();};
extern char vt_8041bec0[];
F1pCategoryOwner::~F1pCategoryOwner(){table=(void**)vt_8041bec0;}
