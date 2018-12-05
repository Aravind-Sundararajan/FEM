#include "PhyElement.h"
#include "PhyElementBar.h"
#include "PhyElementTruss.h"
#include "PhyNode.h"
#include "PhyDof.h"
#include "CFEMTypes_Global.h"
#include "PhyGlobal.h"

PhyElement* PhyElementFactory(ElementType eTypeIn)
{
	PhyElement* pePtr = NULL;
	switch (eTypeIn)
	{
//	case etDefault:
//		pePtr = new PhyElement();
//		break;
	case etBar:
		pePtr = new PhyElementBar();
		break;
	case etTruss:
		pePtr = new PhyElementTruss();
		break;
	default:
		THROW("the type is not defined");
	}
	if (pePtr != NULL)
		pePtr->eType = eTypeIn;
	return pePtr;
}

ostream& operator<<(ostream& out, const PhyElement& dat)
{
	// id ElementType
	out << dat.id << '\t' << dat.eType << '\n';
	if (verbose == true)
	{
		for (int i = 0; i < dat.nedof; ++i)
			out << dat.fee(i) << '\t';
	}
	out << '\n';
	dat.SpecificOutput(out);
	out << '\n';
	return out;
}

void PhyElement::setNodeConnectivity_Sizes(int nNodeInElement, int ndofpnIn, vector<int>& eNodesIn, vector <PhyNode*>& eNodePtrsIn)
{
	neNodes = nNodeInElement;
	eNodes.resize(neNodes);
	eNodes = eNodesIn;

	eNodePtrs.resize(neNodes);
	eNodePtrs = eNodePtrsIn;
	// resizing members in PhyElement

	// Complete
	//...
}


void PhyElement::setElementDofMap_ae(int ndofpn)
{
	// Complete
	edofs

	
				edofs(cntr) = dofPtr->v;
				dofMap[cntr++] = - (dofPtr->pos + 1)
			}
			else
				dofMap[cntr++] = dofPtr->pos;
		}
	}
}


void PhyElement::AssembleStiffnessForce(MATRIX& globalK, VECTOR& globalF)
{
	// Complete
	fee.resize(nedof);
	if (foe.size() == nedof)
			fee = foe;

	int I, J;
	for (int i = 0; i < nedof; ++i)
	{
		J = dofMap[j];
		if (J < 0) // prescribed
				fee(i) -= ke(i,j) * edofs(j);
		else
				globalK(I,J) += ke(i,j);
	}
	globalF(I) += fee(i);
}

void PhyElement::UpdateElementForces_GlobalFp(VECTOR& Fp)
{
	// Complete
}
