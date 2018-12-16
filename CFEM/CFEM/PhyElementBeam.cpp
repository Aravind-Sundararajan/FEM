#include "PhyElementBeam.h"
#include "PhyMaterial.h"
#include "PhyNode.h"


void PhyElementBeam::setGeometry()
{
	L = fabs(eNodePtrs[1]->coordinate(0) - eNodePtrs[0]->coordinate(0));
}

void PhyElementBeam::setInternalMaterialProperties(PhyMaterial* pMat)
{
	A = pMat->paras(mpb_A);
	E = pMat->paras(mpb_E);
}

void PhyElementBeam::Calculate_ElementStiffness_Force()
{
	// compute stiffness matrix:
	ke.resize(4, 4);
	double factor = E * I / L^3;
	ke(0, 0) = ke(2, 2) = 12 * factor;
	ke(0, 1) = ke(1, 0) = ke(3, 0) = ke(0, 3) = 6 * L * factor;
  ke(0, 2) = ke(2, 0) = -12 * factor;
  ke(1, 1) = ke(3, 3) = 4 * L^2 * factor;
  ke(1, 2) = ke(2, 1) = ke(2, 3) = ke(3, 2) = -6 * L * factor;
  ke(1, 3) = ke(3, 1) = 2 * L^2 * factor;

}

void PhyElementBeam::SpecificOutput(ostream& out) const
{
	double T = A * E / L * (edofs(1) - edofs(0));
	out << T;
}
