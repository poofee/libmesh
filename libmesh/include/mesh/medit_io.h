// >>> Complete file added by F. Prill, 04.04.04

// The libMesh Finite Element Library.
// Copyright (C) 2002-2004  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __medit_io_h__
#define __medit_io_h__

// Local includes
#include "libmesh_common.h"
#include "mesh_io.h"

// Forward declarations:
class MeshBase;



/**
 * This class implements writing meshes in the mesh format
 * used by the MEdit visualization tool developed in the Gamma Project
 * at INRIA Roquencourt.
 * For a full description of the mesh format and to obtain the
 * MEdit software see
 * <a href="http://http://www-rocq1.inria.fr/gamma/medit/medit.html">the MEdit home page</a>
 *
 * @author F. Prill, 2004
 */

// ------------------------------------------------------------
// medit_io class definition
class MEDITIO : public MeshIO<MeshBase>
{
 public:

  /**
   * Constructor.  Takes a reference to a constant mesh object.
   * This constructor will only allow us to write the mesh.
   */
  MEDITIO (const MeshBase&);
  
  /**
   * This method implements writing a mesh to a specified file.
   */
  virtual void write (const std::string& );
  
  //  /**
  //   * This method implements writing a mesh with nodal data to a
  //   * specified file where the nodal data and variable names are provided.
  //   */
  //  virtual void write_nodal_data (const std::string&,
  //				 const std::vector<Number>&,
  //				 const std::vector<std::string>&);

  /**
   * Flag indicating whether or not to write a binary file
   */
  bool & binary ();
   
private:

  /**
   * This method implements writing a mesh with nodal data to a
   * specified file where the nodal data and variable names are optionally
   * provided.  This will write an ASCII file.
   */
  virtual void write_ascii (const std::string&,
			    const std::vector<Number>* = NULL,
			    const std::vector<std::string>* = NULL);

  /**
   * Flag to write binary data.
   */
  bool _binary;
 
};



// ------------------------------------------------------------
// medit_io inline members
inline
MEDITIO::MEDITIO (const MeshBase& mesh) :
  MeshIO<MeshBase>  (mesh),
  _binary        (false)
{
}



inline
bool & MEDITIO::binary ()
{
  return _binary;
}



#endif // #define __medit_io_h__
