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
	// Step 8:
	ecdof = 1; // dof counter for element
	for (int en = 1; en < neNodes; ++en)
	{ // number of element nodes
		gn = LEM(en); // global node number for element node en
		for (int endof = 1;endof < ndofpn; ++endof) // This number isxed now, e.g., 2 for 2D trusses
		{
			dofMap(ecdof) = node(gn).dof(endof).pos;
			//gndof = endof, we bypass some steps here
			ecdof = ecdof + 1; // increment counter
		}
	}

	// Step 9:
	dofs = zeros(nedof); // element dofs (edof) resized to number of element dofs and zeroed
	ecdof = 1; // dof counter for element
	for (int en = 1; en < neNodes; ++en)
	{ // number of element nodes
		gn = LEM(en); // global node number for element node en
		for (int endof = 1;endof < ndofpn; ++endof)
		{ // This number isxed now, e.g., 2 for 2D trusses
			if (node(gn).dof(endof).p == true) // gndof = endof we bypass some steps here
			dofs(ecdof) = node(gn).dof(endof).value; // e dof val = corresponding global val
		}
		dofMap(ecdof) = node(gn).dof(endof).pos;
		ecdof = ecdof + 1; // increment counter
	}
	/*
	// End of his code that we borrow
	edofs(cntr) = dofPtr->v;
	dofMap[cntr++] = - (dofPtr->pos + 1)
}
else
dofMap[cntr++] = dofPtr->pos;
}
}
*/
}

// Step 10 is: Compute element stiffness/force (ke, foe (fre: source term; fNe: Neumann BC))
//Equals 0!
void PhyElement::AssembleStiffnessForce(MATRIX& globalK, VECTOR& globalF)
{
	// Complete
	// Step 11
	fee.resize(nedof);
	if (foe.size() == nedof)
	fee = foe;
	else
	fee = 0.0;

	int I, J;
	for (int i = 0; i < nedof; ++i)
	{
		I = dofMap[i];
		if (I < 0) // prescribed dof
		continue
		for (int j = 0; j < nedof; ++j)
		{
			J = dofMap[j];
			if (J < 0) // prescribed
			fee(i) -= ke(i,j) * edofs(j);
			else
			globalK(I,J) += ke(i,j);
		}
		globalF(I) += fee(i);
	}
}

void PhyElement::UpdateElementForces_GlobalFp(VECTOR& Fp)
{
	// Complete
	for (int e = 1; e < ne; ++e) //loop over elements
	{
		fee = feo; //element total force = element all forces except essential force
		for i = 1:nedof //loop over rows of ke; nedof = element # dof
		I = dofMap(i); //local to global dof map M et
		if (I < 0) //I corresponds to a prescribed dof, we skip free dofs
		{
			for (int j = 1; j < nedof; ++j) //loop over columns of ke. ALL columns (dofs) of p and f used
			{
				fee(i) = fee(i) - ke(i, j) * edofs(j); //edofs: element dofs = a e
			}
			Fp(-I) = Fp(-I) - fee(i);
		}
		//1. element’s total force fee component i’th is computed→added to Fp(-I)
		//2. -I used because I < 0: prescribed dof
		//3. fee is subtracted
	}
}
