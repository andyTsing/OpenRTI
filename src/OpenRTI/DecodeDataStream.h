/* -*-c++-*- OpenRTI - Copyright (C) 2009-2010 Mathias Froehlich
 *
 * This file is part of OpenRTI.
 *
 * OpenRTI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * OpenRTI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenRTI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OpenRTI_DecodeDataStream_h
#define OpenRTI_DecodeDataStream_h

#include <limits>
#include "VariableLengthData.h"
#include "Types.h"

namespace OpenRTI {

class OPENRTI_API DecodeDataStream {
public:
  DecodeDataStream(const VariableLengthData& variableLengthData) :
    _variableLengthData(variableLengthData),
    _offset(0)
  { }

  size_t size() const
  { return _variableLengthData.size(); }

  void seek(size_t offset)
  {
    if (_variableLengthData.size() < offset)
      throw RTIinternalError(L"Seeking beyond the end of the packet");
    _offset = offset;
  }

  void align(size_t alignSize)
  {
    if (!alignSize)
      return;
    seek(((_offset + alignSize - 1)/alignSize)*alignSize);
  }

  uint8_t readUInt8LE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt8LE(offset);
  }
  uint8_t readUInt8BE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt8BE(offset);
  }
  uint8_t readAlignedUInt8LE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt8LE(offset);
  }
  uint8_t readAlignedUInt8BE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt8BE(offset);
  }

  int8_t readInt8LE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt8LE(offset);
  }
  int8_t readInt8BE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt8BE(offset);
  }
  int8_t readAlignedInt8LE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt8LE(offset);
  }
  int8_t readAlignedInt8BE()
  {
    size_t offset = _offset;
    _offset += 1;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt8BE(offset);
  }


  uint16_t readUInt16LE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt16LE(offset);
  }
  uint16_t readUInt16BE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt16BE(offset);
  }
  uint16_t readAlignedUInt16LE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt16LE(offset);
  }
  uint16_t readAlignedUInt16BE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt16BE(offset);
  }

  int16_t readInt16LE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt16LE(offset);
  }
  int16_t readInt16BE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt16BE(offset);
  }
  int16_t readAlignedInt16LE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt16LE(offset);
  }
  int16_t readAlignedInt16BE()
  {
    size_t offset = _offset;
    _offset += 2;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt16BE(offset);
  }


  uint32_t readUInt32LE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt32LE(offset);
  }
  uint32_t readUInt32BE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt32BE(offset);
  }
  uint32_t readAlignedUInt32LE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt32LE(offset);
  }
  uint32_t readAlignedUInt32BE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt32BE(offset);
  }

  int32_t readInt32LE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt32LE(offset);
  }
  int32_t readInt32BE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt32BE(offset);
  }
  int32_t readAlignedInt32LE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt32LE(offset);
  }
  int32_t readAlignedInt32BE()
  {
    size_t offset = _offset;
    _offset += 4;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt32BE(offset);
  }


  uint64_t readUInt64LE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt64LE(offset);
  }
  uint64_t readUInt64BE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getUInt64BE(offset);
  }
  uint64_t readAlignedUInt64LE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt64LE(offset);
  }
  uint64_t readAlignedUInt64BE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedUInt64BE(offset);
  }

  int64_t readInt64LE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt64LE(offset);
  }
  int64_t readInt64BE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getInt64BE(offset);
  }
  int64_t readAlignedInt64LE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt64LE(offset);
  }
  int64_t readAlignedInt64BE()
  {
    size_t offset = _offset;
    _offset += 8;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    return _variableLengthData.getAlignedInt64BE(offset);
  }


  // FIXME rethink all below

  // bool readBoolBE()
  // { return !!readUInt8BE(); }
  // bool readBoolLE()
  // { return !!readUInt8LE(); }
  bool readBool() // FIXME
  { return !!readUInt8LE(); }

  uint8_t readUInt8Compressed()
  { uint8_t value = 0; readTemplateCompressed(value); return value; }
  int8_t readInt8Compressed()
  { return readUInt8Compressed(); }

  uint16_t readUInt16Compressed()
  { uint16_t value = 0; readTemplateCompressed(value); return value; }
  int16_t readInt16Compressed()
  { return readUInt16Compressed(); }

  uint32_t readUInt32Compressed()
  { uint32_t value = 0; readTemplateCompressed(value); return value; }
  int32_t readInt32Compressed()
  { return readUInt32Compressed(); }

  uint64_t readUInt64Compressed()
  { uint64_t value = 0; readTemplateCompressed(value); return value; }
  int64_t readInt64Compressed()
  { return readUInt64Compressed(); }

  bool readBoolCompressed()
  { return !!readUInt8BE(); }

  size_t readSizeTCompressed()
  {
    uint64_t value = readUInt64Compressed();
    if (std::numeric_limits<size_t>::max() < value)
      throw ResourceError(L"Size error: data size is too huge for this machine!");
    return size_t(value);
  }
  wchar_t readWCharCompressed()
  {
    uint32_t value = readUInt32Compressed();
    if (uint64_t(std::numeric_limits<wchar_t>::max()) < value)
      return wchar_t(0xfffd);
    return wchar_t(value);
  }

  void readData(VariableLengthData& d, size_t size)
  {
    size_t offset = _offset;
    _offset += size;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    d = VariableLengthData(_variableLengthData, offset, size);
  }

  void readData(void* data, size_t size)
  {
    size_t offset = _offset;
    _offset += size;
    if (_variableLengthData.size() < _offset)
      throw RTIinternalError(L"Reading beyond the end of the packet");
    if (size)
      std::memcpy(data, _variableLengthData.data(offset), size);
  }



  // FIXME Move the below into the encoding implementaiotns?

  void readString(std::wstring& s)
  {
    uint32_t i = readUInt32BE();
    s.resize(0);
    s.reserve(i);
    for (; i != 0; --i)
      s.push_back(readWCharCompressed());
  }

  void readStringCompressed(std::wstring& s)
  {
    size_t i = readSizeTCompressed();
    s.resize(0);
    s.reserve(i);
    for (; i != 0; --i)
      s.push_back(readWCharCompressed());
  }

  std::wstring readStringCompressed()
  {
    std::wstring s;
    readStringCompressed(s);
    return s;
  }

  // FIXME move that into the implementation
  void readData(VariableLengthData& d)
  {
    readData(d, readSizeTCompressed());
  }

private:
  template<typename T>
  void readTemplateCompressed(T& value)
  {
    unsigned shift = 7;
    uint8_t byte = readUInt8BE();
    value = (byte & 0x7f);
    while (byte & 0x80) {
      byte = readUInt8BE();
      value |= T(byte & 0x7f) << shift;
      shift += 7;
    }
  }

  const VariableLengthData& _variableLengthData;
  size_t _offset;
};

} // namespace OpenRTI

#endif
