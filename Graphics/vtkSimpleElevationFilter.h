/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkSimpleElevationFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


Copyright (c) 1993-2001 Ken Martin, Will Schroeder, Bill Lorensen 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither name of Ken Martin, Will Schroeder, or Bill Lorensen nor the names
   of any contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkSimpleElevationFilter - generate scalars along a specified direction
// .SECTION Description
// vtkSimpleElevationFilter is a filter to generate scalar values from a
// dataset.  The scalar values are generated by dotting a user-specified
// vector against a vector defined from the input dataset points to the
// origin. 
// .SECTION See Also
// vtkElevationFilter

#ifndef __vtkSimpleElevationFilter_h
#define __vtkSimpleElevationFilter_h

#include "vtkDataSetToDataSetFilter.h"

class VTK_GRAPHICS_EXPORT vtkSimpleElevationFilter : public vtkDataSetToDataSetFilter 
{
public:
  vtkTypeMacro(vtkSimpleElevationFilter,vtkDataSetToDataSetFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object with Vector=(0,0,1);
  static vtkSimpleElevationFilter *New();

  // Description:
  // Define one end of the line (small scalar values).
  vtkSetVector3Macro(Vector,float);
  vtkGetVectorMacro(Vector,float,3);

protected:
  vtkSimpleElevationFilter();
  ~vtkSimpleElevationFilter() {};

  void Execute();
  float Vector[3];
private:
  vtkSimpleElevationFilter(const vtkSimpleElevationFilter&);  // Not implemented.
  void operator=(const vtkSimpleElevationFilter&);  // Not implemented.
};

#endif


