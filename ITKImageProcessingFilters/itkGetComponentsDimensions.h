#ifndef _ITKGetComponentsDimensions_h
#define _ITKGetComponentsDimensions_h

#include <itkRGBAPixel.h>
#include <itkVector.h>
#include <QVector>

namespace ITKDream3DHelper
{

  template<class PixelType>
  QVector<size_t> GetComponentsDimensions_impl(PixelType*)
  {
    QVector<size_t> cDims(1, 1);
    return cDims;
  }

  template<class PixelType>
  QVector<size_t> GetComponentsDimensions_impl(itk::Vector<PixelType,3>*)
  {
    QVector<size_t> cDims(3, 1);
    return cDims;
  }

  template<class PixelType>
  QVector<size_t> GetComponentsDimensions_impl(itk::Vector<PixelType,2>*)
  {
    QVector<size_t> cDims(2, 1);
    return cDims;
  }

  template<class PixelType>
  QVector<size_t> GetComponentsDimensions_impl(itk::RGBAPixel<PixelType>*)
  {
    QVector<size_t> cDims(1, 4);
    return cDims;
  }

  template<class PixelType>
  QVector<size_t> GetComponentsDimensions()
  {
    return GetComponentsDimensions_impl(static_cast<PixelType*>(0));
  }

}//end of GetComponentsDimensionsHelper namespace

#endif