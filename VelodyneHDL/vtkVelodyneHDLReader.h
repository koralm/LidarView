/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkVelodyneHDLReader.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkVelodyneHDLReader - class for reading Velodyne HDL data
// .Section Description
//

#ifndef _vtkVelodyneHDLReader_h
#define _vtkVelodyneHDLReader_h

#include <vtkPolyDataAlgorithm.h>
#include <vtkSmartPointer.h>

class VTK_EXPORT vtkVelodyneHDLReader : public vtkPolyDataAlgorithm
{
public:
  static vtkVelodyneHDLReader *New();
  vtkTypeMacro(vtkVelodyneHDLReader, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  //Description:
  //
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

  //Description:
  //
  int CanReadFile(const char* fname);


  void SplitFrame();
  void ProcessHDLPacket(unsigned char *data, unsigned int bytesReceived);
  std::vector<vtkSmartPointer<vtkPolyData> >& GetDatasets();

protected:
  vtkVelodyneHDLReader();
  ~vtkVelodyneHDLReader();

  int RequestInformation(vtkInformation *,
                         vtkInformationVector **,
                         vtkInformationVector *);

  int RequestData(vtkInformation *,
                  vtkInformationVector **,
                  vtkInformationVector *);

  char *FileName;

  class vtkInternal;
  vtkInternal* Internal;

private:

  vtkVelodyneHDLReader(const vtkVelodyneHDLReader&);
  void operator = (const vtkVelodyneHDLReader&);

};
#endif
