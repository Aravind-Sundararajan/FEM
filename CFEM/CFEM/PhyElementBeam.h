#ifndef PHY_ELEMENT_BEAM__H
#define PHY_ELEMENT_BEAM__H

#include "PhyElement.h"
#include "CFEMTypes_Global.h"

// class PhyElementBar : public PhyElement means PhyElementBar is a (public) subclass of PhyElement.
// So it has all the functions and data of PhyEelement beside its own functions and data (for example L, A, E for solid bar below)

class PhyElementBeam : public PhyElement
{
public:
	virtual void setGeometry();
	virtual void setInternalMaterialProperties(PhyMaterial* pMat);
	virtual void Calculate_ElementStiffness_Force();
	virtual void SpecificOutput(ostream& out) const;
	double L;
	double A, E, I;
};

#endif
