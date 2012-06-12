//---------------------------------------------------
// Main page documentation
/**
  \mainpage libMesh - A C++ Finite Element Library
 
  \section intro Introduction

   
  The \p libMesh library is a C++ framework for the numerical
  simulation of partial differential equations on serial and parallel
  platforms.  Development began in March 2002 with the intent of
  providing a friendly interface to a number of high-quality software
  packages that are currently available.  Currently the library
  supports 2D and 3D steady and transient finite element simulations.
  <a href="http://www-unix.mcs.anl.gov/petsc/petsc-2"> PETSc </a> is
  currently used for the solution of linear systems on both serial and
  parallel platforms, and
  <a href="http://www.tu-dresden.de/mwism/skalicky/laspack/laspack.html">
   LASPACK </a> is included with the library to provide
  linear solver support on serial machines.
 
  The \p libMesh library is actively developed at The University of Texas at
  Austin in the <a href="http://cfdlab.ae.utexas.edu" target="_top">CFDLab</a>
  and at Technische Universit&auml;t Hamburg-Harburg,
  <a href="http://www.mum.tu-harburg.de/english"> Mechanics and Ocean Engineering</a> 
  in Germany.  Many thanks to
  <a href="http://sourceforge.net"> SourceForge </a>
  for <a href="http://sourceforge.net/projects/libmesh"> hosting the project</a>. 
  You can find out what is currently happening in the development branch
  by checking out the <a href="http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/libmesh"> CVS Logs</a>
  online. 
  
  A major goal of the library is to provide support for adaptive mesh
  refinement (AMR) computations in parallel while allowing a research
  scientist to focus on the physics they are modeling.  The library
  currently offers:
 
   - Partitioning Algorithms
      - Metis K-Way weighted graph partitioning
      - Parmetis parallel graph partitioning
      - Hilbert and Morton-ordered space filling curves
 
   - Generic 2D Finite Elements
      - 3 and 6 noded triangles (\p Tri3, \p Tri6)
      - 4, 8, and 9 noded quadrilaterals (\p Quad4, \p Quad8, \p Quad9)
      - 4 and 6 noded infinite quadrilaterals (\p InfQuad4, \p InfQuad6)
 
   - Generic 3D Finite Elements
      - 4 and 10 noded tetrahedrals (\p Tet4, \p Tet10)
      - 8, 20, and 27 noded hexahedrals (\p Hex8, \p Hex20, \p Hex27)
      - 6, 15, and 18 noded prisms (\p Prism6, \p Prism15, \p Prism18)
      - 5 noded pyramids (\p Pyramid5)
      - 8, 16, and 18 noded infinite hexahedrals (\p InfHex8,
          \p InfHex16, \p InfHex18)
      - 6 and 12 noded infinite prisms (\p InfPrism6, \p InfPrism12)
 
   - Generic Finite Element Families
      - Lagrange
      - Hierarchic
      - Discontinuous Monomials
 
   - Dimension-independence
      - Operators are defined to allow the same code
        to run unmodified on 2D and 3D applications
      - The code you debug and verify on small 2D problems
        can immediately be applied to large, parallel 3D applications
 
   - Sparse Linear Algebra
      - \p PETSc provides a suite of iterative solvers and preconditioners
        for serial and parallel applications
      - Complex values are supported with \p PETSc
      - \p LASPACK provides iterative solvers and preconditioners for serial
        applications
      - The \p SparseMatrix, \p NumericVector, and \p LinearSolverInterface
        allow for transparent switching between solver packages.  Adding
        a new solver interface is as simple as deriving from these classes
 
   - Mesh IO & Format Translation Utilities
      - Ideas Universal (UNV) format (.unv) with support through
        \p MeshData for arbitrary float data, like boundary conditions, 
        associated with mesh entities
      - Sandia National Labs ExodusII format (.exd)
      - Amtec Engineering's Tecplot binary format (.plt)
      - Amtec Engineering's Tecplot ascii format (.dat)
      - Los Alamos National Labs GMV format (.gmv)
      - AVS Unstructured UCD format (.ucd)
 
   - Mesh Creation & Modification Utilities
      - refine or coarsen a mesh: prescribed, level-one-compatible, or uniform
      - build equispaced n-cubes out of \p Edge2, \p Tri3, \p Tri6, 
           \p Quad4, \p Quad8, \p Quad9, \p Hex8, \p Hex20, \p Hex27
      - build circles/spheres out of \p Tri3, \p Tri6, \p Quad4,
           \p Quad8, \p Quad9, \p Hex8
      - add infinite elements to a volume-based mesh, handle symmetry planes
      - convert \p Quad4, \p Quad8, \p Quad9 to \p Tri3, \p Tri6
      - convert a mesh consisting of any of the fore-mentioned
        n-dimensional linear elements to their second-order
        counterparts
      - distort/translate/rotate/scale a mesh
      - determine bounding boxes/spheres
      - extract the mesh boundary for boundary condition handling or
        as a separate mesh


       
  \section install Installation
 
 
 
  \subsection getsoftware Getting the Software
 
  The \p libMesh source can be downloaded from the project's
  <a href="http://sourceforge.net/projects/libmesh">SourceForge
  homepage</a>.   Stable releases are
  located there as compressed tar archives. You may also access the CVS
  source tree for the latest code.  You can get read-only access to the
  CVS repository via:
  
  \verbatim
     cvs -d:pserver:anonymous@cvs.sourceforge.net:/cvsroot/libmesh co libmesh \endverbatim
     
  If you would like to contribute to the project you will need a
  SourceForge developer account, or you can contribute patches.  To create a
  patch from a modified CVS tree simply do:

  \verbatim
    cvs diff -c > patch \endverbatim

  in the top-level directory.  You can then submit the file \p patch.

  
 
 
 
  \subsection compilers Compilers
 
  \p libMesh makes extensive use of the standard C++ library, so you will need
  a decent, standards-compliant compiler.  We have tried very hard to make
  the code completely compiler-agnostic by avoiding questionable (but legal)
  constructs. If you have a compiler that won't build the code please let us
  know. 
 
  You will also need a decent C compiler if you want to build some of the
  contributed packages that add functionality to the library.
 
  The library is known to work with the following compilers:
 
 
  - GNU GCC
    - \p gcc 3.x
    - \p gcc 2.95.x
    - \p gcc 2.96 (RedHat's compiler in the 7.x series)
 
  - Intel ICC/ECC
    - \p icc/ifort 8.x
    - \p icc/ifc 7.x
    - \p icc/ifc 6.0
    - Earlier versions (<= 5.0) not supported.
    
  - SGI Altix
    - \p icc/ifort 8.x
    - \p ecc/efc 7.1
    - \p MPT \p MPI 1.9.1
 
  - SGI IRIX 6.5 with  MIPSPro Compilers
    - CC/cc version 7.4

  - Sun ONE Studio Compilers
    - Version 5.5 tested <code>(CXXFLAGS=-library=stlport4 CPPFLAGS=-library=stlport4 CXX=CC ./configure [...])</code>
    - Must use the STLPort C++ standard library 
 
  - HP, use <code>CXX="aCC -AA" CC="cc -Aa"</code> to get full std support
    - \p aCC A.03.37

  - IBM \p xlC version 5.0, 6.0
  - HP/Compaq/DEC \p cxx 6.3.9.6
 
 
 
  \subsection conf Configuration
 
  Configuring the library is straightforward. The GNU
  autoconf package is used to determine site-specific configuration
  parameters. A standard build will occur after typing
  
  \verbatim
     ./configure
     make \endverbatim
     
  in the top-level project directory.  To see all the configuration
  options type
  
  \verbatim
     ./configure --help \endverbatim
     
  The configure script will find your compilers and create the \p
  Make.common file with the configuration for your site. If you want
  to use different compilers than those found by configure you can
  specify them in environment variables.  For example, the following
  will build with the \p MIPS compilers on an SGI:
  
  \verbatim
     CXX=CC CC=cc F77=f77 CXXFLAGS=-LANG:std ./configure \endverbatim
     
  Note that the FORTRAN compiler is not actually used to compile any
  part of the library, but \p configure uses it to find out how to
  link FORTRAN libraries with C++ code.
 
 
 
  \subsection build Building the Library
 
  To build the library you need \p GNU \p Make and a supported compiler, as
  listed in section \ref conf.  After the library is configured
  simply type \p make to build the library.  Typing \p make \p
  bin/meshtool will build a mesh translation tool using the library.
 
  The Makefiles distributed with the library look at the shell
  environment variable \p METHOD to determine what mode the library
  should be built in.  Valid values for \p METHOD are \p opt
  (optimized mode, the default if \p METHOD is empty), \p debug
  (build with debug symbols), and \p pro (build with profiling
  support for use with \p gprof).  Once the library is configured
  you can build it simply by typing
  \verbatim
     make \endverbatim
  
 
 
 
  \subsection test Testing the Library
 
  \p libMesh includes a number of examples in the \p ./examples
  directory.  From the top-level directory you can build and run
  the example programs by typing 
  \verbatim
     make run_examples \endverbatim
 
  Note that the example programs all create output in the \p GMV
  format, since you can <a href="http://laws.lanl.gov/XCM/gmv/GMVHome.html">download GMV</a>
  for free from Los Alamos National Lab.  It is a simple
  matter to change the source in the example to write a different format,
  just replace the \p write_gmv function call with whatever you like.
 
 
 
  \subsection link Linking With Your Application
 
  Since \p libMesh can be configured with many additional packages
  we recommend including the \p Make.common file created in the
  top-level directory in the \p Makefile of any application you want to
  use with the library.  This will properly set the \p INCLUDE and
  \p LIBS variables, which you can append to with your own stuff.

  For testing simple programs you may want to use the \p libmesh-config script
  included in the \p contrib/bin directory instead of creating a \p Makefile.
  This script may be used to determine the relevant compilation and linking flags
  used by \p libMesh. For example, you could build the application \p foo from
  \p foo.C like this:
  \verbatim
     c++ -o foo foo.C `libmesh-config --cxxflags --include --ldflags` \endverbatim
   
 */

// Local Variables:
// mode: html
// End: