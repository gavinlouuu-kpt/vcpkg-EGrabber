    public:
        Internal::EGrabberDll egrabberDll;
        // for implementation purpose only
        ce::Eur_EGenTL getBox() const { return box; }

    private:
        ce::Eur_EGenTL box;
        EGenTL(const EGenTL&); // EGenTL objects cannot be copied
        EGenTL &operator=(const EGenTL&); // EGenTL objects cannot be copied
        #include "class.EGenTL.generate.h"
